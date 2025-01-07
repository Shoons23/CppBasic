#include <iostream>

class Robot {
   static int total_robot_num_;
   const static int i_ = 0;

   int battery_level_;
   int pos_x_, pos_y_;
   bool is_activated_;
   const int default_damage_;

public:
   Robot();
   Robot(int x, int y);
   Robot(int x, int y, int default_damage);

   int attack();
   Robot& be_attacked(int damage_earn);
   void move(int x, int y);
   void display_status();

   static void display_total_robots();

   ~Robot() { total_robot_num_--; }
};

int Robot::total_robot_num_ = 0;

void Robot::display_total_robots() {
   std::cout << "Total number of robots: " << total_robot_num_ << std::endl;
}

Robot::Robot()
   : battery_level_(100)
   , pos_x_(0)
   , pos_y_(0)
   , is_activated_(true)
   , default_damage_(5) 
{ 
   total_robot_num_++; 
}

Robot::Robot(int x, int y)
   : battery_level_(100)
   , pos_x_(x)
   , pos_y_(y)
   , is_activated_(true)
   , default_damage_(5) 
{ 
   total_robot_num_++; 
}

Robot::Robot(int x, int y, int default_damage)
   : battery_level_(100)
   , pos_x_(x)
   , pos_y_(y)
   , is_activated_(true)
   , default_damage_(default_damage) 
{ 
   total_robot_num_++; 
}

void Robot::move(int x, int y) {
   pos_x_ = x;
   pos_y_ = y;
}

int Robot::attack() {
   const int ATTACK_BATTERY_COST = 20;
   
   if (battery_level_ >= ATTACK_BATTERY_COST) {
       battery_level_ -= ATTACK_BATTERY_COST;
       return default_damage_;
   }
   
   std::cout << "배터리가 부족하여 공격할 수 없습니다." << std::endl;
   return 0;
}

Robot& Robot::be_attacked(int damage_earn) {
   battery_level_ -= damage_earn;
   if (battery_level_ <= 0) {
       is_activated_ = false;
       battery_level_ = 0;
   }
   return *this;
}

void Robot::display_status() {
   std::cout << " *** Robot *** " << std::endl;
   std::cout << " Location : ( " << pos_x_ << " , " << pos_y_ << " ) " << std::endl;
   std::cout << " Battery : " << battery_level_ << std::endl;
   std::cout << " Current total robots: " << total_robot_num_ << std::endl;
}

int main() {
   Robot robot1(2, 3, 5);
   robot1.display_status();

   Robot robot2(3, 5, 10);
   robot2.display_status();

   std::cout << std::endl << "Robot1 attacks Robot2 twice! " << std::endl;
   robot2.be_attacked(robot1.attack()).be_attacked(robot1.attack());

   robot1.display_status();
   robot2.display_status();

   return 0;
}