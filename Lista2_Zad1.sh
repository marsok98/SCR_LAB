#!/bin/bash



dzien=$(date +%w) #+%w okresla format w tym wypadku ktory dzien tygodnia

if [ $dzien -eq 6 ] || [ $dzien -eq 0 ] ; then
    echo "Weekend"
else
    echo "Dzien roboczy"
fi
