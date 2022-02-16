
#include "EducativeToy.h"
#include "ElectronicToy.h"
#include <iostream>
using namespace std;

class ModernToy: public EducativeToy, public ElectronicToy{
private:
    string brand;
    string model;
public:
    ModernToy(string namet="", float volume=0, string type="", string ability="generala", int nrbaterii=1, string brand="", string model="" );

    istream& read(istream& in);

    ostream& write(ostream& out);

};