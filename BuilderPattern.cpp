#include <iostream>
using namespace std;

class PizzaRecipe {
    public:
        virtual void addCheese(string cheese) = 0;
        virtual void addSauce(string sauce) = 0;
        virtual void addMeat(string meat) = 0;
        virtual void addTopping(string topping) = 0;
};

class Pizza : public PizzaRecipe {
    private:
        string cheese;
        string sauce;
        string meat;
        string topping;

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
        void addMeat(string meat){
            this->meat = meat;
        }
        void addTopping(string topping){
            this->topping = topping;
        }
        string getCheese(){
            return cheese;
        }
        string getSauce(){
            return sauce;
        }
        string getMeat(){
            return meat;
        }
        string getTopping(){
            return topping;
        }
};

class PizzaBuilder {
    protected:
        Pizza* pizza;

    public:
        virtual void addCheese() = 0;
        virtual void addSauce() = 0;
        virtual void addMeat() = 0;
        virtual void addTopping() = 0;
        virtual Pizza* getPizza() = 0;
};

class HawaiianPizzaBuilder : public PizzaBuilder {
    public:
        HawaiianPizzaBuilder(){
            pizza = new Pizza();
        }
        void addCheese(){
            pizza->addCheese("Mozzarella");
        }
        void addSauce(){
            pizza->addSauce("Tomato");
        }
        void addMeat(){
            pizza->addMeat("Ham");
        }
        void addTopping(){
            pizza->addTopping("Pineapple");
        }
        Pizza* getPizza(){
            return pizza;
        }
};

class PepperoniPizzaBuilder : public PizzaBuilder {
    public:
        PepperoniPizzaBuilder(){
            pizza = new Pizza();
        }
        void addCheese(){
            pizza->addCheese("Mozzarella");
        }
        void addSauce(){
            pizza->addSauce("Tomato");
        }
        void addMeat(){
            pizza->addMeat("Pepperoni");
        }
        void addTopping(){
            pizza->addTopping("Olives");
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
            pizzaBuilder->addMeat();    
            pizzaBuilder->addTopping();
        }
};

int main(){
    PizzaBuilder* pizzaBuilder = new HawaiianPizzaBuilder();
    PizzaDirector pizzaDirector(pizzaBuilder);
    pizzaDirector.makePizza();
    Pizza* pizza = pizzaDirector.getPizza();
    cout << "Cheese: " << pizza->getCheese() << endl;
    cout << "Sauce: " << pizza->getSauce() << endl;
    cout << "Meat: " << pizza->getMeat() << endl;
    cout << "Topping: " << pizza->getTopping() << endl;
    return 0;
};