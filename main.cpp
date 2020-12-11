#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <cstdlib>
#include "./OS.hpp"
// void control(std::vector<std::string> &result, Memory &ramMem){ //ToDo: pass by reference
//   std::cout << "here\n";
//   bool inUse = false;
//   int pID = 0; //put in own class somwhere
//     //Memory ramMem = Memory(4000);
//     //ramMem.getMemory()
//    if(result.at(0) == "A"){
//      //   //Ask memory if it has room and ask for it to recieve
//      //   //Create process
//      Process p = Process(pID, stoi(result[1]));
//      std::cout << "/* message */" << '\n';
//   //   //Check if CPU in use
//     if(inUse){
//
//     }
//   //   //if no: let cpu be in use with this processes, and change process status to running
//   //   //if yes: add it to the readyQueue;
//    }
// }
std::vector<std::string> parse(std::string input) {
  std::vector<std::string> parsedResult;
  std::istringstream ss(input);
    std::string word; // for storing each word
    while (ss >> word)
    {
        std::cout << word << "\n";
        parsedResult.push_back(word);
    }
    std::cout << parsedResult.size() << '\n';
    return parsedResult;
}

int main(int argc, char const *argv[]) {
  std::string memory, numOfDisks;
  char a;
  std::cout << "How much RAM memory is there on the simulated computer?" << "\n";
  std::cin >> memory;
  std::cout << "How many hard disks does the simulated computer have?" << "\n";
  std::cin >> numOfDisks;
  //std::cout << "\n";
  long long memory2 = stoll(memory);
  OS OSModel = OS(memory2, stoi(numOfDisks));
  //Memory ramMem = Memory(4000);
  std::string input;
  std::vector<std::string> parsedResult, processTwo, processThree;
  //std::cin >> a;
  //std::cout << a << '\n';
  parsedResult.push_back("A");
  parsedResult.push_back("4");
  parsedResult.push_back("1000");
  processTwo.push_back("A");
  processTwo.push_back("5");
  processTwo.push_back("400");
  processThree.push_back("A");
  processThree.push_back("7");
  processThree.push_back("100");
  OSModel.parse(parsedResult);
  OSModel.parse(processTwo);
  OSModel.parse(processThree);
  //OS.addProcess(parsedResult);
  //control(parsedResult, ramMem);

  while (getline(std::cin, input)) {
    std::cout << "input:" << input << "end" << std::endl;
    if(input.size() > 0){
        parsedResult = parse(input);
        OSModel.parse(parsedResult);
    }

  }
  std::cout << "Main exit" << std::endl;
  return 0;
}
