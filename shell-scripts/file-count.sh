#!/bin/bash

read -p "Enter directory path: " DIR

if [ ! -d "$DIR" ]; then
  echo "Not a valid directory."
  exit 1
fi

LOG="file-count-log.txt"

echo "File count for $DIR on $(date)" > $LOG

find "$DIR" -type f | sed 's/.*\.//' | sort | uniq -c | sort -nr >> $LOG

cat $LOG

