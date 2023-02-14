#include <iostream>
using namespace std;

int value=0;

class Singleton {
    private:
        static Singleton* instance;
        Singleton(){}
    public:
        static Singleton* getInstance(){
            if(instance == NULL){
                instance = new Singleton();
                return instance;
            }
            return instance;
        }
        void Deposit(int amt){
            value+=amt;
        }
        void Withdraw(int amt){
            value-=amt;
        }
};

Singleton* Singleton::instance = NULL;

int main(){
    Singleton* transaction1 = Singleton::getInstance();
    transaction1->Deposit(1000);
    cout << "Balance: " << value << endl;
    cout << "ID: " << transaction1 << endl << endl;

    Singleton* transaction2 = Singleton::getInstance();
    transaction2->Withdraw(500);
    cout << "Balance: " << value << endl;
    cout << "ID: " << transaction2 << endl << endl;
    
    Singleton* transaction3 = Singleton::getInstance();
    transaction3->Deposit(3700);
    cout << "Balance: " << value << endl;
    cout << "ID: " << transaction3 << endl << endl;
    return 0;
}