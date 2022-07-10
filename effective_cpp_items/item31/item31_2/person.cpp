#include "person.h"
#include "real_person.h"
//#include "person_impl.h"

string Person::name() const
{
    return "venner";
}

Person::~Person()
{

}

std::shared_ptr<Person> Person::Create(const string &name)
{
    RealPerson* real_person = new RealPerson(name);
    return std::shared_ptr<Person>(real_person);
}
