#include<DxLib.h>
#include"judge.h"


int judge(int my,int your) {
	enum stats {
		win,
		lose,
		draw,
	};
	enum type {
		gu,
		tyoki,
		pa,
		typeEnd,
	};
	switch (my) {
	case gu:
		switch (your) {
		case gu:
			return draw;
			break;
		case tyoki:
			return win;
			break;
		case pa:
			return lose;
			break;
		default:
			return -1;
			break;
		}
		break;
	case tyoki:
		switch (your) {
		case gu:
			return lose;
			break;
		case tyoki:
			return draw;
			break;
		case pa:
			return win;
			break;
		default:
			return -1;
			break;
		}
		break;
	case pa:
		switch (your) {
		case gu:
			return win;
			break;
		case tyoki:
			return lose;
			break;
		case pa:
			return draw;
			break;
		default:
			return -1;
			break;
		}
		break;
	default:
		return -1;
		break;
	}

	return -1;
}