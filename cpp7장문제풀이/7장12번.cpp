/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

문제이해도가 낮아서 쉽게 풀 수 없었던 문제.  이 문제에 복사생성자, 동적생성, 연산자중복, 알고리즘 등 다양한 개념이 녹아있으니 다음에 또 봐주면 좋을듯함.
복사생성자를 까먹었다. ----> 코드를 보면서 감을 살리자.

c = a + b에서 (+연산자함수)작성시 왜 tmp를 쓰냐면 a객체의 배열에다 b를 붙여서 리턴을 한다면 a원본을 손상시켜야한다. 
그러면 a.show() 호출하고 결과가 a객체의 배열은 a+b배열의 결과가 나올 것이다. 
그걸 방지하기 위해 tmp를 써서 tmp의 배열에다가 a+b 붙인다음 tmp를 리턴해주는 것이다. 이 내용은 책의 연산자중복 파트를 다시보면 알 수 있을 것이다.

(=연산자 함수)는  코드 전체적인 구조로 보면 사실상 c = tmp인 셈이다. 그래서 c객체에다가 tmp객체를 복사하고 c인 *this로 리턴을 해주는 것이다. 
(c=tmp)에서 연산자함수로 넘어가면 매개변수는 tmp, this는 c가 된다.

그리고 p가 포인터라 this도 포인터니까 this->p 이런거 안될줄 알았는데 알고보니 된다. 즉 this->p[i] 이런 것도 된다.

sort에서는 tmp를 사용해서 인덱스를 차례로 비교하는 것이다. 
예를 들어 p[0]과 p[1]을 비교하면 p[0]>p[1]이라고 해보자.  tmp=p[0]해주고 p[0]=p[1]로 p[0]위치에 p[1]을 넣어주고 p[1]위치에 tmp를 넣어주는 구조이다.

이 문제 진짜 좋다. 나중에 중간중간에 봐주자

*/

#include <iostream>

using namespace std;

class SortedArray{
    int size;
    int *p;
    void sort();
    public:
    SortedArray(){
        size=0, p=NULL;
    }
    
    SortedArray(SortedArray& src){
        this->size = src.size;
        this->p = new int [size];
        for(int i=0; i<size; i++){
            this->p[i] = src.p[i];
        }
        sort();
    }
    
    SortedArray(int p[], int size){
        this->size = size;
        this->p = new int [size];
        for(int i=0; i<size; i++){
            this->p[i] = p[i];
        }
        sort();
    }
    
    ~SortedArray(){delete [] p;}
    
    SortedArray operator + (SortedArray& op2){
        SortedArray tmp;
        tmp.size = size + op2.size;
        tmp.p = new int [tmp.size];
        
        for(int i=0; i<size; i++){
            tmp.p[i] = p[i];
        }
        
        for(int i=3; i<tmp.size; i++){ 
            tmp.p[i] = op2.p[i-3];
        }
        
        sort();
        
        return tmp;
    }
    
    SortedArray& operator = (const SortedArray& op2){
    delete [] p;
    this->size = op2.size;
    this-> p = new int[this->size];
    for(int i=0; i<this->size; i++){
        this->p[i] = op2.p[i];
    }
    sort();
    
    return *this;
}
    
    void show(){
        cout << "배열 출력 : ";
        for(int i=0; i<size; i++){
            cout << p[i] << ' ';
        }
        cout << endl;
    }
};

void SortedArray::sort(){
    int tmp;
    for(int i=0; i<size-1; i++){
    if(p[i] > p[i+1]){
    tmp = p[i];
    p[i] = p[i+1];
    p[i+1] = tmp;
    }
    }
}

int main()
{
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};
    SortedArray a(n,3), b(m,4), c;
    
    c = a + b;
    
    a.show();
    b.show();
    c.show();
    
    return 0;
}
