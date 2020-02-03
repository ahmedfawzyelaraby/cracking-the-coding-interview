#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

node* sumLinkedList(node* head_1, node* head_2) {
    int sum_1 = 0;
    int multiplier_1 = 1;
    while (head_1 != NULL) {
        sum_1 += multiplier_1 * head_1->data;
        multiplier_1 *= 10;
        head_1 = head_1->next;
    }

    int sum_2 = 0;
    int multiplier_2 = 1;
    while (head_2 != NULL) {
        sum_2 += multiplier_2 * head_2->data;
        multiplier_2 *= 10;
        head_2 = head_2->next;
    }

    int sum = sum_1 + sum_2;

    node* head = new node();
    node* current = head;

    if(sum == 0) {
        current->data = sum;
        current->next = NULL;
        return head;
    }

    int counter = 0;
    while(sum != 0) {
        if(counter == 0) {
            current->data = sum % 10;
            current->next = NULL;
        } else {
            node* tmp = new node();
            tmp->data = sum % 10;
            tmp->next = NULL;
            current->next = tmp;
            current = current->next;
        }
        sum /= 10;
        counter++;
    }

    return head;
}

int main(int argc, char** argv) {
    int separator_index = -1;
    for(int i = 1; i < argc; i++) {
        if(std::string(argv[i]) == "-") {
            separator_index = i;
            break;
        }
    }

    node* head_1 = new node();
    head_1->data = std::atoi(argv[1]);
    head_1->next = NULL;
    node* current_1 = head_1;
    for(int i = 2; i < separator_index; i++) {
        node* new_node = new node();
        new_node->data = std::atoi(argv[i]);
        new_node->next = NULL;
        current_1->next = new_node;
        current_1 = new_node;
    }

    node* head_2 = new node();
    head_2->data = std::atoi(argv[separator_index + 1]);
    head_2->next = NULL;
    node* current_2 = head_2;
    for(int i = separator_index + 2; i < argc; i++) {
        node* new_node = new node();
        new_node->data = std::atoi(argv[i]);
        new_node->next = NULL;
        current_2->next = new_node;
        current_2 = new_node;
    }

    node* new_head = sumLinkedList(head_1, head_2);
    while(new_head != NULL) {
        std::cout << new_head->data << std::endl;
        new_head = new_head->next;
    }

    return 0;
}