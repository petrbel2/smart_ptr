#include "tests.hpp"
#include "SharedPtr.hpp"
#include "UnqPtr.hpp"
#include <iostream>
#include <chrono>
#include <memory>

void t_comparison(int iter) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; i++) {
        int* j = new int;
        UnqPtr testing(j);
        (*testing) = 1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto d_1 = end - start;
    auto start_2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; i++) {
        std::unique_ptr<int> testing {std::make_unique<int>(1)};
        *testing = 2;
    }
    auto end_2 = std::chrono::high_resolution_clock::now();
    auto d_2 = end_2 - start_2;
    auto start_3 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; i++) {
        int* j = new int;
        SharedPtr testing(j);
        (*testing) = 1;
    }
    auto end_3 = std::chrono::high_resolution_clock::now();
    auto d_3 = end_3 - start_3;
    auto start_4 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; i++) {
        std::shared_ptr<int> testing {std::make_shared<int>(1)};
        *testing = 2;
    }
    auto end_4 = std::chrono::high_resolution_clock::now();
    auto d_4 = end_4 - start_4;
    auto start_5 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iter; i++) {
        int* l = new int;
        *l = 1;
        delete l;
    }
    auto end_5 = std::chrono::high_resolution_clock::now();
    auto d_5 = end_5 - start_5;
    std::cout<<"Benchmark: time used per "<<iter<<" iterations\n";
    std::cout<<"Time for custom unique ptr: "<<d_1.count()<<" mc"<<'\n';
    std::cout<<"Time for standard unique ptr: "<<d_2.count()<<" mc"<<'\n';
    std::cout<<"Time for custom shared ptr: "<<d_3.count()<<" mc"<<'\n';
    std::cout<<"Time for standard shared ptr: "<<d_4.count()<<" mc"<<'\n';
    std::cout<<"Time for basic ptr: "<<d_5.count()<<" mc"<<'\n';
}