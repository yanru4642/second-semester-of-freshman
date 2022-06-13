#include <iostream>
#include "sciencestudent.h"
using namespace std;

int main() {
    ScienceStudent a("Amy","NUTN",101,"CSIE","Calculus");
    ScienceStudent b=a;
    ScienceStudent c(b);
    a.output();
    b.output();
    c.output();

    system("pause");
    return 0;
}