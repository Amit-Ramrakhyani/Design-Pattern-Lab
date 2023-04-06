#include <iostream>
#include <vector>
using namespace std;

class Iterator {
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool hasNext() = 0;
        virtual string current_item() = 0;
};

class ConcreteIterator : public Iterator {
    private:
        vector<string> *notifications;
        int index;
    public:
        ConcreteIterator(vector<string> *new_items) {
            notifications = new_items;
            index = 0;
        }
        void first() {
            index = 0;
        }
        void next() {
            index++;
        }
        bool hasNext() {
            if (index < notifications->size()) {
                return true;
            }
            return false;
        }
        string current_item() {
            return notifications->at(index);
        }
};

class Aggregate {
    public:
        virtual Iterator *create_iterator() = 0;
};

class ConcreteAggregate : public Aggregate {
    private:
        vector<string> *notifications;
    public:
        ConcreteAggregate() {
            notifications = new vector<string>();
        }
        void add_item(string item) {
            notifications->push_back(item);
        }
        Iterator *create_iterator() {
            return new ConcreteIterator(notifications);
        }
};

int main() {
    ConcreteAggregate *aggregate = new ConcreteAggregate();
    aggregate->add_item("You have a new email");
    aggregate->add_item("You have a missed call");
    aggregate->add_item("New message from John");
    aggregate->add_item("Your parcel has been delivered");
    
    Iterator *iterator = aggregate->create_iterator();
    while (iterator->hasNext()) {
        cout << iterator->current_item() << endl;
        iterator->next();
    }
    return 0;
}