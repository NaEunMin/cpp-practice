/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

  Statistics(int size=0){  ------>>>>> 생성자로 size를 디폴트 매개변수로 주는 디테일. (size는 언제든지 증가할 수 있다.)
        this->size = size;
        stat_Array = new int[size];
    }

    bool operator !(){ -----> 아까 디폴트매개변수로 size=0 이므로 배열의 크기가 0이므로 비어있는 상태.
        if(size==0)
        return true;
        else
        return false;
    }

연산자 함수를 함수중복으로 작성했는데 알고보니 위 주석 달아놓은 것처럼 사실 정수를 인수로 넘겨주는 것이라 함수1개가 쓸모가 없었다.

*/

#include <iostream>

using namespace std;

class Statistics{
    int *stat_Array;
    int size;
    public:
    Statistics(int size=0){
        this->size = size;
        stat_Array = new int[size];
    }
    
    ~Statistics(){
        delete [] stat_Array;
    }
    
    Statistics& operator << (int num){  //main문에서 stat<<x[i]인데 for문 안에 x[i]가 있으므로 사실 int형 정수를 인수로 넘겨주는 것이다.
        size += 1;
        stat_Array[size-1] = num;
        return *this;
    }
    
    bool operator !(){
        if(size==0)
        return true;
        else
        return false;
    }
    
    void operator ~(){
        for(int i=0; i<size; i++){
            cout << stat_Array[i] << ' ';
        }
        cout << endl;
    }
    
    int operator >>(int& avg){
        int sum=0;
        for(int i=0; i<size; i++){
            sum += stat_Array[i];
        }
        avg = sum / size;
        return avg;
    }
    
};

int main()
{
Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

	int x[5];
	cout << "5개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;

    return 0;
}
