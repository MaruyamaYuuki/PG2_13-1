#include <Novice.h>
#include "Enemy.h"
#include"Player.h"

const char kWindowTitle[] = "LC1B_24_マルヤマユウキ_PG2_13-1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Enemy* enemyA = new Enemy();
	Enemy* enemyB = new Enemy();
	Player* player = new Player();

	enemyB->SetPosY(300);
	enemyB->SetSpeed(-10);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		player->Move(keys, preKeys);

		enemyA->Update();
		enemyB->Update();

		enemyA->HitBullet(player->bullet_->transform_, player->bullet_->radius_);
		enemyB->HitBullet(player->bullet_->transform_, player->bullet_->radius_);

		enemyA->Respawn(keys, preKeys);
		enemyB->Respawn(keys, preKeys);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		enemyA->Draw();
		enemyB->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemyA;
	delete enemyB;
	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
