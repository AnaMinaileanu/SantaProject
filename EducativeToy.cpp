#include "EducativeToy.h"

    EducativeToy::EducativeToy(string namet="", float volume=0, string type="", string ability=""):
            Toy(namet, volume, type), ability(ability){}

    istream& EducativeToy::read(istream& in){
        Toy::read(in);
        cout<<"The ability the toy develops is: ";
        in>>ability;
        cout<<"\n";
        return in;
    }

    ostream& EducativeToy::write(ostream& out){
        Toy::write(out);
        out<<"The ability the toy develops is: "<<ability<<"\n";
        return out;
    }
