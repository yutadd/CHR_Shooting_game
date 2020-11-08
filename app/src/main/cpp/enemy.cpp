//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
#include "thread"
enemy::enemy(){

}
enemy::enemy(int x,int y,int type,int kyara){
    graph=kyara;
    enemy::x=x;
    enemy::type=type;
    enemy::y=y;

};
void enemy::control(){
    ene_frame+=1;
    switch(type){
        case 0:
            if(ene_frame<=5){
                enemy_vector.x=2;
                enemy_vector.y=4;
            }else if(ene_frame==60){
                enemy_vector.x=-3;
                enemy_vector.y=2;
            }else if(ene_frame==120){
                enemy_vector.x=4;
                enemy_vector.y=1;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
        case 1:
            if(ene_frame<=5){
                enemy_vector.x=-2;
                enemy_vector.y=4;
            }else if(ene_frame==60){
                enemy_vector.x=3;
                enemy_vector.y=2;
            }else if(ene_frame==120){
                enemy_vector.x=-4;
                enemy_vector.y=1;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            break;
    }
}
void enemy::draw(){
    DrawRotaGraphF((int)x,(int)y,1.4,0,graph,1);
}
enemy::~enemy() {

}
