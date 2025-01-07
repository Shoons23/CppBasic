#include <iostream>
#include <string>

class Robot {
private:
   int battery_level_;        
   int position_x_, position_y_;  
   std::string robot_name_;    
   bool is_active_;            

public:
   // 생성자 
   Robot(const std::string& name, int x, int y) {
       battery_level_ = 100;
       position_x_ = x;
       position_y_ = y;
       is_active_ = true;
       robot_name_ = name;
   }

   // 소멸자
   ~Robot() {
       std::cout << robot_name_ << " 로봇의 소멸자 호출!" << std::endl;
   }

   // 상태 표시 함수 - const 추가
   void displayStatus() const {
       std::cout << "\n=== " << robot_name_ << " 상태 ===" << std::endl;
       std::cout << "위치: (" << position_x_ << ", " << position_y_ << ")" << std::endl;
       std::cout << "배터리: " << battery_level_ << "%" << std::endl;
   }
};

int main() {
    // 스택에 로봇 생성
    Robot robot1("R2D2", 2, 3);
    robot1.displayStatus();

    // 동적으로 로봇 생성
    Robot* robot2 = new Robot("C3PO", 5, 5);
    robot2->displayStatus();
    delete robot2;

    return 0;
}