#include <string>
#include <iostream>
#include <memory>
#include <vector>

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
            this->stack_size++;
        }
        int pop() {
            if(this->top != nullptr) {
                std::unique_ptr<StackNode> tmp = std::move(this->top);
                this->top = std::move(tmp->getNext());

                this->stack_size--;
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
        int size() { return this->stack_size; }
    private:
        std::unique_ptr<StackNode> top;
        int stack_size = 0;
};

class SetOfStacks {
    public:
        SetOfStacks(int input_max_stack_size) {
            this->max_stack_size = input_max_stack_size;
        }
        ~SetOfStacks() {}
        void push(int node_value) {
            if(this->set_of_stacks.size() <= 0) {
                std::unique_ptr<MyStack> new_stack = std::make_unique<MyStack>();
                this->set_of_stacks.push_back(std::move(new_stack));
            }

            if(this->set_of_stacks[this->set_of_stacks.size() - 1]->size() >= this->max_stack_size) {
                std::unique_ptr<MyStack> new_stack = std::make_unique<MyStack>();
                this->set_of_stacks.push_back(std::move(new_stack));
            }

            this->set_of_stacks[this->set_of_stacks.size() - 1]->push(node_value);
        }
        int pop() {
            if(this->set_of_stacks.size() > 0) {
                return this->set_of_stacks[this->set_of_stacks.size() - 1]->pop();
            }
        }
        int peek() {
            if(this->set_of_stacks.size() > 0) {
                return this->set_of_stacks[this->set_of_stacks.size() - 1]->peek();
            }
        }
        int isEmpty() {
            if(this->set_of_stacks.size() <= 0)
                return true;

            if(this->set_of_stacks[0]->size() <= 0)
                return true;

            return false;
        }
    private:
        int max_stack_size;
        std::vector<std::unique_ptr<MyStack>> set_of_stacks;

};

int main(int argc, char** argv) {
    SetOfStacks stack(2);
    std::cout << stack.isEmpty() << std::endl;
    std::cout << stack.peek() << std::endl;
    std::cout << stack.pop() << std::endl;

    stack.push(5);
    std::cout << stack.peek() << std::endl;

    stack.push(1);
    std::cout << stack.peek() << std::endl;

    stack.push(7);
    std::cout << stack.peek() << std::endl;

    stack.push(0);
    std::cout << stack.peek() << std::endl;

    std::cout << stack.pop() << std::endl;
    
    std::cout << stack.pop() << std::endl;

    return 0;
}