#include <iostream>
#include <cstring>

class Robot {
private:
    int battery_level_;      // 명확한 이름으로 변경
    int position_x_;         // coord 대신 position 사용
    int position_y_;
    char* robot_name_;       // name 대신 구체적인 이름 사용
    int power_level_;        // 명확한 이름으로 변경

public:
    // 기본 생성자 
    Robot(int x, int y) {
        battery_level_ = 100;
        position_x_ = x;
        position_y_ = y;
        power_level_ = 20;
        robot_name_ = nullptr;    // NULL 대신 nullptr 사용
    }

    // 이름을 포함한 생성자
    Robot(int x, int y, const char* name) {
        battery_level_ = 100;
        position_x_ = x;
        position_y_ = y;
        power_level_ = 20;
        robot_name_ = new char[strlen(name) + 1];
        strcpy(robot_name_, name);
    }

    // 복사 생성자
    Robot(const Robot& other) {
        std::cout << "Copy constructor called!" << std::endl;
        battery_level_ = other.battery_level_;
        position_x_ = other.position_x_;
        position_y_ = other.position_y_;
        power_level_ = other.power_level_;
        
        if (other.robot_name_) {
            robot_name_ = new char[strlen(other.robot_name_) + 1];
            strcpy(robot_name_, other.robot_name_);
        } else {
            robot_name_ = nullptr;
        }
    }

    // 소멸자
    ~Robot() {
        delete[] robot_name_;
    }

    // const 멤버 함수로 변경
    void displayStatus() const {
        std::cout << "Robot Name: " << (robot_name_ ? robot_name_ : "Unnamed") << std::endl;
        std::cout << "Position: (" << position_x_ << ", " << position_y_ << ")" << std::endl;
        std::cout << "Battery Level: " << battery_level_ << "%" << std::endl;
    }

    // getter 함수 추가
    int getBatteryLevel() const { return battery_level_; }
    int getPositionX() const { return position_x_; }
    int getPositionY() const { return position_y_; }
    int getPowerLevel() const { return power_level_; }
    const char* getRobotName() const { return robot_name_; }
};

int main() {
   Robot robot(3, 3, "R2D2");
   Robot copied_robot = robot;  // 복사 생성자 호출

   robot.displayStatus();
}