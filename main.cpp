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
    std::cout<<"UnqPtr testing. successful tests "<<big_counter<<" out of 3\n";
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
}

int main() {
    run_tests();
    /*
    int i = 10;
    UnqPtr trying(&i);
    (*trying)++;
    std::cout<<*trying;
    
    int* stupid;
    int l = 1;
    *stupid = l;
    SharedPtr s_1(stupid);
    (*s_1) += 1;
    int r = (*s_1);
    r++;
    std::cout<<r;
    std::cout<<*s_1;
    
    
    int* stupid;
    *stupid = 1;
    (*stupid)++;
    std::cout<<*stupid;
    delete stupid;
    */
    int l = 10;
    ArrayUnqPtr tr(&l);
    (*(tr + 3)) = 3;
    std::cout<<*(tr + 3);
}