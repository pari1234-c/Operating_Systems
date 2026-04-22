#!/bin/bash

echo "Choose an option:"
echo "1. Check Leap Year"
echo "2. Check Even or Odd"
echo "3. Find Largest of Three Numbers"

read choice

case $choice in

1)
    echo "Enter a year:"
    read year

    if (( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) )); then
        echo "Leap Year"
    else
        echo "Not a Leap Year"
    fi
    ;;

2)
    echo "Enter a number:"
    read num

    if [ $((num % 2)) -eq 0 ]; then
        echo "Number is Even"
    else
        echo "Number is Odd"
    fi
    ;;

3)
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
    ;;

*)
    echo "Invalid choice"
    ;;

esac
