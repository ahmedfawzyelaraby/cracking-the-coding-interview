#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

bool checkLoop(node* head) {
    std::map<node*, int> occurance_map;
    node* current = head;
    while(current != NULL) {
        std::map<node*, int>::iterator index = occurance_map.find(current);
        if(index != occurance_map.end()) {
            return true;
        } else {
            occurance_map[current] = 1;
        }
        current = current->next;
    }

    return false;
}

int main(int argc, char** argv) {
    node* head = new node();
    head->data = std::atoi(argv[1]);
    head->next = NULL;
    node* current = head;
    for(int i = 2; i < argc; i++) {
        node* new_node = new node();
        new_node->data = std::atoi(argv[i]);
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }

    std::cout << checkLoop(head) << std::endl;

    return 0;
}