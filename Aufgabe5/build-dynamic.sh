#!/bin/sh 
for s in liste.c notenspiegel.c fachnote.c ; do 
        compile_command="gcc -c -fPIC -W -Wall -ansi -pedantic $s"  
        echo $compile_command
        eval $compile_command
    if [ $? -ne 0 ] ; then
        echo build failed 
        exit 1 
    fi 
done 
link_dynamisch="gcc -shared liste.o fachnote.o -o libaufgabe.so" 
echo $link_dynamisch
eval $link_dynamisch
if [ $? -ne 0 ] ; then 
    echo build failed 
    exit 1 
fi 
link_command="gcc notenspiegel.o -L. -laufgabe5 -o notenspiegel" 
echo $link_command
eval $link_command
if [ $? -ne 0 ] ; then 
    echo build failed 
    exit 1 
fi 

echo build successful 