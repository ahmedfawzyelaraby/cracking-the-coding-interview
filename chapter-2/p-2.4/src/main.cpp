#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

node* partitionLinkedList(node* head, int partition_element) {
    node* before_head = NULL;
    node* after_head = NULL;

    node* before_current = NULL;
    node* after_current = NULL;

    int before_counter = 0;
    int after_counter = 0;

    node* current = head;
    while(current != NULL) {
        node* tmp;
        tmp = new node();
        tmp->data = current->data;
        tmp->next = NULL;
        if(current->data < partition_element) {
            if(before_counter == 0) {
                before_head = tmp;
                before_current = tmp;
            } else {
                before_current->next = tmp;
                before_current = before_current->next;
            }
            before_counter++;
        } else {
            if(after_counter == 0) {
                after_head = tmp;
                after_current = tmp;
            } else {
                after_current->next = tmp;
                after_current = after_current->next;
            }
            after_counter++;
        }
        current = current->next;
    }

    if(before_head != NULL) {
        before_current->next = after_head;
        return before_head;
    } else {
        return after_head;
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

    node* new_head = partitionLinkedList(head, std::atoi(argv[1]));
    while(new_head != NULL) {
        std::cout << new_head->data << std::endl;
        new_head = new_head->next;
    }

    return 0;
}