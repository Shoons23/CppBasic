# C++ Coding Standard

## 1. 클래스와 구조체 (Classes and Structs)
- Pascal Case 사용 (각 단어의 첫 글자를 대문자로)
```cpp
class RobotController {
    // ...
};

struct SensorData {
    // ...
};
```

## 2. 멤버 변수 (Member Variables)
- 접미사 '_' 사용
- 의미가 명확한 명사 사용
```cpp
class Robot {
private:
    int position_;
    double velocity_;
    std::string robot_name_;
    std::vector<double> joint_values_;
};
```

## 3. 멤버 함수 (Member Functions)
- Camel Case 사용 (첫 단어는 소문자, 이후 단어들은 대문자로 시작)
- 동사로 시작하여 행동을 명확히 표현
```cpp
class RobotController {
public:
    void moveToPosition(double x, double y);
    bool isReady() const;
    void setJointValues(const std::vector<double>& values);
    std::vector<double> getJointPositions() const;
};
```

## 4. 일반 변수 (Variables)
- Snake Case 사용 (소문자와 언더스코어)
- 명확한 의미를 가진 명사 사용
```cpp
int current_position;
double linear_velocity;
std::string robot_state;
std::vector<double> joint_angles;
```

## 5. 상수와 열거형 (Constants and Enums)
- 대문자와 언더스코어 사용
```cpp
const int MAX_JOINT_NUMBER = 6;
const double DEFAULT_VELOCITY = 1.0;

enum RobotState {
    IDLE,
    RUNNING,
    ERROR,
    EMERGENCY_STOP
};

#define PI_VALUE 3.14159
```

## 6. Bool형 변수 (Boolean Variables)
- is_, has_, can_ 등의 접두어 사용
- 질문 형태로 이름 지정
```cpp
bool is_initialized;
bool has_error;
bool can_move;

class Robot {
private:
    bool is_enabled_;
    bool has_gripper_;
    bool can_rotate_;
};
```

## 7. const 규칙 (Const Usage)
- 물리/수학 상수와 대용량 데이터 전달에만 const 사용
- 일반적인 설정값이나 임계값에는 const 사용 제한

### 7.1 물리/수학 상수
```cpp
class PhysicsConstants {
private:
    const double PI_ = 3.14159265359;
    const double GRAVITY_ = 9.81;        // m/s^2
    const double LIGHT_SPEED_ = 299792458;  // m/s
};
```

### 7.2 대용량 데이터 전달
```cpp
class RobotController {
public:
    void processTrajectory(const std::vector<Point>& points);
    void analyzeSensorData(const std::vector<double>& sensor_data);
};
```


## 예시
```cpp
class RobotArm {
private:
    // 물리 상수
    const double PI_ = 3.14159265359;
    
    // 일반 멤버 변수
    int joint_count_ = 6;
    double max_speed_ = 1.0;
    std::vector<double> joint_positions_;
    std::string robot_name_;
    bool is_enabled_;
    bool has_error_;

public:
    // 대용량 데이터는 const 참조로 전달
    void updateTrajectory(const std::vector<double>& trajectory) {
        joint_positions_ = trajectory;
    }

    // 일반 멤버 함수 (camelCase)
    void moveToPosition(double x, double y) {
        // 위치로 이동
    }

    void setRobotName(std::string name) {
        robot_name_ = name;
    }

    // bool 반환 함수는 is, has, can 등으로 시작
    bool isReady() {
        return is_enabled_ && !has_error_;
    }

    // 일반 변수 사용 예시 (snake_case)
    void calculateTrajectory() {
        int point_count = 100;
        double current_velocity = 0.0;
        std::vector<double> target_points;

        // enum 사용 (대문자)
        enum MotionState {
            IDLE,
            MOVING,
            STOPPED
        };
    }

    // 간단한 데이터는 값으로 전달
    double getPosition(int joint_index) {
        return joint_positions_[joint_index];
    }

    void setMaxSpeed(double speed) {
        max_speed_ = speed;
    }
};
```




## 8. 파일 명명 규칙 (File Naming)

### 8.1 소스 파일 (.cpp)
- snake_case 사용
- 챕터 번호와 내용을 명확히 구분
- 형식: `chapter_name.cpp` 또는 `chapter_subsection_name.cpp`

### 8.2 예제 파일
- 예제임을 명확히 표시
- 형식: `chapter_name_example.cpp`

### 8.3 주의사항
1. 공백 사용 금지
2. 챕터 구분은 언더스코어 사용
3. 숫자와 문자 사이는 언더스코어로 구분
4. 의미있는 이름 사용