#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class PersonImpl;
class Date;
class Address;

class Person
{
public:
    Person(const std::string& name,
           const Date& birthday,
           const Address& addr);

    std::string name() const;
    std::string birthDate() const;
    std::string address() const;

private:
    std::shared_ptr<PersonImpl> pImpl;
};

#endif // PERSON_H
