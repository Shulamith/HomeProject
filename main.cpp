#include "./OS.hpp"
#include "./disk.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
std::vector<std::string> parse(std::string input) {
  std::vector<std::string> parsedResult;
  std::istringstream ss(input);
  std::string word; // for storing each word
  while (ss >> word) {
    // std::cout << word << "\n";
    parsedResult.push_back(word);
  }
  return parsedResult;
}

int main(int argc, char const *argv[]) {
  std::string memory, numOfDisks;
  char a;
  std::cout << "How much RAM memory is there on the simulated computer?"
            << "\n";
  std::cin >> memory;
  std::cout << "How many hard disks does the simulated computer have?"
            << "\n";
  std::cin >> numOfDisks;
  long long memory2 = stoll(memory);
  OS OSModel = OS(memory2, stoi(numOfDisks));
  std::string input;
  std::vector<std::string> parsedResult, processTwo, processThree;
  // std::cin >> a;
  // std::cout << a << '\n';
  // parsedResult.push_back("A");
  // parsedResult.push_back("4");
  // parsedResult.push_back("1000");
  // processTwo.push_back("A");
  // processTwo.push_back("5");
  // processTwo.push_back("400");
  // processThree.push_back("A");
  // processThree.push_back("7");
  // processThree.push_back("100");
  // OSModel.parse(parsedResult);
  // OSModel.parse(processTwo);
  // OSModel.parse(processThree);
  // OS.addProcess(parsedResult);
  // control(parsedResult, ramMem);
  // disk d = disk();
  // d.setup(4);
  // d.finishReading(0);
  // d.addCylinder(1,6,3);
  // d.diskPrint();
  while (getline(std::cin, input)) {
    if (input.size() > 0) {
      parsedResult = parse(input);
      OSModel.parse(parsedResult);
    }
  }
  std::cout << "Main exit" << std::endl;
  return 0;
}
