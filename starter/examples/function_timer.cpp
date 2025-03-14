// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#include <functional>
#include <iostream>

#include "FunctionTimer.h"

int add(int a, int b) { return a + b; }

void printMessage(const std::string& message) {
  std::cout << message << std::endl;
}

void printHello() { std::cout << "Hello World" << std::endl; }

void fillInt(int& x) {
  static int x_counter = 0;
  x = x_counter;
  x_counter++;
}

void funcParam(std::function<void()> foo) { foo(); }

int main() {
  // int return type
  auto timedAdd = FunctionTimer::timeFunction(add, 3, 4);
  std::cout << "Result: " << timedAdd.result
            << ", Elapsed time: " << timedAdd.elapsed_nanoseconds()
            << " nanoseconds\n";

  // void return type
  auto timedPrint = FunctionTimer::timeFunction(printMessage, "Hello, world!");
  std::cout << "Elapsed time for printMessage: "
            << timedPrint.elapsed_nanoseconds() << " nanoseconds\n";

  // no args and void return type
  auto timedHello = FunctionTimer::timeFunction(printHello);
  std::cout << "Elapsed time for printHello: "
            << timedHello.elapsed_nanoseconds() << " nanoseconds\n";

  // reference parameter
  int val;
  auto timedFillInt = FunctionTimer::timeFunction(fillInt, val);
  std::cout << "Result: " << val
            << ", Elapsed time: " << timedFillInt.elapsed_nanoseconds()
            << " nanoseconds\n";

  // function parameter
  auto timedFuncPrint = FunctionTimer::timeFunction(funcParam, printHello);
  std::cout << "Elapsed time for printMessage: "
            << timedFuncPrint.elapsed_nanoseconds() << " nanoseconds\n";

  return 0;
}
