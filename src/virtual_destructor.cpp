#include <iostream>

class NonVirtualBase
{
public:
    NonVirtualBase() { std::cout << "NonVirtualBase constructor" << std::endl; }
    ~NonVirtualBase() { std::cout << "NonVirtualBase destructor" << std::endl; }
    void show() { std::cout << "NonVirtualBase show" << std::endl; }
};

class VirtualBase
{
public:
    VirtualBase() { std::cout << "VirtualBase constructor" << std::endl; }
    virtual ~VirtualBase() { std::cout << "VirtualBase destructor" << std::endl; }
    virtual void show() { std::cout << "VirtualBase show" << std::endl; }
};

class Derived1 : public NonVirtualBase
{
public:
    Derived1() { std::cout << "Derived1 constructor" << std::endl; }
    ~Derived1() { std::cout << "Derived1 destructor" << std::endl; }
    void show() { std::cout << "Derived1 show" << std::endl; }
};

class Derived2 : public VirtualBase
{
public:
    Derived2() { std::cout << "Derived2 constructor" << std::endl; }
    ~Derived2() { std::cout << "Derived2 destructor" << std::endl; }
    void show() { std::cout << "Derived2 show" << std::endl; }
};

int main(int argc, char const *argv[])
{
    NonVirtualBase *var1{new Derived1{}};
    Derived1 * var2{new Derived1{}};
    var1->show();
    var2->show();
    delete var1;
    delete var2;

    std::cout << std::endl;

    VirtualBase *var3{new Derived2{}};
    Derived2 * var4{new Derived2{}};
    var3->show();
    var4->show();
    delete var3;
    delete var4;

    std::cout << std::endl;

    return 0;
}
