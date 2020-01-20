#include <string>
#include <iostream>

bool isUniqueDoubleLoop(std::string input) {
    for(int i = 0; i < (input.length() - 1); i++) {
        for(int j = i + 1; j < input.length(); j++) {
            if(input[i] == input[j])
                return false;
        }
    }

    return true;
}

bool isUniqueHashTable(std::string input) {
    
}

int main(int argc, char** argv) {
    std::string string_to_check(argv[1]);

    std::cout << isUniqueDoubleLoop(string_to_check) << std::endl;
}