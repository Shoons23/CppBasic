#include <iostream>

size_t strlen(const char *str) {
    size_t length = 0; // 문자열 길이를 저장할 변수

    // 문자열 끝('\0')을 만날 때까지 반복
    while (str[length] != '\0') {
        length++;
    }

    return length; // 계산된 길이를 반환
}


class MyString{
    char* string_content; // 
    int string_length;
public:
    MyString(char c);
    MyString(const char* str);

    MyString(const MyString& str);
    ~MyString();
    
    int length() const;
    void print() const;
    void println() const;
};


MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);  // 문자열 길이 반환 
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }
void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
    }
    std::cout << std::endl;
}

int main() {
    MyString str1("hello world!");
    MyString str2(str1);
    str1.println();
    str2.println();
}