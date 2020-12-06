#include <iostream>

void parse(std:: string input){
  for(int i=0; i<input.length(); i++){
    std::cout << "parse: " << input[i] << std::endl;
    if (input[i] == 'A'){
      //while whitespace
      while(i<input.length() && input[i+1] == ' '){
        i++;
        std::cout << i << "\n";
      }
      //catch if i out of bounds?
      std::string prioritySize = "";
      std::cout << "prioritySize" << prioritySize << std::endl;
      i=i+1;
      while(input[i] != ' '){
        prioritySize += input[i];
        i++;
      }
      std::cout << "prioritySize: " << prioritySize << "\n";
      int priorityNumber = stoi(prioritySize);
      std::cout << priorityNumber << "\n";
    }
  }

}

void listen() {
  std::string input;
  while (getline(std::cin, input)){
    std::cout << input << std::endl;
    parse(input);
  }
 }

int main(int argc, char const *argv[]) {
  listen();
  std::cout << "Main exit" << std::endl;
  return 0;
}
