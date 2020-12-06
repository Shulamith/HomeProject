#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

void parse(std::string input) {
  std::vector<std::string> parsedResult;
  int number;
  std::cout << input[input.size()-1];
  std::istringstream ss(input);
    std::string word; // for storing each word
    while (ss >> word)
    {
        std::cout << word << "\n";
        parsedResult.push_back(word);
    }

}

void listen() {
  std::string input;
  while (getline(std::cin, input)) {
    std::cout << input << std::endl;
    parse(input);
  }
}

int main(int argc, char const *argv[]) {
  listen();
  std::cout << "Main exit" << std::endl;
  return 0;
}
