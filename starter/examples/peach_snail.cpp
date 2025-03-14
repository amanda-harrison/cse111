// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#include <fstream>
#include <iostream>

#include "FunctionTimer.h"
#include "TestFunctions.h"

constexpr auto fibonacci = fibonacci_pure;
constexpr auto matrix_multiply = matrix_multiply_fast;

// constexpr auto fibonacci = fibonacci_memo;
// constexpr auto matrix_multiply = matrix_multiply_fast;

// constexpr auto fibonacci = fibonacci_pure;
// constexpr auto matrix_multiply = matrix_multiply_slow;

// constexpr auto fibonacci = fibonacci_memo;
// constexpr auto matrix_multiply = matrix_multiply_slow;

int main() {
  for (int i = 0; i < 8; i++) {
    peach_snail(fibonacci, matrix_multiply);
  }
  return 0;
}
