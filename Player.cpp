#include "Player.h"
#include "Novice.h"

Player::Player() {
	transform_ = { 640,360 };
	radius_ = 30;
	speed_ = 5;

	bullet_ = new Bullet();
}

Player::~Player() {
	delete bullet_;
}

void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		transform_.pos.y -= speed_;
	}
	if (keys[DIK_S]) {
		transform_.pos.y += speed_;
	}
	if (keys[DIK_A]) {
		transform_.pos.x -= speed_;
	}
	if (keys[DIK_D]) {
		transform_.pos.x += speed_;
	}

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		if (bullet_->isShot_ == 0) {
		    bullet_->transform_.pos = transform_.pos;
		    bullet_->isShot_ = true;
		}
	}

	bullet_->Update();
}

void Player::Draw() {
	Novice::DrawEllipse(int(transform_.pos.x), int(transform_.pos.y), int(radius_), int(radius_), 0.0f, GREEN, kFillModeSolid);

	bullet_->Draw();
}