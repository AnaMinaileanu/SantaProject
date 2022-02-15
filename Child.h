#include <iostream>
using namespace std;
#include "Toy.h"
#include <vector>
#include "ClassicToy.h"
#include "EducativeToy.h"
#include "ElectronicToy.h"
#include "ModernToy.h"

class Child{
    
protected:
    static int lastid;
    int id;
    string surname;
    string name;
    string adress;
    int age;
    int goodDeedsNo;
    vector<Toy*> listofToys;

public:
    Child(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}) :
            id(lastid++), surname(surname), name(name), adress(adress), age(age), goodDeedsNo(goodDeedsNo), listofToys(listofToys){}

    int getId() const;

    int getGoodDeedsNo() const;

    int getAge() const;

    const string &getSurname() const;

    const string &getName() const;

    const vector<Toy*> &getListofToys() const;

    void addToy();

    virtual istream &read(istream &in);

    virtual ostream& write(ostream &out);

    friend istream& operator>>(istream &in, Child &c);

    friend ostream& operator<<(ostream &out, Child &c);

};