/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

concat은 방법이 그냥 바로 생각나서했는데 remove는 굉장히 여러가지 방법이 떠올랐는데
배열s1을 처음부터 시작해서 배열s2를 for문으로 돌린다.
배열s1에 해당하는 원소가 배열s2에 있다면 패스, 없다면 removeArray에 s1해당인덱스 저장하는 방식으로 해봄.
문제 풀고 다른 사람들이 푼 코드도 봤는데 느낀건 역시 알고리즘공부할때는 '내가 이해할 수 있는 코드가 먼저다' 라는 생각이 들었다.

*/

#include <iostream>

using namespace std;

class ArrayUtility2{
    public:
    static int* concat(int s1[], int s2[], int size);
    static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size){
    int *addArray = new int[size*2];
    for(int i=0; i<size; i++){
        addArray[i] = s1[i];
    }
    
    for(int i=size; i<size*2; i++){
        addArray[i] = s2[i-5];
    }
    cout<<"합친 정수 배열을 출력한다.\n";
    for(int i=0; i<size*2; i++){
        cout << addArray[i] << ' ';    
    }
    cout << endl;
    return addArray;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize){
    int *removeArray = new int[retSize];
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(s1[i]!=s2[j])
            removeArray[i]=s1[i];
        }
    }
    retSize = sizeof(removeArray)/sizeof(removeArray[0]);
    cout << "배열 x에서 배열 y을 뺀 결과를 출력한다.\n";
    for(int i=0; i<retSize; i++){
        cout << removeArray[i] << " ";
    }
    return removeArray;
}

int main(){
    int s1[5];
    int s2[5];
    int removeSize;
    cout << "정수 5개를 입력하라. 배열 x에 삽입한다.>>";
    for(int i=0; i<5; i++){
        cin >> s1[i];
    }
    
    cout << "정수 5개를 입력하라. 배열 y에 삽입한다.>>";
    for(int i=0; i<5; i++){
        cin >> s2[i];
    }
    
    ArrayUtility2::concat(s1,s2,5);
    ArrayUtility2::remove(s1,s2,5,removeSize);
    return 0;
}


