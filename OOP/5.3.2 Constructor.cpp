// 수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다. 중학생용 기하학 소프트웨워를 만드는 것인데요, 
// 클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 다른 하나는
// Geometry 로 점들을 가지고 연산을 하는 클래스 입니다. 즉 아래와 같은 두 클래스의 함수들을
// 모두 정의하세요 (난이도 : 上)


#include <iostream>

class Point{
    int x,y;
public:
    Point(int pos_x, int pos_y);
};

class Geometry{
    Point* point_array[100];

public:
    Geometry(Point **point_list);
    Geometry();

    void addPoint(const Point &point);

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void printDistance();

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 
    // 이면 됩니다.
    void printNumMeets();
};

void Geometry::printDistance(){

}