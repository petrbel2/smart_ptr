#include "tests.hpp"
#include "SharedPtr.hpp"
#include "ArraySharedPtr.hpp"
#include "UnqPtr.hpp"
#include "ArrayUnqPtr.hpp"
#include <iostream>
#include <chrono>
#include <memory>

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

int t_comparison() {
    int iter = 100000;
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
        int* l = new int;
        *l = 1;
        delete l;
    }
    auto end_3 = std::chrono::high_resolution_clock::now();
    auto d_3 = end_3 - start_3;
    std::cout<<"Time for custom smart ptr: "<<d_1.count()<<'\n';
    std::cout<<"Time for standard smart ptr: "<<d_2.count()<<'\n';
    std::cout<<"Time for basic ptr: "<<d_3.count()<<'\n';
    return 0;
}