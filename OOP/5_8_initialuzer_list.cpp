#include <iostream>
#include <string>

class Robot {
private:

    int battery_level_;
    int position_x_;
    int position_y_;
    int laser_power_;
    bool is_disabled_;
    std::string model_number_;
    
public:
   
    Robot();
    Robot(int x, int y, std::string model);


    int getLaserPower() const;
    void moveToPosition(int x, int y);
    void chargeBattery(int amount);
    void takeDamage(int damage_amount);
    void displayStatus() const;
    bool isOperational() const;
};

// 생성자의 초기화 리스트
Robot::Robot() 
    : battery_level_(100)
    , position_x_(0)
    , position_y_(0)
    , laser_power_(10)
    , is_disabled_(false)
    , model_number_("R-000") 
{
}

Robot::Robot(int x, int y, std::string model)
    : battery_level_(100)
    , position_x_(x)
    , position_y_(y)
    , laser_power_(10)
    , is_disabled_(false)
    , model_number_(model) 
{
}

int Robot::getLaserPower() const {
    if (battery_level_ >= 20) {  // 공격에는 배터리 20 소모
        return laser_power_;
    }
    std::cout << "배터리가 부족하여 공격할 수 없습니다." << std::endl;
    return 0;
}

void Robot::moveToPosition(int x, int y) {
    if (battery_level_ >= 10) {  // 이동에는 배터리 10 소모
        position_x_ = x;
        position_y_ = y;
        battery_level_ -= 10;
    } else {
        std::cout << "배터리가 부족하여 이동할 수 없습니다." << std::endl;
    }
}

void Robot::chargeBattery(int amount) {
    const int MAX_BATTERY_LEVEL = 100;  // 상수는 대문자와 언더스코어
    battery_level_ += amount;
    if (battery_level_ > MAX_BATTERY_LEVEL) {
        battery_level_ = MAX_BATTERY_LEVEL;
    }
}

void Robot::takeDamage(int damage_amount) {
    battery_level_ -= damage_amount;
    if (battery_level_ <= 0) {
        is_disabled_ = true;
        battery_level_ = 0;
    }
}

bool Robot::isOperational() const {
    return !is_disabled_;
}

void Robot::displayStatus() const {
    std::cout << " *** Robot " << model_number_ << " *** " << std::endl;
    std::cout << " Location : ( " << position_x_ << " , " << position_y_ << " ) "
              << std::endl;
    std::cout << " Battery : " << battery_level_ << "%" << std::endl;
    std::cout << " Laser Power : " << laser_power_ << std::endl;
    std::cout << " Status : " << (is_disabled_ ? "Disabled" : "Active") << std::endl;
}

int main() {
    Robot robot1(2, 3, "R-101");
    Robot robot2(3, 5, "R-102");

    std::cout << "Initial Status:" << std::endl;
    robot1.displayStatus();
    robot2.displayStatus();

    std::cout << "\nAfter robot1 moves:" << std::endl;
    robot1.moveToPosition(4, 4);
    robot1.displayStatus();

    std::cout << "\nAfter robot1 attacks:" << std::endl;
    robot1.getLaserPower();  // 배터리 소모
    robot1.displayStatus();

    return 0;
}