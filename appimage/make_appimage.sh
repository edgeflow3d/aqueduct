#!/bin/sh

linuxdeploy --appdir ./appdir -e ../build/bin/Aqueduct -d ./aqueduct.desktop -i ./aqueduct_logo_256.png --custom-apprun=./AppRun

ARCH=x86_64 appimagetool ./appdir/
