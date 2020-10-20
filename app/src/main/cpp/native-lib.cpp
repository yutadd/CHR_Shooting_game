#include "DxLib.h"
#include "iostream"

// プログラムは android_main から始まります
int android_main( void )
{
    int Sx , Sy , Cb ;
    GetScreenState( &Sx , &Sy , &Cb ) ;
    SetGraphMode( Sx , Sy , Cb ) ;
    int i ;
    int PosX, PosY ;
    if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
    {
        return -1 ;			// エラーが起きたら直ちに終了
    }
    while( ProcessMessage() == 0 )
    {
        ClearDrawScreen();
        DrawBox( 220, 140, 420, 340, GetColor( 255,255,255 ), TRUE ) ;	// 四角形を描画する
        GetTouchInput( i, &PosX, &PosY, NULL, NULL );
        printfDx("%s\n", &PosX);
        LoadGraphScreen( PosX, PosY, "test.bmp" , TRUE ) ;
    ScreenFlip() ;
    }
    //WaitKey() ;				// キー入力待ち
    DxLib_End() ;				// ＤＸライブラリ使用の終了処理
    return 0 ;					// ソフトの終了
}