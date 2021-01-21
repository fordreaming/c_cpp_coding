#ifndef INHERITANCEB_H
#define INHERITANCEB_H
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Base.h"

class InheritanceB : public Base
{
public:
    InheritanceB();
    void SynchronousData(const std::vector<float> &dataVec);
    void ReceiveSignal(bool &flag, std::mutex &m_mutex, std::condition_variable &m_condVariable);

public:
    std::vector<float>              m_dataVec;
};

#endif // INHERITANCEB_H
