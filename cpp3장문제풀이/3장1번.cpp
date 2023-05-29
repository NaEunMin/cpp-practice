/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Tower{
    private:
    int height;
    
    public:
    Tower();
    Tower(int i);
    int getHeight();
};

Tower::Tower(){
    height = 1;
}

Tower::Tower(int i){
    height = i;
}

int Tower::getHeight(){
   return height;
}
int main()
{
    Tower myTower; //1미터
    Tower seoulTower(100); //100미터
    cout << "높이는" << myTower.getHeight() << "미터" << '\n';
    cout << "높이는" << seoulTower.getHeight() << "미터" << '\n';

    return 0;
}
