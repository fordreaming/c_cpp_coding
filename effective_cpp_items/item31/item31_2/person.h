#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Person
{
public:
    virtual std::string name() const = 0;
//    virtual std::string birthDate() const = 0;
//    virtual std::string address() const = 0;

    virtual ~Person();

    static std::shared_ptr<Person> Create(const std::string& name);
};

#endif // PERSON_H
