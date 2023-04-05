#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Player {
    public: 
       virtual void assignWeapon(string weapon) = 0;
       virtual void mission() = 0;
};

class Terrorist : public Player {
    private:
        string weapon;
    
    public:
        string task;
        Terrorist() {
            task = "PLANT A BOMB";
        }

        void assignWeapon(string weapon) override {
            this->weapon = weapon;
        }

        void mission() override {
            cout << "Terrorist with a mission to " << task << " and weapon " << weapon << endl;
        }
};

class CounterTerrorist : public Player {
    private:
        string task;
        string weapon;
    
    public:
        CounterTerrorist() {
            task = "DIFFUSE THE BOMB";
        }

        void assignWeapon(string weapon) override {
            this->weapon = weapon;
        }

        void mission() override {
            cout << "Counter Terrorist with a mission to " << task << " and weapon " << weapon << endl;
        }
};

class PlayerFactory {
    private:
        static unordered_map <string, Player*> umap;
    
    public:
        Player* getPlayer(string type) {
            
            auto player = umap.find(type); 

            if(player == umap.end()) {
                Player* p;
                if (type == "Terrorist") {
                    cout << "Terrorist created - ";
                    p =  new Terrorist();
                }

                else if (type == "CounterTerrorist") {
                    cout << "Counter Terrorist created - ";
                    p = new CounterTerrorist();
                }
                umap[type] = p;

                return p;
            }

            else {
                return player->second;
            }
        }
};

unordered_map <string, Player*> PlayerFactory::umap;

const char* playerType[] = {"Terrorist", "CounterTerrorist"};
const char* weapons[] = {"AK-47", "Maverick", "Gut Knife", "Desert Eagle"};    

static string getRandPlayerType() {
    int randInt = rand() % 2;
    return playerType[randInt];
}

static string getRandWeapon() {
    int randInt = rand() % 4;
    return weapons[randInt];
}

int main() {

    for (int i=0; i<10; i++) {
        PlayerFactory pf;
        Player* p = pf.getPlayer(getRandPlayerType());
        p->assignWeapon(getRandWeapon());
        p->mission();
    }

};