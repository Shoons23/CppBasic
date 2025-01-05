1. 초기화 리스트(initializer list)를 사용 



실제 예시로 성능 차이를 보여드리면:
```cpp
class Person {
    string name;
    int age;
public:
    // 방법 1: 초기화 리스트 미사용
    Person() {
        name = "John";  // string 기본 생성 후 대입
        age = 20;      // int 기본 생성 후 대입
    }

    // 방법 2: 초기화 리스트 사용
    Person() : name("John"), age(20) {}  // 직접 초기화
};
```

`name` 변수의 경우:
- 방법 1: string 기본 생성 → "John" 임시 string 생성 → 대입 → 임시 객체 소멸
- 방법 2: "John"으로 직접 초기화

따라서 초기화 리스트를 사용하면 더 효율적이고 안전한 코드를 작성할 수 있습니다.