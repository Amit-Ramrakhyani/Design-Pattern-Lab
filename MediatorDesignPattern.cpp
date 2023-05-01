#include <iostream>
#include <vector>
#include <string>

class User;

class ChatMediator {
    public:
        virtual void sendMessage(const std::string& msg, User* user) = 0;
        virtual void addUser(User* user) = 0;
};

class User {
    protected:
        ChatMediator* mediator;
        std::string name;
    public:
        User(ChatMediator* med, const std::string& name) : mediator(med), name(name) {}
        virtual void send(const std::string& msg) = 0;
        virtual void receive(const std::string& msg) = 0;
};

class ChatMediatorImpl : public ChatMediator {
    private:
        std::vector<User*> users;
    public:
        void addUser(User* user) {
            users.push_back(user);
        }
        void sendMessage(const std::string& msg, User* user) {
            for (auto u : users) {
                if (u != user) {
                    u->receive(msg);
                }
            }
        }
};

class ConcreteUser : public User {
    public:
        ConcreteUser(ChatMediator* med, const std::string& name) : User(med, name) {}
        void send(const std::string& msg) {
            std::cout << "Sending message: " << msg << "\n";
            mediator->sendMessage(msg, this);
        }
        void receive(const std::string& msg) {
            std::cout << name << " received message: " << msg << "\n";
        }
};

int main() {
    ChatMediatorImpl mediator;
    ConcreteUser user1(&mediator, "John");
    ConcreteUser user2(&mediator, "Jane");
    ConcreteUser user3(&mediator, "Bob");
    mediator.addUser(&user1);
    mediator.addUser(&user2);
    mediator.addUser(&user3);
    user1.send("Hello, everyone!");
    return 0;
}
