# Bankers_Algorithm 
Banker's Algorithm for deadlock avoidance.
The program will print if the system is a safe state.
If there is a safe state, the safe sequence will be printed.
## Setup
```
sudo apt install g++
```
## Compilation  
```
c++ banker.cpp
./a.out [txt file name].txt
```
## Files
Banker.cpp checks the system based off the process list in the form of a txt file
txt files are setup to be in the format of
Process Name | Allocation | Max | Available
## Example
```
$ c++ banker.cpp
$ ./a.out
File Needs a txt file to read from.
$ ./a.out process_list.txt
Process          Allocation      Max     Need
P0       0 1 0          7 5 3           7 4 3
P1       2 0 0          3 2 2           1 2 2
P2       3 0 2          9 0 2           6 0 0
P3       2 1 1          2 2 2           0 1 1
P4       0 0 2          4 3 3           4 3 1
System is in a safe state. The Safe Sequence is:
P1 P3 P4 P0 P2
$ ./a.out process_list2.txt
Process          Allocation      Max     Need
P0       0 1 0          17 15 13                17 14 13
P1       2 0 0          3 2 2           1 2 2
P2       3 0 2          9 0 2           6 0 0
P3       2 1 1          2 2 2           0 1 1
P4       0 0 2          4 3 3           4 3 1
System is not in a safe state
```
