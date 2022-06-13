#include <iostream>
#include <ctime>
#include <string>
#include "human.h"
#include "cyberdemon.h"
#include "balrog.h"
#include "elf.h"
using namespace std;

void battleArena(Creature& creature1, Creature& creature2);

int main() {
    srand(time(NULL));
    //0 human, 1 cyberdemon, 2 balrog, 3 elf
    Human human(30, 60);
    Cyberdemon cyber(25, 45);
    Balrog balrog(20, 30);
    Elf elf(30, 50);

    battleArena(elf, human);
    system("pause");
    battleArena(cyber, balrog);
    system("pause");
    battleArena(cyber, elf);
    system("pause");

    return 0;
}

void battleArena(Creature& creature1, Creature& creature2) {
    int round = 1;
    int creature1Damage;
    int creature2Damage;
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    cout << creature1.getSpecies() << "  V.S.  " << creature2.getSpecies() << endl;
    while (true){
        cout << "Round: " << round << endl;
        cout << "Total HP:  ";
        cout << "[" << creature1.getSpecies() << ": "
            << creature1.getHitpoints() << "]     [";
        cout << creature2.getSpecies() << ": "
            << creature2.getHitpoints() << "]\n" << endl;

        creature1Damage = creature1.getDamage();
        creature2Damage = creature2.getDamage();

        cout << "Total Damage:  ";
        cout << "[" << creature1.getSpecies() << ": "
            << creature1Damage << "]     [";
        cout << creature2.getSpecies() << ": "
            << creature2Damage << "]" << endl;
        creature1.setHitpoints(creature1.getHitpoints() - creature2Damage);
        creature2.setHitpoints(creature2.getHitpoints() - creature1Damage);

        cout << "\nNow HP:  ";
        cout << "[" << creature1.getSpecies() << ": "
            << creature1.getHitpoints() << "]     [";
        cout << creature2.getSpecies() << ": "
            << creature2.getHitpoints() << "]" << endl;
        if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
            cout << "Draw!" << endl;
            break;
        }
        else if (creature1.getHitpoints() > 0 && creature2.getHitpoints() <= 0) {
            cout << creature1.getSpecies() << " wins!" << endl;
            break;
        }
        else if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() > 0) {
            cout << creature2.getSpecies() << " wins!" << endl;
            break;
        }
        round++;
        cout << "--------------------------------------------------" << endl;
    }
    cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
}