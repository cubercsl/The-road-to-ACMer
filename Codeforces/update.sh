#!/bin/bash
if [ -z $1 ] 
then
    echo "usage: update <commmit message>"
    exit
fi
find -name "*.txt" |xargs rm -rf {}
git add .
git commit -m $1
git push
