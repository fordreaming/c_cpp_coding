#include "real_person.h"

RealPerson::RealPerson(const string &name) : theName(name)
{

}

string RealPerson::name() const
{
    return theName;
}

RealPerson::~RealPerson()
{

}
