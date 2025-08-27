//
// Created by 20506 on 2025/8/27.
//
#include <iostream>
#include <thread>
#include <chrono>

void say_hello(int& x) {
    std::cout << "Hello from thread!" << std::endl;
    std::cout << "Value of x in thread: " << x << std::endl;
    x += 10; // Modify the value of x
}


int main() {
    std::cout << "Hello, World! From Subdirectory" << std::endl;

    int mainx = 5;
    std::thread t1(say_hello, std::ref(mainx)); // Pass by reference using std::ref
    t1.join(); // Wait for t1 to finish
    std::cout << "Value of mainx after thread: " << mainx << std::endl;

    return 0;
}
