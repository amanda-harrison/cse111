// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#include <functional>
#include <unordered_map>
#include <vector>

int64_t fibonacci_pure(int64_t n) {
  if (n <= 1) return n;
  return fibonacci_pure(n - 1) + fibonacci_pure(n - 2);
}

int64_t fibonacci_memo(int64_t n) {
  static std::unordered_map<int64_t, int64_t> memo;
  if (n <= 1) return n;
  if (memo.find(n) != memo.end()) return memo.at(n);
  memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
  return memo.at(n);
}

typedef std::vector<std::vector<double>> matrix_t;

matrix_t matrix_multiply_slow(const matrix_t& matrix1,
                              const matrix_t& matrix2) {
  int m1Rows = matrix1.size();
  int m1Cols = matrix1[0].size();
  int m2Cols = matrix2[0].size();

  matrix_t result(m1Rows);
  for (auto& row : result) row.resize(m2Cols);
  for (auto& row : result)
    for (auto& cell : row) cell = 0;

  for (int i = 0; i < m1Rows; i++) {
    for (int k = 0; k < m1Cols; k++) {
      for (int j = 0; j < m2Cols; j++) {
        if (matrix1[i][k] == 0) continue;
        if (matrix2[k][j] == 0) continue;
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

matrix_t matrix_multiply_fast(const matrix_t& matrix1,
                              const matrix_t& matrix2) {
  int m1Rows = matrix1.size();
  int m1Cols = matrix1[0].size();
  int m2Cols = matrix2[0].size();

  matrix_t result(m1Rows);
  for (auto& row : result) row.resize(m2Cols);

  for (int j = 0; j < m2Cols; j++) {
    for (int k = 0; k < m1Cols; k++) {
      for (int i = 0; i < m1Rows; i++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

void writeMatrixToFile(const matrix_t& matrix, const std::string& filename) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Unable to open file: " << filename << std::endl;
    return;
  }
  for (const auto& row : matrix) {
    for (const auto& elem : row) {
      file << elem << " ";
    }
    file << std::endl;
  }
  file.close();
  std::cout << "Matrix written to file: " << filename << std::endl;
}

// ============================================================ //

void peach_snail(
    std::function<int64_t(int64_t)> fibonacci,
    std::function<matrix_t(const matrix_t&, const matrix_t&)> matrix_multiply) {
  const int MAX_FIB = 32;

  std::vector<double> fibResults;
  for (int i = 0; i < MAX_FIB; i++) {
    fibResults.push_back(fibonacci(i));
  }

  matrix_t matrix(256);
  for (auto& row : matrix) row.resize(256);

  int fibIndex = 0;
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      int sign = (rand() & 1) ? -1 : 1;
      matrix[i][j] = sign * fibResults[fibIndex % MAX_FIB];
      fibIndex++;
    }
  }

  matrix_t resultMatrix = matrix;
  resultMatrix = matrix_multiply(resultMatrix, matrix);
  resultMatrix = matrix_multiply(resultMatrix, matrix);
  resultMatrix = matrix_multiply(resultMatrix, matrix);
  resultMatrix = matrix_multiply(resultMatrix, matrix);

  writeMatrixToFile(resultMatrix, "resultMatrix.txt");
}
