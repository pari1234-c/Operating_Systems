#!/bin/bash

echo "Enter a number:"
read num

flag=0

if [ $num -le 1 ]; then
    echo "Number is not a Prime number"
    exit
fi

for ((i=2; i<=num/2; i++))
do
    if [ $((num % i)) -eq 0 ]; then
        flag=1
        break
    fi
done

if [ $flag -eq 0 ]; then
    echo "Number is a Prime number"
else
    echo "Number is not a Prime number"
fi
