#!/bin/bash

file1=$1
file2=$2

if cmp -s "$file1" "$file2"; then
    # the same
    printf 'files (%s : %s) are the same\n' "$file1" "$file2"
else
    # not the same!!
    printf 'ERROR: files (%s : %s) are not the same\n%s\n%s\n\n' "$file1" "$file2" "$(cat $file1)" "$(cat $file2)"
fi
