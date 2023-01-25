#include <iostream>
using namespace std;

class PizzaRecipe {
    public:
        virtual void addCheese(string cheese) = 0;
        virtual void addSauce(string sauce) = 0;
        virtual void addPepperoni(string pepperoni) = 0;
        virtual void addOlives(string olives) = 0;
};

class Pizza : public PizzaRecipe {
    private:
        string cheese;
        string sauce;
        string pepperoni;
        string olives;

    public:
        Pizza(){
            cout << "Pizza is being prepared." << endl;
        }
        void addCheese(string cheese){
            this->cheese = cheese;
        }
        void addSauce(string sauce){
            this->sauce = sauce;
        }
        void addPepperoni(string pepperoni){
            this->pepperoni = pepperoni;
        }
        void addOlives(string olives){
            this->olives = olives;
        }
        string getCheese(){
            return cheese;
        }
        string getSauce(){
            return sauce;
        }
        string getPepperoni(){
            return pepperoni;
        }
        string getOlives(){
            return olives;
        }
};

class PizzaBuilder {
    protected:
        Pizza* pizza;

    public:
        PizzaBuilder(){
            pizza = new Pizza; 
        }
        void addCheese(){
            pizza->addCheese("Mozzarella");
        }
        void addSauce(){
            pizza->addSauce("Tomato");
        }
        void addPepperoni(){
            pizza->addPepperoni("Pepperoni");
        }
        void addOlives(){
            pizza->addOlives("Black Olives");
        }
        Pizza* getPizza(){
            return pizza;
        }
};

class PizzaDirector {
    private:
        PizzaBuilder* pizzaBuilder;

    public:
        PizzaDirector(PizzaBuilder* pizzaBuilder){
            this->pizzaBuilder = pizzaBuilder;
        }
        Pizza* getPizza(){
            return pizzaBuilder->getPizza();
        }
        void makePizza(){
            pizzaBuilder->addCheese();
            pizzaBuilder->addSauce();
            pizzaBuilder->addPepperoni();    
            pizzaBuilder->addOlives();
        }
};

int main(){
    PizzaBuilder* pizzaBuilder = new PizzaBuilder();
    PizzaDirector pizzaDirector(pizzaBuilder);
    pizzaDirector.makePizza();
    Pizza* pizza = pizzaDirector.getPizza();
    cout << "Cheese: " << pizza->getCheese() << endl;
    cout << "Sauce: " << pizza->getSauce() << endl;
    cout << "Pepperoni: " << pizza->getPepperoni() << endl;
    cout << "Olives: " << pizza->getOlives() << endl;
    return 0;
};