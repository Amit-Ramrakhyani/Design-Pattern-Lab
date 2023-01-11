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
        Person(){

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
        int marks[5];
        int studyHours;
    public:
        Student(string name, int age, long long int mobileNo, int rollNo, int marks[5], int studyHours) : Person(name, age, mobileNo){
            for(int i=0; i<5; i++){
                this->marks[i] = marks[i];
            }
            this->rollNo = rollNo;
            this->studyHours = studyHours;
        }
        void calculatePercentage(){
            int sum=0;
            for(int i=0; i<5; i++){
                sum += marks[i];
            }
            return sum/5;
        }

        void studentDetails(){
            cout << "Name: " << name << endl << "Age: " << age << endl <<  "Mobile No: " << mobileNo << endl << "Studying Hours: " << studyHours << endl <<  "Roll No: " << rollNo << endl << "Percentage: " << calculatePercentage();
        }

        int getRollNo(){return rollNo;}
        int getMarks(){return marks;}
        int getStudyHours(){return studyHours;}
        void actionPerformed(){cout<<"Student is studying.";}
}

int main(){
    Employee e1("Sahil Kumar", 21, 8748034893, 50000, 7);
    e1.employeeDetails();
    e1.actionPerformed();

    Student s1("Manan Gupta", 19, 7389923902, 328, {89, 90, 97, 67, 98}, 12);
    s1.studentDetails();
    return 0;
}