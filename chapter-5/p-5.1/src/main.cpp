#include <string>
#include <iostream>
#include <memory>
#include <vector>

int bitInsertion(int n, int m, int i, int j) {
  for(int k = i; k <= j; k++) {
    int mask = 1 << k;
    n = n & (~mask);
  }

  return (n | (m << i));
}

int main(int argc, char** argv) {
  int n = std::atoi(argv[1]);
  int m = std::atoi(argv[2]);
  int i = std::atoi(argv[3]);
  int j = std::atoi(argv[4]);

  std::cout << bitInsertion(n, m, i, j) << std::endl;

  return 0;
}