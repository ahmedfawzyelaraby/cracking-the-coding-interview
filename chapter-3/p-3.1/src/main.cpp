#include <string>
#include <iostream>
#include <map>

class MyStack {
    public:
        MyStack(int input_stack_size) {
            this->stack_size = input_stack_size;
            this->data_array = new int[3 * this->stack_size];
            this->stack_top  = new int[3]{-1, -1, -1};
        }

        ~MyStack() {}

        int pop(int stack_num) {
            int result_index = this->stack_top[stack_num];
            this->stack_top[stack_num]--;
            return this->data_array[(stack_num * this->stack_size) + result_index];
        }

        bool push(int stack_num, int value) {
            this->stack_top[stack_num]++;
            if(this->stack_top[stack_num] < this->stack_size) {
                this->data_array[(stack_num * this->stack_size) + this->stack_top[stack_num]] = value;
                return true;
            }
            return false;
        }

        int peek(int stack_num) {
            if(this->stack_top[stack_num] >= 0)
                return this->data_array[(stack_num * this->stack_size) + this->stack_top[stack_num]];
        }

        bool isEmpty(int stack_num) {
            return (this->stack_top[stack_num] < 0);
        }
    private:
        int stack_size;
        int* data_array;
        int* stack_top;
};

int main(int argc, char** argv) {
    MyStack triple_stack(5);

    triple_stack.push(0, 4);
    triple_stack.push(0, 1);
    triple_stack.push(0, 2);

    triple_stack.push(1, 2);
    triple_stack.push(1, 7);

    triple_stack.push(2, 90);
    triple_stack.push(2, 47);

    std::cout << triple_stack.peek(0) << std::endl;
    std::cout << triple_stack.peek(1) << std::endl;
    std::cout << triple_stack.peek(2) << std::endl;

    triple_stack.pop(0);
    triple_stack.pop(1);
    triple_stack.pop(2);

    std::cout << triple_stack.peek(0) << std::endl;
    std::cout << triple_stack.peek(1) << std::endl;
    std::cout << triple_stack.peek(2) << std::endl;

    return 0;
}