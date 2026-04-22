#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Enter third number:"
read c

if [ $a -ge $b ] && [ $a -ge $c ]; then
    echo "Largest number is: $a"
elif [ $b -ge $a ] && [ $b -ge $c ]; then
    echo "Largest number is: $b"
else
    echo "Largest number is: $c"
fi
