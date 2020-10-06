#!/bin/bash

VERSION=1.0
ARCH=x86_64
THISHOST=$(hostname)
TODAY=$(date)
ME=$USER

pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd "$@" > /dev/null
}

# check the arguments
if [ $# == 1 ] && [ $1 == "-h" ] ; then
         echo "usage: ./welcome.sh -- print useful info (${VERSION})"
         exit
fi

if [ $# != 0 ] ; then
		echo "ERROR!!!! There are $# arguments!!";
		exit
fi

BANNER="Welcome ${ME}@${THISHOST}, ${TODAY} (Version ${VERSION}:${ARCH})"
echo $BANNER

if [ ! -d ./mydir ] ; then 
		mkdir ./mydir
fi

echo "There are $# arguments!!"
if [ -d ./mydir ] ; then
         echo "mydir is present"
fi

pushd ./mydir
echo [$(pwd)]
touch t1.c
touch t2.c
touch t3.c
touch t4.c 

for f in *.c ; do
                echo ${f}
done
popd

X=0
while [ ${X} -lt 5 ] ; do
                echo ${X}
                let X=X+1
done

