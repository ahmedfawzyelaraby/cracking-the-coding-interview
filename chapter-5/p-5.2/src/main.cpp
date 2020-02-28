#include <string>
#include <iostream>
#include <memory>
#include <vector>

std::string binaryToString(double n) {
  if((n < 0) || (n >= 1)) {
    return "ERROR";
  }

  std::string result = "0.";
  while(n > 0) {
    n *= 2.0;
    if(result.length() > 32)
      return "ERROR";

    if(n >= 1) {
      result += "1";
      n -= 1.0;
    } else {
      result += "0";
    }
  }

  return result;
}

int main(int argc, char** argv) {
  double n = std::atof(argv[1]);

  std::cout << binaryToString(n) << std::endl;

  return 0;
}