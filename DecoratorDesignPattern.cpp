#include <iostream>
using namespace std;

class Pizza {
    public:
        virtual void get_description() = 0;
        virtual int get_cost() = 0;
};

class PlainPizza : public Pizza {
    public:
        void get_description() {
            cout << "Thin Dough";
        }
        int get_cost() {
            return 4;
        }
};

class PizzaDecorator : public Pizza {
    protected:
        Pizza *temp_pizza;
    public:
        PizzaDecorator(Pizza *new_pizza) {
            temp_pizza = new_pizza;
        }
        void get_description() {
            temp_pizza->get_description();
        }
        int get_cost() {
            return temp_pizza->get_cost();
        }
};

class TomatoSauce : public PizzaDecorator {
    public:
        TomatoSauce(Pizza *new_pizza) : PizzaDecorator(new_pizza) {

        }
        void get_description() {
            temp_pizza->get_description();
            cout << ", tomato sauce";
        }
        int get_cost() {
            return temp_pizza->get_cost() + 2;
        }
};

class Mozzarella : public PizzaDecorator {
    public:
        Mozzarella(Pizza *new_pizza) : PizzaDecorator(new_pizza) {

        }
        void get_description() {
            temp_pizza->get_description();
            cout << ", mozzarella";
        }
        int get_cost() {
            return temp_pizza->get_cost() + 2;
        }
};

class Ham : public PizzaDecorator {
    public:
        Ham(Pizza *new_pizza) : PizzaDecorator(new_pizza) {

        }
        void get_description() {
            temp_pizza->get_description();
            cout << ", ham";
        }
        int get_cost() {
            return temp_pizza->get_cost() + 2;
        }
};

int main() {
    Pizza *pizza = new TomatoSauce(new Mozzarella(new Ham(new PlainPizza())));  
    cout << "Ingredients: " << endl;
    pizza->get_description();
    cout << endl << "Cost: " << pizza->get_cost() << endl;
    return 0;
}