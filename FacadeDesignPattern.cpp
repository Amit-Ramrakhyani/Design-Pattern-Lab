#include <iostream>
using namespace std;

class CarSystem {
    public:
        void working(){}
        void data(){}
};

class Engine : public CarSystem {
    public:
        void working() {
            cout << "Engine is working" << endl;
        }

        void data() {
            cout << "Engine is at its full capacity" << endl; 
        }
};

class Speedometer : public CarSystem {
    public:
        void working() {
            cout << "Speedometer is working" << endl; 
        }
        
        void data() {
            cout << "Total distance covered is 1858 KMs" << endl; 
        }
};

class FuelGauge : public CarSystem {
    public:
        void working() {
            cout << "Fuel Gauge is working" << endl;
        }
        
        void data() {
            cout << "Fuel in the tank: 3.9 litres" << endl; 
        }
};

class TemperatureGauge : public CarSystem {
    public:
        void working() {
            cout << "Temperature Gauge is working" << endl;
        }
        
        void data() {
            cout << "Temperature is 34 degress C" << endl; 
        }
};

class Odometer : public CarSystem {
    public: 
        void working() {
            cout << "Odometer is working" << endl;
        }
        
        void data() {
            cout << "Current speed is 56 KMph" << endl; 
        }
};

class CarSubSystem {
    private:
        Engine eng;
        Speedometer speedo;
        FuelGauge fuel;
        TemperatureGauge temp;
        Odometer od;

    public:
        void Engine() {
            eng.working();
            eng.data();
        }
        
        void Speedometer() {
            speedo.working();
            speedo.data();
        }
        
        void FuelGauge() {
            fuel.working();
            fuel.data();
        }
        
        void TemperatureGauge() {
            temp.working();
            temp.data();
        }
        
        void Odometer() {
            od.working();
            od.data();
        }
};

int main() {

    CarSubSystem css;
    cout << endl;

    css.Engine();
    cout << endl;
    
    css.Speedometer();
    cout << endl;
    
    css.FuelGauge();
    cout << endl;
    
    css.TemperatureGauge();
    cout << endl;
    
    css.Odometer();
    cout << endl;

    return 0;
}