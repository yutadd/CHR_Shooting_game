#include "DxLib.h"

int android_main( void )
{
    //SetDrawScreen(DX_SCREEN_BACK);
    //SetDrawMode(DX_DRAWMODE_BILINEAR);
    int i ;
    int PosX, PosY ;
    int GHandle ;
    SetGraphMode(1920,1080, 32);
    if( DxLib_Init() == -1 )        // ＤＸライブラリ初期化処理
    {
        return -1;        // エラーが起きたら直ちに終了
    }

    // ＢＭＰ画像のメモリへの読みこみ
    GHandle = LoadGraph( "test.bmp" ) ;
    //


    // 画面左上に描画します(『DrawGraph』を使用)
    while(ProcessMessage()==0&&ClearDrawScreen()==0) {
        GetTouchInput( i, &PosX, &PosY, NULL, NULL ) ;
        DrawRotaGraphF(PosX, PosY, 1, 0, GHandle, TRUE);
        ScreenFlip();
    }
    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph( GHandle ) ;
    DxLib_End() ;            // ＤＸライブラリ使用の終了処理

    return 0 ;            // ソフトの終了
}