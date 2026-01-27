#!/bin/bash

# Compile contacts program
gcc ../c-programs/contacts.c -o contacts

# Run contacts
./contacts

# Backup all C files
tar -czf contacts-backup.tar.gz ../c-programs/*

# Log execution time
echo "Project ran at $(date)" >> project-log.txt

