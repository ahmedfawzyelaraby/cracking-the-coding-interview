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
    bool traverse() {
      std::shared_ptr<int> max_level = std::make_shared<int>(0);
      return this->traverseChild(this->root, 0, max_level);
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
    bool traverseChild(std::shared_ptr<Node> current_node, int level, std::shared_ptr<int> max_level) {
      bool result = true;
      std::shared_ptr<int> max_left = std::make_shared<int>(0);
      std::shared_ptr<int> max_right = std::make_shared<int>(0);
      *(max_level.get()) = level - 1;
      if(!current_node->isEmpty()) {
        bool balanced_left = this->traverseChild(current_node->getLeft(), level + 1, max_left);
        bool balanced_right = this->traverseChild(current_node->getRight(), level + 1, max_right);
        int tmp = ((*(max_left.get())) > (*(max_right.get())) ? (*(max_left.get())) : (*(max_right.get())));
        *(max_level.get()) = (level > tmp ? level : tmp);
        result = (balanced_left && balanced_right && (abs((*(max_left.get())) - (*(max_right.get()))) <= 1));
        std::cout << "Current Node: " << current_node->getValue() << " at Level: " << level << " with Max Depth: " <<
          *(max_level.get()) << " and Balance State: " << result << std::endl;
      }
      return result;
    }
  std::shared_ptr<Node> root;
  bool first_insertion = true;         
};

int main(int argc, char** argv) {
  std::shared_ptr<BinaryTree> tree = std::make_shared<BinaryTree>();
  for(int i = 1; i < argc; i++) {
      tree->insert(std::atoi(argv[i]));
  }
  
  std::cout << tree->traverse() << std::endl;

  return 0;
}