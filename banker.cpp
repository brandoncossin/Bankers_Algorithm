// Operating System Assignment 2
// Banker's Algorithm

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]){
  //5 processes, 3 columns, 3 values in each column
  int processes[5][3][3];
  //array of the available
  int available[3];
  //array of number of each process to give the safe sequence
  int safe_sequence[5];
  // index is a talley of how many are safe, if safe this will be 5
  // this removes use of vectors
  int index = 0;
  //talley of how many times around the loop we go
  //this checks if we have done a full loop, which means unsafe
  //this prevents unlimited loops
  int unsafe_check = 0;
  //checks if the process was used;
  int flag[5] = {0, 0, 0, 0, 0};
  //Initial setup, reading from the input
  std::ifstream file;
  if(argc == 1){
    std::cout << "File Needs a txt file to read from." << std::endl;
    return 0;
  }
  //opens file
  file.open(argv[1]);
  if(file.is_open()){
    std::string line;
    int process_tracker = 0;
    while(std::getline(file, line)){
      int tracker = 0;
      std::istringstream ss(line);
      std::string value;
      while(std::getline(ss, value, ' ')){
        if (tracker != 0){
          int num = stoi(value);
          if(tracker == 1 || tracker == 2 || tracker == 3){
            //Allocation Values
            processes[process_tracker][0][tracker-1] = num;
          }
          if(tracker == 4 || tracker == 5 || tracker == 6){
            //Max Values
            processes[process_tracker][1][tracker-4] = num;
          }
          if(tracker == 7 || tracker == 8 || tracker == 9){
            //Available Values
            //Only present on first string/first process
            // Adds to unique array which is used to keep track of the values
            available[tracker-7] = num;
          }
        }
        ++tracker;
      }
      ++process_tracker;
    }
    file.close();
  }
  // Generates the Need Values
  for(int i = 0; i < 5; ++i){
    processes[i][2][0] = processes[i][1][0] - processes[i][0][0];
    processes[i][2][1] = processes[i][1][1] - processes[i][0][1];
    processes[i][2][2] = processes[i][1][2] - processes[i][0][2];
  }
  // Prints the processes
  std::cout << "Process \t Allocation \t Max \t Need"<< std::endl;
  for(int i = 0; i < 5; ++i){
    std::cout << "P" << i << "\t " << processes[i][0][0] <<" "<< processes[i][0][1] << " " << processes[i][0][2] << '\t';
    std::cout << '\t' << processes[i][1][0] <<" "<< processes[i][1][1] << " " << processes[i][1][2] << '\t';
    std::cout << '\t'<<processes[i][2][0] <<" "<< processes[i][2][1] << " " << processes[i][2][2] << std::endl;
  }
    //Loop continuisly until the safe sequence is found
  for(int j = 0; index <= 4; ++j){
    int i = (j%6);
    //if the Need is less than the available
    if(processes[i][2][0] <= available[0] & processes[i][2][1] <= available[1] & processes[i][2][2] <= available[2] & flag[i] == 0){
      // available + allocation
      available[0] += processes[i][0][0];
      available[1] += processes[i][0][1];
      available[2] += processes[i][0][2];
      safe_sequence[index] = i;
      ++index;
      unsafe_check = 0;
      flag[i] = 1;
    }
    //if not less than, increment so the loop can be tracked
    else{
      ++unsafe_check;
    }
    //if the loop did a full round trip with no change it is unsafe
    if(unsafe_check == 5){
      break;
    }
  }
  if(unsafe_check == 5){
    std::cout << "System is not in a safe state" << std::endl;
  }
  else{
    std::cout << "System is in a safe state. The Safe Sequence is: \n";
    for(int i = 0; i < 5; ++i){
      std::cout << 'P' << safe_sequence[i] << ' ';
    }
    std::cout << std::endl;
  }
}
