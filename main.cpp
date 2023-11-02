#include <Novice.h>
#include"audio.h"
#include"easing.h"
#include<Vector2.h>



const char kWindowTitle[] = "TDGAME";

int map[15][40] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};




//イージング用ラープ関数　※いじらないで
Vector2 leap(const Vector2& start, const Vector2& end, float t) {
	Vector2 ret;
	ret.x = start.x + (end.x - start.x) * t;
	ret.y = start.y + (end.y - start.y) * t;
	return ret;
}


//ブロックの構造体
struct Block {
	Vector2 pos;
};

Block block = {
	{0,0}
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 960);

	//=======フラグ=======
	int sceneCount = 0;

	//=======フラグ=======

	//=======グラフハンドル==========


	//=======グラフハンドル=======
	int blockImage = Novice::LoadTexture("./images/block.png");



	//=======Audioハンドル=======


	//=======Audioハンドル=======



	enum scene {
		title = 0,
		exp = 1,
		play = 2,
		result = 3
	};

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから

		// シーン描画
		switch (sceneCount) {
		case title:

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sceneCount += 2;
			}

			break;
		case exp://ルール説明

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sceneCount += 1;
			}
			break;
		case play:

			/*	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
					sceneCount += 1;
				}*/

				//マップ
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 40; j++) {
					block.pos.y = (float)i * 64;
					block.pos.x = (float)j * 64;
					if (map[i][j] == 1) {
						Novice::DrawSprite((int)block.pos.x, (int)block.pos.y, blockImage, 1, 1, 0.0F, 0xFFFFFFFF);
					}

				}
				block.pos.x = 0;
			}

			break;
		case result:

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sceneCount += 1;
			}
			break;
		}




		Novice::ScreenPrintf(0, 0, "%d", sceneCount);
		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}