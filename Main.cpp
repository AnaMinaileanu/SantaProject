#include <iostream>
#include <vector>
#include "Toy.h"
#include "ClassicToy.h"
#include "EducativeToy.h"
#include "ElectronicToy.h"
#include "ModernToy.h"
#include "Child.h"
#include "GoodChild.h"
#include "BadChild.h"
#include "DataBase.h"
using namespace std;

int Child::lastid= 1234;

int main() {
    Toy *t = new ModernToy("masina",56, "de curse", "generala", 1, "ferrari", "rosu");
    Toy *t1 = new EducativeToy("carte", 12, "de citit", "citit");
    Toy *t2 = new ElectronicToy("masinuta", 13, "cu telecomanda", 4);
    Toy *t3 = new ClassicToy("leagan", 23, "de leganat", "lemn", "maro");

    Child *c1 = new GoodChild("minaileanu","ana", "strada anina", 13, 11, {t,t1,t1, t2, t3,t2, t1, t3, t2, t1}, 23);
    Child *c2 = new BadChild("ioan", "cosmin", "bucuresti", 16, 1, {t}, 23);

    vector<Child*> v1={c1, c2};

    DataBase d(v1);
    d.menu();
    return 0;
}
