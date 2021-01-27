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
  long long memory2 = std::stoll(memory);
  OS OSModel = OS(memory2, stoi(numOfDisks));
  std::string input;
  std::vector<std::string> parsedResult, processTwo, processThree;

  while (getline(std::cin, input)) {
    if (input.size() > 0) {
      parsedResult = parse(input);
      OSModel.parse(parsedResult);
    }
  }
  std::cout << "Main exit" << std::endl;
  return 0;
}
