#pragma once
#include "Struct.h"


class Bullet{
public:

	Bullet();
	void Update();
	void Draw();

public:

	Transform transform_;
	float radius_;
	float speed_;
	int isShot_;
};

