#include <iostream>
#include <vector>
using namespace std;

class Component{
    public:
        virtual int getPrice() = 0;
        virtual void showPrice() = 0;
};

class Leaf : public Component {
    int price;
    string name;

    public:
        Leaf(string name, int price) {
            this->name = name;
            this->price = price;
        }

        int getPrice() {
            return price;
        }

        void showPrice() {
            cout << name << ": " << price << endl;
        }
};

class Composite : public Component {
    string name;
    vector<Component*> components;

    public:
        Composite(string name) {
            this->name = name;
        }

        void add(Component* component) {
            components.push_back(component);
        }

        int getPrice() {
            int price = 0;
            for (int i = 0; i < components.size(); i++) {
                price += components[i]->getPrice();
            }
            return price;
        }

        void showPrice() {
            cout << name << ": " << getPrice() << endl;
            for (int i = 0; i < components.size(); i++) {
                components[i]->showPrice();
            }
        }
};

int main() {
    Component *hd = new Leaf("HDD", 100);
    Component *mouse = new Leaf("Mouse", 50);
    Component *monitor = new Leaf("Monitor", 200);
    Component *cpu = new Leaf("CPU", 300);
    Component *ram = new Leaf("RAM", 150);

    Composite *ph = new Composite("Peripherals");
    Composite *cabinet = new Composite("Cabinet");
    Composite *mb = new Composite("Motherboard");
    Composite *computer = new Composite("Computer");

    ph->add(mouse);
    ph->add(monitor);

    mb->add(cpu);
    mb->add(ram);

    cabinet->add(hd);
    cabinet->add(mb);

    computer->add(ph);
    computer->add(cabinet);

    computer->showPrice();
}