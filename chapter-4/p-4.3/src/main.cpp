#include <string>
#include <iostream>
#include <memory>
#include <vector>

class Node {
  public:
    Node() {
        this->is_empty = true;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~Node() {}
    void setValue(int input_node_value) { 
      this->node_value = input_node_value;
      this->is_empty = false;
    }
    int getValue() { return this->node_value; }
    std::shared_ptr<Node> getLeft() {
      if(this->left == nullptr)
        this->left = std::make_shared<Node>();
      
      return this->left;
    }
    std::shared_ptr<Node> getRight() {
      if(this->right == nullptr)
        this->right = std::make_shared<Node>();
      
      return this->right;
    }
    bool isEmpty() { return this->is_empty;}
  private:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    int node_value;
    bool is_empty;
};

class BinaryTree {
  public:
    BinaryTree() {
      this->root = std::make_shared<Node>();
    }
    ~BinaryTree() {}
    void insert(int node_value) {
      this->insertToChild(node_value, this->root);
    }
    std::vector<std::vector<std::shared_ptr<Node>>> traverse() {
      std::vector<std::vector<std::shared_ptr<Node>>> input;
      return this->traverseChild(this->root, 0, input);
    }
  private:
    void insertToChild(int node_value, std::shared_ptr<Node> parent) {
      if(parent->isEmpty())
        parent->setValue(node_value);
      else if(node_value <= parent->getValue())
        this->insertToChild(node_value, parent->getLeft());
      else
        this->insertToChild(node_value, parent->getRight());
    }
    std::vector<std::vector<std::shared_ptr<Node>>> traverseChild(std::shared_ptr<Node> current_node, int level,
      std::vector<std::vector<std::shared_ptr<Node>>> input) {
      if(!current_node->isEmpty()) {
        std::cout << "Current Node: " << current_node->getValue() << " at Level: " << level << std::endl;
        if(level > (int(input.size()) - 1)) {
          std::vector<std::shared_ptr<Node>> new_level_list;
          input.push_back(new_level_list);
        }
        input[level].push_back(current_node);
        input = this->traverseChild(current_node->getLeft(), level + 1, input);
        input = this->traverseChild(current_node->getRight(), level + 1, input);
      }
      return input;
    }
  std::shared_ptr<Node> root;
  bool first_insertion = true;         
};

int main(int argc, char** argv) {
  std::shared_ptr<BinaryTree> tree = std::make_shared<BinaryTree>();
  for(int i = 1; i < argc; i++) {
      tree->insert(std::atoi(argv[i]));
  }
  std::vector<std::vector<std::shared_ptr<Node>>> result = tree->traverse();

  std::cout << "Number of Levels: " << result.size() << std::endl;

  return 0;
}