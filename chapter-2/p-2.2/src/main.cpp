#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

node* findKthElement(node* head, int element_index) {
    node* current = head;
    int counter = 0;
    while(current != NULL) {
        if(counter == (element_index - 1))
            return current;
        current = current->next;
        counter++;
    }
    return NULL;
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

    node* element = findKthElement(head, std::atoi(argv[1]));
    if(element == NULL)
        std::cout << "NOT FOUND" << std::endl;
    else
        std::cout << element->data << std::endl;

    return 0;
}