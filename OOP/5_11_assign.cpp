#include <iostream>
#include <cstring>

class MyString{
    char* string_content; // 
    int string_length;
public:
    MyString();
    MyString(char c);
    MyString(const char* str);

    MyString(const MyString& str);
    ~MyString();
    
    // assign 멤버함수들
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    int length() const;
    void print() const;
    void println() const;
};

MyString::MyString() : string_content(nullptr), string_length(0) {}
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

MyString& MyString::assign(const MyString& str) {
    if(str.string_length > string_length){
        delete[] string_content;  // delete[] 사용
        string_content = new char[str.string_length];
    }
    for(int i = 0; i != str.string_length; i++){
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > string_length) {
        delete[] string_content;
        string_content = new char[str_length];
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}

int main() {
    MyString str1;
    MyString str2;

    str1.assign("Hello, world!");
    str2.assign(str1);

    std::cout << "str1 Length: " << str1.length() << std::endl;
    std::cout << "str2 Length: " << str2.length() << std::endl;

    return 0;
}