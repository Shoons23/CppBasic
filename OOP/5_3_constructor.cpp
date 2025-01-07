#include <iostream>

class Date {
private:
   int year_;
   int month_;
   int day_;

public:
   // 생성자 
   Date() {
       std::cout << "기본 생성자 호출!" << std::endl;
       year_ = 2024;
       month_ = 7;
       day_ = 12;
   }

   Date(int year, int month, int day) {
       std::cout << "인자 3개 생성자 호출!" << std::endl;
       year_ = year;
       month_ = month;
       day_ = day;
   }

   void setDate(int year, int month, int day);
   void addDay(int increment);
   void addMonth(int increment);
   void addYear(int increment);
   int getMonthDays(int year, int month) const;
   void showDate() const;
};

void Date::setDate(int year, int month, int day) {
   year_ = year;
   month_ = month;
   day_ = day;
}

int Date::getMonthDays(int year, int month) const {
   static const int DAYS_IN_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   if (month != 2) {
       return DAYS_IN_MONTH[month - 1];
   }
   else if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0)) {
       return 29;  // 윤년
   }
   else {
       return 28;
   }
}

void Date::addDay(int increment) {
   while (increment > 0) {
       int daysInCurrentMonth = getMonthDays(year_, month_);

       if (day_ + increment <= daysInCurrentMonth) {
           day_ += increment;
           return;
       }
       else {
           increment -= (daysInCurrentMonth - day_ + 1);
           day_ = 1;
           addMonth(1);
       }
   }
}

void Date::addMonth(int increment) {
   addYear((increment + month_ - 1) / 12);
   month_ = month_ + increment % 12;
   month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::addYear(int increment) {
   year_ += increment;
}

void Date::showDate() const {
   std::cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_
             << "일 " << std::endl;
}

int main() {
   Date day(2025, 1, 1);
   
   day.showDate();
   day.addDay(30);
   day.showDate();
   day.addDay(2000);
   day.showDate();

   day.setDate(2012, 1, 31);  // 윤년
   day.addDay(29);
   day.showDate();

   day.setDate(2012, 8, 4);
   day.addDay(2500);
   day.showDate();

   return 0;
}