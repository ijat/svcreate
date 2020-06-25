#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <limits.h>
#include "lib/inipp.h"

#define defType "simple"
#define defTarget "multi-user.target"

int main(int argc, char *argv[]) {
    inipp::Ini<char> ini;

    char cwd[PATH_MAX];
    getcwd(cwd, PATH_MAX);

    std::string ExePath = argv[1];
    std::string ExeName = std::filesystem::path(ExePath).filename().string();

    // Unit section
    auto &unit = ini.sections["Unit"];
    unit["Description"] = ExeName + " Service";

    // Service section
    auto &service = ini.sections["Service"];
    service["Type"] = defType;
    service["ExecStart"] = ExePath;
    service["WorkingDirectory"] = cwd;

    // Install section
    auto &install = ini.sections["Install"];
    install["WantedBy"] = defTarget;

    // Generate and save
    std::ofstream iniout;
    iniout.open("out.service");
    ini.generate(iniout);

    return 0;
}
