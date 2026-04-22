#!/bin/bash

echo "Enter value of a:"
read a

echo "Enter value of b:"
read b

if [ $b -eq 0 ]; then
    echo "Division by zero not allowed"
else
    div=$((a / b))
    echo "Division of $a and $b is: $div"
fi
