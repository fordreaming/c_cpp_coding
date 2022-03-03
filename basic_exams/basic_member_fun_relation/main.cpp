#include <QCoreApplication>
#include <iostream>
using namespace std;

class OverrideA {
public:
    virtual void fun1(int, int) {
        std::cout << "override A" << std::endl;
    }
};

class OverrideB : public OverrideA {
public:
    void fun1(int, int) {
        std::cout << "overrideB" << std::endl;
    }
};


class OverseeA1 {
public:
    void fun(int xp) {
        std::cout << "oversee a1" << std::endl;
    }

    virtual void fun2(int xp) {
        std::cout << "fun2: oversee a1" << std::endl;
    }
};

class OverseeB1 : public OverseeA1 {
public:
    void fun(int xp) {
        std::cout << "oversee b1" << std::endl;
    }

    void fun2(char* xp) {
        std::cout << "fun2: oversee b1" << std::endl;
    }
};




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 覆盖
//    OverrideA* override_a = new OverrideB();
//    override_a->fun1(2, 3);

    // 隐藏
//    OverseeB1 oversee_b1;
//    oversee_b1.fun(2);
//    oversee_b1.OverseeA1::fun(3);
//    OverseeA1* oversee_a1 = new OverseeB1();
//    oversee_a1->fun(2);

    // 2)
    OverseeB1 oversee_b1;
//    char ch[3];
//    oversee_b1.fun2(ch);
    OverseeA1* oversee_a1 = new OverseeB1();
    int data{2};
    oversee_a1->fun2(data);

    return a.exec();
}
