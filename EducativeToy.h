#include "Toy.h"
#include <iostream>
using namespace std;

class EducativeToy: virtual public Toy{
protected:
    string ability;
public:
    EducativeToy(string namet="", float volume=0, string type="", string ability="");

    istream& read(istream& in);

    ostream& write(ostream& out);
};