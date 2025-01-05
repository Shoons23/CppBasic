// 두 명의 플레이어 주사위 게임을 수행한다.
// 주사위 게임은 두 개의 주사위를 던져 두 주사위의 함이 큰 사람이 승리
// 클래스 구성

// 누가 이겼는지 결과로 출력

#include <iostream>

using namespace std;

class Dice{
int faceValue;

public:
	Dice() {
		faceValue = 0;	
	}

	void roll() {
		faceValue = rand() % 6 + 1;
	};
	int getFaceValue() {
		return faceValue;
	};
};



class Player{
    std::string name;
    int total;

public:
    Player(){
        name = "unknown";
        total = 0;
    }

    void setName(const std::string& name);
	const string& getName() const { // const 참조 반환으로 수정
		return name;
	}
    void roll(Dice& dice1, Dice& dice2);
	int getTotal() const { // const 멤버 함수로 수정
		return total;
	}
};

void Player::setName(const std::string& name) {
	this->name = name;
}
void Player::roll(Dice& dice1, Dice& dice2) {
	dice1.roll();
	dice2.roll();
	total = dice1.getFaceValue() + dice2.getFaceValue();
}


int main(){
    Player player1;
    Player player2;
    Dice dice;
    string name;


    cout << "플레이어 이름을 입력하세요:" << endl;
    cin >> name;
    player1.setName(name);

	player1.roll(dice, dice);
	cout << player1.getName() << "의 주사위 합: " << player1.getTotal() << endl;

	cout << "플레이어 이름을 입력하세요:" << endl;
	cin >> name;
	player2.setName(name);

	player2.roll(dice, dice);
	cout << player2.getName() << "의 주사위 합: " << player2.getTotal() << endl;



	if (player1.getTotal() > player2.getTotal()) {
		cout << player1.getName() << "이" << player1.getTotal() - player2.getTotal() << "차로 이겼습니다." << endl;
	}
	else if (player1.getTotal() < player2.getTotal()) {
		cout << player2.getName() << "이" << player2.getTotal() - player1.getTotal() << "차로 이겼습니다." << endl;
	}
	else {
		cout << "비겼습니다." << endl;
	}
	return 0;
}

