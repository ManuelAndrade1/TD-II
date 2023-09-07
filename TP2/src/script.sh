#!/bin/bash

program="$1"
uinp="$2"
uout="$3"
count="$4"
fname="$5"

for ((i=0; i < 10; i++)); do 
    ( time ./"$program" "$uinp" "$uout" "$count" ) >> "$fname" 2>&1;
done;