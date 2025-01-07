/*
--------------------------------------
Author      : tshoon
Date        : 2025.1.1
---------------------------------------
*/

// object - class
#include <iostream>

class Animal {
private:
    int food_;
    int weight_;  // 접미사 '_' 추가

public:
    void setAnimal(int food, int weight) {  // 매개변수 이름 수정
        food_ = food;
        weight_ = weight;
    }

    void increaseFood(int increment) {  // 더 명확한 매개변수 이름
        food_ += increment;
        weight_ += (increment / 3);
    }

    void viewStatus() const {  // const 추가
        std::cout << "이 동물의 food: " << food_ << std::endl;
        std::cout << "이 동물의 weight: " << weight_ << std::endl;
    }
};

class Date {
private:  // private 키워드 추가
    int year_;
    int month_;
    int day_;

public:
    void setDate(int year, int month, int day);  // date -> day로 수정
    void addDay(int increment);    // inc -> increment
    void addMonth(int increment);
    void addYear(int increment);
    void showDate() const;         // const 추가
};

int main() {  // void 제거
    Animal dog;
    dog.setAnimal(100, 50);
    dog.viewStatus();
    dog.increaseFood(30);
    dog.viewStatus();

    return 0;
}