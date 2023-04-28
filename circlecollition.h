#pragma once
bool CircleColliton(int zx, int zy, int zr, int ax, int ay, int ar) {
	int x, y, xyh, r;
	x = zx - ax;
	y = zy - ay;
	xyh = x * x + y * y;
	r = zr * zr + ar * ar;
	if (xyh <= r)return true;

	return false;
}