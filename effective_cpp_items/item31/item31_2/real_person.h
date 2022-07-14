#ifndef REAL_PERSON_H
#define REAL_PERSON_H

#include "person.h"

class RealPerson : public Person
{
public:
    RealPerson(const std::string& name);

    virtual std::string name() const;
    virtual ~RealPerson();

private:
    std::string theName;
};

#endif // REAL_PERSON_H
