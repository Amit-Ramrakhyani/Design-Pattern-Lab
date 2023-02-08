#include <iostream>
using namespace std;

class Singleton {
    private:
        static Singleton* instance;
        Singleton(int x){
            cout << "Singleton " << x << " is being created." << endl;
        }
    public:
        static Singleton* getInstance(int a){
            if(instance == NULL){
                instance = new Singleton(a);
            }
            return instance;
        }
};

Singleton* Singleton::instance = NULL;

int main(){
    Singleton* s1 = Singleton::getInstance(2);
    s1->getInstance(3);
    Singleton* s2 = Singleton::getInstance(4);
    Singleton* s3 = Singleton::getInstance(7);
    return 0;
}