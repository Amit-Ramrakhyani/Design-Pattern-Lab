#include <iostream>
#include <vector>

using namespace std;

class Subject;

// Observer interface that defines the update method
class Observer {
    public:
        virtual void update(Subject* subject) = 0;
};

// Subject interface that defines the attach, detach, and notify methods
class Subject {
    public:
        virtual void attach(Observer* observer) = 0;
        virtual void detach(Observer* observer) = 0;
        virtual void notify() = 0;
};

// Concrete Subject class that implements the Subject interface
class ConcreteSubject : public Subject {
    private:
        int state_;
        vector<Observer*> observers_;

    public:
        void attach(Observer* observer) override {
            observers_.push_back(observer);
        }

        void detach(Observer* observer) override {
            for (auto it = observers_.begin(); it != observers_.end(); ++it) {
                if (*it == observer) {
                    observers_.erase(it);
                    break;
                }
            }
        }

        void notify() override {
            for (auto observer : observers_) {
                observer->update(this);
            }
        }

        void setState(int state) {
            state_ = state;
            notify();
        }

        int getState() const {
            return state_;
        }
};

// Concrete Observer class that implements the Observer interface
class ConcreteObserver : public Observer {
    public:
        void update(Subject* subject) override {
            cout << "Observer: Subject state is now " << static_cast<ConcreteSubject*>(subject)->getState() << endl;
        }
};

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1, observer2;

    // Attach the observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Change the state of the subject and notify the observers
    subject.setState(1);

    // Detach an observer from the subject
    subject.detach(&observer1);

    // Change the state of the subject again and notify the remaining observer
    subject.setState(2);

    return 0;
}
