#include "DxLib.h"
#include "unistd.h"
#include "thread"
#include "unistd.h"
#include "enemy.h"

#define PI    3.1415926535897932384626433832795f
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
    int chr;
    int exit;
    void sce();
    int right;

    int taskbar;
    SetGraphMode( 1280 , 720, 32,60 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    back=LoadGraph("back2.png");
    chr=LoadGraph("chr.png");
    exit=LoadGraph("exit.bmp");
    right=LoadGraph("right.bmp");
    title=LoadGraph("title.bmp");
    taskbar=LoadGraph("taskbar.png");
    start_button=LoadGraph("start.bmp");
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
        }else if(screen==1){
            while( ProcessMessage() == 0) {
                frames++;
                ClearDrawScreen() ;
                DrawGraph(0, 0, back,true);
                ScreenFlip() ;
            }
            //ステージ
        }else if(screen==2){
            int bgm=LoadSoundMem("stage.mp3");
            PlaySoundMem(bgm,DX_PLAYTYPE_LOOP);
            while( ProcessMessage() == 0) {
                frames++;
                ClearDrawScreen() ;
                std::thread th_1(sce);

                th_1.detach();
                DrawGraph(0, 0, back,true);
                ScreenFlip() ;
            }
        }
    }
    // ＤＸライブラリの後始末
    DxLib_End() ;
    // ソフトの終了
    return 0 ;
}
//どこで敵キャラは移動させる？
//↑敵キャラにvectorを持たせて、弾の移動ついでに移動させる
void sce(){
usleep(1000*1000);
}