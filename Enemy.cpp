#include "Enemy.h"

Enemy::Enemy() {
	pos_ = { 200,100 };
	radius_ = 20;
	speed_ = 10;
}
int Enemy::alive = true;

void Enemy::Update() {
	if (alive) {
	    pos_.x += speed_;
	    if (pos_.x + radius_ >= 1280 || pos_.x - radius_ <= 0) {
		    speed_ *= -1;
	    }
	}

}

void Enemy::Draw() {
	if (alive) {
	    Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, RED, kFillModeSolid);
	}

}

void Enemy::SetSpeed(float speed) {
	speed_ = speed;
}

void Enemy::SetPosY(float y) {
	pos_.y = y;
}

void Enemy::HitBullet(Transform transform, float radius) {
	float dx = pos_.x - transform.pos.x;
	float dy = pos_.y - transform.pos.y;

	float combonedRadius = float(radius_ + radius);

	if ((dx * dx + dy * dy) < (combonedRadius * combonedRadius)) {
		alive = false;
	}
}

void Enemy::Respawn(char* keys, char* preKeys) {
	if (keys[DIK_R] && preKeys[DIK_R] == 0) {
		alive = true;
	}
}



