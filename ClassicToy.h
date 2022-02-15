#include "Toy.h"
#include<iostream>
using namespace std;
class ClassicToy: public Toy{
private:
    string material;
    string colour;
public:
    ClassicToy(string namet="", float volume=0, string type="", string material="", string colour="");

    istream& read(istream& in);

    ostream& write(ostream& out);

};