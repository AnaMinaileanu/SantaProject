#include <iostream>
using namespace std;

class Toy{
protected:
    string namet;
    float volume;
    string type;

public:
    Toy(string namet="", float volume=0, string type="");
    Toy(Toy &j);

    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out);

    friend istream& operator>>(istream &in, Toy &j);
    friend ostream& operator<<(ostream &out, Toy &j);

};