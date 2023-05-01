#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Model class that represents the application data
class Model {
    private:
        string data_;

    public:
        void setData(const string& data) {
            data_ = data;
        }

        const string& getData() const {
            return data_;
        }
};

// View interface that defines the display method
class View {
    public:
        virtual void display(const string& data) = 0;
};

// Concrete View class that implements the View interface
class ConsoleView : public View {
    public:
        void display(const string& data) override {
            cout << "Console: " << data << endl;
        }
};

// Controller interface that defines the handleInput method
class Controller {
    public:
        virtual void handleInput(const string& input) = 0;
};

// Concrete Controller class that implements the Controller interface
class ConsoleController : public Controller {
    private:
        Model* model_;
        View* view_;
        
    public:
        ConsoleController(Model* model, View* view) : model_(model), view_(view) {}

        void handleInput(const string& input) override {
            model_->setData(input);
            view_->display(model_->getData());
        }
};

int main() {
    Model model;
    ConsoleView view;
    ConsoleController controller(&model, &view);

    // Handle user input and display the data
    controller.handleInput("Hello, world!");

    return 0;
}
