#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

void remove_duplicate(node* head) {
    std::map<int, int> occurance_map;
    node* previous = head;
    occurance_map[head->data] = 1;

    node* current = head->next;
    while(current != NULL) {
        std::map<int, int>::iterator search_index = occurance_map.find(current->data);
        if(search_index != occurance_map.end()){
            previous->next = current->next;
        } else {
            occurance_map[current->data] = 1;
            previous = current;
        }
        current = current->next;
    }
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

    remove_duplicate(head);

    while(head != NULL) {
        std::cout << head->data << std::endl;
        head = head->next;
    }

    return 0;
}