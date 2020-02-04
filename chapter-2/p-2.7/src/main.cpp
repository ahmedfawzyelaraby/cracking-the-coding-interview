#include <string>
#include <iostream>
#include <map>

struct node {
    int data;
    struct node* next;
};

node* checkIntersection(node* head_1, node* head_2) {
    std::map<node*, int> occurance_map;
    node* current_1 = head_1;
    while(current_1 != NULL) {
        occurance_map[current_1] = 1;
        current_1 = current_1->next;
    }

    node* current_2 = head_2;
    while(current_2 != NULL) {
        std::map<node*, int>::iterator index = occurance_map.find(current_2);
        if(index != occurance_map.end())
            return current_2;
        current_2 = current_2->next;
    }

    return NULL;
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

    node* intersection = checkIntersection(head_1, head_2);
    if(intersection == NULL)
        std::cout << "No Intersection" << std::endl;
    else
        std::cout << "Intersection Found" << std::endl;

    return 0;
}