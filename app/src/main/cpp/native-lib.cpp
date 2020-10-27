#include "DxLib.h"

int android_main( void )
{
    int i ;
    int PosX=300, PosY =300;
    int back;
    int frames=0;
    int title;
    int kyara[12];
    int taskbar;
SetGraphMode( 1280 , 720, 32 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    back=LoadGraph("back.png",false);
    title=LoadGraph("title.png",false);
    taskbar=LoadGraph("taskbar.png");
    LoadDivGraph("kyara.png",12,3,4,48,48,kyara);
    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // メインループ
    long time;
    long nowtime;
    int fps=0.0f;
    time = GetNowHiPerformanceCount();
    int title_size=1;
    bool title_b=false;
    while( ProcessMessage() == 0 ) {
        frames++;
       // if (frames % 10==0) {
        if (title_b) {
            title_size++;
            if (title_size > 15) {
                title_b = false;
            }
        } else {
            title_size--;
            if (title_size < 2) {
                title_b = true;
            }
        }
    //}
        ClearDrawScreen() ;
        nowtime = GetNowHiPerformanceCount();
        fps = 1000000 / (nowtime - time);
        time = nowtime;
        //back.png
        //DrawRotaGraphF(640,360,1,0,back,false);
        DrawRotaGraphF(1106,360,1,0,taskbar,false);

        // タッチされている箇所の数だけ繰り返し
        for( i = 0 ; i < GetTouchInputNum() ; i ++ )
        {
            if(GetTouchInputNum()>0) {
                // タッチされている箇所の座標を取得
                GetTouchInput(i, &PosX, &PosY, NULL, NULL);
            }
        }
        DrawRotaGraphF(PosX, PosY, 1.5, 0, kyara[11], true);
        DrawRotaGraphF(500, 150, 1+((double)title_size/100), 0, title, true);
        // 裏画面の内容を表画面に反映
        DrawFormatStringF(1000, 0, GetColor(255, 255, 255), "FPS:%i", fps);
        ScreenFlip() ;
    }

    // ＤＸライブラリの後始末
    DxLib_End() ;

    // ソフトの終了
    return 0 ;
}