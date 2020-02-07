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

class MySotedStack {
    public:
        MySotedStack() {
            this->main_stack = std::make_unique<MyStack>();
            this->tmp_stack = std::make_unique<MyStack>();
        }
        ~MySotedStack() {}
        void sort() {
            int to_sort_size = this->main_stack->size();

            while(to_sort_size > 0) {
                int max_value;
                int counter = 0;
                if(!this->main_stack->isEmpty()) {
                    max_value = this->main_stack->pop();
                    counter++;
                }
                while(counter < to_sort_size) {
                    if(max_value < this->main_stack->peek()) {
                        this->tmp_stack->push(max_value);
                        max_value = this->main_stack->pop();
                    } else {
                        this->tmp_stack->push(this->main_stack->pop());
                    }
                    counter++;
                }
                this->main_stack->push(max_value);
                while(!this->tmp_stack->isEmpty()) {
                    this->main_stack->push(this->tmp_stack->pop());
                }
                to_sort_size--;
            }
        }
        void push(int node_value) {
            this->main_stack->push(node_value);
            this->sort();
        }
        int peek() {
            return this->main_stack->peek();
        }
        int pop() {
            return this->main_stack->pop();
        }
        bool isEmpty() {
            return this->main_stack->isEmpty();
        }
    private:
        std::unique_ptr<MyStack> main_stack;
        std::unique_ptr<MyStack> tmp_stack;

};

int main(int argc, char** argv) {
    MySotedStack stack;
    std::cout << stack.isEmpty() << std::endl;
    std::cout << stack.peek() << std::endl;
    std::cout << stack.pop() << std::endl;

    stack.push(5);
    std::cout << stack.peek() << std::endl;

    stack.push(1);
    std::cout << stack.peek() << std::endl;

    stack.push(7);
    std::cout << stack.peek() << std::endl;

    std::cout << stack.pop() << std::endl;
    
    std::cout << stack.pop() << std::endl;

    stack.push(9);
    std::cout << stack.pop() << std::endl;

    return 0;
}