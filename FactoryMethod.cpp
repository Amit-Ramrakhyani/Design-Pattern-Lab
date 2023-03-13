#include <iostream>
using namespace std;

class Mobile{
    protected:
        string name;
        string os;
        int price;
    public:
        virtual string call() = 0;
};

class Samsung : public Mobile{
    public:
        Samsung(){
            name = "Samsung";
            os = "Android";
            price = 10000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string call(){
            return "Samsung is ringing";
        }
};

class Apple : public Mobile{
    public:
        Apple(){
            name = "Apple";
            os = "iOS";
            price = 20000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string call(){
            return "Apple is ringing";
        }
};

class Nokia : public Mobile{
    public:
        Nokia(){
            name = "Nokia";
            os = "Symbian";
            price = 5000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string call(){
            return "Nokia is ringing";
        }
};

class MobileFactory{
    public:
        static Mobile* getMobile(string name){
            if(name == "Samsung"){
                return new Samsung();
            }
            else if(name == "Apple"){
                return new Apple();
            }
            else if(name == "Nokia"){
                return new Nokia();
            }
            else{
                return NULL;
            }
        }
};

int main(){
    string name;
    cout << "Enter the mobile you want to buy: ";
    cin >> name;
    Mobile* mobile = MobileFactory::getMobile(name);
    cout << mobile->call() << endl;
    return 0;
}