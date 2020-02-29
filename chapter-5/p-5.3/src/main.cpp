#include <string>
#include <iostream>
#include <memory>
#include <vector>

int maxOnesBinary(int n) {
  std::vector<int> input_binary;
  std::vector<int> ones_length;
  while(n > 0) {
    if(n % 2 == 0)
      input_binary.push_back(0);
    else
      input_binary.push_back(1);
    
    n /= 2;
  }

  int currentLength = 0;
  int previousLength = 0;
  int max = 0;
  for(int i = 0; i < input_binary.size(); i++) {
    if(input_binary[i] == 1) {
      currentLength++;
    } else {
      previousLength = currentLength;
      currentLength = 0;
    }

    max = (max > (currentLength + previousLength + 1) ? max : (currentLength + previousLength + 1));
  }

  return max;
}

int main(int argc, char** argv) {
  int n = std::atoi(argv[1]);

  std::cout << maxOnesBinary(n) << std::endl;

  return 0;
}