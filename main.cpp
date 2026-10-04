#include "tests.hpp"
#include "SharedPtr.hpp"
#include "ArraySharedPtr.hpp"
#include "UnqPtr.hpp"
#include "ArrayUnqPtr.hpp"
#include <iostream> 

int main() {
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
    (*tr)++;
    std::cout<<*(tr);
}