#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>

int staircase(int n, std::shared_ptr<std::map<int, int>> memory) {
  if(n < 0)
    return 0;

  if(n == 0)
    return 1;

  if(memory->find(n) != memory->end())
    return (*memory)[n];

  (*memory)[n] = staircase(n-1, memory) + staircase(n - 2, memory) + staircase(n - 3, memory);
  return (*memory)[n];
}

int staircase(int n) {
  std::shared_ptr<std::map<int, int>> memory = std::make_shared<std::map<int, int>>();
  return staircase(n, memory);
}

int main(int argc, char** argv) {
  int n = std::atoi(argv[1]);

  std::cout << staircase(n) << std::endl;

  return 0;
}