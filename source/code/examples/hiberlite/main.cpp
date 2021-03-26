#include "include/hiberlite.h"
#include <string>
#include <vector>

using namespace std;

class Person{
    friend class hiberlite::access;
    template<class Archive>
    void hibernate(Archive & ar)
    {
        ar & HIBERLITE_NVP(name);
        ar & HIBERLITE_NVP(age);
        ar & HIBERLITE_NVP(bio);
    }
public:
    string name;
    double age;
    vector<string> bio;
};
HIBERLITE_EXPORT_CLASS(Person)

int main(){
    Person p;
}