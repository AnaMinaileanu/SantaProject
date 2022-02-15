\
#include "DataBase.h"

    DataBase::DataBase(vector<Child*> childrenlist={}) : childrenlist(childrenlist){}
    ostream &operator<<(ostream &out, DataBase &b){
        for(auto i: b.childrenlist){
            out<<i<<endl;
        }
        return out;
    }

    void DataBase::addnChildren(){
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

    void DataBase::displayChildren(){
        for(auto i: childrenlist){
            cout<<*i<<"\n"<<"\n";
        }
    }

    void DataBase::addChild(){
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

    void DataBase::addToytoChild(){
        int cid;
        cout<<"Input the ID of the child you want to add the toy to: ";
        cin>>cid;
        for(auto i: childrenlist){
            if(cid == i->getId())
                i->addToy();
        }
    }

    void DataBase::findChildbyName(){
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

    void DataBase::findChildbyID(){
        int cid;
        cout<<"Input the ID of the child you want to find in the database: ";
        cin >> cid;
        for(auto i: childrenlist){
            if(i->getId() == cid)
                cout<<*i;
        }
    }
    void DataBase::orderbyAge(){
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

    void DataBase::orderbyGoodDeeds(){
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

    int DataBase::gettoyType(Toy *t){
        if(dynamic_cast<ClassicToy*>(t) != nullptr)
            return 1;
        if(dynamic_cast<ModernToy*>(t) != nullptr)
            return 4;
        if(dynamic_cast<EducativeToy*>(t) != nullptr)
            return 2;
        if(dynamic_cast<ElectronicToy*>(t) != nullptr)
            return 3;

    }

    void DataBase::toyStatistic(){
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

    void DataBase::menu() {
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
