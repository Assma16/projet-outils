#! /bin/sh
mkdir ~/.initdev
zip -r initdev.zip *
unzip initdev.zip -d ~/.initdev
cd ~/.initdev
./main.sh

