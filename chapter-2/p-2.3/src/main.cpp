#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

void deleteMiddleElement(node* head, int element_index) {
    node* previous = head;
    node* current = head->next;
    int counter = 1;
    while(current != NULL) {
        if(counter == (element_index - 1)) {
            previous->next = current->next;
            break;
        }
        previous = current;
        current = current->next;
        counter++;
    }
}

int main(int argc, char** argv) {
    node* head = new node();
    head->data = std::atoi(argv[2]);
    head->next = NULL;

    node* current = head;
    for(int i = 3; i < argc; i++) {
        node* new_node = new node();
        new_node->data = std::atoi(argv[i]);
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }

    deleteMiddleElement(head, std::atoi(argv[1]));
    while(head != NULL) {
        std::cout << head->data << std::endl;
        head = head->next;
    }

    return 0;
}