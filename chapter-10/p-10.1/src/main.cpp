#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
  int a_counter = 0;
  int b_counter = 0;
  while((a_counter < a.size()) && (b_counter < b.size())) {
    if(a[a_counter] < b[b_counter]) {
      b.insert(b.begin() + b_counter, a[a_counter]);
      a_counter++;
      b_counter++;
    } else {
      b_counter++;
    }
  }

  while(a_counter < a.size()) {
    b.push_back(a[a_counter]);
    a_counter++;
  }

  return b;
}

int main(int argc, char** argv) {
  std::vector<int> a = {1, 5, 7, 50, 90, 155};
  std::vector<int> b = {2, 4, 8, 77, 88, 154};

  std::vector<int> result = merge(a, b);
  for(int i = 0; i < result.size(); i++) {
    std::cout << result[i] << std::endl;
  }

  return 0;
}