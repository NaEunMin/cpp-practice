/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

생성자가 있을때는 countPass 매개변수를 참조로 안해주면 되고 생성자 없앨려면 매개변수를 참조로 해주면 됨.
복사생성자 작성할 때 복사하는 객체로 확실하게 복사해주기 무슨 말이냐면
    this->size = dept.size;
    this->scores = new int[dept.size];
    for(int i=0;i<dept.size;i++){
        scores[i]=dept.scores[i];  여기서 자꾸 dept. 이거 빼먹고 코드작성해서 오류가 나왔음. 이런 실수 하지않게 꼼꼼히 코드보기
//포인터의 존재로 디폴트복사생성자가 호출되면 포인터안의 값이 완벽히 복사되지않고 디버깅 돌려보면 음수의 이상한 값이 남아있어 프로그램이 정상적으로 작동하지 않는다.
// 위의 이유로 scores값을 완벽이 for문으로 복사를 해주던가 아니면 함수의 매개변수를 참조로 받아 객체의 전부를 완벽히 넘겨주게 만들어야한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Dept{
  int size;
  int *scores;
  public:
  Dept(int size){
      this->size = size; 
      scores = new int[size];
  }
  
  /*Dept(const Dept &dept){
    this->size = dept.size;
    this->scores = new int[dept.size];
    for(int i=0;i<dept.size;i++){
        scores[i]=dept.scores[i];
      
  }
 }*/ 
  ~Dept(){
      if(scores)
      delete [] scores;
  }
  
  int getSize(){return size;}
  void read();
  bool isOver60(int index);
};

void Dept::read(){
    cout << "10개 정수 입력 >>";
    for(int i=0;i<size;i++){
        cin >> scores[i];
    }
}

bool Dept::isOver60(int index){
    if(scores[index]>60)
    return true;
    else
    return false;
}

int countPass(Dept &dept){
    int count=0;
    for(int i=0; i<dept.getSize(); i++){
        if(dept.isOver60(i))
        count++;
    }
    return count;
}


int main(){
    Dept com(10);
    com.read();
    int n = countPass(com);
    cout << "60점 이상은 " << n << "명";
    return 0;
}
