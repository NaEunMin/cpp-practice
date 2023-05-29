/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

이제 어떤 상황에서 어떤 매개변수에 참조매개변수를 사용해야할지 감이 오는듯 하다.
더 많은 상황들을 접해봐야 할 것 같다.

*/

#include <iostream>

using namespace std;

class Matrix{
    int num1, num2, num3, num4;
    public:

    Matrix(int num1=0, int num2=0, int num3=0, int num4=0){
        this->num1 = num1;
        this->num2 = num2;
        this->num3 = num3;
        this->num4 = num4;
    }
    /* 클래스 함수 구현******************
    Matrix operator + (Matrix op){
        Matrix tmp;
        tmp.num1 = this->num1 + op.num1;
        tmp.num2 = this->num2 + op.num2;
        tmp.num3 = this->num3 + op.num3;
        tmp.num4 = this->num4 + op.num4;
        
        return tmp;
    }
    
    Matrix& operator += (Matrix op){
        this->num1 += op.num1;
        this->num2 += op.num2;
        this->num3 += op.num3;
        this->num4 += op.num4;
        
        return *this;
    }
    
    bool operator == (Matrix op){
        if(this->num1 == op.num1 && this->num2 == op.num2 && this->num3 == op.num3 &&
        this->num4 == op.num4){
            return true;
        }
        else
        return false;
    }*/
    
    void show(){
        cout<< "Matrix" << '{' << num1 << ' ' << num2 << ' ' << num3 << ' ' << num4 << '}' << endl;
    }
    
    friend Matrix operator + (Matrix op1, Matrix op2);
    friend Matrix& operator += (Matrix &op1, Matrix op2);
    friend bool operator == (Matrix op1, Matrix op2);
};

Matrix operator + (Matrix op1, Matrix op2){
    Matrix tmp;
    tmp.num1 = op1.num1 + op2.num1;
    tmp.num2 = op1.num2 + op2.num2;
    tmp.num3 = op1.num3 + op2.num3;
    tmp.num4 = op1.num4 + op2.num4;
        
    return tmp;
}

Matrix& operator += (Matrix &op1, Matrix op2){
    op1.num1 += op2.num1;
    op1.num2 += op2.num2;
    op1.num3 += op2.num3;
    op1.num4 += op2.num4;
        
    return op1; 
}

bool operator == (Matrix op1, Matrix op2){
    if(op1.num1 == op2.num1 && op1.num2 == op2.num2 && op1.num3 == op2.num3 &&
        op1.num4 == op2.num4){
            return true;
    }
    else
    return false;
    
}

int main()
{
    Matrix a(1,2,3,4), b(2,3,4,5), c;
    c = a + b;
    a += b;
    a.show();
    b.show();
    c.show();
    if(a == c)
    cout << "a and c are the same" << endl;

    return 0;
}
