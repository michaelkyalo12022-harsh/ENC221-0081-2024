#include <iostream>
#include <string>
using namespace std;

class Classmate {
public: 
    string name;
    int age;
    string hobby;
    string gender;
    string skincolor;
    string height;
};
int main() {
    Classmate friend1;
    
    friend1.name = "michael";
    friend1.age = 17;
    friend1.hobby = "Playing football";
    friend1.gender = "male";
    friend1.skincolor = "brown";
    friend1.height = "6ft";
    cout<< "Name: " << friend1.name << endl;
     cout << "Age: " <<friend1.age << endl;
     cout << "Hobby: " << friend1.hobby << endl;
     cout << "gender:" << friend1.gender << endl;
     cout << "skincolor:" << friend1.skincolor << endl;
     cout << "height:" <<friend1.height << endl;
     cout << endl;
     
     return 0;
};