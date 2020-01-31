#include <string>
#include <iostream>
#include <map>

bool isPalindromePermutation(std::string input) {
    char space = ' ';

    std::map<char, int> occurance_map;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] != space) {
            if(occurance_map.find(std::tolower(input[i])) != occurance_map.end())
                occurance_map[std::tolower(input[i])]++;
            else
                occurance_map[std::tolower(input[i])] = 1;
        }
    }

    int num_odd_char = 0;
    for(std::map<char, int>::iterator i = occurance_map.begin(); i != occurance_map.end(); i++) {
        if((i->second % 2) != 0)
            num_odd_char++;
    }

    if(num_odd_char <= 1)
        return true;
    else
        return false;
}

int main(int argc, char** argv) {
    std::string input_string(argv[1]);

    std::cout << isPalindromePermutation(input_string) << std::endl;

    return 0;
}