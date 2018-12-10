#!/bin/sh 
for s in liste.c notenspiegel.c fachnote.c ; do 
        compile_command="gcc -c -W -Wall -ansi -pedantic $s"  
        echo $compile_command
        eval $compile_command
    if [ $? -ne 0 ] ; then
        echo build failed 
        exit 1 
    fi 
done 
link_command="gcc fachnote.o notenspiegel.o liste.o -o notenspiegel" 
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then 
    echo build failed 
    exit 1 
fi 
echo build successful 