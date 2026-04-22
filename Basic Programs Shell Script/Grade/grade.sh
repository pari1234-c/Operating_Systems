#!/bin/bash

echo "Enter marks:"
read marks

if [ $marks -gt 75 ]; then
    echo "Distinction"
elif [ $marks -ge 65 ] && [ $marks -le 75 ]; then
    echo "1st Division"
elif [ $marks -ge 55 ] && [ $marks -lt 65 ]; then
    echo "2nd Division"
else
    echo "3rd Division"
fi
