#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string i_name, int i_age): name{i_name}, age{i_age} {}
    Person(): name{""}, age{0} {}
    void getdata() {
        std::cout << "Name: " << name << " Age: " << age << std::endl;
    }
    void putdata() {
        std::cout << "Name: " << name << " Age: " << age << std::endl;
    }
    virtual ~Person() {} // destructor
};

class Professor: public Person {
private:
    int cur_id, publications;
public:
    Professor(string i_name, int i_age): Person{i_name, i_age} {}
    Professor(): Person() {}
    ~Professor() {}
};

class Student: public Person{
private:
    int cur_id, marks;
public:
    Student(string i_name, int i_age): Person{i_name, i_age} {}
    Student(): Person() {}
    ~Student() {}
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
