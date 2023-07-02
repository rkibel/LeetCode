#!/bin/bash


# Iterate over the files in the directory
for file in Problem*; do
    # Extract the problem number
    problem_number="${file#Problem}"

    # Rename the file
    mv "$file" "$problem_number"
done

echo "File renaming complete."

read -n 1 -s -r -p "Press any key to exit..."