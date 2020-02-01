#include <string>
#include <iostream>
#include <map>

void rotateMatrix() {
    int rows = 3;
    int cols = 4;
    int matrix[rows][cols] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    int result[cols][rows];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[cols - 1 - j][i] = matrix[i][j];
        }
    }

    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {
    rotateMatrix();

    return 0;
}