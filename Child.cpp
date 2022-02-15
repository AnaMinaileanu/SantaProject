#include "Child.h"

    Child::Child(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}) :
            id(lastid++), surname(surname), name(name), adress(adress), age(age), goodDeedsNo(goodDeedsNo), listofToys(listofToys){}

    
int Child::getId() const {
    return id;
}

const vector<Toy *> &Child::getListofToys() const {
    return listofToys;
}

const string &Child::getName() const {
    return name;
}

const string &Child::getSurname() const {
    return surname;
}

int Child::getAge() const {
    return age;
}

int Child::getGoodDeedsNo() const {
    return goodDeedsNo;
}


    void Child::addToy(){
        int input;
        cout<<"Choose the type of toy you want to add(1 for Classic Toy, 2 for Educative Toy, 3 for Electronic Toy, 4 for Modern Toy)";
        cin>>input;
        Toy *newtoy;
        if(input==1){
            newtoy = new ClassicToy;
            cin >> *newtoy;

        }
        else
            if(input==2){
                newtoy = new EducativeToy;
                cin >> *newtoy;

            }
            else
                if(input==3){
                    newtoy = new ElectronicToy;
                    cin >> *newtoy;

                }
                else
                    if(input==4){
                        newtoy = new ModernToy;
                        cin >> *newtoy;

                    }
        listofToys.push_back(newtoy);

    }

     istream & Child::read(istream &in){
        cout << "The surname of the child: ";
        in >> surname;
        cout << "The name of the child: ";
        in >> name;
        cout << "The adress of the child: ";
        in.get();
        getline(in, adress);
        cout << "The age of the child: ";
        in >> age;
        cout << "The number of good deeds of the child: ";
        in >> goodDeedsNo;
        cout << "The child's list of toys: "<<"\n";
        for(int i=0; i<goodDeedsNo;i++){
            addToy();
        }
        return in;
    }
    
    ostream& Child::write(ostream &out){
        out << "Id: "<<id<<"\n";
        out << "The surname of the child is: " << surname << "\n";
        out << "The name of the child is: "<< name << "\n";
        out << "The adress of the child is: " << adress <<"\n";
        out << "The age of the child is: " << age <<"\n";
        out << "The child's number of good deeds is: "<< goodDeedsNo <<"\n";
        out << "The child's list of toys: ";
        int c=0;
        for(auto i: listofToys) {
            if(c!=0)
                out<<"\n";
            out << *i;
            c++;
        }
        return out;

    }

     istream& operator>>(istream &in, Child &c){
        c.read(in);
        return in;
    }

     ostream& operator<<(ostream &out, Child &c){
        c.write(out);
        return out;

    }
