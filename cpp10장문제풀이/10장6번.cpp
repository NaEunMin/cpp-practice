/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

처음에는 minus[0]부터 하나씩 집어서 src배열을 한바퀴씩 돌면서 검사하려고
for(.... sizeMinus...){
   for(....sizeSrc...){}
}
이런 구조로 해봤는데 뭔가 꼬이는 듯하여 두 배열을 바꾸었다.  //sizeSrc와 sizeMinus의 위치를 바꾸었다는 의미이다.

***if(j==sizeMinus)***
위 for문의 검사에서 걸리지않고 끝까지왔다면 j의 값은 sizeMinus와 값이 같아야할 것이다. 이 점을 이용하여 위 if문을 걸고 
tmp[retSize++] = src[i];을 작성했다.
retSize는 main문의 변수를 참조 한 것이다. main문에서 사용해야하기 때문이다.

*/

#include <iostream>

using namespace std;

template <class T>
T *remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize){
    T *tmp = new T[sizeSrc+sizeMinus];
    int i=0;
    int j=0;
    for(i=0; i<sizeSrc; i++){
        for(j=0; j<sizeMinus; j++){
            if(src[i]==minus[j])
            break;
        }
        if(j==sizeMinus) //만약 minus[]검사에서 끝까지 패스했다면
        tmp[retSize++]=src[i]; //tmp에 해당 src원소 대입  retSize는 main에서 참조한 변수이므로 직접 늘려주어야한다.
        
    }
    return tmp;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1,2};
    int retSize = 0;
    int *c = remove(a, 5, b, 2, retSize);
    for(int i=0; i<retSize; i++){
        cout << c[i] << " ";
    }
    return 0;
}
