#include "tests.hpp"
#include "SharedPtr.hpp"
#include "ArraySharedPtr.hpp"
#include "UnqPtr.hpp"
#include "ArrayUnqPtr.hpp"
#include <iostream>

int t_UnqPtr() {
    int* g = new int[1];
    *g = 10;
    UnqPtr test_ptr(g);
    int good_counter = 0;
    int result;
    try {
        result = *test_ptr;
        if (result != 10) {throw std::runtime_error("Incorrect * result in t_UnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout<<error.what();}
    try {
        int* result_2 = test_ptr.get();
        if (*result_2 != 10) {throw std::runtime_error("Incorrect get result in t_UnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout<<error.what();}
    try {
        (*test_ptr)++;
        result = *test_ptr;
        if (result != 11) {throw std::runtime_error("Incorrect result after changing data in t_UnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout<<error.what();}
    return good_counter;
}