#include <iostream>

int main() {
    if (__cplusplus == 202302L) { // Placeholder for C++23 value, check official documentation
        std::cout << "C++23 is supported." << std::endl;
    } else if (__cplusplus == 202002L) {
        std::cout << "C++20 is supported." << std::endl;
    } else if (__cplusplus == 201703L) {
        std::cout << "C++17 is supported." << std::endl;
    } else if (__cplusplus == 201402L) {
        std::cout << "C++14 is supported." << std::endl;
    } else if (__cplusplus == 201103L) {
        std::cout << "C++11 is supported." << std::endl;
    } else {
        std::cout << "Unknown C++ standard or older version: " << __cplusplus << std::endl;
    }
    return 0;
}