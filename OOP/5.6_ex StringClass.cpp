#include <iostream>
#include <cstring> // 문자열 처리를 위한 라이브러리

class string {
    char *str; // 문자열 저장
    int len;   // 문자열 길이

public:
    // 문자 c가 n 개 있는 문자열로 정의하는 생성자
    string(char c, int n) {
        len = n;
        str = new char[n + 1];
        for (int i = 0; i < n; i++) {
            str[i] = c;
        }
        str[n] = '\0';
    }

    // 문자열 상수를 받아 초기화하는 생성자
    string(const char *s) {
        len = std::strlen(s);
        str = new char[len + 1];
        std::strcpy(str, s);
    }

    // 복사 생성자
    string(const string &s) {
        len = s.len;
        str = new char[len + 1];
        std::strcpy(str, s.str);
    }

    // 소멸자
    ~string() {
        delete[] str;
    }

    // str 뒤에 s를 붙이는 함수
    void add_string(const string &s) {
        char *temp = new char[len + s.len + 1];
        std::strcpy(temp, str);
        std::strcat(temp, s.str);

        delete[] str;
        str = temp;
        len += s.len;
    }

    // str에 s를 복사하는 함수
    void copy_string(const string &s) {
        delete[] str;
        len = s.len;
        str = new char[len + 1];
        std::strcpy(str, s.str);
    }

    // 문자열 길이를 반환하는 함수
    int strlen() const {
        return len;
    }

    // 문자열 출력
    void print() const {
        std::cout << str << std::endl;
    }
};

int main() {
    string s1('a', 5);      
    string s2("hello");    
    string s3 = s2;         // 복사 생성자 호출

    s1.add_string(s2);      // s1: "aaaaahello"
    std::cout << "s1: ";
    s1.print();

    s3.copy_string(s1);     // s3: "aaaaahello"
    std::cout << "s3: ";
    s3.print();

    std::cout << "s3 길이: " << s3.strlen() << std::endl;

    return 0;
}
