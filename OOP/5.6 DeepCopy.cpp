#include <iostream>
#include <cstring>

class Robot {
private:
   int battery_;
   int coord_x_, coord_y_;
   char* name_;
   int power_;

public:
   // 일반 생성자 
   Robot(int x, int y) {
       battery_ = 100;
       coord_x_ = x;
       coord_y_ = y;
       power_ = 20;
       name_ = NULL;
   }

   // 이름이 있는 생성자
   Robot(int x, int y, const char* robot_name) {
       battery_ = 100;
       coord_x_ = x;
       coord_y_ = y;
       power_ = 20;
       name_ = new char[strlen(robot_name) + 1];
       strcpy(name_, robot_name);
   }

   // 복사 생성자
   Robot(const Robot& robot) {
       std::cout << "Copy constructor called!" << std::endl;
       battery_ = robot.battery_;
       coord_x_ = robot.coord_x_;
       coord_y_ = robot.coord_y_;
       power_ = robot.power_;
       name_ = new char[strlen(robot.name_) + 1];
       strcpy(name_, robot.name_);
   }

   // 소멸자
   ~Robot() {
       if (name_) delete[] name_;
   }

   void showStatus() {
       std::cout << "Robot :: " << name_ << std::endl;
       std::cout << "Location : (" << coord_x_ << ", " << coord_y_ << ")" << std::endl;
       std::cout << "Battery : " << battery_ << "%" << std::endl;
   }
};

int main() {
   Robot r1(3, 3, "R2D2");
   Robot r2 = r1;  // 복사 생성자 호출

   r1.showStatus();
}