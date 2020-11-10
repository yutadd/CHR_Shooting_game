//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
#include "player.h"
#include "cmath"
#include "vector"
#include "thread"
#define PI    3.1415926535897932384626433832795f
double add(double a,double b){
    a*=10;
    b*=10;
    a+=b;
    return a/10;
}
/*
 *
 * �ǉ����Fdouble�덷�Ȃ��v�Z
 * */

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
    switch(type){
        //�E�A�E���ɐi�݁A��^�𒆉��Ɍ����Ĕ��˂��A��ʊO�Ɉړ�
        case 0:
            if(ene_frame<=5){
                enemy_vector.x=2;
                enemy_vector.y=4;
            }else if(ene_frame==60){

                /*int kosu=10;
                for (double i = 0; i < kosu; i++) {
                    double _rad = ((i / kosu) * PI * 2) + 0;
                    double fx = (100 * cos(_rad)) + x;
                    double fy = (100 * sin(_rad)) + y;
                    double dx=(3*cos(_rad));
                    double dy=(3*sin(_rad));
                    std::vector<double> v={dx,dy};
                    tamas.push_back(tama(fx, fy,v,tama_gra));
                }*/
                int kosu=9;
                int kakudo=2;
                float hanni=0.2;
                for (double i = 0; i < kosu; i++) {
                    double _rad = ((i / kosu) * PI * hanni) + kakudo;
                    float fx = (360 * cos(_rad)) + x;
                    float fy = (360 * sin(_rad)) + y;
                    //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                    tamas.push_back(tama(x, y,std::vector<double>{ (fx-x)/60,(fy-y)/60 },tama_gra,pl));
                }
                enemy_vector.x=-3;
                enemy_vector.y=2;
            }else if(ene_frame==120){
                enemy_vector.x=4;
                enemy_vector.y=1;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
            //��,�����ɐi�݁A��^�ɒ��������Ŕ���
        case 1:
            if(ene_frame<=5){
                enemy_vector.x=-2;
                enemy_vector.y=4;
            }else if(ene_frame==60){
                int kosu=9;
                int kakudo=7;
                float hanni=0.2;
                for (double i = 0; i < kosu; i++) {
                    double _rad = ((i / kosu) * PI * hanni) + kakudo;
                    float fx = (360 * cos(_rad)) + x;
                    float fy = (360 * sin(_rad)) + y;
                    //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                    tamas.push_back(tama(x, y,std::vector<double>{ (fx-x)/60,(fy-y)/60 },tama_gra,pl));
                }
                enemy_vector.x=3;
                enemy_vector.y=2;
            }else if(ene_frame==120){
                enemy_vector.x=-4;
                enemy_vector.y=1;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
        //���ɐi�݁A�E�ɕY���悤�Ɉړ��B���ԂŁA�~�`�ɔ���
        case 2:
            if(ene_frame<=5){
                enemy_vector.x=0;
                enemy_vector.y=2;
            }else if(ene_frame==60){
                int kosu=15;
                int kakudo=0;
                float hanni=2;
                for (double i = 0; i < kosu; i++) {
                    double _rad = ((i / kosu) * PI * hanni) + kakudo;
                    float fx = (360 * cos(_rad)) + x;
                    float fy = (360 * sin(_rad)) + y;
                    //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                    tamas.push_back(tama(x, y,std::vector<double>{ (fx-x)/60,(fy-y)/60 },tama_gra,pl));
                }
                enemy_vector.x=3;
                enemy_vector.y=-1;
            }else if(ene_frame==100){
                enemy_vector.x=3;
                enemy_vector.y=1;
            }else if(ene_frame==140){
                enemy_vector.x=3;
                enemy_vector.y=-1;
            }else if(ene_frame==180){
                enemy_vector.x=3;
                enemy_vector.y=1;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
            //��,���ɐi�݁A���ɕY���悤�Ɉړ�����A���ԂŁA�e�𔭎˂���B
        case 3:
            if(ene_frame<=5){
                enemy_vector.x=0;
                enemy_vector.y=2;
            }else if(ene_frame==60){
                int kosu=15;
                int kakudo=0;
                float hanni=2;
                for (double i = 0; i < kosu; i++) {
                    double _rad = ((i / kosu) * PI * hanni) + kakudo;
                    float fx = (360 * cos(_rad)) + x;
                    float fy = (360 * sin(_rad)) + y;
                    //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                    tamas.push_back(tama(x, y,std::vector<double>{ (fx-x)/60,(fy-y)/60 },tama_gra,pl));
                }
                enemy_vector.x=-3;
                enemy_vector.y=-1;
            }else if(ene_frame==100){
                enemy_vector.x=-3;
                enemy_vector.y=1;
            }else if(ene_frame==140){
                enemy_vector.x=-3;
                enemy_vector.y=-1;
            }else if(ene_frame==180){
                enemy_vector.x=-3;
                enemy_vector.y=1;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
            //�C�ӁA�ォ�牺�֏����ړ�������A���~��ɉ��ɔ��˂���B
        case 4:
            if(ene_frame<=5){
                enemy_vector.x=0;
                enemy_vector.y=3;
            }else if(ene_frame==40){
                double kosu=8.0;
                double kakudo=0.3;
                double hanni=1;
                for (double i = 0.0; i < kosu; i++) {
                    double _rad = ((i / kosu) * DX_PI * hanni) + kakudo;
                    double fx = (360 * cos(_rad)) + (float)x;
                    double fy = (360 * sin(_rad)) + (float)y;
                    //komes.push_back(kome((float)x, (float)y, image, VECTOR{ (float)(center_x - x) / 140,(float)(center_y - y) / 140 }, false, 0));
                    tamas.push_back(tama(x, y,std::vector<double>{ (float)(fx-(float)x)/60.0f,(float)(fy-(float)y)/60.0f },tama_gra,pl));
                }

                enemy_vector.x=0;
                enemy_vector.y=0;
            }else if(ene_frame==100){
                enemy_vector.x=-0;
                enemy_vector.y=-3;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
    }
}

void enemy::draw(){
    //DrawFormatString((float)pl->x,(float)pl->y,GetColor(255,255,255),"%d",pl->y);
    DrawRotaGraphF((int)x,(int)y,1.9,0,*graph,1);
}
enemy::~enemy() {

}
