#include "BadChild.h"


    BadChild::BadChild(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}, int coalNo=0):
            Child(surname, name, adress, age, goodDeedsNo, listofToys), coalNo(coalNo){}

    istream& BadChild::read(istream& in){
        Child::read(in);
        cout<<"Nr. carbuni: ";
        in >> coalNo;
        cout<<"\n";
        return in;
    }
    ostream& BadChild::write(ostream& out){
        Child::write(out);
        out<< "The child number of sweets is: "<<coalNo<<"\n";
        return out;
    }

