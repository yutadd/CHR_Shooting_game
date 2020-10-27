#include "DxLib.h"

int android_main( void )
{
    int touch_num=0;
    int PosX=300, PosY =400;
    int back;
    int frames=0;
    int title;
    int screen=0;
    int start_button;
    int kyara[12];
    int taskbar;
    SetGraphMode( 1280 , 720, 32 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    back=LoadGraph("back2.png");
    title=LoadGraph("title.png");
    taskbar=LoadGraph("taskbar.png");
    start_button=LoadGraph("start.png");
    LoadDivGraph("kyara.png",12,3,4,48,48,kyara);
    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;

    // メインループ
    long time;
    long nowtime;
    int fps=0.0f;
    time = GetNowHiPerformanceCount();
    int title_size=1;
    int tempx;
    int tempy;
    bool title_b=false;
    while(ProcessMessage()==0){
        if(screen==0){
                while( ProcessMessage() == 0) {
                    frames++;
                    // if (frames % 10==0) {
                    if (title_b) {
                        title_size++;
                        if (title_size > 50) {
                            title_b = false;
                        }
                    } else {
                        title_size--;
                        if (title_size < 2) {
                            title_b = true;
                        }
                    }
                    GetTouchInput(touch_num, &tempx, &tempy);
                    if(GetTouchInputNum()>0) {
                        // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                        if(350<tempx && 370<tempy&&tempx<520&&426>tempy){
                            screen=1;
                            break;
                        }
                    }
                    ClearDrawScreen() ;
                    nowtime = GetNowHiPerformanceCount();
                    fps = 1000000 / (nowtime - time);
                    time = nowtime;
                    //back.png
                    //DrawRotaGraphF(640,360,1,0,back,false);
                    DrawGraph(0, 0, back,true);
                    DrawRotaGraphF(1106,360,1,0,taskbar,false);
                    // タッチされている箇所の数だけ繰り返し
                    DrawRotaGraphF(300, 400, 1.5, 0, kyara[11], true);
                    DrawRotaGraphF(400, 200, 1+((double)title_size/300), 0, title, true);
                    DrawGraph(350, 370, start_button,true);
                    // 裏画面の内容を表画面に反映
                    DrawFormatStringF(1000, 0, GetColor(255, 255, 255), "FPS:%i", fps);
                    ScreenFlip() ;
                }
        }else if(screen==1){
            while( ProcessMessage() == 0) {
                frames++;
                ClearDrawScreen() ;
                DrawRotaGraphF(1106,360,1,0,taskbar,false);

                ScreenFlip() ;
            }
        }
    }
    // ＤＸライブラリの後始末
    DxLib_End() ;
    // ソフトの終了
    return 0 ;
}