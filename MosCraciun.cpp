#include <iostream>
#include <vector>
using namespace std;

class Toy{
protected:
    string namet;
    float volume;
    string type;
public:
    Toy(string namet="", float volume=0, string type="") : namet(namet), volume(volume), type(type){}
    Toy(Toy &j): Toy(j.namet, j.volume, j.type){}

    virtual istream& read(istream& in){
        cout<<"The name of the toy: ";
        in>>namet;
        cout<<"The volume of the toy: ";
        in>>volume;
        cout<<"The type of toy: ";
        in>>type;
        return in;

    }
    virtual ostream& write(ostream& out){
        out<<"The name of the toy is: "<<namet<<"\n";
        out<<"The volume of the toy is: "<<volume<<"\n";
        out<<"The type of toy is: "<<type<<"\n";
        return out;
    }

    friend istream& operator>>(istream &in, Toy &j){
        j.read(in);
        return in;
    }
    friend ostream& operator<<(ostream &out, Toy &j){
        j.write(out);
        return out;
    }


};
class ClassicToy: public Toy{
private:
    string material;
    string colour;
public:
    ClassicToy(string namet="", float volume=0, string type="", string material="", string colour="")
            : Toy(namet, volume, type),material(material), colour(colour){}

    istream& read(istream& in){
        Toy::read(in);
        cout<<"The material of the toy is: ";
        in>>material;
        cout<<"The colour of the toy is: ";
        in>>colour;
        cout<<"\n";
        return in;
    }

    ostream& write(ostream& out){
        Toy::write(out);
        out<<"The material of the toy is: "<<material<<"\n";
        out<<"The colour of the toy is: "<<colour<<"\n";
        return out;
    }

};


class EducativeToy: virtual public Toy{
protected:
    string ability;
public:
    EducativeToy(string namet="", float volume=0, string type="", string ability=""):
            Toy(namet, volume, type), ability(ability){}

    istream& read(istream& in){
        Toy::read(in);
        cout<<"The ability the toy develops is: ";
        in>>ability;
        cout<<"\n";
        return in;
    }

    ostream& write(ostream& out){
        Toy::write(out);
        out<<"The ability the toy develops is: "<<ability<<"\n";
        return out;
    }
};

class ElectronicToy: virtual public Toy{
protected:
    int bateriesNo;
public:
    ElectronicToy(string namet="", float volume=0, string type="", int bateriesNo=0):
            Toy(namet, volume, type), bateriesNo(bateriesNo) {}

    istream& read(istream& in){
        Toy::read(in);
        cout<<"The number of bateries required: ";
        in>>bateriesNo;
        cout<<"\n";
        return in;
    }

    ostream& write(ostream& out){
        Toy::write(out);
        out<<"The number of bateries required: "<<bateriesNo<<"\n";
        return out;
    }
};

class ModernToy: public EducativeToy, public ElectronicToy{
private:
    string brand;
    string model;
public:
    ModernToy(string namet="", float volume=0, string type="", string ability="generala", int nrbaterii=1, string brand="", string model="" ):
            Toy(namet, volume, type), brand (brand), model(model)
            {
                this->ability = "generala";
                this->bateriesNo= 1;
            }

    istream& read(istream& in){
        Toy::read(in);
        cout<<"The brand of the toy: ";
        in>>brand;
        cout<<"The model of the toy: ";
        in>>model;
        cout<<"\n";
        return in;
    }

