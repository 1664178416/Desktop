#include <iostream>

class Base1 {
public:
    virtual void func1() {
        std::cout << "Base1::func1()" << std::endl;
    }
    virtual void func4() {
        std::cout << "Base1::func4()" << std::endl;
    
    }
};

class Base2 {
public:
    virtual void func2() {
        std::cout << "Base2::func2()" << std::endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    virtual void func1() {
        std::cout << "Derived::func1()" << std::endl;
    }

    virtual void func2() {
        std::cout << "Derived::func2()" << std::endl;
    }
    virtual void func4() {
        std::cout << "Derived::func4()" << std::endl;
    }
};

int main() {
    Derived d;
    Base1* b1 = &d;
    Base2* b2 = &d;

    b1->func1(); // 调用 Derived::func1()
    b2->func2(); // 调用 Derived::func2()
    b1->func4(); // 调用 Derived::func4()

    return 0;
}