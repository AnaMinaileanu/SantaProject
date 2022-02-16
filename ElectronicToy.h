#include "Toy.h"
#include <iostream>
using namespace std;

class ElectronicToy: virtual public Toy{
protected:
    int bateriesNo;
public:
    ElectronicToy(string namet="", float volume=0, string type="", int bateriesNo=0);

    istream& read(istream& in);

    ostream& write(ostream& out);
};