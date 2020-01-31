#include <string>
#include <iostream>
#include <map>

bool isStringsFormPermutation(std::string first_input, std::string second_input) {
    if(first_input.length() != second_input.length())
        return false;

    std::map<char, int> first_occurance_map;
    for(int i = 0; i < first_input.length(); i++) {
        if(first_occurance_map.find(first_input[i]) != first_occurance_map.end())
            first_occurance_map[first_input[i]]++;
        else
            first_occurance_map[first_input[i]] = 1;
    }

    std::map<char, int> second_occurance_map;
    for(int i = 0; i < second_input.length(); i++) {
        if(second_occurance_map.find(second_input[i]) != second_occurance_map.end())
            second_occurance_map[second_input[i]]++;
        else
            second_occurance_map[second_input[i]] = 1;
    }

    for(std::map<char, int>::iterator i = first_occurance_map.begin(); i != first_occurance_map.end(); i++) {
        if(i->second != second_occurance_map[i->first])
            return false;
    }

    return true;
}

int main(int argc, char** argv) {
    std::string first_string_to_check(argv[1]);
    std::string second_string_to_check(argv[2]);

    std::cout << isStringsFormPermutation(first_string_to_check, second_string_to_check) << std::endl;

    return 0;
}