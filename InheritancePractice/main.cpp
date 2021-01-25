//#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

#include "Base.h"
#include "InheritanceA.h"
#include "InheritanceB.h"


int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    {
        std::mutex mutex;
        std::condition_variable   conditionVariable;
        bool flag = false;

        Base base;
        InheritanceA inheritanceA;
        InheritanceB inheritanceB;

//        std::thread tA(&InheritanceA::SendSignal, InheritanceA(), flag, std::ref(mutex),
//                       std::ref(conditionVariable));
//        std::thread tB(&InheritanceB::ReceiveSignal, InheritanceB(), flag, std::ref(mutex),
//                       std::ref(conditionVariable));

        std::thread tA = std::thread(&InheritanceA::SendSignal,
                                     &inheritanceA,
                                     std::ref(flag),
                                     std::ref(mutex),
                                     std::ref(conditionVariable));

        std::thread tB = std::thread(&InheritanceB::ReceiveSignal,
                                     &inheritanceB,
                                     std::ref(flag),
                                     std::ref(mutex),
                                     std::ref(conditionVariable));

//        inheritanceA.m_dataVec[0] = 1;
//        inheritanceA.m_dataVec[1] = 2;

//        inheritanceB.SynchronousData(inheritanceA.m_dataVec);

//        for(auto & item: inheritanceB.m_dataVec)
//        {
//            cout << item;
//        }
        tA.join();
        tB.join();
    }

//    class CFoo {
//    public:
//        int m_i = 0;
//        void bar(bool flag) {
//            ++m_i;
//        }
//    };

//    CFoo foo;
//    bool flag = false;
//    std::thread t1(&CFoo::bar, &foo, flag);
//    t1.join();
//    std::thread t2(&CFoo::bar, &foo, flag);
//    t2.join();
//    std::cout << foo.m_i << std::endl;

//    return a.exec();
    return 0;
}
