/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Person{
    int id;
    double weight;
    string name;
    public:
    /*Person(){
        id=1, weight=20.5, name="Grace";
    }
        
    Person(int id, string name){
        this->id = id, this->name = name, weight = 20.5;
    }
    
    Person(int id, string name, int weight){
        this->id = id, this->name = name, this->weight = weight;
    }*/
    void show(){
        cout << id << ' ' << weight << ' ' << name << endl;
    }
    Person(int id=1, string name="Grace", double weight=20.5){
        this->id = id, this->name = name, this->weight = weight;
    }
};


int main()
{
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
    return 0;
}
