#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player {
public:

	Player();
	~Player();

	void Draw();
	void Move(char* keys, char* preKeys );

public:

	Transform transform_;
	float radius_;
	float speed_;

	Bullet* bullet_;
};
