#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>

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
    int cur_id;
    int publications;
public:
    static int id;
    Professor(string i_name, int i_age): Person{std::move(i_name), i_age} {
        cur_id = ++id;
    }
    Professor(): Person() {
        cur_id = ++id;
    }

    void getdata() override {
        cin >> name >> age >> publications;
    }

    void putdata() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }

    ~Professor() {}
};
int Professor::id = 0;

class Student: public Person{
private:
    int cur_id;
    array<int, 6> marks;
public:
    static int id;
    Student(string i_name, int i_age): Person{i_name, i_age} {
        cur_id = ++id;
    }
    Student(): Person() {
        cur_id = ++id;
    }

    void getdata() override {
        cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
    }

    void putdata() override {
        cout << name << " " << age << " " << accumulate(begin(marks), end(marks), 0, plus<int>{}) << " " << cur_id << endl;
    }

    ~Student() {}
};
int Student::id = 0;

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
