#!/bin/bash
#########################################################################
# File Name: rand.sh
# Author: free
# mail: fancanglang@foxmail.com
# Created Time: Fri 29 Jun 2018 08:56:21 AM CST
#########################################################################

for i in `seq 1 1000` 
do
	rand=`expr $RANDOM % 1000`
	echo $rand >> random
done
