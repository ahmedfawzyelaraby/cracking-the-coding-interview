#include <string>
#include <iostream>
#include <map>

bool isOneStepAway(std::string first_input, std::string second_input) {
    if(first_input == second_input)
        return true;
    
    bool is_shifted = false;
    int not_found = 0;
    int current_right_char_in_second_string = -1;
    for(int i = 0; i < first_input.length(); i++) {
        std::size_t index = second_input.find(first_input[i], current_right_char_in_second_string + 1);

        if(index == std::string::npos) {
            not_found++;
        } else {
            if(int(index) != i)
                is_shifted = true;
            current_right_char_in_second_string = index;
        }
    }

    if(not_found > 1)
        return false;
    else if(not_found == 1) {
        if(is_shifted) {
            if((first_input.length() - second_input.length()) == 1)
                return true;
            else
                return false;
        } else {
            if((first_input.length() == second_input.length()) || ((first_input.length() - second_input.length()) == 1))
                return true;
            else
                return false;
        }
    } else {
        if((first_input.length() == second_input.length()) || ((first_input.length() - second_input.length()) == -1))
            return true;
        else
            return false;
    }
}

int main(int argc, char** argv) {
    std::string first_input_string(argv[1]);
    std::string second_input_string(argv[2]);

    std::cout << isOneStepAway(first_input_string, second_input_string) << std::endl;

    return 0;
}