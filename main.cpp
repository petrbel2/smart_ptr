/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
*/
#include "tests.hpp"
#include "SharedPtr.hpp"
#include "UnqPtr.hpp"
#include "benchmarks.hpp"
#include <iostream> 

void run_tests() {
    int total_counter = 0; 
    int big_counter; 
    big_counter = t_UnqPtr();
    total_counter += big_counter;
    std::cout<<"UnqPtr testing. successful tests "<<big_counter<<" out of 9\n";
    big_counter = t_SharedPtr();
    total_counter += big_counter;
    std::cout<<"SharedPtr testing. successful tests "<<big_counter<<" out of 7\n";
    big_counter = t_ArrayUnqPtr();
    total_counter += big_counter;
    std::cout<<"Array UnqPtr testing. successful tests "<<big_counter<<" out of 5\n";
    big_counter = t_ArraySharedPtr();
    total_counter += big_counter;
    std::cout<<"Array SharedPtr testing. successful tests "<<big_counter<<" out of 5\n";
    std::cout<<"Total successful tests: "<<total_counter<<" out of 26\n";
    std::cout<<"Failed tests: "<<26 - total_counter<<"\n";
    t_comparison(10);
    t_comparison(100000);
}

class X_1 {
    private:
    int data;
};

class X_2: public X_1 {
    private:
    int g;
public:
    X_2(int a = 5): g(a) {}
};


int main() {
    /*
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    */
    run_tests();
    int* i = new int[2];
    i[1] = 5;
    SharedPtr<int[]> testing(i);
    std::cout<<testing[1];
    return 0;
}