//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
#include "player.h"
#include "cmath"
#include "vector"
#include "thread"
#include <random>
#define PI    3.1415926535897932384626433832795f
std::vector<double> vect[2];

enemy::enemy(){

}
enemy::enemy(int x,int y,int type,int* kyara,int* tama_gra,player* pl){
    enemy::graph=kyara;
    enemy::x=x;
    enemy::type=type;
    enemy::y=y;
    enemy::tama_gra=tama_gra;
    enemy::pl=pl;

};
VECTOR normal(VECTOR v){
    float norm2=std::sqrt(v.x * v.x + v.y * v.y);
    float mag=1/norm2;
    float x=v.x*mag;
    float y=v.y*mag;
    VECTOR ret=VECTOR{x,y};
    return ret;
}
void enemy::control(){
    ene_frame+=1;
    if(!isdead) {
        switch (type) {
            //右、右下に進み、3発程度発射、画面外に移動
            case 0:
                if (ene_frame <= 5) {
                    enemy_vector.x = 6;
                    enemy_vector.y = 12;
                } else if (ene_frame == 60) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    enemy_vector.x = -9;
                    enemy_vector.y = 6;
                } else if (ene_frame == 80) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 100) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 120) {
                    enemy_vector.x = 12;
                    enemy_vector.y = 3;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //右、右下に進み、3発程度発射、画面外に移動
            case 1:
                if (ene_frame <= 5) {
                    enemy_vector.x = -6;
                    enemy_vector.y = 12;
                } else if (ene_frame == 60) {

                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    enemy_vector.x = 9;
                    enemy_vector.y = 6;
                } else if (ene_frame == 80) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 100) {
                    double _rad = atan2(pl->y - y, pl->x - x);
                    std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                    tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                } else if (ene_frame == 120) {
                    enemy_vector.x = -12;
                    enemy_vector.y = 3;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //下に進み、右に漂うように移動。中間で、円形に発射
            case 2:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 6;
                } else if (ene_frame == 60) {
                    int kosu = 15;
                    int kakudo = 0;
                    float hanni = 2;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * hanni) + kakudo;
                        float fx = (360 * cos(_rad)) + x;
                        float fy = (360 * sin(_rad)) + y;
                        //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                        tamas.push_back(
                                tama(x, y, std::vector<double>{(fx - x) / 60, (fy - y) / 60},
                                     tama_gra, pl, false));
                    }
                    enemy_vector.x = 9;
                    enemy_vector.y = -3;
                } else if (ene_frame == 100) {
                    enemy_vector.x = 9;
                    enemy_vector.y = 3;
                } else if (ene_frame == 140) {
                    enemy_vector.x = 9;
                    enemy_vector.y = -3;
                } else if (ene_frame == 180) {
                    enemy_vector.x = 9;
                    enemy_vector.y = 3;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //左,下に進み、左に漂うように移動する、中間で、弾を発射する。
            case 3:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 6;
                } else if (ene_frame == 60) {
                    int kosu = 15;
                    int kakudo = 0;
                    float hanni = 2;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * hanni) + kakudo;
                        float fx = (360 * cos(_rad)) + x;
                        float fy = (360 * sin(_rad)) + y;
                        //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                        tamas.push_back(
                                tama(x, y, std::vector<double>{(fx - x) / 60, (fy - y) / 60},
                                     tama_gra, pl, false));
                    }
                    enemy_vector.x = -9;
                    enemy_vector.y = -3;
                } else if (ene_frame == 100) {
                    enemy_vector.x = -9;
                    enemy_vector.y = 3;
                } else if (ene_frame == 140) {
                    enemy_vector.x = -9;
                    enemy_vector.y = -3;
                } else if (ene_frame == 180) {
                    enemy_vector.x = -9;
                    enemy_vector.y = 3;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //任意、上から下へ少し移動した後、半円状に下に発射する。
            case 4:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 9;
                } else if (ene_frame == 40) {
                    double kosu = 8.0;
                    double kakudo = 0.3;
                    double hanni = 1;
                    for (double i = 0.0; i < kosu; i++) {
                        double _rad = ((i / kosu) * DX_PI * hanni) + kakudo;
                        double fx = (360 * cos(_rad)) + (float) x;
                        double fy = (360 * sin(_rad)) + (float) y;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }

                    enemy_vector.x = 0;
                    enemy_vector.y = 0;
                } else if (ene_frame == 100) {
                    enemy_vector.x = -0;
                    enemy_vector.y = -9;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //左から右、途中で円形に発射
            case 5:
                if (ene_frame == 5) {
                    enemy_vector.x = 10;
                } else if (ene_frame == 100) {
                    int kosu = 20;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * 2) + 0;
                        //float fx = (10 * cos(_rad)) + x;
                        //float fy = (10 * sin(_rad)) + y;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //右から左、途中で円形に発射
            case 6:
                if (ene_frame <= 5) {
                    enemy_vector.x = -10;
                } else if (ene_frame == 100) {
                    int kosu = 20;
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((i / kosu) * PI * 2) + 0;
                        //float fx = (10 * cos(_rad)) + x;
                        //float fy = (10 * sin(_rad)) + y;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
                //上から下、ランダム方向４つに５回発射
            case 7:
                if (ene_frame <= 5) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 9;
                } else if (ene_frame == 100) {
                    enemy_vector.x = 0;
                    enemy_vector.y = 0;
                    std::random_device rnd;
                    std::mt19937 mt(rnd());
                    std::uniform_real_distribution<> rand100(0, 10);
                    int kosu = 2;
                    srand(time(NULL));
                    for (double i = 0; i < kosu; i++) {
                        double _rad = ((rand100(mt) / 10) * PI * 1) - 0.1;
                        //float fx = (10 * cos(_rad)) + x;
                        //float fy = (10 * sin(_rad)) + y;
                        std::vector<double> v = {18 * cos(_rad), 18 * sin(_rad)};
                        vect[(int) i] = v;
                        tamas.push_back(tama(x, y, v, tama_gra, pl, false));
                    }
                } else if (ene_frame == 110) {
                    for (int i = 0; i < 2; i++) {
                        tamas.push_back(tama(x, y, vect[i], tama_gra, pl, false));
                    }

                } else if (ene_frame == 120) {
                    for (int i = 0; i < 2; i++) {
                        tamas.push_back(tama(x, y, vect[i], tama_gra, pl, false));
                    }

                } else if (ene_frame == 130) {
                    for (int i = 0; i < 2; i++) {
                        tamas.push_back(tama(x, y, vect[i], tama_gra, pl, false));
                    }

                } else if (ene_frame == 140) {
                    for (int i = 0; i < 2; i++) {
                        tamas.push_back(tama(x, y, vect[i], tama_gra, pl, false));
                    }

                } else if (ene_frame == 150) {
                    for (int i = 0; i < 2; i++) {
                        tamas.push_back(tama(x, y, vect[i], tama_gra, pl, false));
                    }

                } else if (ene_frame == 200) {
                    enemy_vector.x = 0;
                    enemy_vector.y = -9;
                }
                y += enemy_vector.y;
                x += enemy_vector.x;
                break;
        }
    }
}

void enemy::draw(){
    //DrawFormatString((float)pl->x,(float)pl->y,GetColor(255,255,255),"%d",pl->y);
    if(!isdead){
        DrawRotaGraphF((int)x,(int)y,3.0,0,*graph,1);
    }
}
enemy::~enemy() {

}
