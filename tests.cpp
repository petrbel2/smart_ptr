#include "tests.hpp"
#include "SharedPtr.hpp"
#include "ArraySharedPtr.hpp"
#include "UnqPtr.hpp"
#include "ArrayUnqPtr.hpp"
#include <iostream>
#include <chrono>

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
    try {
        int* released = test_ptr.release();
        if (released == nullptr || *released != 11) {throw std::runtime_error("Incorrect release result in t_UnqPtr!\n");}
        good_counter++;
        delete released;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    return good_counter;
}

int t_SharedPtr() {
    int* g = new int[1];
    *g = 10;
    SharedPtr<int> test_ptr1(g);
    SharedPtr<int> test_ptr2(test_ptr1);
    int good_counter = 0;
    int result;
    
    try {
        result = *test_ptr1;
        if (result != 10) {throw std::runtime_error("Incorrect * result in t_SharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        result = *test_ptr2;
        if (result != 10) {throw std::runtime_error("Incorrect * result in copied t_SharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        int* result_2 = test_ptr1.get();
        if (*result_2 != 10) {throw std::runtime_error("Incorrect get result in t_SharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        (*test_ptr1)++;
        result = *test_ptr2;
        if (result != 11) {throw std::runtime_error("Incorrect result after changing data in t_SharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    return good_counter;
}

int t_ArrayUnqPtr() {
    int* g = new int[3]{10, 20, 30};
    ArrayUnqPtr<int> test_ptr(g);
    int good_counter = 0;
    int result;
    
    try {
        result = *test_ptr;
        if (result != 10) {throw std::runtime_error("Incorrect * result in t_ArrayUnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        int* result_2 = test_ptr.get();
        if (result_2[1] != 20) {throw std::runtime_error("Incorrect get result in t_ArrayUnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        int* result_3 = test_ptr + 1; 
        if (*result_3 != 20) {throw std::runtime_error("Incorrect + result in t_ArrayUnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        (*test_ptr)++;
        result = *test_ptr;
        if (result != 11) {throw std::runtime_error("Incorrect result after changing data in t_ArrayUnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}

    try {
        test_ptr.release();
        if (test_ptr.get() != nullptr) {throw std::runtime_error("Incorrect get result after release in t_ArrayUnqPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    return good_counter;
}

int t_ArraySharedPtr() {
    int* g = new int[3]{10, 20, 30};
    ArraySharedPtr<int> test_ptr1(g);
    ArraySharedPtr<int> test_ptr2(test_ptr1);
    int good_counter = 0;
    int result;
    
    try {
        result = *test_ptr1;
        if (result != 10) {throw std::runtime_error("Incorrect * result in t_ArraySharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        result = *test_ptr2;
        if (result != 10) {throw std::runtime_error("Incorrect * result in copied t_ArraySharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        int* result_2 = test_ptr1.get();
        if (result_2[1] != 20) {throw std::runtime_error("Incorrect get result in t_ArraySharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        int* result_3 = test_ptr1 + 1;
        if (*result_3 != 20) {throw std::runtime_error("Incorrect + result in t_ArraySharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    try {
        (*test_ptr1)++;
        result = *test_ptr2;
        if (result != 11) {throw std::runtime_error("Incorrect result after changing data in t_ArraySharedPtr!\n");}
        good_counter++;
    }
    catch(const std::runtime_error& error) {std::cout << error.what();}
    
    return good_counter;
}