    ostream& write(ostream& out){
        Toy::write(out);
        out<<"The ability the toy develops is: "<<ability<<"\n";
        out<<"The number of bateries required: "<<bateriesNo<<"\n";
        out<<"The brand of the toy is: "<<brand<<"\n";
        out<<"The model of the toy is: "<<model<<"\n";
        return out;
    }

};

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

    void addToy(){
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

    virtual istream &read(istream &in){
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

    virtual ostream& write(ostream &out){
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

    friend istream& operator>>(istream &in, Child &c){
        c.read(in);
        return in;
    }

    friend ostream& operator<<(ostream &out, Child &c){
        c.write(out);
        return out;

    }

};
int Child::lastid= 1234;

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


class GoodChild : public Child{
private:
    int sweetsNo;
public:
    GoodChild(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}, int sweetsNo=0):
            Child(surname, name, adress, age, goodDeedsNo, listofToys), sweetsNo(sweetsNo){}


    istream& read(istream &in){
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
        }

        cout << "The child's list of toys: ";
        for(int i=0; i<goodDeedsNo;i++){
            addToy();
        }


        cout<< "The child number of sweets: ";
        in>>sweetsNo;
        return in;
    }


    ostream& write(ostream &out){
        Child::write(out);
        out<< "The child number of sweets is: "<<sweetsNo;
        return out;
    }
};

class BadChild : public Child{
private:
    int coalNo;
public:
    BadChild(string surname="", string name="", string adress="", int age=0, int goodDeedsNo=0, vector<Toy*> listofToys={}, int coalNo=0):
            Child(surname, name, adress, age, goodDeedsNo, listofToys), coalNo(coalNo){}

    istream& read(istream& in){
        Child::read(in);
        cout<<"Nr. carbuni: ";
        in >> coalNo;
        cout<<"\n";
        return in;
    }
    ostream& write(ostream& out){
        Child::write(out);
        out<< "The child number of sweets is: "<<coalNo<<"\n";
        return out;
    }
};


class DataBase{
private:
    vector<Child*> childrenlist;
public:
    DataBase(vector<Child*> childrenlist={}) : childrenlist(childrenlist){}
    friend ostream &operator<<(ostream &out, DataBase &b){
        for(auto i: b.childrenlist){
            out<<i<<endl;
        }
        return out;
    }

    void addnChildren(){
        cout<<"Input the number of children you want to add: "<<"\n";
        int childrenNo;
        cin>>childrenNo;
        for(int i=0; i<childrenNo; i++){

            cout<<"Choose whether the child is good or bad. Input 0 for good and 1 for bad: ";
            bool goodbad;
            cin>>goodbad;
            Child *kid;
            if(goodbad == 0){
                kid = new GoodChild;
                cin >> *kid;
            }
            else
                if(goodbad == 1){
                    kid = new BadChild;
                    cin >> *kid;
                }

            childrenlist.push_back(kid);
        }
    }

    void displayChildren(){
        for(auto i: childrenlist){
            cout<<*i<<"\n"<<"\n";
        }
    }

    void addChild(){
        cout<<"Choose whether the child is good or bad. Input 0 for good and 1 for bad: ";
        bool goodbad;
        cin>>goodbad;
        Child *kid;
        if(goodbad == 0){
            kid = new GoodChild;
            cin >> *kid;
        }
        else
        if(goodbad == 1){
            kid = new BadChild;
            cin >> *kid;
        }
        childrenlist.push_back(kid);
    }

    void addToytoChild(){
        int cid;
        cout<<"Input the ID of the child you want to add the toy to: ";
        cin>>cid;
        for(auto i: childrenlist){
            if(cid == i->getId())
                i->addToy();
        }
    }

    void findChildbyName(){
        string cname, csurname;
        cout<<"Input the name of the child you want to find in the database: ";
        cin>>cname;
        cout<<"Input the surname of the child you want to find in the database: ";
        cin>>csurname;
        for(auto i: childrenlist){
            if(i->getName() == cname && i->getSurname() == csurname) {
                cout << "da";
                cout << *i << endl;
            }
        }
    }

    void findChildbyID(){
        int cid;
        cout<<"Input the ID of the child you want to find in the database: ";
        cin >> cid;
        for(auto i: childrenlist){
            if(i->getId() == cid)
                cout<<*i;
        }
    }
    void orderbyAge(){
        for(int i=0; i<childrenlist.size()-1; i++)
            for(int j=1; j<childrenlist.size(); j++)
                if(childrenlist[i]->getAge() > childrenlist[j]->getAge())
                {
                    auto aux = childrenlist[i];
                    childrenlist[i] = childrenlist[j];
                    childrenlist[j] = aux;
                }
        displayChildren();
    }

