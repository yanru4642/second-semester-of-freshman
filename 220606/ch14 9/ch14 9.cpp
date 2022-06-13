#include <iostream>
#include <ctime>
#include <string>
#include "human.h"
#include "cyberdemon.h"
#include "balrog.h"
#include "elf.h"
using namespace std;

int main() {
    srand(time(NULL));
    //0 human, 1 cyberdemon, 2 balrog, 3 elf
    Human h(100, 100);
    Cyberdemon c(50, 50);
    Balrog b(40, 40);
    Elf e(75, 75);
    string again;
    do
    {
        cout << "-------------------------------" << endl;
        cout << h.getSpecies() << ": " << h.getDamage() << endl;
        cout << c.getSpecies() << ": " << c.getDamage() << endl;
        cout << b.getSpecies() << ": " << b.getDamage() << endl;
        cout << e.getSpecies() << ": " << e.getDamage() << endl;
        cout << "\nEnter 'y' to get damage again, escape otherwise> ";
        getline(cin, again);
    } while (again == "y");
    
    system("pause");
    return 0;
}