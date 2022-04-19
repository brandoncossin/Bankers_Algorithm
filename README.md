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
g++ banker -o banker.cpp
./banker
```
## Files
Banker.cpp checks the system based off the process list in the form of a txt file
txt files are setup to be in the format of
Process Name | Allocation | Max | Available
## Example
