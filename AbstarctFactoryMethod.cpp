#include <iostream>
using namespace std;

class Electronics{
    protected:
        string name;
        string os;
        int price;
    public:
        virtual string purpose(){};
};

class ElectronicsFactory{
    public:
        virtual Electronics* getDevice(string name){};
};

class Samsung : public Electronics{
    public:
        Samsung(){
            name = "Samsung";
            os = "Android";
            price = 10000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string purpose(){
            return "Samsung is used for running high performance apps.";
        }
};

class Apple : public Electronics{
    public:
        Apple(){
            name = "Apple";
            os = "iOS";
            price = 20000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string purpose(){
            return "Apple is used for photography.";
        }
};

class Nokia : public Electronics{
    public:
        Nokia(){
            name = "Nokia";
            os = "Symbian";
            price = 5000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string purpose(){
            return "Nokia is used for is strength properties.";
        }
};

class MobileFactory : public ElectronicsFactory{
    public:
        Electronics* getDevice(string name){
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

/*class Laptop{
    protected:
        string name;
        string os;
        int price;
    public:
        virtual string features(){};
};*/

class Dell : public Electronics{
    public:
        Dell(){
            name = "Dell";
            os = "Linux";
            price = 60000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string purpose(){
            return "Dell has a 2GB graphics card";
        }
};

class Macbook : public Electronics{
    public:
        Macbook(){
            name = "Macbook";
            os = "MacOS";
            price = 80000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string purpose(){
            return "Macbook has a 4GB graphics card";
        }
};

class Lenovo : public Electronics{
    public:
        Lenovo(){
            name = "Lenovo";
            os = "Windows";
            price = 50000;
            cout << "Name: " << name << endl << "OS: " << os << endl <<  "Price: " << price << endl;
        }
        string purpose(){
            return "Lenovo has a 1GB graphics card";
        }
};

class LaptopFactory : public ElectronicsFactory{ 
    public:
        Electronics* getDevice(string name){
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

class Factory{
    public:
        static ElectronicsFactory* getFactory(string device){
            if(device == "Laptop"){
                return new LaptopFactory();
            }
            else{
                return new MobileFactory();
            }
        }
};

int main(){
    string device, name;
    cout << "Enter the device you want to buy: ";
    cin >> device;
    cout << "Enter the name of the device you want to buy: ";
    cin >> name;
    ElectronicsFactory* ef = Factory::getFactory(device);
    Electronics* e = ef->getDevice(name);
    cout << e->purpose() << endl;
    return 0;
}
