#!/bin/bash

if [ $1 -ge 60 ]
then
    echo "及格了"
elif [ $1 -lt 60 ]
then
    echo "不及格"
fi

case $1 in
"1")
    echo "monday"
;;
"2")
    echo "thuesday"
;;
*)
    echo "other"
;;
esac

for(( i=1; i<=$1; i++))
do
    SUM=$[$SUM + $i]
done
echo "SUM=$SUM"
