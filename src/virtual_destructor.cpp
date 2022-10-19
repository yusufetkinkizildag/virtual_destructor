#include <iostream>

class NonVirtualBase
{
public:
    NonVirtualBase() { std::cout << "NonVirtualBase constructor" << std::endl; }
    ~NonVirtualBase() { std::cout << "NonVirtualBase destructor" << std::endl; }
};

class VirtualBase
{
public:
    VirtualBase() { std::cout << "VirtualBase constructor" << std::endl; }
    virtual ~VirtualBase() { std::cout << "VirtualBase destructor" << std::endl; }
};

class Derived1 : public NonVirtualBase
{
public:
    Derived1() { std::cout << "Derived1 constructor" << std::endl; }
    ~Derived1() { std::cout << "Derived1 destructor" << std::endl; }
};

class Derived2 : public VirtualBase
{
public:
    Derived2() { std::cout << "Derived2 constructor" << std::endl; }
    ~Derived2() { std::cout << "Derived2 destructor" << std::endl; }
};

int main(int argc, char const *argv[])
{
    std::cout << std::endl;
    NonVirtualBase *var1{new Derived1{}};
    delete var1;
    std::cout << std::endl;

    VirtualBase *var2{new Derived2{}};
    delete var2;
    std::cout << std::endl;

    return 0;
}
