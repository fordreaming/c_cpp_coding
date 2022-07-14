#ifndef PERSON_IMPL_H
#define PERSON_IMPL_H

#include <string>

class Date;
class Address;

class PersonImpl
{
public:
    PersonImpl(const std::string& name,
               const Date& birthday,
               const Address& addr);

    std::string name() const;

public:
    std::string theName;
};

#endif // PERSON_IMPL_H
