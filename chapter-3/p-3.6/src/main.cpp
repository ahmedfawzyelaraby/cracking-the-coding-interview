#include <string>
#include <iostream>
#include <memory>
#include <vector>

class StackNode {
    public:
        StackNode(std::string input_node_value) {
            this->node_value = input_node_value;
            this->next_node = NULL;
        }
        ~StackNode() {}
        void setNext(std::shared_ptr<StackNode> input_next_node) {
            this->next_node = input_next_node;
        }
        std::shared_ptr<StackNode> getNext() {
            return this->next_node;
        }
        std::string getValue() {
            return this->node_value;
        }
    private:
        std::string node_value;
        std::shared_ptr<StackNode> next_node;
};

class MyQueue {
    public:
        MyQueue() {}
        ~MyQueue() {}
        void add(std::string node_value) {
            std::shared_ptr<StackNode> tmp = std::make_shared<StackNode>(node_value);
            
            if(this->last != nullptr)
                this->last->setNext(tmp);
            
            this->last = tmp;

            if(this->first == nullptr)
                this->first = tmp;
            
            this->queue_size++;
        }
        std::string remove() {
            if(this->first != nullptr) {
                std::string result = this->first->getValue();
                this->first = this->first->getNext();
                if(this->first == nullptr)
                    this->last = nullptr;
                this->queue_size--;
                return result;
            }
            return "";
        }
        std::string peek() {
            if(this->first != nullptr) {
                return this->first->getValue();
            }
        }
        bool isEmpty() {
            return (this->first == nullptr);
        }
        int size() { return this->queue_size; }
    private:
        std::shared_ptr<StackNode> first;
        std::shared_ptr<StackNode> last;
        int queue_size = 0;
};

class AnimalShelter {
    public:
        AnimalShelter() {
            this->queue = std::make_unique<MyQueue>();
        }
        ~AnimalShelter() {}
        void enqueue(std::string node_value) {
            this->queue->add(node_value);
        }
        std::string dequeueAny() {
            return this->queue->remove();
        }
        std::string dequeueDog() {
            return this->dequeueType(this->dog_str);
        }
        std::string dequeueCat() {
            return this->dequeueType(this->cat_str);
        }
    private:
        std::string dequeueType(std::string node_value) {
            std::unique_ptr<MyQueue> tmp = std::make_unique<MyQueue>();
            bool found = false;
            std::string result = "";
            while(!this->queue->isEmpty()) {
                if(!found) {
                    if(this->queue->peek() == node_value) {
                        found = true;
                        result = this->queue->peek();
                    }
                }

                if(!found) {
                    tmp->add(this->queue->remove());
                } else {
                    this->queue->remove();
                    break;
                }

            }
            while(!this->queue->isEmpty()) {
                tmp->add(this->queue->remove());
            }
            this->queue = std::move(tmp);
            std::cout << this->queue->size() << std::endl;
            return result;
        }
        std::unique_ptr<MyQueue> queue;
        const std::string dog_str = "dog";
        const std::string cat_str = "cat";
};

int main(int argc, char** argv) {
    AnimalShelter queue;
    queue.enqueue("cat");
    queue.enqueue("cat");
    queue.enqueue("cat");
    queue.enqueue("dog");
    queue.enqueue("cat");

    std::cout << queue.dequeueDog() << std::endl;
    std::cout << queue.dequeueAny() << std::endl;
    std::cout << queue.dequeueAny() << std::endl;
    std::cout << queue.dequeueAny() << std::endl;
    std::cout << queue.dequeueAny() << std::endl;
    std::cout << queue.dequeueAny() << std::endl;
    std::cout << queue.dequeueAny() << std::endl;

    return 0;
}