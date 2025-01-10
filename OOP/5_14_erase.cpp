 #include <iostream>
 #include <string.h>


 class MyString {
    char* string_content; 
    int string_length;
    int memory_capacity; // 현재 할당된 용량
public:
    MyString(char c);
    MyString(const char* str);
    
    MyString(const MyString& str);
    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);
    void print() const;
    void println() const;
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
    char at(int i) const;


    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
 
    MyString& erase(int loc, int num);
 };
 
MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
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
    if (str.string_length > memory_capacity) {
        delete[] string_content;
       string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
    delete[] string_content;
    string_content = new char[str_length];
    memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }
    string_length = str_length;
    return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
            delete[] prev_string_content;
    }
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0)
        return NULL;
    else
        return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str) {
    if (loc < 0 || loc > string_length) {
        return *this;
    }
    if (string_length + str.string_length > memory_capacity) {
        memory_capacity = string_length + str.string_length;
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        
        int i;
        for (int i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }

        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];     
        }
        delete[] prev_string_content;
        string_length = string_length + str.string_length;
        return *this;
    }

    for (int i = string_length- 1; i >= loc; i--) {
        // 뒤로밀기
        string_content[i + str.string_length] = string_content[i];
    }
        // insert 되는문자다시집어넣기
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];

    string_length = string_length + str.string_length;
    return *this;
}


MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    // 잘못된 입력 처리
    if (num < 0 || loc < 0 || loc >= string_length) return *this;
    

    // loc 위치부터 문자열 끝까지만 지우도록 조정
    num = std::min(num, string_length - loc);
    
    // 문자들을 앞으로 이동
    for (int i = loc + num; i < string_length; i++) {
        string_content[i - num] = string_content[i];
    }
    
    string_length -= num;
    return *this;
}

int main() {
    // 기본 테스트
    MyString str1("Hello World!");
    str1.println();  // Hello World!
    
    // 중간 글자 삭제
    str1.erase(5, 1);  // 공백 삭제
    str1.println();    // HelloWorld!
    
    // 여러 글자 삭제
    str1.erase(5, 3);  // "Wor" 삭제
    str1.println();    // Hellold!
    
    // 범위를 벗어난 케이스 테스트
    MyString str2("Testing");
    std::cout << "\n범위 테스트:" << std::endl;
    str2.erase(-1, 2);     // 잘못된 위치
    str2.println();        // Testing (변화 없음)
    
    str2.erase(10, 2);     // 범위를 벗어난 위치
    str2.println();        // Testing (변화 없음)
    
    str2.erase(2, 100);    // 너무 큰 삭제 길이
    str2.println();        // Te (나머지 모두 삭제)
    
    return 0;
}