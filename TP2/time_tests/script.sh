#!/bin/bash

program="$1"
uinp="$2"
uout="$3"
fname="$4"
step1="_1step"
step5="_5step"
step10="_10step"
t=".txt"

f="$fname$step1$t"
for ((i=0; i < 10; i++)); do 
    ( time ./"$program" "$uinp" "$uout" "1" ) >> "$f" 2>&1;
done;

f="$fname$step5$t"
for ((i=0; i < 10; i++)); do 
    ( time ./"$program" "$uinp" "$uout" "5" ) >> "$f" 2>&1;
done;

f="$fname$step10$t"
for ((i=0; i < 10; i++)); do 
    ( time ./"$program" "$uinp" "$uout" "10" ) >> "$f" 2>&1;
done;