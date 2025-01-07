#include <iostream>
#include <string>

class Robot {
private:
   int battery_level_;      
   int position_x_;         
   int position_y_;
   std::string robot_name_; 
   bool is_active_;         

public:
   // 생성자: 일반적인 초기화 방식 사용
   Robot(const std::string& name, int x, int y) {
       battery_level_ = 100;
       position_x_ = x;
       position_y_ = y;
       robot_name_ = name;
       is_active_ = true;
   }

   // 복사 생성자
   Robot(const Robot& other) {
       battery_level_ = other.battery_level_;
       position_x_ = other.position_x_;
       position_y_ = other.position_y_;
       robot_name_ = other.robot_name_ + "_copy";
       is_active_ = other.is_active_;
       std::cout << "Copy constructor called for " << robot_name_ << std::endl;
   }

   // 소멸자
   ~Robot() {
       std::cout << robot_name_ << " destroyed!" << std::endl;
   }

   void displayStatus() const {
       std::cout << "\n=== " << robot_name_ << " Status ===" << std::endl;
       std::cout << "Position: (" << position_x_ << ", " << position_y_ << ")" << std::endl;
       std::cout << "Battery Level: " << battery_level_ << "%" << std::endl;
       std::cout << "Status: " << (is_active_ ? "Active" : "Inactive") << std::endl;
   }

   // getter 함수들
   int getBatteryLevel() const { return battery_level_; }
   int getPositionX() const { return position_x_; }
   int getPositionY() const { return position_y_; }
   std::string getRobotName() const { return robot_name_; }
   bool isActive() const { return is_active_; }
};

int main() {
   Robot main_robot("R2D2", 0, 0);
   main_robot.displayStatus();

   Robot copied_robot = main_robot;
   copied_robot.displayStatus();

   return 0;
}