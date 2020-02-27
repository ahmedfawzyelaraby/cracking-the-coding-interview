#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

class Node {
  public:
    Node(char input_value) {
      this->node_value = input_value;
    }
    void setValue(char input_value) {
      this->node_value = input_value;
    }
    char getValue() {
      return this->node_value;
    }
    void addChild(char input_value) {
      std::shared_ptr<Node> child = std::make_shared<Node>(input_value);
      this->childs.push_back(child);
    }
    bool hasChilds() {
      return (this->childs.size() > 0);
    }
    bool hasChild(char input_value) {
      for(int i = 0; i < this->childs.size(); i++) {
        if(this->childs[i]->getValue() == input_value)
          return true;
      }

      return false;
    }
    void removeChild(char input_value) {
      for(int i = 0; i < this->childs.size(); i++) {
        if(this->childs[i]->getValue() == input_value) {
          this->childs.erase(this->childs.begin() + i);
          break;
        }
      }
    }
  private:
    char node_value;
    std::vector<std::shared_ptr<Node>> childs;
};

class Graph {
  public:
    Graph() {}
    ~Graph() {}
    void addNode(char input_value) {
      std::shared_ptr<Node> node = std::make_shared<Node>(input_value);
      this->nodes.push_back(node);
    }
    void removeNode(char input_value) {
      for(int i = 0; i < nodes.size(); i++) {
        if(this->nodes[i]->getValue() == input_value) {
          this->nodes.erase(this->nodes.begin() + i);
          break;
        }
      }
    }
    void addNodeDependancy(char node, char dependancy) {
      for(int i = 0; i < nodes.size(); i++) {
        if(this->nodes[i]->getValue() == node)
          this->nodes[i]->addChild(dependancy);
      }
    }
    void removeNodeDependancy(char node, char dependancy) {
      for(int i = 0; i < nodes.size(); i++) {
        if(this->nodes[i]->getValue() == node)
          this->nodes[i]->removeChild(dependancy);
      }
    }
    void removeDependancy(char dependancy) {
      for(int i = 0; i < nodes.size(); i++) {
        this->nodes[i]->removeChild(dependancy);
      }
    }
    std::vector<std::shared_ptr<Node>> getReadyNodes() {
      std::vector<std::shared_ptr<Node>> readyNodes;
      for(int i = 0; i < nodes.size(); i++) {
        if(!this->nodes[i]->hasChilds())
          readyNodes.push_back(this->nodes[i]);
      }
      return readyNodes;
    }
    bool hasNodes() {
      return (this->nodes.size() > 0);
    }
    void drainBuildOrder() {
      while((this->hasNodes()) && (this->getReadyNodes().size() > 0)) {
        std::vector<std::shared_ptr<Node>> ready_nodes = this->getReadyNodes();
        for(int i = 0; i < ready_nodes.size(); i++) {
          std::cout << ready_nodes[i]->getValue() << std::endl;
          this->removeDependancy(ready_nodes[i]->getValue());
          this->removeNode(ready_nodes[i]->getValue());
        }
      }

      if(this->hasNodes())
        std::cout << "No Solution" << std::endl;
    }
  private:
    std::vector<std::shared_ptr<Node>> nodes;
};

int main(int argc, char** argv) {
  // std::vector<char> input_nodes = {'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<char> input_nodes = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  // std::vector<std::vector<char>> input_nodes_dependancy = {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};
  std::vector<std::vector<char>> input_nodes_dependancy = {{'d', 'g'}, {'b', 'e'}, {'a', 'e'}, {'b', 'a'}, {'f', 'a'}, {'c', 'a'}, {'f', 'b'}, {'f', 'c'}};
  Graph buildOrderGraph;
  for(int i = 0; i < input_nodes.size(); i++) {
    buildOrderGraph.addNode(input_nodes[i]);
  }
  for(int i = 0; i < input_nodes_dependancy.size(); i++) {
    buildOrderGraph.addNodeDependancy(input_nodes_dependancy[i][1], input_nodes_dependancy[i][0]);
  }
  buildOrderGraph.drainBuildOrder();
  return 0;
}