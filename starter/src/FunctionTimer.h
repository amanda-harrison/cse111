// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include <chrono>

// Struct to hold the function result and the elapsed time
template <typename ResultType>
struct TimedResult {
  ResultType result;
  std::chrono::duration<double> elapsed_time;

  auto elapsed_nanoseconds() const {
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    return duration_cast<nanoseconds>(elapsed_time).count();
  }
};

// Void return type
template <>
struct TimedResult<void> {
  std::chrono::duration<double> elapsed_time;

  auto elapsed_nanoseconds() const {
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    return duration_cast<nanoseconds>(elapsed_time).count();
  }
};

class FunctionTimer {
 private:
  template <typename Func, typename... Args>
  static auto timeNonvoidFunction(Func&& func, Args&&... args) {
    using ResultType = decltype(func(args...));

    auto start = std::chrono::high_resolution_clock::now();
    ResultType result = func(args...);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - start;

    return TimedResult<ResultType>{result, elapsed};
  }

  template <typename Func, typename... Args>
  static auto timeVoidFunction(Func&& func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(args...);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - start;

    return TimedResult<void>{elapsed};
  }

 public:
  template <typename Func, typename... Args>
  static auto timeFunction(Func&& func, Args&&... args) {
    using ResultType = decltype(func(args...));

    if constexpr (std::is_void_v<ResultType>) {
      return timeVoidFunction(func, args...);
    } else {
      return timeNonvoidFunction(func, args...);
    }
  }
};
