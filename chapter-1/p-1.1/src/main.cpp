#include <string>
#include <iostream>
#include <map>

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
    std::map<char, int> occurance_map;
    for(int i = 0; i < input.length(); i++) {
        if(occurance_map.find(input[i]) != occurance_map.end())
            occurance_map[input[i]]++;
        else
            occurance_map[input[i]] = 1;
    }

    for(std::map<char, int>::iterator i = occurance_map.begin(); i != occurance_map.end(); i++) {
        if(i->second > 1)
            return false;
    }

    return true;
}

int main(int argc, char** argv) {
    std::string string_to_check(argv[1]);

    std::cout << isUniqueDoubleLoop(string_to_check) << std::endl;

    std::cout << isUniqueHashTable(string_to_check) << std::endl;

    return 0;
}