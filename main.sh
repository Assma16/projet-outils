#! /bin/sh
gcc -D_GNU_SOURCE -o initdev main.c -w
echo "\ninitdev compiled successfully\n"
./initdev
export PATH=$PATH:~/.initdev
