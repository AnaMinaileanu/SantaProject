#include "Child.h"
#include <iostream>
#include <vector>
#include "BadChild.h"
#include "GoodChild.h"
using namespace std;

class DataBase{
private:
    vector<Child*> childrenlist;
public:
    DataBase(vector<Child*> childrenlist={});

    friend ostream &operator<<(ostream &out, DataBase &b);

    void addnChildren();

    void displayChildren();

    void addChild();

    void addToytoChild();

    void findChildbyName();

    void findChildbyID();

    void orderbyAge();

    void orderbyGoodDeeds();

    int gettoyType(Toy *t);

    void toyStatistic();

    void menu();
};