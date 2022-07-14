#include "person.h"
#include "person_impl.h"

Person::Person(const string &name,
               const Date &birthday,
               const Address &addr) : pImpl(new PersonImpl(name, birthday, addr))
{

}

string Person::name() const
{
    return pImpl->name();
}
