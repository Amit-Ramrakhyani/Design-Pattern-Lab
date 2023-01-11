#include <iostream>
using namespace std;

class Person{
    protected:
        string name;
        int age;
        long long int mobileNo;

    public:
        explicit Person(string name, int age, long long int mobileNo){
            this->age = age;
            this->name = name;
            this->mobileNo = mobileNo;
        }
        void personDetails(){
            cout << "Name: " << name << endl << "Age: " << age << endl <<  "Mobile No: " << mobileNo << endl;
        }
        int getAge(){return age;}
        string getName(){return name;}
        long long int getMobileNo(){return mobileNo;}
        virtual void actionPerformed() = 0;
};

class Employee : public Person{
    private:
        int workingHours;
        int salary;
    public:
        Employee(string name, int age, long long int mobileNo, int workingHours, int salary) : Person(name, age, mobileNo){
            this->salary = salary;
            this->workingHours = workingHours;
        }

        void employeeDetails(){
            cout << "Name: " << name << endl << "Age: " << age << endl <<  "Mobile No: " << mobileNo << endl << "Working Hours: " << workingHours << endl <<  "Salary: " << salary << endl;
        }

        int getWorkingHours(){return workingHours;}
        int getSalary(){return salary;}
        void actionPerformed(){cout<<"Employee is working.";}
};

class Student : public Person{
    private:
        int rollNo;
        int studyHours;
    public:
        Student(string name, int age, long long int mobileNo, int rollNo, int studyHours) : Person(name, age, mobileNo){
            this->rollNo = rollNo;
            this->studyHours = studyHours;
        }

        void studentDetails(){
            cout << "Name: " << name << endl << "Age: " << age << endl <<  "Mobile No: " << mobileNo << endl << "Studying Hours: " << studyHours << endl <<  "Roll No: " << rollNo << endl;
        }

        int getRollNo(){return rollNo;}
        int getStudyHours(){return studyHours;}
        void actionPerformed(){cout<<"Student is studying.";}
};

int main(){
    Employee e1("Darius Tenz", 21, 8748034893, 50000, 7);
    e1.employeeDetails();
    e1.actionPerformed();

    Student s1("Smith Jones", 19, 7389923902, 328, 12);
    s1.studentDetails();
    return 0;
}