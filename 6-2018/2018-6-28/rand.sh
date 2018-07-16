#!/bin/bash
#########################################################################
# File Name: rand.sh
# Author: free
# mail: fancanglang@foxmail.com
# Created Time: Thu 28 Jun 2018 11:27:15 AM CST
#########################################################################

for i in `seq 1 1000`
do
	res=`expr $RANDOM % 1000`
	echo $res >> random
done
