#include "DxLib.h"
#include "thread"
#include "enemy.h"
#include "vector"
#include "unistd.h"
#include "player.h"
/*TODO:
 * 敵にHPを追加。
 * 処理の最適化
 * */
std::vector<enemy> en;
int kyara[96];
int enes[96];
int tama_gra[48];
player player1;
int senkai=0;
int screen=0;
int shougeki;
int shougeki2;
int ptama_graph[14];
std::vector<tama> ptama;
int mahou;
int ususa=0;
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
    int title_haikei;
    int right;
    int zin;
    int taskbar;
    int vect;
    int levels;
    int easy;
    int subtitle;
    int normal;
    int hard;
    int level;
    int title_bake;
    int fonts_small[75];
    int fonts[75];
    int hart;
    int fonts_jp[2];
    SetGraphMode( 3840 , 2160, 32,60 ) ;
    // ＤＸライブラリの初期化
    if( DxLib_Init() < 0 ) return -1 ;
    level=0;
    zin=LoadGraph("zin2.png");
shougeki2=LoadGraph("shougeki2.png");
    shougeki=LoadGraph("shougeki.png");
    hart=LoadGraph("hart.png");
    subtitle=LoadGraph("subtitle.png");
    mahou=LoadGraph("maho.png");
    back=LoadGraph("haikei.png");
    title_haikei=LoadGraph("haikei.jpg");
    title_bake=LoadGraph("title_bake.png");
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
    LoadDivGraph("font_jp.png",2,2,1,196,180,fonts_jp);
    LoadDivGraph("enes.png",96,12,8,48,48,enes);
    LoadDivGraph("tama3.png",48,24,2,10,10,tama_gra);
    LoadDivGraph("tama_10.png",14,14,1,8,16,ptama_graph);
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
    AddFontImageToHandle(FontHandle,"得",fonts_jp[0],0,0,180) ;
    AddFontImageToHandle(FontHandle,"点",fonts_jp[1],0,0,180) ;
    AddFontImageToHandle(FontHandle,"♥",hart,0,0,92) ;

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
                if(animation_kyara<1200)animation_kyara+=42;
                if(animation_title<2000)animation_title+=42;
                if(animation_start>2790)animation_start-=30;
                if(animation_exit>2700)animation_exit-=30;
                frames++;
                ClearDrawScreen() ;
                nowtime = GetNowHiPerformanceCount();
                fps = 1000000 / (nowtime - time);
                time = nowtime;
                DrawGraph(0, 0, title_haikei,true);
                DrawRotaGraphF(animation_title, 400, 2.8, 0, title_bake, true);
                DrawGraph(animation_start, 1210, start_button,true);
                DrawGraph(animation_exit, 1610, exit,true);
                // 裏画面の内容を表画面に反映
                DrawFormatStringF(3000, 0, GetColor(255, 255, 255), "FPS:%i", fps);
                DrawRotaGraphF(800, /*390+*/animation_kyara, 19, 0,kyara[1], true);
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
            int step=0;
            bool down=0;
            while (ProcessMessage() == 0) {
                frames++;
                ClearDrawScreen();
                DrawGraph(0, 0, title_haikei, true);
                DrawGraph(1050, 0, levels, true);
                if(level!=0)SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
                DrawGraph(1350, 450, easy, true);
                if(level!=0)SetDrawBlendMode(DX_BLENDMODE_NOBLEND,100);
                if(level!=1)SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
                DrawGraph(1350, 900, normal, true);
                if(level!=1)SetDrawBlendMode(DX_BLENDMODE_NOBLEND,100);
                if(level!=2)SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
                DrawGraph(1350, 1350, hard, true);
                if(level!=2)SetDrawBlendMode(DX_BLENDMODE_NOBLEND,100);
                if(frames%9==0){
                    if(step==2)down=true;
                    if(step==0)down=false;
                    if(down){
                        step--;
                    }else{
                        step++;
                    }
                }

                DrawRotaGraphF(450, 600+(450*level), 12, 0,kyara[27+step], true);
                DrawRotaGraphF(3450, 600+(450*level), 12, 0,kyara[18+step], true);
                ScreenFlip();
                GetTouchInput(touch_num, &tempx, &tempy);
                if(GetTouchInputNum()>0) {
                    // タッチされている箇所の座標を取得し、ボタンの範囲内だったらスタートする
                    if(1350<tempx && 450<tempy&&tempx<2550&&900>tempy){
                        level=0;
                        screen=2;
                        break;
                    }
                }
            }
        }else if(screen==2){
            en.clear();
            senkai++;
            std::thread th(sce);
            th.detach();
            double kaiten=0;
            player1.health=7;
            std::thread th_2(controler);
            th_2.detach();
            int font01;
            font01  = CreateFontToHandle( "ＭＳ ゴシック", 120,  9, DX_FONTTYPE_NORMAL,-1,0,false);           //"MSゴシック"の50pt,太さ9のフォントを作成

            while(ProcessMessage() == 0&&screen==2){
                frames++;
                ClearDrawScreen();
                if(player1.muteki>0){
                        SetDrawBlendMode(DX_BLENDMODE_ALPHA,255-ususa);
                        ususa+=20;
                        DrawRotaGraph(player1.x,player1.y,150-player1.muteki,0,shougeki,true);
                        SetDrawBlendMode(DX_BLENDMODE_NOBLEND,200);
                }
                player1.control();
                for(int i=0;i<en.size();i++){
                    en[i].draw();
                    if(en[i].dieing!=-1&&en[i].dieing!=-2){
                        en[i].dieing-=1;
                        SetDrawBlendMode(DX_BLENDMODE_ALPHA,255-en[i].ususa);
                        en[i].ususa+=25;
                        DrawRotaGraph(en[i].x,en[i].y,(double)(10-en[i].dieing)/2.0,en[i].dieing,shougeki2,true);
                        if(en[i].dieing==0){
                            en[i].dieing=-2;
                            en[i].isdead=true;
                        }
                    }
                    for(int n=0;n<en[i].tamas.size();n++){
                        en[i].tamas[n].draw();
                    }
                }
                for(int i=0;i<ptama.size();i++){
                    ptama[i].draw();
                }
                SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
                if(frames%2==0)kaiten+=0.1;
                DrawRotaGraph(player1.x,player1.y,7,kaiten,mahou,true);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
                DrawGraph(0, 0, back, true);
                DrawFormatStringToHandle(2400,400,GetColor(0,0,0),font01,"player");
                DrawFormatStringToHandle(2395,390,GetColor(255,255,255),font01,"player");
                for(int i=0;i<player1.health;i++){
                    DrawRotaGraph(3000+(92*i),500,0.7,0,hart,true);
                }
                DrawFormatStringToHandle(2400,200,GetColor(0,0,0),font01,"得点        %07d",player1.score);
                DrawFormatStringToHandle(2395,190,GetColor(255,255,255),font01,"得点        %07d",player1.score);
                DrawRotaGraph(3100,1500,1,0,zin,true);
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
    int se=senkai;
    while(true) {
        if (se != senkai)return;
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1850, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1850, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1950, -50, 0, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(650, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(750, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(650, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(650, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(400 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(550, -50, 1, &enes[1], &tama_gra[24], &player1));
        usleep(2200 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(2250, -50, 0, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(450, -50, 1, &enes[4], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(2150, -50, 0, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(650, -50, 1, &enes[4], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1850, -50, 0, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(950, -50, 1, &enes[4], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1550, -50, 0, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(1250, -50, 1, &enes[4], &tama_gra[24], &player1));
        usleep(3000 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(2450, -50, 4, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 4, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(2150, -50, 4, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(650, -50, 4, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1850, -50, 4, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(950, -50, 4, &enes[1], &tama_gra[24], &player1));
        usleep(500 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1550, -50, 4, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(1250, -50, 4, &enes[1], &tama_gra[24], &player1));
        usleep(2000 * 1000);
        //en.push_back(enemy(2450, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(350, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(250 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(250 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(2150, -50, 4, &enes[4], &tama_gra[24], &player1));
        //en.push_back(enemy(650, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(250 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(250 * 1000);
        if (se != senkai)return;
        //en.push_back(enemy(1850, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(950, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(250 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(250 * 1000);
        if (se != senkai)return;
        en.push_back(enemy(1550, -50, 4, &enes[4], &tama_gra[24], &player1));
        //en.push_back(enemy(1250, -50, 4, &enes[4], &tama_gra[24], &player1));
        en.push_back(enemy(-50, 500, 5, &enes[7], &tama_gra[24], &player1));
        en.push_back(enemy(2500, 500, 6, &enes[7], &tama_gra[24], &player1));
        usleep(2000 * 1000);
        en.push_back(enemy(100, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(450, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(700, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(1050, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(1350, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(1650, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(1950, -50, 7, &enes[1], &tama_gra[24], &player1));
        en.push_back(enemy(2250, -50, 7, &enes[1], &tama_gra[24], &player1));
        //screen=0;
        usleep(5000 * 1000);
    }
}
void damage_player(){
    for(player1.muteki=150;player1.muteki!=0;player1.muteki--){
        usleep(20*1000);
    }
}
void die_en(int ite){
    for(int kaiten=0;kaiten<100;kaiten++){

        DrawRotaGraph(player1.x,player1.y,kaiten/10,kaiten,shougeki,true);
        usleep(20*1000);
    }
    en[ite].isdead=true;
}
void controler(){

    long frames=0;
    //50fps
    while(screen==2){
        if(frames%4==0)ptama.push_back(tama(player1.x,player1.y-120,std::vector<double>{0,-50},&ptama_graph[0],&player1,true));
        if(frames%4==0)ptama.push_back(tama(player1.x-20,player1.y,std::vector<double>{-15,-35},&ptama_graph[0],&player1,true));
        if(frames%4==0)ptama.push_back(tama(player1.x+20,player1.y,std::vector<double>{15,-35},&ptama_graph[0],&player1,true));
        if(frames%1000)for(int i=0;i<ptama.size();){if(ptama[i].x<0||ptama[i].y<0||ptama[i].x>3840||ptama[i].y>2160){ptama.erase(ptama.begin()+i);}else{i++;}}
        if(frames%1000)for(int i=0;i<en.size();i++){for(int n=0;n<en[i].tamas.size();){if(en[i].tamas[n].x<0||en[i].tamas[n].y<0||en[i].tamas[n].x>3840||en[i].tamas[n].y>2160){en[i].tamas.erase(en[i].tamas.begin()+n);}else{n++;}}}
        frames++;
        for(int i=0;i<en.size();i++){
            en[i].control();
            for(int n=0;n<en[i].tamas.size();n++){
                en[i].tamas[n].control();
                if(en[i].tamas[n].collision(player1.x,player1.y)){
                    if(player1.muteki==0){
                        ususa=0;
                        std::thread th_(damage_player);
                        th_.detach();
                        player1.health--;
                    }
                    if(player1.health<=0){
                        screen=0;
                    }
                }
            }
        }
        for(int i=0;i<ptama.size();i++){
            ptama[i].control();
            for(int n=0;n<en.size();n++){
                if(ptama[i].collision(en[n].x,en[n].y)){
                    if(en[n].dieing==-1){
                        en[n].dieing=10;
                        player1.score+=10;
                    }
                }
            }

        }
        usleep(20*1000);
    }
}