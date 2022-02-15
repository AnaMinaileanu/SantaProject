#include "Child.h"
#include <iostream>
using namespace std;

class GoodChild : public Child{

private:
    int sweetsNo;

public:
    GoodChild(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}, int sweetsNo=0);

    istream& read(istream &in);
    ostream& write(ostream &out);
};