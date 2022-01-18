#include "file2.h"

extern const int counter = 5;

File2::File2()
{

}

void File2::ConstActionScope()
{
    for(int index = 0; index != counter; ++index) {
        std::cout << "index: " << index << std::endl;
    }
}



