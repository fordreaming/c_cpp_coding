#include <QCoreApplication>
#include "person.h"

int main(int argc, char *argv[])
{
    std::string name{"keven"};
    std::shared_ptr<Person> pp(Person::Create(name));

    std::cout << pp->name()
              << "was born on"
              << std::endl;
}
