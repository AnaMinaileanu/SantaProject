#include "ClassicToy.h"

    ClassicToy::ClassicToy(string namet="", float volume=0, string type="", string material="", string colour="")
            : Toy(namet, volume, type),material(material), colour(colour){}

    istream& ClassicToy::read(istream& in){
        Toy::read(in);
        cout<<"The material of the toy is: ";
        in>>material;
        cout<<"The colour of the toy is: ";
        in>>colour;
        cout<<"\n";
        return in;
    }

    ostream& ClassicToy::write(ostream& out){
        Toy::write(out);
        out<<"The material of the toy is: "<<material<<"\n";
        out<<"The colour of the toy is: "<<colour<<"\n";
        return out;
    }

