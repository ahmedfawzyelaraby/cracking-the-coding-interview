#include <string>
#include <iostream>
#include <map>

std::string compressString(std::string input) {
    std::string result = "";

    if(input.length() < 2)
        return input;

    result += input[0];
    int counter = 1;
    for(int i = 1; i < input.length(); i++) {
        if(input[i] == input[i-1])
            counter++;
        else {
            result += std::to_string(counter) + input[i];
            counter = 1;
        }
    }
    result += std::to_string(counter);

    if(result.length() > input.length())
        return input;
    else
        return result;
}

int main(int argc, char** argv) {
    std::string input_string(argv[1]);

    std::cout << compressString(input_string) << std::endl;

    return 0;
}