#include <iostream>
#include "Toy.h"
using namespace std;

    Toy::Toy(string namet="", float volume=0, string type="") : namet(namet), volume(volume), type(type){}
    Toy::Toy(Toy &j): Toy(j.namet, j.volume, j.type){}

     istream& Toy::read(istream& in){
        cout<<"The name of the toy: ";
        in>>namet;
        cout<<"The volume of the toy: ";
        in>>volume;
        cout<<"The type of toy: ";
        in>>type;
        return in;

    }
     ostream& Toy::write(ostream& out){
        out<<"The name of the toy is: "<<namet<<"\n";
        out<<"The volume of the toy is: "<<volume<<"\n";
        out<<"The type of toy is: "<<type<<"\n";
        return out;
    }

     istream& operator>>(istream &in, Toy &j){
        j.read(in);
        return in;
    }
     ostream& operator<<(ostream &out, Toy &j){
        j.write(out);
        return out;
    }

