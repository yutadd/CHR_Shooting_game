#include "DxLib.h"
#include "scenario.h"
#include "thread"
#include "enemy.h"
#include "unistd.h"
int android_main( void )
{
    int touch_num=0;
    int PosX=300, PosY =400;
    int back;
    int frames=0;
    int title;
    int screen=0;
    int start_button;
    int kyara[96];
    int exit;
    void sce();
    int right;
    int taskbar;

    int levels;
    int easy;
    int normal;
    int hard;
    int level;
    SetGraphMode( 1280 , 720, 32,60 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    level=2;
    back=LoadGraph("back2.png");
    easy=LoadGraph("easy.png");
    normal=LoadGraph("normal.png");
    hard=LoadGraph("hardl.png");
    exit=LoadGraph("exit.bmp");
    right=LoadGraph("right.bmp");
    title=LoadGraph("title.bmp");
    levels=LoadGraph("levels.png");
    taskbar=LoadGraph("taskbar.png");
    start_button=LoadGraph("start.bmp");
    LoadDivGraph("kyara.bmp",96,12,8,48,48,kyara);
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
            int animation_kyara=0;
            int animation_title=0;
            int animation_start=1280;
            int animation_exit=1280;
                while( ProcessMessage() == 0) {
                    if(animation_kyara<390)animation_kyara+=14;
                    if(animation_title<400)animation_title+=14;
                    if(animation_start>930)animation_start-=10;
                    if(animation_exit>900)animation_exit-=10;
                    frames++;
                    ClearDrawScreen() ;
                    nowtime = GetNowHiPerformanceCount();
                    fps = 1000000 / (nowtime - time);
                    time = nowtime;
                    //back.png
                    //DrawRotaGraphF(640,360,1,0,back,false);
                    DrawGraph(0, 0, back,true);
                    //DrawRotaGraphF(1106,360,1,0,taskbar,false);
                    // タッチされている箇所の数だけ繰り返し
                    //DrawRotaGraphF(300, 400, 1.5, 0, kyara[11], true);
                    DrawRotaGraphF(animation_title, 200, 0.5, -0.5, title, true);
                    DrawGraph(animation_start, 370, start_button,true);
                    DrawGraph(animation_exit, 470, exit,true);
                    // 裏画面の内容を表画面に反映
                    DrawFormatStringF(1000, 0, GetColor(255, 255, 255), "FPS:%i", fps);
                    DrawRotaGraphF(630, /*390+*/animation_kyara, 5, 0,kyara[1], true);
                    DrawRotaGraphF(630, 690, 0.9, 0, right, true);
                    ScreenFlip() ;
                    GetTouchInput(touch_num, &tempx, &tempy);
                    if(GetTouchInputNum()>0) {
                        // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                        if(930<tempx && 370<tempy&&tempx<1156&&442>tempy){
                            screen=1;
                            break;
                        }
                    }
                }
                //レベル選択
        }else if(screen==1) {
            enemy en= enemy(0,0,1);

            while (ProcessMessage() == 0) {
                frames++;
                ClearDrawScreen();

                DrawGraph(0, 0, back, true);
                DrawGraph(350, 0, levels, true);
                DrawGraph(450, 150, easy, true);
                DrawGraph(450, 300, normal, true);
                DrawGraph(450, 450, hard, true);
                DrawRotaGraphF(150, 200+(150*level), 4, 0,kyara[26], true);
                DrawRotaGraphF(1150, 200+(150*level), 4, 0,kyara[18], true);
                en.control();
                ScreenFlip();
                GetTouchInput(touch_num, &tempx, &tempy);
                if(GetTouchInputNum()>0) {
                    // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                    if(930<tempx && 370<tempy&&tempx<1156&&442>tempy){
                        screen=1;
                        break;
                    }
                }
            }
        }else if(screen==2){
            std::thread th=std::thread(sce);
                while(ProcessMessage() == 0){
                    frames++;
                    ClearDrawScreen();
                    DrawRotaGraphF(1106,360,1,0,taskbar,false);
                    DrawGraph(0, 0, back, true);

                    ScreenFlip();
                }
            }
        }
    // ＤＸライブラリの後始末
    DxLib_End() ;
    // ソフトの終了
    return 0 ;
}
void sce(){
usleep(1000*1000);

}