
#include "ElectronicToy.h"

    ElectronicToy::ElectronicToy(string namet="", float volume=0, string type="", int bateriesNo=0):
            Toy(namet, volume, type), bateriesNo(bateriesNo) {}

    istream& ElectronicToy::read(istream& in){
        Toy::read(in);
        cout<<"The number of bateries required: ";
        in>>bateriesNo;
        cout<<"\n";
        return in;
    }

    ostream& ElectronicToy::write(ostream& out){
        Toy::write(out);
        out<<"The number of bateries required: "<<bateriesNo<<"\n";
        return out;
    }
