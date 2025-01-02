#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;
    
public:
    void setDate(int year, int month, int day);
    void addDay(int inc);
    void addMonth(int inc);
    void addYear(int inc);

    // 해당 월 일의 총 일 수
    int getCurrentMonthTotalDays(int year, int month);

    void showDate();

    // 생성자
    Date(int year, int month, int day){
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

void Date::setDate(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::getCurrentMonthTotalDays(int year, int month){
    static int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month != 2){
        return month_day[month-1];
    }
    else if(year%4 == 0 && year % 100 != 0 || (year % 400 == 0)){
        return 29; // 윤년
    }
    else{
        return 28;
    }
}

void Date::addDay(int inc){
    while(inc > 0){
        int currentMonthTotalDays = getCurrentMonthTotalDays(year_, month_);

        // 현재 달에서 며칠이 더 필요한가
        if(day_ + inc <= currentMonthTotalDays){
            day_ += inc;
            return; // 함수 종료
        } else{
            inc -= (currentMonthTotalDays - day_ +1);
            day_ = 1;
            addMonth(1);
        }
    }

    
}

void Date::addMonth(int inc) {
    addYear((inc + month_ - 1) / 12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::addYear(int inc) { year_ += inc; }

void Date::showDate() {
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
    << " 일 " << std::endl;
}

int main() {
    Date day(2025,1,1);
    
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