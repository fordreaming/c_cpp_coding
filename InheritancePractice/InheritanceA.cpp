#include "InheritanceA.h"
#include "InheritanceB.h"
#include <iostream>

using namespace std;

InheritanceA::InheritanceA()
{
    m_pInheritanceB = new InheritanceB();
}

void InheritanceA::SendSignal(bool &flag, std::mutex &m_mutex, std::condition_variable &m_condVariable)
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        flag = true;
        std::vector<float> dataVec;
        dataVec.emplace_back(0);
        dataVec.emplace_back(1);
        m_pInheritanceB->SynchronousData(dataVec);
        std::cout << "A send signal" << endl;
    }

    for(int i = 0; i < 1000000; i++) {
        std::cout << "A sleep" << i << "s" << endl;
        sleep(2);
    }
}

