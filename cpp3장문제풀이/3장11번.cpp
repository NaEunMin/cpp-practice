/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

Box.h와 Box.cpp코드를 밑에 주석으로 해놓았음.

*/

#include <iostream>

using namespace std;

#include "Box.h"
int main()
{
    Box b(10,2);
    b.draw();
    cout << endl;
    b.setSize(7, 4);
    b.setFill('^');
    b.draw();

    return 0;
}
/*Box.h파일
class Box{ 
    int width, height;
    char fill;
    public:
    Box(int w, int h){
        setSize(w,h);
        fill = '*';
    }
    
    void setFill(char f){
        fill = f;
    }
    
    void setSize(int w, int h){
        width = w;
        height = h;
    }
    
    void draw();
};
*/

/* Box.cpp파일
#include <iostream>
using namespace std;

#include "Box.h"

void Box::draw(){
    for(int n=0; n<height;n++)
    {
        for(int m=0; m<width; m++)
        {
            cout << fill;
        }
        cout << endl;
    }
}*/