    void orderbyGoodDeeds(){
        for(int i=0; i<childrenlist.size()-1; i++)
            for(int j=1; j<childrenlist.size(); j++)
                if(childrenlist[i]->getGoodDeedsNo() > childrenlist[j]->getGoodDeedsNo())
                {
                    auto aux = childrenlist[i];
                    childrenlist[i] = childrenlist[j];
                    childrenlist[j] = aux;
                }
        displayChildren();
    }

    int gettoyType(Toy *t){
        if(dynamic_cast<ClassicToy*>(t) != nullptr)
            return 1;
        if(dynamic_cast<ModernToy*>(t) != nullptr)
            return 4;
        if(dynamic_cast<EducativeToy*>(t) != nullptr)
            return 2;
        if(dynamic_cast<ElectronicToy*>(t) != nullptr)
            return 3;

    }

    void toyStatistic(){
        int classic=0, educative=0, electronic=0, modern=0;
        for(auto i: childrenlist){
            for(auto j: i->getListofToys()) {
                int type = gettoyType(j);
                if(type == 1)
                    classic++;
                else
                    if(type == 2)
                        educative++;
                    else
                        if(type == 3)
                            electronic++;
                        else
                            if(type == 4)
                                modern++;
            }
        }

        cout<<"The total number of toys Santa gifted was "<<classic+educative+electronic+modern<<"."<<"\n";
        cout<<"Out of the total, there were "<<classic<<" classic toys, "<<educative<<" educative toys, "<<electronic<<" electronic toys ";
        cout<<"and "<<modern<<"modern toys."<<"\n";

    }

    void menu() {
        while (true) {
            int input;
            cout << "The soft can perform the following task:" << "\n";
            cout << "1: Add n children, along with their toys, to the database whether they are good or bad" << "\n";
            cout << "2: Display all children, along with their toys, whether they are good or bad" << "\n";
            cout << "3: Add a new child" << "\n";
            cout << "4: Add a new toy to a specific child" << "\n";
            cout << "5: Find a child by name&surname and write their data" << "\n";
            cout << "6: Find a child by ID and write their data" << "\n";
            cout << "7: Order the children by their age" << "\n";
            cout << "8: Order the children by their number of good deeds" << "\n";
            cout << "9: Display a statistic of all the toys Santa gifted" << "\n";
            cout << "10: Exit the database" << "\n";
            cout << "Choose a task you want to perform out of the preceding 9" << "\n";
            cout << "Your chosen task is: ";
            cin >> input;
            cout << input << "\n";
            if (input == 1) {
                addnChildren();
            } else if (input == 2)
                displayChildren();
            else if (input == 3)
                addChild();
            else if (input == 4)
                addToytoChild();
            else if (input == 5)
                findChildbyName();
            else if (input == 6)
                findChildbyID();
            else if (input == 7)
                orderbyAge();
            else if (input == 8)
                orderbyGoodDeeds();
            else if (input == 9)
                toyStatistic();
            else if (input == 10)
                break;
            cout<<"\n";
        }
    }
};


int main() {
    Toy *t = new ModernToy("masina",56, "de curse", "generala", 1, "ferrari", "rosu");
    Toy *t1 = new EducativeToy("carte", 12, "de citit", "citit");
    Toy *t2 = new ElectronicToy("masinuta", 13, "cu telecomanda", 4);
    Toy *t3 = new ClassicToy("leagan", 23, "de leganat", "lemn", "maro");

    Child *c1 = new GoodChild("minaileanu","ana", "strada anina", 13, 11, {t,t1,t1, t2, t3,t2, t1, t3, t2, t1}, 23);
    Child *c2 = new BadChild("ioan", "cosmin", "bucuresti", 16, 1, {t}, 23);

    vector<Child*> v1={c1, c2};

    DataBase d(v1);
    d.menu();
    return 0;
}
