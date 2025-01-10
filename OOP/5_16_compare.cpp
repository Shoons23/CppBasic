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

    int compare(const MyString& str) const;
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

int MyString::compare(const MyString& str) const {
    // 두 문자열을 사전식으로 비교
    // 반환값:
    //  1: this가 str보다 사전식으로 뒤에 옴
    //  0: 두 문자열이 같음
    // -1: this가 str보다 사전식으로 앞에 옴
    
    // 먼저 공통 길이만큼 문자 단위로 비교
    int common_length = std::min(string_length, str.string_length);
    for (int i = 0; i < common_length; i++) {
        if (string_content[i] > str.string_content[i]) 
            return 1;
        else if (string_content[i] < str.string_content[i]) 
            return -1;
    }
    
    if (string_length == str.string_length) 
        return 0;
    

    else if (string_length > str.string_length) 
        return 1;
    
    return -1;
}


int main() {
    std::cout << "=== compare 함수 테스트 ===" << std::endl;

    // 테스트 케이스 1: 같은 문자열 비교
    MyString str1("hello");
    MyString str2("hello");
    std::cout << "\n1. 같은 문자열 비교" << std::endl;
    std::cout << "str1: "; str1.println();
    std::cout << "str2: "; str2.println();
    std::cout << "비교 결과: " << str1.compare(str2) << std::endl;

    // 테스트 케이스 2: 사전식 순서 비교
    MyString str3("hello");
    MyString str4("world");
    std::cout << "\n2. 사전식 순서 비교" << std::endl;
    std::cout << "str3: "; str3.println();
    std::cout << "str4: "; str4.println();
    std::cout << "비교 결과: " << str3.compare(str4) << std::endl;

    // 테스트 케이스 3: 길이가 다른 문자열 비교
    MyString str5("abc");
    MyString str6("abcd");
    std::cout << "\n3. 길이가 다른 문자열 비교" << std::endl;
    std::cout << "str5: "; str5.println();
    std::cout << "str6: "; str6.println();
    std::cout << "비교 결과: " << str5.compare(str6) << std::endl;

    // 테스트 케이스 4: 첫 글자가 다른 경우
    MyString str7("apple");
    MyString str8("banana");
    std::cout << "\n4. 첫 글자가 다른 경우" << std::endl;
    std::cout << "str7: "; str7.println();
    std::cout << "str8: "; str8.println();
    std::cout << "비교 결과: " << str7.compare(str8) << std::endl;

    std::cout << "\n=== 테스트 종료 ===" << std::endl;
    return 0;
}