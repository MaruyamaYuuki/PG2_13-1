#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	transform_ = { 0,0 };
	radius_ = 10;
	speed_ = 15;
	isShot_ = false;
}

void Bullet::Update() {
	if (isShot_) {
		transform_.pos.y -= speed_;
	}
	if (transform_.pos.y + radius_ <= 0) {
		isShot_ = false;
	}
}

void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(int(transform_.pos.x), int(transform_.pos.y), int(radius_), int(radius_), 0.0f, WHITE, kFillModeSolid);
	}
}

