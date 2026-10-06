#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "tests.hpp"
#include "SharedPtr.hpp"
#include "ArraySharedPtr.hpp"
#include "UnqPtr.hpp"
#include "ArrayUnqPtr.hpp"
#include <iostream> 

void run_tests() {
    int total_counter = 0; 
    int big_counter; 
    big_counter = t_UnqPtr();
    total_counter += big_counter;
    std::cout<<"UnqPtr testing. successful tests "<<big_counter<<" out of 4\n";
    big_counter = t_SharedPtr();
    total_counter += big_counter;
    std::cout<<"SharedPtr testing. successful tests "<<big_counter<<" out of 4\n";
    big_counter = t_ArrayUnqPtr();
    total_counter += big_counter;
    std::cout<<"ArrayUnqPtr testing. successful tests "<<big_counter<<" out of 5\n";
    big_counter = t_ArraySharedPtr();
    total_counter += big_counter;
    std::cout<<"ArraySharedPtr testing. successful tests "<<big_counter<<" out of 5\n";
    std::cout<<"Total successful tests: "<<total_counter<<" out of 18\n";
    std::cout<<"Failed tests: "<<18 - total_counter<<"\n";
    t_comparison();
}

int main() {
    run_tests();
    int* i = new int[2];
    i[1] = 5;
    ArraySharedPtr testing(i);
    std::cout<<testing[1];
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
}