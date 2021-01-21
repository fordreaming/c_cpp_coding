#ifndef INHERITANCEA_H
#define INHERITANCEA_H
#include <algorithm>
#include <thread>
#include <condition_variable>

#include <unistd.h>

#include "Base.h"
class InheritanceB;

class InheritanceA : public Base
{
public:
    InheritanceA();
    void SendSignal(bool &flag, std::mutex &m_mutex, std::condition_variable &m_condVariable);

public:
    InheritanceB *m_pInheritanceB;
};

#endif // INHERITANCEA_H
