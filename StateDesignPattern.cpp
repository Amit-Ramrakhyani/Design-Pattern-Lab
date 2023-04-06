#include <iostream>
using namespace std;

class ProcessState {
    public:
        virtual void execute() = 0;
};

class New : public ProcessState {
    void execute() override {
        cout << "Process is in NEW state" << endl;
    }
};

class Ready : public ProcessState {
    void execute() override {
        cout << "Process is in READY queue" << endl;
    }
};

class Running : public ProcessState {
    void execute() override {
        cout << "Process is in RUNNING state" << endl;
    }
};

class Waiting : public ProcessState {
    void execute() override {
        cout << "Process is in WAITING state" << endl;
    }
};

class Terminated : public ProcessState {
    void execute() override {
        cout << "Process is TERMINATED" << endl;
    }
};

class StateContext {
    public:
        ProcessState* ps;
        
        StateContext() {
            ps = new New();
        }

        void changeState(ProcessState* state) {
            ps = state;
        }

        void execute() {
            ps->execute();
        }
};

int main() {
    StateContext sc;
    sc.execute();
    sc.changeState(new Ready());
    sc.execute();
    sc.changeState(new Running());
    sc.execute();
    sc.changeState(new Waiting());
    sc.execute();
    sc.changeState(new Ready());
    sc.execute();
    sc.changeState(new Running());
    sc.execute();
    sc.changeState(new Terminated());
    sc.execute();
}