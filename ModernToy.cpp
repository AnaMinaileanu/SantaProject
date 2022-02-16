#include "ModernToy.h"

    ModernToy::ModernToy(string namet="", float volume=0, string type="", string ability="generala", int nrbaterii=1, string brand="", string model="" ):
            Toy(namet, volume, type), brand (brand), model(model)
            {
                this->ability = "generala";
                this->bateriesNo= 1;
            }

    istream& ModernToy::read(istream& in){
        Toy::read(in);
        cout<<"The brand of the toy: ";
        in>>brand;
        cout<<"The model of the toy: ";
        in>>model;
        cout<<"\n";
        return in;
    }

    ostream& ModernToy::write(ostream& out){
        Toy::write(out);
        out<<"The ability the toy develops is: "<<ability<<"\n";
        out<<"The number of bateries required: "<<bateriesNo<<"\n";
        out<<"The brand of the toy is: "<<brand<<"\n";
        out<<"The model of the toy is: "<<model<<"\n";
        return out;
    }
