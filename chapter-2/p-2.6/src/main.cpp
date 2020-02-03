#include <string>
#include <iostream>
#include <vector>

struct node {
    int data;
    struct node* next;
};

bool checkPalindrome(node* head) {
    std::vector<int> occurance_map;
    while(head != NULL) {
        occurance_map.push_back(head->data);
        head = head->next;
    }

    int forward = 0;
    int backword = occurance_map.size() - 1;
    while(forward < backword) {
        if(occurance_map[forward] != occurance_map[backword])
            return false;
        
        forward++;
        backword--;
    }

    return true;
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

    std::cout << checkPalindrome(head) << std::endl;

    return 0;
}