#include <iostream>
#include <string>

class Robot {
private:
   int battery_;
   int coord_x_, coord_y_;
   std::string name_;
   bool is_dead_;

public:
   // Constructor
   Robot(const std::string& name, int x, int y) {
       battery_ = 100;
       coord_x_ = x;
       coord_y_ = y;
       name_ = name;
       is_dead_ = false;
   }

   // Copy Constructor
   Robot(const Robot& other) {
       battery_ = other.battery_;
       coord_x_ = other.coord_x_;
       coord_y_ = other.coord_y_;
       name_ = other.name_ + "_copy";
       is_dead_ = other.is_dead_;
       std::cout << "Copy constructor called for " << name_ << std::endl;
   }

   // Destructor
   ~Robot() {
       std::cout << name_ << " destroyed!" << std::endl;
   }

   void showStatus() const {
       std::cout << "\n=== " << name_ << " Status ===" << std::endl;
       std::cout << "Position: (" << coord_x_ << ", " << coord_y_ << ")" << std::endl;
       std::cout << "Battery: " << battery_ << "%" << std::endl;
   }
};

int main() {
   Robot r1("R2D2", 0, 0);
   r1.showStatus();

   Robot r2 = r1;  // Copy constructor called
   r2.showStatus();

   return 0;
}