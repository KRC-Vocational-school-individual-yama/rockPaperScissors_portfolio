#include "DxLib.h"
#include <string>
#include"kobusi.h"
#include"circlecollition.h"
#include"maneger.h"
#include"judge.h"
#include"WinLoseDraw.h"
#include<stdio.h>


namespace {
	status kobusis;
	int getrandnum = 4;
	int getrandnum2 = 4;
	bool keystop = false;
	int syoubu[3] = {};
	enum stats {
		win,
		lose,
		draw,
	};

	bool countflug = false;
	int count = 0;
	int ccount = 0;
	bool mozistop = false;
}

mgr::mgr() {
	Init();
}

mgr::~mgr() {
	Delete();
}
//ç≈èâÇ…1âÒåƒÇŒÇÍÇÈèàóù
void mgr::Init() {

	en[0].Setimg(LoadGraph("gu-_256.png"));
	en[1].Setimg(LoadGraph("tyoki_256.png"));
	en[2].Setimg(LoadGraph("pa-_256.png"));
	en[3].Setimg(-1);
	
	youren[0].Setimg(LoadGraph("gu-_256.png"));
	youren[1].Setimg(LoadGraph("tyoki_256.png"));
	youren[2].Setimg(LoadGraph("pa-_256.png"));
	youren[3].Setimg(-1);

	for (int i = 0; i < 3; i++) {
		en[i].Setx(((double)10 + (double)i * (double)266));
		en[i].Sety(300);
		en[i].Setr(128);
		en[i].Setflug(false);
	}
}

void mgr::Update() {
	count++;
	GetMousePoint(&mx, &my);
	int statusnum = -1;
	for (int i = 0; i < 3; i++) {
		if (
			CircleColliton(en[i].Getx() + 128, en[i].Gety() + 128, en[i].Getr(), mx, my, 10)
			) {
			en[i].Setflug(true);
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) && keystop == false) {
				mozistop = false;

				countflug = true;
				en[i].Setstatus(i);
				en[i].Setflug(false);
				getrandnum = GetRand(2);
				getrandnum2 = getrandnum;
				if (en[i].Getstatus() != -1) {
					statusnum = en[i].Getstatus();
				}
				int sta = judge(statusnum, getrandnum);
				switch (sta) {
				case win:
					syoubu[0]++;
					break;
				case lose:
					syoubu[1]++;
					break;
				case draw:
					syoubu[2]++;
					break;
				default:
					break;
				}
				keystop = true;
			}
		}
		else {
			en[i].Setflug(false);
			if (GetMouseInput() & MOUSE_INPUT_LEFT) {
				en[i].Setstatus(-1);
			}
		}
		if (en[i].Getstatus() != -1) {
			statusnum = en[i].Getstatus();
		}

	}
	if (countflug == true) {
		getrandnum = (count / 5) % 3;
		if ((count / 5) % 3 == 2) {
			ccount++;
		}
		if (ccount >= 3) {
			mozistop = true;
			getrandnum = getrandnum2;
		}
	}
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) {
		mozistop = true;
		countflug = false;
		count = 0;
		ccount = 0;
		keystop = false;
	}
	printfDx("%d", getrandnum);
	int sta = judge(statusnum, getrandnum);
	SetFontSize(64);
	if (mozistop == true)
		switch (sta) {
		case win:
			kobusis.statusWin();
			//DrawFormatString(400-64, 300-64, GetColor(100, 100, 100), "èüÇø");
			break;
		case lose:
			kobusis.statusLose();
			//DrawFormatString(400 - 64, 300 - 64, GetColor(100, 100, 100), "ïâÇØ");
			break;
		case draw:
			kobusis.statusDraw();
			//DrawFormatString(400 - 64,300 - 64,GetColor(100,100,100),"Ç†Ç¢Ç±");
			break;
		default:
			DrawFormatString(400 - 64, 300 - 64, GetColor(100, 100, 100), "ëIÇÒÇ≈ÇÀ");
			break;
		}
	SetFontSize(16);

	/*
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 0) {
	keystop = false;
	}
	*/
}

void mgr::Draw() {
	//îwåi
	DrawBox(0, 0, 800, 600, GetColor(245, 222, 179), true);

	for (int i = 0; i < 3; i++) {


		if (en[i].Getflug() != true) {
			en[i].circleDraw();
				youren[getrandnum].circleDraw();
			
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			en[i].circleDraw();
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}


	}
	printfDx("èüÇøÅ@=%2d\n", syoubu[0]);
	printfDx("ïâÇØÅ@=%2d\n", syoubu[1]);
	printfDx("Ç†Ç¢Ç±=%2d\n", syoubu[2]);
}

void mgr::Delete() {


}