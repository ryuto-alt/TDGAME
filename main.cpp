#include <Novice.h>
#include"audio.h"
#include"easing.h"
#include<Vector2.h>


const char kWindowTitle[] = "TDGAME";


//イージング用ラープ関数　※いじらないで
Vector2 leap(const Vector2& start, const Vector2& end, float t) {
	Vector2 ret;
	ret.x = start.x + (end.x - start.x) * t;
	ret.y = start.y + (end.y - start.y) * t;
	return ret;
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//=======フラグ=======
	int sceneCount = 0;

	//=======フラグ=======

	//=======グラフハンドル==========


	//=======グラフハンドル=======


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
				sceneCount += 1;
			}
			break;
		case exp://ルール説明

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sceneCount += 1;
			}
			break;
		case play:

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sceneCount += 1;
			}
			break;
		case result:

			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				sceneCount += 1;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///




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
