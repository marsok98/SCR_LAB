#!/bin/bash

#nazwa pliku do szukania$1
#ilosc dni do tylu$2
# nazwa archiwum 3
tar cfv $3 `find -name "$1" -mtime -$2`
