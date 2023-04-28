#include<DxLib.h>
#include"WinLoseDraw.h"

namespace {

}
/*
class status {
public:

	void statusWin();
	void statusLose();
	void statusDraw();
private:

};
*/


void status::statusWin() {
	DrawFormatString(400 - 64, 300 - 64, GetColor(100, 100, 100), "èüÇø");
}
void status::statusLose() {
	DrawFormatString(400 - 64, 300 - 64, GetColor(100, 100, 100), "ïâÇØ");
}
void status::statusDraw() {
	DrawFormatString(400 - 64, 300 - 64, GetColor(100, 100, 100), "Ç†Ç¢Ç±");
}