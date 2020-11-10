#include "DxLib.h"
#include "scenario.h"
#include "thread"
#include "enemy.h"
#include "vector"
#include "unistd.h"
#include "player.h"

std::vector<enemy> en;
int kyara[96];
int enes[96];
int tama_gra[48];
player player1;
int screen=0;
int android_main( void )
{
    int touch_num=0;
    int PosX=300, PosY =400;
    int back;
    int frames=0;
    int title;

    int start_button;

    int exit;
    void sce();

    void controler();
    void controler_t();

    int right;
    int taskbar;
    int vect;
    int levels;
    int easy;

    int normal;
    int hard;
    int level;
    int fonts[63];
    SetGraphMode( 1280 , 720, 32,60 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    level=2;
    back=LoadGraph("back2.png");
    easy=LoadGraph("easy.png");
    normal=LoadGraph("normal.png");
    hard=LoadGraph("hardl.png");
    vect=LoadGraph("vector3.png");
    exit=LoadGraph("exit.bmp");
    right=LoadGraph("right.bmp");
    title=LoadGraph("title.bmp");
    levels=LoadGraph("levels.png");
    taskbar=LoadGraph("taskbar.png");
    start_button=LoadGraph("start.bmp");
    LoadDivGraph("kyara.bmp",96,12,8,48,48,kyara);
    LoadDivGraph("fontk2.png",64,16,4,22,35,fonts);
    LoadDivGraph("enes.png",96,12,8,48,48,enes);
    LoadDivGraph("tama3.png",48,24,2,10,10,tama_gra);
    // 描画先を裏画面にする
    SetDrawScreen( DX_SCREEN_BACK ) ;
    player1=player(kyara[38]);
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
            SetFontSize(20);
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
                ScreenFlip();
                GetTouchInput(touch_num, &tempx, &tempy);
                if(GetTouchInputNum()>0) {
                    // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                    if(450<tempx && 150<tempy&&tempx<850&&300>tempy){
                        screen=2;
                        break;
                    }
                }
            }
        }else if(screen==2){

            SetFontSize(50);
            int FontHandle = CreateFontToHandle( NULL, 16, 0 ) ;
            AddFontImageToHandle(FontHandle,"0",fonts[47],0,0,27) ;
            AddFontImageToHandle(FontHandle,":",fonts[26],0,0,27) ;
            AddFontImageToHandle(FontHandle,"s",fonts[51],0,-3,27) ;
            AddFontImageToHandle(FontHandle,"c",fonts[35],0,0,27) ;
            AddFontImageToHandle(FontHandle,"o",fonts[47],0,0,27) ;
            AddFontImageToHandle(FontHandle,"r",fonts[50],0,-3,27) ;
            AddFontImageToHandle(FontHandle,"e",fonts[37],0,0,27) ;

            std::thread th(sce);
            th.detach();
            std::thread th_2(controler);
            th_2.detach();
            std::thread th_3(controler_t);
            th_3.detach();
            while(ProcessMessage() == 0&&screen==2){
                frames++;
                ClearDrawScreen();
                DrawGraph(0, 0, back, true);
                player1.control();
                for(int i=0;i<en.size();i++){
                    en[i].draw();
                    for(int n=0;n<en[i].tamas.size();n++){
                        en[i].tamas[n].draw();
                    }

                }
                DrawRotaGraphF(1106,360,1,0,taskbar,false);
                DrawGraph(1000, 500, vect, true);
                SetFontSize(40);
                DrawFormatStringToHandle(970,100,GetColor(255,255,255),FontHandle,"score",player1.score);
                DrawFormatStringToHandle(1010,130,GetColor(255,255,255),FontHandle,"%d00000",player1.score);
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
    while(true) {
        usleep(1000 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 0, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 0, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 0, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 0, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 2, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 3, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 2, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 3, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(650, -50, 2, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 3, &enes[1], &tama_gra[24], &player1));
        if (screen != 2)return;
        usleep(3000 * 1000);
        en.push_back(enemy(650, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(550, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(450, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 4, &enes[4], &tama_gra[24], &player1));
        usleep(3000 * 1000);
        //screen=0;
    }
}
void controler(){
    while(screen==2){
        for(int i=0;i<en.size();i++){
            en[i].control();
            for(int n=0;n<en[i].tamas.size();n++){
                en[i].tamas[n].control();
                if(en[i].tamas[n].collision()){
                    screen=0;
                }
            }
        }
        usleep(20*1000);
    }
    en.clear();
}
void controler_t(){
    /*while(true){
        for(int i=0;i<en.size();i++){
            for(int n=0;n<en[i].tamas.size();n++){
                en[i].tamas[n].control();
            }
        }
        usleep(20*1000);
    }*/

}