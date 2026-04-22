#include "MyVector.h"
#include <vector>
#include <iostream>
#include <chrono>

int main() {
    const int N = 10000000;
    
    auto start = std::chrono::high_resolution_clock::now();
    MyVector<int> myvec;
    for (int i = 0; i < N; ++i) myvec.push_back(i);
    auto end = std::chrono::high_resolution_clock::now();
    auto my_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    start = std::chrono::high_resolution_clock::now();
    std::vector<int> stdvec;
    for (int i = 0; i < N; ++i) stdvec.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    auto std_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "push_back " << N << " elements:\n";
    std::cout << "  MyVector:   " << my_time << " ms\n";
    std::cout << "  std::vector: " << std_time << " ms\n\n";
    
    start = std::chrono::high_resolution_clock::now();
    long long sum1 = 0;
    for (int i = 0; i < N; ++i) sum1 += myvec[i];
    end = std::chrono::high_resolution_clock::now();
    my_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    start = std::chrono::high_resolution_clock::now();
    long long sum2 = 0;
    for (int i = 0; i < N; ++i) sum2 += stdvec[i];
    end = std::chrono::high_resolution_clock::now();
    std_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    std::cout << "access " << N << " elements:\n";
    std::cout << "  MyVector:   " << my_time << " ms\n";
    std::cout << "  std::vector: " << std_time << " ms\n";
    std::cout << "  sums match: " << (sum1 == sum2 ? "YES" : "NO") << "\n";
    
    return 0;
}
