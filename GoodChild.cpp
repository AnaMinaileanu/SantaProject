#include "GoodChild.h"

    GoodChild::GoodChild(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}, int sweetsNo=0):
            Child(surname, name, adress, age, goodDeedsNo, listofToys), sweetsNo(sweetsNo){}


    istream& GoodChild::read(istream &in){
        cout << "The surname of the child: ";
        in >> surname;
        cout << "The name of the child: ";
        in >> name;
        cout << "The adress of the child: ";
        in >> adress;
        cout << "The age of the child: ";
        in >> age;
        while(true){
            cout << "The number of good deeds of the child: ";
            in >> goodDeedsNo;
            if(goodDeedsNo<10) {
                cout<<"Add the number of good deeds again(it has to be >=10): ";
                in >> goodDeedsNo;
            }
            else
                break;
        }        cout << "The child's list of toys: ";
        for(int i=0; i<goodDeedsNo;i++){
            addToy();
        }
        cout<< "The child number of sweets: ";
        in>>sweetsNo;
        return in;
    }


    ostream& GoodChild::write(ostream &out){
        Child::write(out);
        out<< "The child number of sweets is: "<<sweetsNo;
        return out;
    }
