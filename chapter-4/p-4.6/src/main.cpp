#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>

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
    void search(int search_value) {
      this->traverseChild(this->root, search_value);
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
    void traverseChild(std::shared_ptr<Node> current_node, int search_value) {
      if(!current_node->isEmpty()) {
        this->traverseChild(current_node->getLeft(), search_value);
        std::cout << "Current Node: " << current_node->getValue();
        if(this->found) {
          std::cout << " and it is the right successor!";
          this->found = false;
        }
        if(search_value == current_node->getValue())
          this->found = true;
        std::cout << std::endl;
        this->traverseChild(current_node->getRight(), search_value);
      }
    }
  std::shared_ptr<Node> root;
  bool found = false;
};

int main(int argc, char** argv) {
  std::shared_ptr<BinaryTree> tree = std::make_shared<BinaryTree>();
  for(int i = 1; i < (argc - 1); i++) {
      tree->insert(std::atoi(argv[i]));
  }
  
  tree->search(std::atoi(argv[argc - 1]));

  return 0;
}