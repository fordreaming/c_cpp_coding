#include "person_impl.h"


PersonImpl::PersonImpl(const std::string &name, const Date &birthday, const Address &addr)
{

}

std::string PersonImpl::name() const
{
    return theName;
}
