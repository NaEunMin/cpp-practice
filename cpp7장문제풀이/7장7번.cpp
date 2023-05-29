/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

'>>'연산자 함수(외부함수) 구현할때는 바꾸려는 타겟이 main문에 있는 배열이다. 배열의 이름은 곧 포인터이기 때문에 '주소에 의한 호출'로 원본이 바뀐다.
하지만
'<<'연산자 함수(외부함수) 구현할때는 바꾸려는 타겟이 Matrix의 객체 b의 배열이다. main문에 있는 객체를 바꾸려면 복사본이 아닌 원본에 접근해야하기에
'참조에 의한 호출'을 사용해주어야한다.

그리고 클래스멤버함수 코드를 보면 알겠지만 내가 잘못 생각한 부분이 있다. 바로 '값,주소,참조에 의한 호출'은 매개변수를 통해서 이루어진다 는 것이다.
리턴값으로 이루어지는게 아니다. 근데 저렇게 리턴타입 정해서 리턴해줘도 문제는 풀린다.

*/

#include <iostream>

using namespace std;

class Matrix{
    int Num_array[4];
    public:
    Matrix(int num1=0, int num2=0, int num3=0, int num4=0){
        Num_array[0]=num1;
        Num_array[1]=num2;
        Num_array[2]=num3;
        Num_array[3]=num4;
    }
    void show(){
        cout << "Matrix = { ";
        for(int i=0; i<4; i++){
            cout << Num_array[i] << ' ';
        }
        cout << '}';
    }
    /* 클래스 멤버함수 구현 ******************
    int* operator >> (int x[4]){
        for(int i=0; i<4; i++){
            x[i] = Num_array[i];
        }
        return x;
    }
    
    Matrix& operator << (int x[4]){
        for(int i=0; i<4; i++){
            Num_array[i] = x[i];
        }
        return *this;
    }*/
    
    friend void operator >> (Matrix op, int x[4]);
    friend void operator << (Matrix &op, int x[4]);

};

void operator >> (Matrix op, int x[4]){
    for(int i=0; i<4; i++){
        x[i] = op.Num_array[i];
    }
}

void operator << (Matrix &op, int x[4]){
    for(int i=0; i<4; i++){
        op.Num_array[i] = x[i];
    }
}

int main()
{
    Matrix a(4,3,2,1), b;
    int x[4], y[4] = {1,2,3,4};
    a >> x;
    b << y;
    
    for(int i=0; i<4; i++){
        cout << x[i] << ' ' ;
    }
    
    cout << endl;
    b.show();

    return 0;
}
