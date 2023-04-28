#pragma once
#include"kobusi.h"
class mgr
{
public:
	mgr();
	~mgr();

	void Update();
	void Draw();

private:
	void Init();
	void Delete();
	int mx = 0;
	int my = 0;

	
	Circle en[4];
	CircleYour youren[4];
};

