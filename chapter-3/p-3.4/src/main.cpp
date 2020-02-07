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

class MyQueue {
    public:
        MyQueue() {
            this->input_stack = std::make_unique<MyStack>();
            this->output_stack = std::make_unique<MyStack>();
        }
        ~MyQueue() {}
        void shiftStacks() {
            if(this->output_stack->isEmpty()) {
                while(!this->input_stack->isEmpty()) {
                    this->output_stack->push(this->input_stack->pop());
                }
            }
        }
        void add(int node_value) {
            this->input_stack->push(node_value);
        }
        int peek() {
            this->shiftStacks();
            return this->output_stack->peek();
        }
        int remove() {
            this->shiftStacks();
            return this->output_stack->pop();
        }
        bool isEmpty() {
            return (this->input_stack->isEmpty() && this->output_stack->isEmpty());
        }
    private:
        std::unique_ptr<MyStack> input_stack;
        std::unique_ptr<MyStack> output_stack;

};

int main(int argc, char** argv) {
    MyQueue queue;
    std::cout << queue.isEmpty() << std::endl;
    std::cout << queue.peek() << std::endl;
    std::cout << queue.remove() << std::endl;

    queue.add(5);
    std::cout << queue.peek() << std::endl;

    queue.add(1);
    std::cout << queue.peek() << std::endl;

    queue.add(7);
    std::cout << queue.peek() << std::endl;

    queue.add(0);
    std::cout << queue.peek() << std::endl;

    std::cout << queue.remove() << std::endl;
    
    std::cout << queue.remove() << std::endl;

    return 0;
}