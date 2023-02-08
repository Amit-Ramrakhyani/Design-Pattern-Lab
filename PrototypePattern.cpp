#include <iostream>
using namespace std;

class Prototype {
    private:
        string name;
        int age;
        string address;
        string phone;
    public:
        Prototype(string name, int age, string address, string phone){
            this->name = name;
            this->age = age;
            this->address = address;
            this->phone = phone;
        }
        /*Prototype(const Prototype& prototype){
            this->name = prototype.name;
            this->age = prototype.age;
            this->address = prototype.address;
            this->phone = prototype.phone;
        }*/
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        string getAddress(){
            return address;
        }
        string getPhone(){
            return phone;
        }
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        void setAddress(string address){
            this->address = address;
        }
        void setPhone(string phone){
            this->phone = phone;
        }
        Prototype* clone(){
            return new Prototype(*this);
        }
};

int main(){
    Prototype* prototype = new Prototype("John", 25, "123 Main Street", "123-456-7890");
    //Prototype* clone = prototype; // For shallow cloning
    Prototype* clone = prototype->clone(); // For deep cloning

    cout << "Name: " << clone->getName() << endl;
    cout << "Age: " << clone->getAge() << endl;
    cout << "Address: " << clone->getAddress() << endl;
    cout << "Phone: " << clone->getPhone() << endl << endl;
    
    prototype->setName("Kelly");
    prototype->setAge(23);
    prototype->setAddress("456 Main Street");
    prototype->setPhone("987-654-3210");
    
    cout << "Name: " << clone->getName() << endl;
    cout << "Age: " << clone->getAge() << endl;
    cout << "Address: " << clone->getAddress() << endl;
    cout << "Phone: " << clone->getPhone() << endl << endl;

    cout << "Name: " << prototype->getName() << endl;
    cout << "Age: " << prototype->getAge() << endl;
    cout << "Address: " << prototype->getAddress() << endl;
    cout << "Phone: " << prototype->getPhone() << endl;
    
    return 0;
}

