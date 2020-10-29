#!/bin/bash
x=1;
#trap "Ciach" {1..17} #w drugiej czesci zadania
while [ $x -le 10000 ] ; do
	x=$[x + 1]
echo "PID $$"
	sleep 1s
done

#Crl Z 19 SIGSTOP
#Crl C 2 SIGINT
#Crl \ 3 SIGQUIT
#kill -18  SIGCONT

