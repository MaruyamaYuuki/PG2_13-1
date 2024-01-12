#pragma once
#include <Novice.h>
#include"Struct.h"

class Enemy
{
protected:
	Vector2 pos_;
	int radius_;
	float speed_;
public:
	static int alive;
	Enemy();

	void Update();
	void Draw();
	void SetSpeed(float speed);
	void SetPosY(float y);
	void HitBullet(Transform transform, float radius);
	void Respawn(char* keys, char* preKeys);
};

