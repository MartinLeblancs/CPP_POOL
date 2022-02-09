#include "Array.hpp"
#include "Stack.hpp"
#include <iostream>

int main ( void )
{
    const Array<int, 3> array;
    try {
        array[0] = 21;
        array[1] = 42;
        array[2] = 84;
        array[3] = 84;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << array << std::endl;
    array
            .convert<float>([](const int &v) {
                return static_cast < float >( v ) / 10.f;
            })
            .forEach([](const float &v) { std::cout << v << std::endl; });
    return 0;
}

//int main ( void )
//{
//    Command command;
//    Stack stack;
//    try {
//        command.registerCommand("push", [& stack]() { stack.push(4.2); });
//        command.registerCommand("display", [& stack]() {
//            std::cout << stack.top() <<
//                      std::endl;
//        });
//        command.registerCommand("add", [& stack]() { stack.add(); });
//        command.registerCommand("sub", [& stack]() { stack.sub(); });
//        command.registerCommand("mul", [& stack]() { stack.mul(); });
//        command.registerCommand("div", [& stack]() { stack.div(); });
//        command.registerCommand("display", []() {});
//    }
//    catch (const std::exception &e) {
//        std::cout << e.what() << std::endl;
//    }
//    try {
//        command.executeCommand("push");
//        command.executeCommand("push");
//        command.executeCommand("push");
//        command.executeCommand("add");
//        command.executeCommand("div");
//        command.executeCommand("display");
//        command.executeCommand("nau");
//    }
//    catch (const std::exception &e) {
//        std::cout << e.what() << std::endl;
//    }
//    return 0;
//}