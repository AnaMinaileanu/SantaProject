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
    
    Toy *t = new ModernToy("car",56, "racing", "general", 1, "ferrari", "red");
    Toy *t1 = new EducativeToy("book", 12, "fantasy", "reading");
    Toy *t2 = new ElectronicToy("car", 13, "remote-control", 4);
    Toy *t3 = new ClassicToy("horse", 23, "swinging", "wood", "brown");

    Child *c1 = new GoodChild("Smith","John", "Maple Street 11", 13, 11, {t,t1,t1, t2, t3,t2, t1, t3, t2, t1}, 23);
    Child *c2 = new BadChild("Johnson", "Jane", "View Street 6", 16, 1, {t}, 23);

    vector<Child*> v1={c1, c2};

    DataBase d(v1);
    d.menu();
    return 0;
}
