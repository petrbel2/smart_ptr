#include "tests.hpp"
#include "SharedPtr.hpp"
#include "ArraySharedPtr.hpp"
#include "UnqPtr.hpp"
#include "ArrayUnqPtr.hpp"
#include <iostream>

int main() {
    int i = 10;
    UnqPtr trying(&i);
    std::cout<<*trying;
}