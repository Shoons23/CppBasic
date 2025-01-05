#include <iostream>
#include <cstring> // 문자열 처리를 위한 라이브러리

class MyString {
    char* str_;  // 문자열 저장
    int length_; // 문자열 길이
    
public:
    // 문자 c가 n개 있는 문자열로 정의하는 생성자
    MyString(char c, int n) {
        length_ = n;
        str_ = new char[n + 1];
        for (int i = 0; i < n; i++) {
            str_[i] = c;
        }
        str_[n] = '\0';
    }

    // 문자열 상수를 받아 초기화하는 생성자
    MyString(const char* s) {
        if (s == NULL) {  // null 체크 추가 (nullptr)
            length_ = 0;
            str_ = new char[1];
            str_[0] = '\0';
            return;
        }
        length_ = std::strlen(s);
        str_ = new char[length_ + 1];
        std::strcpy(str_, s);
    }

    // 복사 생성자
    MyString(const MyString& other) {
        length_ = other.length_;
        str_ = new char[length_ + 1];
        std::strcpy(str_, other.str_);
    }

    // 소멸자
    ~MyString() {
        delete[] str_;
    }

    // 문자열 연결
    void appendString(const MyString& other) {
        char* temp = new char[length_ + other.length_ + 1];
        std::strcpy(temp, str_);
        std::strcat(temp, other.str_);

        delete[] str_;
        str_ = temp;
        length_ += other.length_;
    }

    // 문자열 복사
    void copyString(const MyString& other) {
        if (this != &other) {  // 자기 복사 검사
            delete[] str_;
            length_ = other.length_;
            str_ = new char[length_ + 1];
            std::strcpy(str_, other.str_);
        }
    }



    // 문자열 길이 반환
    int getLength() const {
        return length_;
    }

    // 문자열 내용 반환
    const char* getCString() const {
        return str_;
    }

    // 문자열 출력
    void display() const {
        std::cout << str_ << std::endl;
    }
};

int main() {
    MyString s1('o', 5);          // "aaaaa"
    s1.display();

    MyString s2("Hello");
    s2.display();

    MyString s3 = s2;             // 복사 생성자
    s3.display();

    s2.appendString(s1);          // "aaaaaHello"
    s2.display();

    return 0;
}
