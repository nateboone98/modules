#!/bin/bash

if  [ $# == 0 ] || ( [ $# == 1 ]  && [ $1 == "-q" ] ) ; then
		if [ !  -e *.c ] && [ ! -e *.h ] && [ ! -e Makefile ]; then
				echo "Nothing to backup";
				exit
		fi
	  if [ ! -d .backup ] ; then
			 mkdir .backup
		fi
		if [ -e *.c ] ; then
		for f in *.c ; do
			 if  !( diff ${f} .backup/${f} &> /dev/null) ; then
					 cp ${f} .backup/${f}
					 if [ $# == 0 ]; then
							echo ${f}
					 else
							 echo -n  ".";
					 fi
				fi
		done
		fi
if [  -e *.h ] ; then
		for f in *.h ; do
       if !(diff ${f} .backup/${f} &> /dev/null) ; then
           cp ${f} .backup/${f}
           if [ $# == 0 ]; then
              echo ${f}
           else
               echo -n  ".";
           fi
        fi
    done
fi
if [  -e Makefile ] ; then
		for f in Makefile ; do
       if !(diff ${f} .backup/${f} &> /dev/null) ; then
           cp ${f} .backup/${f}
           if [ $# == 0 ]; then
              echo ${f}
           else
               echo -n  ".";
           fi
       fi
		 done
	fi
else
		echo "usage: backup.sh";
		exit
fi
