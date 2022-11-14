#include "base_map_exams.h"

BaseMapExams::BaseMapExams()
{

}

void BaseMapExams::delMapVal()
{
    std::map<char,int> mymap;
    std::map<char,int>::iterator it;

    // insert some values:
    mymap['a'] = 50;
    mymap['b'] = 10;
    mymap['c'] = 10;
    mymap['d'] = 10;
    mymap['e'] = 10;
    mymap['f'] = 60;


    // show content:
    for (it = mymap.begin(); it != mymap.end(); ++it) {
        if(it->second == 10) {
            mymap.erase(it);
        }
    }
}
