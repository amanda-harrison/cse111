#include <iostream>
#include <vector>
#include <fstream>  // Add this line

#include "FunctionTimer.h"
#include "TestFunctions.h"

constexpr int NUM_ITERATIONS = 10;
constexpr int MATRIX_SIZE = 256;

// Function to compute average time
template <typename Func, typename... Args>
double compute_average(Func&& func, Args&&... args) {
    double total_time = 0;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        auto result = FunctionTimer::timeFunction(func, args...);
        total_time += result.elapsed_nanoseconds();
    }
    return total_time / NUM_ITERATIONS;
}

int main() {
    std::cout << "Measuring performance...\n";

    // Measure fibonacci_pure(32)
    double time_fib_pure = compute_average(fibonacci_pure, 32);
    std::cout << "Avg time for fibonacci_pure(32): " << time_fib_pure << " ns\n";

    // Measure fibonacci_memo(32) (sequential calls)
    double time_fib_memo = compute_average(fibonacci_memo, 32);
    std::cout << "Avg time for fibonacci_memo(32): " << time_fib_memo << " ns\n";

    // Initialize two 256x256 matrices with random values
    matrix_t matA(MATRIX_SIZE, std::vector<double>(MATRIX_SIZE, 1.0));
    matrix_t matB(MATRIX_SIZE, std::vector<double>(MATRIX_SIZE, 1.0));

    // Measure matrix_multiply_slow(256x256)
    double time_mat_slow = compute_average(matrix_multiply_slow, matA, matB);
    std::cout << "Avg time for matrix_multiply_slow(256x256): " << time_mat_slow << " ns\n";

    // Measure matrix_multiply_fast(256x256)
    double time_mat_fast = compute_average(matrix_multiply_fast, matA, matB);
    std::cout << "Avg time for matrix_multiply_fast(256x256): " << time_mat_fast << " ns\n";

    return 0;
}
