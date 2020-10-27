#include "DxLib.h"

int android_main( void )
{
    int i ;
    int PosX, PosY ;
    int back;
    int kyara[12];
    int taskbar;
SetGraphMode( 1280 , 720, 32 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    back=LoadGraph("back.png",false);
    taskbar=LoadGraph("taskbar.png");
    LoadDivGraph("kyara.png",12,3,4,48,48,kyara);
    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // メインループ
    long time;
    long nowtime;
    int fps=0.0f;
    time = GetNowHiPerformanceCount();
    while( ProcessMessage() == 0 )
    {
        ClearDrawScreen() ;
        nowtime = GetNowHiPerformanceCount();
        fps = 1000000 / (nowtime - time);
        time = nowtime;

        // 画面のクリア

        //back.png
        //DrawRotaGraphF(640,360,1,0,back,false);
        DrawRotaGraphF(1106,360,1,0,taskbar,false);

        // タッチされている箇所の数だけ繰り返し
        for( i = 0 ; i < GetTouchInputNum() ; i ++ )
        {
            // タッチされている箇所の座標を取得
            GetTouchInput( i, &PosX, &PosY, NULL, NULL ) ;

            // タッチされている箇所の座標に円を描画
            DrawRotaGraphF(PosX,PosY,1.5,0,kyara[11],true);
        }

        // 裏画面の内容を表画面に反映
        DrawFormatStringF(1000, 0, GetColor(255, 255, 255), "FPS:%i", fps);
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}