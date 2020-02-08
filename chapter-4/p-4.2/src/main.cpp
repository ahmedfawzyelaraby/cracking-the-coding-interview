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
    void traverse() {
      this->traverseChild(this->root);
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
    void traverseChild(std::shared_ptr<Node> current_node) {
      if(!current_node->isEmpty()) {
        std::cout << "Current Node: " << current_node->getValue() << std::endl;
        this->traverseChild(current_node->getLeft());
        this->traverseChild(current_node->getRight());
      }
    }
  std::shared_ptr<Node> root;
  bool first_insertion = true;         
};

void balancedTree(std::vector<int> values, std::shared_ptr<BinaryTree> tree) {
  int pos = (values.size() - 1) / 2;
  tree->insert(values[pos]);

  if(pos > 0)
    balancedTree(std::vector<int>(values.begin(), values.begin() + pos), tree);

  if(pos+1 < values.size())
    balancedTree(std::vector<int>(values.begin() + pos + 1, values.end()), tree);
  
}

int main(int argc, char** argv) {
  std::vector<int> input_values;
  for(int i = 1; i < argc; i++) {
      input_values.push_back(std::atoi(argv[i]));
  }

  std::shared_ptr<BinaryTree> tree = std::make_shared<BinaryTree>();
  balancedTree(input_values, tree);
  tree->traverse();

  return 0;
}