#include <string>
#include <iostream>
#include <memory>

class StackNode {
    public:
        StackNode(int input_node_value) {
            this->node_value = input_node_value;
            this->next_node = NULL;
        }
        ~StackNode() {}
        void setNext(std::unique_ptr<StackNode> input_next_node) {
            this->next_node = std::move(input_next_node);
        }
        std::unique_ptr<StackNode> getNext() {
            return std::move(this->next_node);
        }
        int getValue() {
            return this->node_value;
        }
    private:
        int node_value;
        std::unique_ptr<StackNode> next_node;
};

class MyStack {
    public:
        MyStack() {}
        ~MyStack() {}
        void push(int node_value) {
            std::unique_ptr<StackNode> tmp = std::make_unique<StackNode>(node_value);
            if(this->top != nullptr)
                tmp->setNext(std::move(top));
            this->top = std::move(tmp);

            if(this->minimum_top != nullptr) {
                if(this->minimum_top->getValue() > node_value) {
                    std::unique_ptr<StackNode> minimum_tmp = std::make_unique<StackNode>(node_value);
                    minimum_tmp->setNext(std::move(minimum_top));
                    this->minimum_top = std::move(minimum_tmp);
                } else {
                    std::unique_ptr<StackNode> minimum_tmp = std::make_unique<StackNode>(this->minimum_top->getValue());
                    minimum_tmp->setNext(std::move(minimum_top));
                    this->minimum_top = std::move(minimum_tmp);
                }
            } else {
                std::unique_ptr<StackNode> minimum_tmp = std::make_unique<StackNode>(node_value);
                this->minimum_top = std::move(minimum_tmp);
            }
        }
        int pop() {
            if(this->top != nullptr) {
                std::unique_ptr<StackNode> tmp = std::move(this->top);
                this->top = std::move(tmp->getNext());

                std::unique_ptr<StackNode> minimum_tmp = std::move(this->minimum_top);
                this->minimum_top = std::move(minimum_tmp->getNext());

                return tmp->getValue();
            }
        }
        int peek() {
            if(this->top != nullptr) {
                return this->top->getValue();
            }
        }
        bool isEmpty() {
            return (this->top == nullptr);
        }
        int min() {
            if(this->top != nullptr) {
                return this->minimum_top->getValue();
            }
        }
    private:
        std::unique_ptr<StackNode> top;
        std::unique_ptr<StackNode> minimum_top;
};

int main(int argc, char** argv) {
    MyStack stack;
    std::cout << stack.isEmpty() << std::endl;
    std::cout << stack.peek() << std::endl;
    std::cout << stack.pop() << std::endl;

    stack.push(5);
    std::cout << stack.peek() << std::endl;
    std::cout << stack.min() << std::endl;

    stack.push(1);
    std::cout << stack.peek() << std::endl;
    std::cout << stack.min() << std::endl;

    stack.push(7);
    std::cout << stack.peek() << std::endl;
    std::cout << stack.min() << std::endl;

    stack.push(0);
    std::cout << stack.peek() << std::endl;
    std::cout << stack.min() << std::endl;

    std::cout << stack.pop() << std::endl;
    std::cout << stack.min() << std::endl;
    
    std::cout << stack.pop() << std::endl;
    std::cout << stack.min() << std::endl;

    return 0;
}