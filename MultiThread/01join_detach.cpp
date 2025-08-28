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

//
// Created by QiQiByte on 2025/8/27.
//
#include <iostream>
#include <thread>
#include <chrono>

std::thread t;


void say_hello(int& x_) {
    std::cout << "Hello from thread!" << std::endl;
    std::cout << "Value of x in thread: " << x_ << std::endl;
    x_ += 10; // Modify the value of x
}

void runThread(){
    int x = 15;
    t = std::thread(say_hello, std::ref(x));
    return;
}
//(1) x 是 runThread 的局部变量，存在栈上。

//(2) 你用 std::ref(x) 把这个局部变量的引用传给线程。

//(3) 函数 runThread 结束时，x 已经被销毁，栈空间可能被复用。

//👉 这时候子线程里拿到的引用，指向了一块已经失效的内存（悬空引用）。


void question01(){
    runThread();  //其中的变量 x 的作用域只在自己函数内，执行该函数后，其对应生命周期也结束了
    t.join();
}

void question02(){
}


int main() {
    std::cout << "------------Subdirectory----------------" << std::endl;
    // question01();

    return 0;
}
