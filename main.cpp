#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

void parse(std::string input) {
  std::vector<std::string> parsedResult;
  std::string digitsInAString;
  int number;
  std::cout << input[input.size()-1];
  std::istringstream ss(input);

    std::string word; // for storing each word

    // Traverse through all words
    // while loop till we get
    // strings to store in string word
    while (ss >> word)
    {
        // print the read word
        std::cout << word << "\n";
        parsedResult.push_back(word);
    }
  // char* char_arr;
  // // char_arr = &input[0];
  // // char delim = ' ';
  // // char *token = strtok(char_arr, delim);
  // // while(token){
  // //   parsedResult.push_back(token);
  // //   std::cout << token << "\n";
  // //   token = strtok(NULL, delim);
  // // }
  // // LATER I CAN CLEAN IT
  // // HASH table or just regular table? # of expected inputs
  // // input = input.split("\\s+");
  // //   std::cout << "try" << input;
  // //
  // for (int i = 0; i < input.length(); i++) {
  //   std::cout << "parse: " << input[i] << std::endl;
  //   if (input[i] = 't') {
  //     // callterminate
  //   }
  //   if (input[i] == 'S') {
  //     while (i < input.length() && input[i + 1] == ' ') {
  //       i++;
  //     }
  //     i = i + 1;
  //     if (input[i] == 'r') {
  //       // showProcesses();
  //     } else if (input[i] == 'i') {
  //       // showi();
  //     } else if (input[i] == 'm') {
  //       // showm();
  //     } else {
  //       std::cout
  //           << "Something is broken in the Parser or user input is incorrect "
  //           << std::endl;
  //     }
  //   }
  //   if (input[i] == 'D') {
  //     parsedResult.push_back(2);
  //     while (i < input.length() && input[i + 1] == ' ') {
  //       i++;
  //     }
  //     i = i + 1;
  //     digitsInAString = "";
  //     while (input[i] != ' ') {
  //       digitsInAString += input[i];
  //       i++;
  //     }
  //     int number = stoi(digitsInAString);
  //     std::cout << number << "\n";
  //     parsedResult.push_back(number);
  //   }
  //   if (input[i] == 'd') {
  //     /// this is broken
  //     parsedResult.push_back(1);
  //     for (int j = 0; j < 2; j++) {
  //       // while whitespace
  //       while (i < input.length() && input[i + 1] == ' ') {
  //         i++;
  //       }
  //       // Should I catch if i out of bounds??
  //       i = i + 1;
  //       digitsInAString = "";
  //       while (input[i] != ' ') {
  //         digitsInAString += input[i];
  //         i++;
  //       }
  //       int number = stoi(digitsInAString);
  //       std::cout << number << "\n";
  //       parsedResult.push_back(number);
  //     }
  //   }
  //   if (input[i] == 'A') {
  //     parsedResult.push_back(1);
  //     for (int j = 0; j < 2; j++) {
  //       // while whitespace
  //       while (i < input.length() && input[i + 1] == ' ') {
  //         i++;
  //       }
  //       // Should I catch if i out of bounds??
  //       i = i + 1;
  //       digitsInAString = "";
  //       while (input[i] != ' ') {
  //         digitsInAString += input[i];
  //         i++;
  //       }
  //       int number = stoi(digitsInAString);
  //       std::cout << number << "\n";
  //       parsedResult.push_back(number);
  //     }
  //     // TO DO: CHECK IF THE VECTOR HAS THE RIGHT AMOUNT OF ELEMENTS if not
  //     // reset vector and let the user know
  //   }
  // }
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
