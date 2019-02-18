#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string i_name, int i_age): name{std::move(i_name)}, age{i_age} {}
    Person(): name{""}, age{0} {}
    virtual void getdata() = 0;
    virtual void putdata() = 0;
    virtual ~Person() = default; // destructor
};

class Professor: public Person {
private:
    const int cur_id = 1;
    int publications;
public:
    Professor(string i_name, int i_age): Person{std::move(i_name), i_age} {}
    Professor(): Person() {}

    void getdata() override {
        cin >> name >> age >> publications;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }

    ~Professor() {}
};

class Student: public Person{
private:
    int cur_id, marks[6];
public:
    Student(string i_name, int i_age): Person{i_name, i_age} {}
    Student(): Person() {}

    void getdata() override {
        cin >> name >> age;
    }

    void putdata() override {

    }

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
