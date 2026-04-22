#!/bin/bash

# Program to find largest of two numbers

echo "Enter first number:"
read a

echo "Enter second number:"
read b

if [ $a -gt $b ]; then
    echo "Largest number is: $a"
elif [ $b -gt $a ]; then
    echo "Largest number is: $b"
else
    echo "Both numbers are equal"
fi
