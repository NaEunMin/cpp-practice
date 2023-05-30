/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/


/*

자료구조 "링크드리스트"에 대해 잘 알고있어야 해결 할 수 있는 문제. *** 링크드리스트를 처음 접해서 공부하면서 풀었다 ***

*** 링크드리스트 : 삽입 ***
1. Shape *pStart, Shape *pLast를 생성한다. // pStart=링크드리스트의 시작, pLast=링크드리스트의 끝
2. pStart = NULL로 설정해주고 , nodesize = 0 으로 해준다. // 처음에는 첫번째 노드에 뭐가 없기 때문에 아무것도 가르키지 않는 NULL로 설정,  링크드 리스트가 몇개가 연결되어 있는지 알기 위해 초기에는 아무것도 연결되어 있지 않으므로 nodesize=0으로 설정
3-1. nodesize=0일때==> pStart에 설정할 객체를 동적 생성해주고 pLast = pStart 해준다. // 처음으로 생성한 노드이기에 pStart가 곧 pLast일 것이다.
3-2. nodesize>0일때==> pLast에 설정할 객체를 pLast = pLast-> add(new 객체())를 해준다. // add()는 매개변수객체주소를 next에 저장하고 매개변수객체주소를 리턴한다.
Why? ==> 예를들어 Line 다음에 Circle이 오도록한다고 하자. Line 다음에 올 Circle주소를 next에 저장하고 Circle주소를 리턴한다. 그럼 pLast = Circle이 되므로 링크드리스트의 마지막은 Circle이 되는 것이다.

*** 링크드리스트 : 삭제 ***
삭제의 알고리즘 : ex) Line->Circle->Rectangle 이 링크드리스트가 있다고하자. Circle을 삭제한다고 하면 Line의 next를 Rectangle로 해주고 Circle을 delete Circle; 해주는 것이다.
1. Shape* pre = pStart; Shape* tmp = pStart; 를 해준다. //링크드리스트는 정보를 탐색하거나 삭제하려면 앞에서부터 찾아야하는 특성을 가지고있다. 그래서 pStart부터 시작.
2. 삭제할 인덱스를 입력후 삭제할 인덱스까지 for문으로 접근. // 아래코드를 잘 보자.
pre = tmp  //pre=Line , tmp=Line                           //tmp, 즉 pStart를 pre에 저장한다.
tmp = tmp->getNext(); //tmp=Circle  //Line의 다음노드인 Circle을 tmp에 저장한다.
2-1. 첫번째 노드를 삭제하는 경우
pStart = tmp->getNext(); //링크드리스트 첫번째노드에 다음 노드를 불러주고 첫번째 노드 삭제  //이 상황에서 tmp는 Line이다. pStart에 Circle을 불러오는 것이다.
delete tmp; //Line 삭제
2-2. 위 상황이 아닌경우
pre->add(tmp->getNext()); //Line에서 링크를 Rectangle로 옮긴다.  pre=Line, add(tmp->getNext())= add(Rectangle)      add(Rectangle)은 Line다음을 Rectangle로 설정하고 
Rectangle을 리턴한다. 
delete tmp;  //Circle 삭제
nodesize-- //노드의 개수가 줄었으므로 nodesize를 해줘야한다. 이거안해주면 모두보기기능 사용시 계속 링크드리스트 출력안됨.

***링크드리스트 : 모두보기 ***
1. Shape * p =pStart 해주기 // 링크드리스트의 특성상 앞에서부터 탐색해야한다고 위에서 언급.
2. if(p == NULL) //링크드리스트에 아무것도 없다면 즉, 리스트의 시작인 pStart가 NULL이라면 리스트가 비어있음을 알림.
3. 		while (p != NULL) { //p가 아무것도 가르키지 않을때까지
			cout << i++ << ": "; //앞에 번호를 붙여주는 것 크게 의미없음.
			p->paint(); //해당도형이름을 출력한다.
			p = p->getNext(); //다음도형주소로 이동. p에 계속 출력하고 다음도형주소 넘겨주고를 반복한다.
		}
 *** 주의사항 ***
NULL포인터 : 포인터가 아무것도 가르키지 않는 상태. 즉 아무것도 가르키지 않는 포인터를 'NULL 포인터' 라고 한다.
NULL포인터를 접근하면 안된다.

위 코드를 예로들면
pStart = NULL;
pStart = new Line(); 이런 건 된다. 당연하다.
여기서 상황이 갈린다.
1. 첫번째 노드인지 아닌지 구별안하고 아래처럼 작성하는 경우
pStart = NULL; pLast = pStart;
if(shapetypeNumber==1){
pLast = pLast->add(new Line()); //선 생성한다고 이 처럼 작성하면 안된다. 컴파일 오류 --> pLast는 현재 아무것도 가르키지않는 NULL포인터인데 pLast->add()로 접근함.
}

하지만 이렇게 해결할 수 있다.
        if(shapetypeNumber==1){
            if(node_size==0){
                pStart = new Line();
                pLast = pStart; //pLast에 pStart를 주면 pLast는 NULL포인터가 아니게된다.
            }
            else
            pLast = pLast->add(new Line()); //접근가능해진 상태
            node_size++;
        }
이렇게 해결 가능하다.

*/

#include <iostream>

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
    public:
    GraphicEditor(){ 
        pStart = NULL;
        node_size = 0;
    }
    int run(){
        cout << "그래픽 에디터입니다." << endl;
    while(true){
    int menuNumber = UI::getMenu();
    if(menuNumber==1){
        int shapetypeNumber = UI::getShapeType();
        if(shapetypeNumber==1){
            if(node_size==0){
                pStart = new Line();
                pLast = pStart;
            }
            else
            pLast = pLast->add(new Line());
            node_size++;
        }
        else if(shapetypeNumber==2){
            if(node_size==0){
                pStart = new Circle();
                pLast = pStart;
            }
            else
            pLast = pLast->add(new Circle());
            node_size++;
        }
        else if(shapetypeNumber==3){
            if(node_size==0){
                pStart = new Rectangle();
                pLast = pStart;
            }
            else
            pLast = pLast->add(new Rectangle());
            node_size++;
        }
    }
    else if(menuNumber==2){
        int index = UI::getDeleteShape();
        Shape* pre = pStart;
		Shape* tmp = pStart;
		if (pStart == NULL) {
			cout << "도형이 없습니다" << endl;
		}
		else { //ex) 1.Line 2.Circle 3.Rectangle
			for (int i = 1; i < index; i++) { //링크드 리스트는 앞에서 부터 찾아야하기에 선택한 인덱스까지 주소를 타고 이동
				pre = tmp;  //pre=Line
				tmp = tmp->getNext(); //tmp=Circle
			}
			if (tmp == pStart) { //첫번째 노드를 삭제하는 경우
				pStart = tmp->getNext(); //링크드리스트 첫번째노드에 다음 노드를 불러주고 첫번째 노드 삭제
				delete tmp;
			}
			else {
				pre->add(tmp->getNext()); //Line에서 링크를 Rectangle로 옮긴다. //add(Rectangle)= Line의 next는 Rectangle add(Rectangle)은 객체포인터 Rectangle리턴
				delete tmp;
			}
			node_size--;
		}
        
    }
    else if(menuNumber==3){
        Shape *p = pStart;
        int i = 1;
        if(p == NULL)
        cout << "List Empty\n";
        else{
		while (p != NULL) {
			cout << i++ << ": ";
			p->paint();
			p = p->getNext();
		}
    }
}
    else if(menuNumber==4){
        return 0;
    }
}
    }
};    
int main()
{
    GraphicEditor GE;
    GE.run();
   
    return 0;
}
