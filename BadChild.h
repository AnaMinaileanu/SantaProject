#include "Child.h"
#include <iostream>
using namespace std;

class BadChild : public Child{

private:
    int coalNo;
public:
    BadChild(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}, int coalNo=0);
    
    istream& read(istream& in);
    ostream& write(ostream& out);
};
