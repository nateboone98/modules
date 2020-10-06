#!/bin/bash
#Nathanael Boone
#This script runs regression testing on module2


if [ $# -lt 2 ] ; then
		echo "usage: regress.sh <dirname> <testfilename>"
		exit 1
fi

first=$1

if [ -f $1 ] ; then
		echo "please enter a directory for <dirname>"
		exit 1
fi

shift

for f in "$@" ; do
		if [[ !  -r "$f" || !  -f  "$f" ]] ; then
				echo "Please enter valid filenames"
				exit 1
		fi
done

if [ ! -d "$first" ] ; then
		mkdir "$first"
		echo "test results saved in "$first""


  for f in "$@" ; do
        cat "$f" > ./"$first"/"$f".test
        bash "$f"  2>  ./"$first"/"$f".stderr 1> ././"$first"/"$f".stdout
				echo "$?"  > ./"$first"/"$f".status
    done

exit 0		
fi

if [ -d "$first" ] ; then
		dir=$(date '+%Y%m%d.%H%M%S')
		mkdir "$dir"

		for f in "$@" ; do
				cat "$f" > ./"$first"/"$f".test
        bash "$f"  2>  ./"$first"/"$f".stderr 1> ././"$first"/"$f".stdout
        echo "$?"  > ./"$first"/"$f".status

		done

fi

echo "comparing $dir and  $first"
diff=$(diff --brief "$dir" "$first")
if [ ! diff = "" ] ; then
	 	exit 1
else
		echo "no differences"
		exit 0
fi
