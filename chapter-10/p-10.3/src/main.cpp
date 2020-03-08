#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>

int binarySearch(std::vector<int> array, int start, int end, int search_value) {
  if(start > end)
    return -1;

  int mid = (start + end) / 2;
  if(array[mid] == search_value)
    return mid;
  else if(search_value < array[mid])
    return binarySearch(array, start, mid - 1, search_value);
  else
    return binarySearch(array, mid + 1, end, search_value);
}

int searchRotated(std::vector<int> array, int search_value) {
  std::vector<int> vertices;
  for(int i = 1; i < array.size(); i++) {
    if(array[i] < array[i - 1])
      vertices.push_back(i);
  }

  if(vertices.size() <= 0)
    return binarySearch(array, 0, array.size() - 1, search_value);

  for(int i = 0; i < vertices.size(); i++) {
    int result;
    if(i == 0)
      result = binarySearch(array, 0, vertices[i] - 1, search_value);
    else
      result = binarySearch(array, vertices[i - 1], vertices[i], search_value);

    if(result != -1)
      return result;
  }

  return binarySearch(array, vertices[vertices.size() - 1], array.size() - 1, search_value);
}

int main(int argc, char** argv) {
  int search_value = std::atoi(argv[1]);
  std::vector<int> array;
  for(int i = 2; i < argc; i++) {
    array.push_back(std::atoi(argv[i]));
  }

  std::cout << searchRotated(array, search_value) << std::endl;

  return 0;
}