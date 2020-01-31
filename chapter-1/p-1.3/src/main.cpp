#include <string>
#include <iostream>
#include <map>

char* replaceSpaces(char* input, int input_length) {
    char space = ' ';
    char space_replacement_1 = '%';
    char space_replacement_2 = '2';
    char space_replacement_3 = '0';

    int spaces_count = 0;
    for(int i = 0; i < input_length; i++) {
        if(input[i] == space) {
            spaces_count++;
        }
    }

    int current_char = (input_length + (2 * spaces_count) - 1);
    int string_iterator = input_length - 1;
    while(current_char >= 0) {
        if(input[string_iterator] == space) {
            input[current_char] = space_replacement_3;
            current_char--;
            input[current_char] = space_replacement_2;
            current_char--;
            input[current_char] = space_replacement_1;
            current_char--;
        } else {
            input[current_char] = input[string_iterator];
            current_char--;
        }
        string_iterator--;
    }
    
    return input;
}

int main(int argc, char** argv) {
    std::string input_string(argv[1]);
    int char_count = std::stoi(std::string(argv[2]));

    std::cout << input_string << std::endl << replaceSpaces((char*) input_string.c_str(), char_count) << std::endl;

    return 0;
}