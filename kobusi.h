#pragma once
class Circle {
public:
	
	

	Circle() {

		for (int i = 0; i < 3; i++) {
			x = 10;/*10 + i * 266;*/
			y = 300;
			r = 128;
			flug = false;
		}
	}
	int Getx() { return x; }
	int Gety() { return y; }
	int Getr() { return r; }
	bool Getflug() { return flug; }
	int Getimg() { return img; }
	int Getstatus() { return kobusistatus; }
	void Setx(double SetNum) { x = (int)SetNum; }
	void Sety(double SetNum) { y = (int)SetNum; }
	void Setr(double SetNum) { r = (int)SetNum; }
	void Setflug(bool Setflug) { flug = Setflug; }
	void Setimg(int Setimg) { img = Setimg; }
	void Setstatus(double Setsta) { kobusistatus = Setsta; }
	void circleDraw() {
		int size = r*2;
		DrawExtendGraph(x,y,x+ size,y+ size,img,true);
		//DrawExtendGraph(x+ size,y+ size,x,y,img,true);
		//DrawGraph(x, y, img, true);
	}
	
	~Circle() {
		DeleteGraph(img);
	}
private:
	int x = 0, y = 0, r = 0;
	bool flug = false;
	int img = -1;
	int kobusistatus = -1;
};

class CircleYour {
public:



	CircleYour() {

		for (int i = 0; i < 3; i++) {
			x = 280;/*10 + i * 266;*/
			y = 8;
			r = (256/1.1)/2;
			flug = false;
		}
	}
	int Getx() { return x; }
	int Gety() { return y; }
	int Getr() { return r; }
	bool Getflug() { return flug; }
	int Getimg() { return img; }
	int Getstatus() { return kobusistatus; }
	void Setx(double SetNum) { x = (int)SetNum; }
	void Sety(double SetNum) { y = (int)SetNum; }
	void Setr(double SetNum) { r = (int)SetNum; }
	void Setflug(bool Setflug) { flug = Setflug; }
	void Setimg(int Setimg) { img = Setimg; }
	void Setstatus(double Setsta) { kobusistatus = Setsta; }
	void circleDraw() {
		int size = r*2 ;
		//DrawExtendGraph(x, y, x + size, y + size, img, true);
		DrawExtendGraph(x+ size,y+ size,x,y,img,true);
		//DrawGraph(x, y, img, true);
	}

	~CircleYour() {
		DeleteGraph(img);
	}
private:
	int x = 0, y = 0, r = 0;
	bool flug = false;
	int img = -1;
	int kobusistatus = -1;
};