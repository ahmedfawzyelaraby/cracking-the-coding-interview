#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>

bool isObstacle(std::vector<int> current_node, std::vector<std::vector<int>> obstacles) {
  for(int i = 0; i < obstacles.size(); i++) {
    if((current_node[0] == obstacles[i][0]) && (current_node[1] == obstacles[i][1]))
      return true;
  }

  return false;
}

bool findPath(std::vector<int> current_node, int rows, int cols, std::vector<std::vector<int>> obstacles, std::shared_ptr<std::vector<std::vector<int>>> path_way ) {
  if(current_node[0] >= rows)
    return false;

  if(current_node[1] >= cols)
    return false;

  if(isObstacle(current_node, obstacles))
    return false;

  if((current_node[0] == (rows - 1)) && (current_node[1] == (cols - 1))) {
    path_way->push_back(current_node);
    return true;
  }

  std::vector<int> next_node = current_node;
  next_node[0]++;
  if(findPath(next_node, rows, cols, obstacles, path_way)) {
    path_way->push_back(current_node);
    return true;
  }

  next_node = current_node;
  next_node[1]++;
  if(findPath(next_node, rows, cols, obstacles, path_way)) {
    path_way->push_back(current_node);
    return true;
  }
}

std::vector<std::vector<int>> findPath(int rows, int cols, std::vector<std::vector<int>> obstacles) {
  std::vector<int> start = {0, 0};
  std::shared_ptr<std::vector<std::vector<int>>> path_way = std::make_shared<std::vector<std::vector<int>>>();
  findPath(start, rows, cols, obstacles, path_way);
  return (*path_way);
}

int main(int argc, char** argv) {
  int r = std::atoi(argv[1]);
  int c = std::atoi(argv[2]);
  std::vector<std::vector<int>> obstacles;
  for(int i = 3; i < argc; i++) {
    std::vector<int> current_obstacle;
    current_obstacle.push_back(std::atoi(argv[i]));
    current_obstacle.push_back(std::atoi(argv[i+1]));
    i++;
    obstacles.push_back(current_obstacle);
  }

  std::vector<std::vector<int>> result = findPath(r, c, obstacles);
  for(int i = 0; i < result.size(); i++) {
    std::cout << result[i][0] << "\t" << result[i][1] << std::endl;
  }

  return 0;
}