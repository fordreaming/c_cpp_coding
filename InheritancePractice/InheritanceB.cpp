#include "InheritanceB.h"
#include <iostream>
#include <unistd.h>
using namespace std;

InheritanceB::InheritanceB()
{
}

void InheritanceB::SynchronousData(const std::vector<float> &dataVec)
{
//    std::copy(m_dataVec.begin(), m_dataVec.end(), dataVec.begin());
//    m_dataVec = dataVec;
    m_dataVec.emplace_back(dataVec[0]);
    m_dataVec.emplace_back(dataVec[1]);
}

void InheritanceB::ReceiveSignal(bool &flag, std::mutex &m_mutex, std::condition_variable &m_condVariable)
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_condVariable.wait(lock, [=] { return flag == true;});
        std::cout << "B receive signal " << endl;

        for(auto &item: m_dataVec) {
            cout << item << endl;
        }
    }

    for(int i = 0; i < 1000000; i++) {
        std::cout << "B sleep" << i << "s" << endl;
        sleep(2);
    }
}

