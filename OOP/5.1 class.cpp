/*
--------------------------------------
Author      : tshoon
Date        : 2025.1.1
---------------------------------------
*/


// object - class
#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;
    
public:
    void SetDate(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    }

    void AddDay(){
        day_ += 1;
        if(day_ > 31){
            day_ = 1;
            AddMonth();
        }
    }
    void AddMonth(){
        month_ += 1;
        if(month_ > 12){
            month_ = 1;
            AddYear();
        }
    }
    void AddYear(){
        year_ += 1;
    }

    void ShowDate(){
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일 " << std::endl; 
    }
};

int main(void){
    Date date;
    date.SetDate(2025, 1, 1);
    date.ShowDate();
    return 0;
}