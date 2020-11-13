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
int title_haikei;
    int right;
    int taskbar;
    int vect;
    int levels;
    int easy;

    int normal;
    int hard;
    int level;
    int fonts[75];
    SetGraphMode( 3840 , 2160, 32,60 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    level=2;
    back=LoadGraph("haikei.png");
    title_haikei=LoadGraph("haikei.jpg");
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
    LoadDivGraph("font_.png",75,15,5,82,173,fonts);
    LoadDivGraph("enes.png",96,12,8,48,48,enes);
    LoadDivGraph("tama3.png",48,24,2,10,10,tama_gra);
    int FontHandle = CreateFontToHandle( NULL, 16, 0 ) ;
    AddFontImageToHandle(FontHandle,"1",fonts[0],0,0,82) ;
    AddFontImageToHandle(FontHandle,"2",fonts[1],0,0,82) ;
    AddFontImageToHandle(FontHandle,"3",fonts[2],0,0,82) ;
    AddFontImageToHandle(FontHandle,"4",fonts[3],0,0,82) ;
    AddFontImageToHandle(FontHandle,"5",fonts[4],0,0,82) ;
    AddFontImageToHandle(FontHandle,"6",fonts[5],0,0,82) ;
    AddFontImageToHandle(FontHandle,"7",fonts[6],0,0,82) ;
    AddFontImageToHandle(FontHandle,"8",fonts[7],0,0,82) ;
    AddFontImageToHandle(FontHandle,"9",fonts[8],0,0,82) ;
    AddFontImageToHandle(FontHandle,"0",fonts[9],0,0,82) ;
    AddFontImageToHandle(FontHandle,"a",fonts[10],0,0,82) ;
    AddFontImageToHandle(FontHandle,"b",fonts[11],0,0,82) ;
    AddFontImageToHandle(FontHandle,"c",fonts[12],0,0,82) ;
    AddFontImageToHandle(FontHandle,"d",fonts[13],0,0,82) ;
    AddFontImageToHandle(FontHandle,"e",fonts[14],0,0,82) ;
    AddFontImageToHandle(FontHandle,"f",fonts[15],0,0,82) ;
    AddFontImageToHandle(FontHandle,"g",fonts[16],0,0,82) ;
    AddFontImageToHandle(FontHandle,"h",fonts[17],0,0,82) ;
    AddFontImageToHandle(FontHandle,"i",fonts[18],0,0,82) ;
    AddFontImageToHandle(FontHandle,"j",fonts[19],0,0,82) ;
    AddFontImageToHandle(FontHandle,"k",fonts[20],0,0,82) ;
    AddFontImageToHandle(FontHandle,"l",fonts[21],0,0,82) ;
    AddFontImageToHandle(FontHandle,"m",fonts[22],0,0,82) ;
    AddFontImageToHandle(FontHandle,"n",fonts[23],0,0,82) ;
    AddFontImageToHandle(FontHandle,"o",fonts[24],0,0,82) ;
    AddFontImageToHandle(FontHandle,"p",fonts[25],0,0,82) ;
    AddFontImageToHandle(FontHandle,"q",fonts[26],0,0,82) ;
    AddFontImageToHandle(FontHandle,"r",fonts[27],0,0,82) ;
    AddFontImageToHandle(FontHandle,"s",fonts[28],0,0,82) ;
    AddFontImageToHandle(FontHandle,"t",fonts[29],0,0,82) ;
    AddFontImageToHandle(FontHandle,"u",fonts[30],0,0,82) ;
    AddFontImageToHandle(FontHandle,"v",fonts[31],0,0,82) ;
    AddFontImageToHandle(FontHandle,"w",fonts[32],0,0,82) ;
    AddFontImageToHandle(FontHandle,"x",fonts[33],0,0,82) ;
    AddFontImageToHandle(FontHandle,"y",fonts[34],0,0,82) ;
    AddFontImageToHandle(FontHandle,"z",fonts[35],0,0,82) ;
    AddFontImageToHandle(FontHandle," ",fonts[36],0,0,82) ;
    AddFontImageToHandle(FontHandle,"!",fonts[37],0,0,82) ;
    AddFontImageToHandle(FontHandle,"%",fonts[38],0,0,82) ;
    AddFontImageToHandle(FontHandle,"(",fonts[39],0,0,82) ;
    AddFontImageToHandle(FontHandle,")",fonts[40],0,0,82) ;
    AddFontImageToHandle(FontHandle,"-",fonts[41],0,0,82) ;
    AddFontImageToHandle(FontHandle,"@",fonts[42],0,0,82) ;
    AddFontImageToHandle(FontHandle,":",fonts[69],0,0,82) ;

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
            int animation_start=3840;
            int animation_exit=3840;
            while( ProcessMessage() == 0) {
                if(animation_kyara<990)animation_kyara+=42;
                if(animation_title<1200)animation_title+=42;
                if(animation_start>2790)animation_start-=30;
                if(animation_exit>2700)animation_exit-=30;
                frames++;
                ClearDrawScreen() ;
                nowtime = GetNowHiPerformanceCount();
                fps = 1000000 / (nowtime - time);
                time = nowtime;
                DrawGraph(0, 0, title_haikei,true);
                DrawRotaGraphF(animation_title, 600, 1.5, -0.5, title, true);
                DrawGraph(animation_start, 1010, start_button,true);
                DrawGraph(animation_exit, 1410, exit,true);
                // 裏画面の内容を表画面に反映
                DrawFormatStringF(3000, 0, GetColor(255, 255, 255), "FPS:%i", fps);
                DrawRotaGraphF(1890, /*390+*/animation_kyara, 15, 0,kyara[1], true);
                DrawRotaGraphF(1890, 2070, 0.9, 0, right, true);
                ScreenFlip() ;
                GetTouchInput(touch_num, &tempx, &tempy);
                if(GetTouchInputNum()>0) {
                    // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                    if(2790<tempx && 1010<tempy&&tempx<3468&&1400>tempy){
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
                DrawGraph(0, 0, title_haikei, true);
                DrawGraph(1050, 0, levels, true);
                DrawGraph(1350, 450, easy, true);
                DrawGraph(1350, 900, normal, true);
                DrawGraph(1350, 1350, hard, true);
                DrawRotaGraphF(450, 600+(450*level), 12, 0,kyara[26], true);
                DrawRotaGraphF(3450, 600+(450*level), 12, 0,kyara[18], true);
                ScreenFlip();
                GetTouchInput(touch_num, &tempx, &tempy);
                if(GetTouchInputNum()>0) {
                    // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                    if(1350<tempx && 450<tempy&&tempx<2550&&900>tempy){
                        screen=2;
                        break;
                    }
                }
            }
        }else if(screen==2){

            std::thread th(sce);
            th.detach();
            std::thread th_2(controler);
            th_2.detach();
            std::thread th_3(controler_t);
            th_3.detach();
            while(ProcessMessage() == 0&&screen==2){
                frames++;
                ClearDrawScreen();

                player1.control();
                for(int i=0;i<en.size();i++){
                    en[i].draw();
                    for(int n=0;n<en[i].tamas.size();n++){
                        en[i].tamas[n].draw();
                    }

                }
                DrawGraph(0, 0, back, true);
                //DrawRotaGraphF(1106,360,1,0,taskbar,false);
                //DrawGraph(1000, 500, vect, true);
                DrawFormatStringToHandle(2600,390,GetColor(255,255,255),FontHandle,"score:%07d",player1.score);
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
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(1050, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(1050, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (screen != 2)return;
        en.push_back(enemy(1050, -50, 1, &enes[1], &tama_gra[24], &player1));
        if (screen != 2)return;
        usleep(3000 * 1000);
        en.push_back(enemy(1950, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(1650, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(1350, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(1050, -50, 4, &enes[4], &tama_gra[24], &player1));
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