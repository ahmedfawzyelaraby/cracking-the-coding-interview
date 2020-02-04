#include <string>
#include <iostream>
#include <map>

bool stringRotation(std::string s1, std::string s2) {
    if(s1.length() != s2.length())
        return false;
    
    if(s1.length() == 0)
        return false;

    std::string s1s1 = s1 + s1;

    if(s1s1.find(s2) == std::string::npos)
        return false;
    else
        return true;
}

int main(int argc, char** argv) {
    std::string first_input_string(argv[1]);
    std::string second_input_string(argv[2]);

    std::cout << stringRotation(first_input_string, second_input_string) << std::endl;

    return 0;
}