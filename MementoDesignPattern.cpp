#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Memento {
    private:
        string state_;
    public:
        Memento(const string& state) : state_(state) {}
        string getState() const { return state_; }
};

class Originator {
    private:
        string state_;
    public:
        void setState(const string& state) { state_ = state; }
        string getState() const { return state_; }
        Memento createMemento() const { return Memento(state_); }
        void restoreMemento(const Memento& memento) { state_ = memento.getState(); }
};

class Caretaker {
    private:
        vector<Memento> mementos_;
    public:
        void addMemento(const Memento& memento) { mementos_.push_back(memento); }
        Memento getMemento(int index) const { return mementos_[index]; }
};

int main() {
    Originator originator;
    Caretaker caretaker;

    // Set the initial state of the originator and store a memento
    originator.setState("State 1");
    caretaker.addMemento(originator.createMemento());

    // Change the state of the originator and store another memento
    originator.setState("State 2");
    caretaker.addMemento(originator.createMemento());

    // Change the state of the originator again
    originator.setState("State 3");

    // Restore the first memento
    originator.restoreMemento(caretaker.getMemento(0));
    cout << "Current state: " << originator.getState() << endl;

    // Restore the second memento
    originator.restoreMemento(caretaker.getMemento(1));
    cout << "Current state: " << originator.getState() << endl;

    return 0;
}
