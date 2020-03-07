# How to use?

Run this command to start

`svcrete /path/to/bin`

Then out.service file will be generated in the same folder (or your current working directory). Move it to `/usr/lib/systemd/services` and run `systemctl daemon reload`. Now your app service available to use using systemctl.
