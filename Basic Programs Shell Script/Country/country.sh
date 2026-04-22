#!/bin/bash

echo "Enter the country name:"
read country

if [ "$country" == "India" ]; then
    echo "Country name is India"
elif [ "$country" == "Nepal" ]; then
    echo "Country name is Nepal"
else
    echo "Invalid country"
fi
