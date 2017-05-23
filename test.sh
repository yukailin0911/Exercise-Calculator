#!/bin/bash

PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

make testElement
make testMyStack
make testMyQueue

./testElement
./testMyStack
./testMyQueue

make clean

exit 0
