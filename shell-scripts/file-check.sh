#!/bin/bash

read -p "Enter a filename: " FILE

if [ -e "$FILE" ]; then
  echo "File exists."
  ls -l "$FILE"
else
  echo "File does NOT exist."
fi

