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

    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;
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

int MyString::find(int find_from, const MyString& str) const {
    int i, j;
    if (str.string_length == 0) return-1;
    for (i = find_from; i <= string_length- str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }
    if (j == str.string_length) return i;
    } 
    return -1;
}

int main() { // with CLAUDE 3.5 Sonnet
   std::cout << "=== find 함수 테스트 ===" << std::endl;

   // 테스트 케이스 1: 기본 검색
   MyString str1("Hello World Hello");
   MyString search1("Hello");
   std::cout << "\n1. 기본 검색 테스트" << std::endl;
   std::cout << "원본 문자열: ";
   str1.println();
   std::cout << "검색 문자열: ";
   search1.println();
   std::cout << "처음부터 검색 (find_from=0): " << str1.find(0, search1) << std::endl;
   std::cout << "중간부터 검색 (find_from=6): " << str1.find(6, search1) << std::endl;

   // 테스트 케이스 2: 찾을 수 없는 경우
   MyString str2("Hello World");
   MyString search2("Python");
   std::cout << "\n2. 찾을 수 없는 경우 테스트" << std::endl;
   std::cout << "원본 문자열: ";
   str2.println();
   std::cout << "검색 문자열: ";
   search2.println();
   std::cout << "검색 결과: " << str2.find(0, search2) << std::endl;

   // 테스트 케이스 3: 빈 문자열 검색
   MyString str3("Test String");
   MyString search3("");
   std::cout << "\n3. 빈 문자열 검색 테스트" << std::endl;
   std::cout << "원본 문자열: ";
   str3.println();
   std::cout << "빈 문자열 검색 결과: " << str3.find(0, search3) << std::endl;

   // 테스트 케이스 4: 경계값 테스트
   MyString str4("Programming");
   MyString search4("ing");
   std::cout << "\n4. 경계값 테스트" << std::endl;
   std::cout << "원본 문자열: ";
   str4.println();
   std::cout << "검색 문자열: ";
   search4.println();
   std::cout << "문자열 끝부분 검색: " << str4.find(0, search4) << std::endl;
   std::cout << "범위를 벗어난 위치에서 검색 (find_from=20): " << str4.find(20, search4) << std::endl;
   
   // 테스트 케이스 5: 중복된 패턴 검색
   MyString str5("banana");
   MyString search5("ana");
   std::cout << "\n5. 중복 패턴 테스트" << std::endl;
   std::cout << "원본 문자열: ";
   str5.println();
   std::cout << "검색 문자열: ";
   search5.println();
   std::cout << "첫 번째 'ana' 위치: " << str5.find(0, search5) << std::endl;
   std::cout << "두 번째 'ana' 위치: " << str5.find(2, search5) << std::endl;

   std::cout << "\n=== 테스트 종료 ===" << std::endl;
   return 0;
}