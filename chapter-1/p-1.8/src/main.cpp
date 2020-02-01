#include <string>
#include <iostream>
#include <map>

void zeroMatrix() {
    int rows = 3;
    int cols = 4;
    int matrix[rows][cols] = {{1, 2, 3, 4}, {5, 0, 7, 8}, {9, 10, 11, 12}};
    int result[rows][cols];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
            result[i][j] = matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) {
                for(int k = 0; k < rows; k++) {
                    result[k][j] = 0;
                }

                for(int k = 0; k < cols; k++) {
                    result[i][k] = 0;
                }
            }
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {
    zeroMatrix();

    return 0;
}