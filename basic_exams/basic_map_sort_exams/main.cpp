#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct increaseKey {
    bool operator() (const std::string& str1, const std::string& str2) {
        return str1.length() < str2.length();
    }
};

void increaseSortBykey() {
    //    map<string, int, greater<string> > mapStudent;  //关键是这句话
    //    map<string, int, less<string>> mapStudent;

    map<string, int, increaseKey> mapStudent;
    mapStudent["LiMin"]=90;
    mapStudent["ZiLinMi"]=72;
    mapStudent["BoB"]=79;
    map<string, int>::iterator iter=mapStudent.begin();

    for(iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
}

typedef struct TagStudentInfo {
    int iID;
    std::string strName;
//    bool operator < (TagStudentInfo const& r) const {
////        if(iID < r.iID) {
////            return true;
////        }

////        //        if(iID == r.iID) return strName.compare(r.strName) < 0;

////        return false;
//        return iID < r.iID;
//    }

//    bool operator > (const TagStudentInfo& r) const {
//        return iID > r.iID;
//    }

//    bool operator >= (const TagStudentInfo& r) const {
//        return iID >= r.iID;
//    }

} StudentInfo;

struct increaseBykey {
    bool operator () (const TagStudentInfo& stu1, const TagStudentInfo& stu2) {
        return stu1.iID < stu2.iID;
    }
};

struct decreaseByKey {
    bool operator () (const TagStudentInfo& stu1, const TagStudentInfo& stu2) {
        return stu1.iID > stu2.iID;
    }
};

void SortByStruct() {
    map<StudentInfo, int, decreaseByKey> mapStudent;
    StudentInfo studentInfo;

    studentInfo.iID = 1;
    studentInfo.strName = "student_one";
    mapStudent[studentInfo] = 90;

    studentInfo.iID = 2;
    studentInfo.strName = "student_two";
    mapStudent[studentInfo] = 80;

    mapStudent[studentInfo] = 85;

    studentInfo.iID = 3;
    studentInfo.strName = "student_three";
    mapStudent[studentInfo] = 70;

    map<StudentInfo, int>::iterator iter = mapStudent.begin();
    for(; iter != mapStudent.end(); iter++) {
        cout << iter->first.iID << " " << iter->first.strName << " " << iter->second << endl;
    }
}

using PAIR = pair<string, int>;

//struct CmpByValue {
//  bool operator()(const PAIR& lhs, const PAIR& rhs) {
//    return lhs.second < rhs.second;
//  }
//};

void SortByVal() {
    map<string, int> name_score_map;
    name_score_map["LiMin"] = 90;
    name_score_map["ZiLinMi"] = 79;
    name_score_map["BoB"] = 92;
    name_score_map.insert(make_pair("Bing",99));
    name_score_map.insert(make_pair("Albert",86));


    vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());

    auto cmpByVal = [&](const PAIR& lhs, const PAIR& rhs) {
        return lhs.second < rhs.second;
    };

    sort(name_score_vec.begin(), name_score_vec.end(), cmpByVal);

    /*sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);也是可以的*/
    for (int i = 0; i != name_score_vec.size(); ++i) {
        cout<<name_score_vec[i].first<<" "<<name_score_vec[i].second<<endl;
    }
}

void print_(std::string const& s) {
    std::cout << "print s: " << s << std::endl;
}

void process_copy(std::vector<int> const& vec_) {
    std::vector<int> vec(vec_);
    vec.push_back(42);
}

int main(int argc, char *argv[])
{
    //    increaseSortBykey();
//    SortByStruct();
//    SortByVal();

//    vector<int> data{1, 2, 3, 4};
//    process_copy(data);

//    SortByStruct();

    return 0;
}
