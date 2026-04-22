#!/bin/bash

echo "Enter your age:"
read age

if [ $age -eq 18 ]; then
    echo "Your age is equal to 18"
else
    echo "Your age is not equal to 18"
fi
