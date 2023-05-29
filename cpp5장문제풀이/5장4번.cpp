/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

bool bigger(int a, int b, int &big){
  if(a==b)
  return true;
  else{
  if(a>b)
  big=a;
  else
  big=b;
  return false;
  }
  

}

int main()
{
    int a,b,big;
    cin >> a >> b;
    
    if(bigger(a,b,big))
    cout << "두 수가 같습니다.";
    else
    cout << "두 수중 큰 수는 " << big;

    return 0;
}
