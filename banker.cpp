// Operating System Assignment 2
File Edit Options Buffers Tools C++ Help
// Operating System Assignment 2
// Banker's Algorithm

#include <iostream>
#include <fstream>
#include <sstream>

int main(){
  int safe_sequence[5];
  //5 processes, 3 columns, 3 values in each column
  int processes[5][3][3];
  std::ifstream file;
  file.open("process_list.txt");
  if(file.is_open()){
    std::string line;
    int process_tracker = 0;
    while(std::getline(file, line)){
      int tracker = 0;
      std::istringstream ss(line);
      std::string value;
      while(std::getline(ss, value, ' ')){
        if(tracker == 0){
          std::cout << "Process" << process_tracker << ": " << '\n';
        }
        if (tracker != 0){
        int num = stoi(value);
        num +=10;
        std::cout << num << '\n';
        if(tracker == 1 || tracker == 2 || tracker == 3){
          //Allocation Values
          processes[process_tracker][0][tracker-1] = num;
          std::cout << num << '\n';
        }
        if(tracker == 4 || tracker == 5 || tracker == 6){
          //Max Values
          processes[process_tracker][1][tracker-4] = num;
          std::cout << num << '\n';
        }
        if(tracker == 7 || tracker == 8 || tracker == 9){
          //Available Values
          //Only present on first string/first process
          processes[process_tracker][2][tracker-7] = num;
          std::cout << num << '\n';
        }
        }
        ++tracker;

      }
      ++process_tracker;

    }
    file.close();
  }
  std::cout << "Allocation Values"<< std::endl;
  for(int i = 0; i < 5; ++i){
    std::cout << "process" << i << " " << processes[i][0][0] <<" "<< processes[i][0][1] << " " << processes[i][0][2] << "\n";

  }
}
