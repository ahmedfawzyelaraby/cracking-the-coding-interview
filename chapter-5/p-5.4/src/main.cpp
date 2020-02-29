#include <string>
#include <iostream>
#include <memory>
#include <vector>

std::vector<unsigned> minMaxSameOnesCount(unsigned n) {
  int ones_count = 0;
  unsigned current_n = n;
  while(current_n > 0) {
    if(current_n % 2 != 0)
      ones_count++;
    
    current_n /= 2;
  }

  std::vector<unsigned> result;

  unsigned current = n - 1;
  bool found = false;
  while((current > 0)  && (!found)) {
    int current_ones_count = 0;
    unsigned current_n = current;
    while(current_n > 0) {
      if(current_n % 2 != 0)
        current_ones_count++;
      
      current_n /= 2;
    }

    if(ones_count == current_ones_count) {
      found = true;
      result.push_back(current);
    }

    current--;
  }

  current = n + 1;
  found = false;
  while((current > 0)  && (!found)) {
    int current_ones_count = 0;
    unsigned current_n = current;
    while(current_n > 0) {
      if(current_n % 2 != 0)
        current_ones_count++;
      
      current_n /= 2;
    }

    if(ones_count == current_ones_count) {
      found = true;
      result.push_back(current);
    }

    current++;
  }

  return result;
}

int main(int argc, char** argv) {
  unsigned n = std::atoi(argv[1]);

  std::vector<unsigned> result = minMaxSameOnesCount(n);
  std::cout << result[0] << std::endl;
  std::cout << result[1] << std::endl;

  return 0;
}