/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

*** 삽입 파트 ***
9장에서 이 문제를 풀때--> 연결 리스트의 처음에 객체를 삽입할때 or 아닐때를 구분하여 코드를 작성
vector 사용 ----> 가변 리스트 이므로 스스로 사이즈를 늘리고 앞에서부터 알아서 넣기때문에 위와 같은 구분이 필요없음.

*** 삭제 파트 ***
9장에서 이 문제를 풀때--> 삭제할 원소 다음의 주소을 미리 삭제할 원소 앞의 원소에 연결해주고 삭제하는 구조
vector 사용 ----> erase()함수가 알아서 삭제후 원소들을 앞으로 이동시켜주어 위와 같은 코드를 작성하지 않아도됨.

        for(int i=0; i<index-1; i++){ // index-1을 해준 이유는 index만 하게되면 도형들을 출력할때 1부터해주어서 1인덱스 삭제한다고 하면 첫도형을 삭제해야하는데 vector의 인덱스1원소를 삭제하기 때문에 -1을 해줌.
            it++; // 삭제할 인덱스까지 it의 주소를 for문으로 전진해줌. ---> iterator it을 사용하는 이유가 vector의 원소를 순차적으로 접근하기 위함.
        }
        Shape *p = *it;  //이 코드는 객체 삭제 후 객체 delete를 위해 존재
        it = v.erase(it);
        delete p;
    }

*/

#include <iostream>
#include <vector>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rectangle : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI {
    public:
    static int getMenu(){
        int menu;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
        cin >> menu;
        return menu;
    }
    static int getShapeType(){
        int shapetype;
        cout << "선:1, 원:2, 사각형:3>>";
        cin >> shapetype;
        return shapetype;
    }
    static int getDeleteShape(){
        int deleteshape;
        cout << "삭제하고자 하는 도형의 인덱스>>";
        cin >> deleteshape;
        return deleteshape;
    }

};

class GraphicEditor {
    Shape *pStart;
    Shape *pLast;
    int node_size;
    vector<Shape*>v;
    public:
    GraphicEditor(){ 
        pStart = NULL;
        node_size = 0;
    }
    int run(){
        cout << "그래픽 에디터입니다." << endl;
    while(true){
    int menuNumber = UI::getMenu();
    if(menuNumber==1){ //삽입파트
        int shapetypeNumber = UI::getShapeType();
        if(shapetypeNumber==1){
            v.push_back(new Line());
        }
        else if(shapetypeNumber==2){
            v.push_back(new Circle());
        }
        else if(shapetypeNumber==3){
            v.push_back(new Rectangle());
        }
    }
    else if(menuNumber==2){ //삭제파트
        int index = UI::getDeleteShape();
        vector<Shape*>::iterator it = v.begin();
        for(int i=0; i<index-1; i++){
            it++;
        }
        Shape *p = *it; //이 코드는 객체 삭제 후 객체 delete를 위해 존재
        it = v.erase(it);
        delete p;
    }
    else if(menuNumber==3){ //모두보기 파트
        for(int i=0; i<v.size(); i++){
            cout << i+1 << ":";
            v[i]->paint();
        }
    }
    else if(menuNumber==4){
        return 0;
    }
}
    } //run함수
};


int main(){

    GraphicEditor* GE = new GraphicEditor();
    GE->run();
    delete GE;
    return 0;
}
