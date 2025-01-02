#include <iostream>
#include <string>

class Robot {
    int battery_;
    int coord_x_, coord_y_;
    std::string name_; 
    bool is_dead_;

public:
    // 생성자
    Robot(const std::string& name, int x, int y) {  // string 레퍼런스로 받음
        battery_ = 100;
        coord_x_ = x;
        coord_y_ = y;
        is_dead_ = false;
        name_ = name;  
    }
    ~Robot() {
        std::cout << name_ << " 로봇의 소멸자 호출!" << std::endl;
    }

    void showStatus() {
        std::cout << "\n=== " << name_ << " 상태 ===" << std::endl;
        std::cout << "위치: (" << coord_x_ << ", " << coord_y_ << ")" << std::endl;
        std::cout << "배터리: " << battery_ << "%" << std::endl;
    }
};

int main() {
    // 스택에 로봇 생성
    Robot robot1("R2D2", 2, 3);
    robot1.showStatus();

    // 동적으로 로봇 생성
    Robot* robot2 = new Robot("C3PO", 5, 5);
    robot2->showStatus();
    delete robot2;

    return 0;
}