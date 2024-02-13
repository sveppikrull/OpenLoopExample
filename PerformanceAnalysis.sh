#!/bin/bash

N="1000 100000 1000000 10000000 100000000"

# Write "C" to file
echo -n "C:        " > Performance.txt

# Execute ./C/main.c and write output to file
for n in $N;
do
    ./C/main "$n" >> Performance.txt
done

# Write "API" to file
echo -e -n "\nAPI:      " >> Performance.txt

# Execute python API/main.py and write output to file
for n in $N;
do
    python API/main.py "$n" >> Performance.txt
done

# Write "Ctypes" to file
echo -e -n "\nCtypes:   " >> Performance.txt

# Execute python Ctypes/main.py and write output to file
for n in $N;
do
    python ctypes/main.py "$n" >> Performance.txt
done

# Write "Python" to file
echo -e -n "\npython:   " >> Performance.txt

# Execute python3 Python/main.py and write output to file
for n in $N;
do
    python python/main.py "$n" >> Performance.txt
done
# Finished
echo "Script execution completed."
