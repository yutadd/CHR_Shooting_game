//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
enemy::enemy(){

}
enemy::enemy(int x,int y,int type,int kyara){
    graph=kyara;
    enemy::x=x;
    enemy::type=type;
    enemy::y=y;
};
bool enemy::control(){
    ene_frame+=1;
    switch(type){
        case 0:
            if(ene_frame<=5){
                enemy_vector.x=2;
                enemy_vector.y=4;
            }else if(ene_frame==80){
                enemy_vector.x=-3;
                enemy_vector.y=2;
            }else if(ene_frame==160){
                enemy_vector.x=0;
                enemy_vector.y=4;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            DrawRotaGraphF((int)x,(int)y,1.4,0,graph,1);
            break;
        case 1:
            if(ene_frame<=5){
                enemy_vector.x=-2;
                enemy_vector.y=4;
            }else if(ene_frame==80){
                enemy_vector.x=3;
                enemy_vector.y=2;
            }else if(ene_frame==160){
                enemy_vector.x=0;
                enemy_vector.y=4;
            }
            y+=enemy_vector.y;
            x+=enemy_vector.x;
            DrawRotaGraphF((int)x,(int)y,1.4,0,graph,1);
            break;
    }
   return true;
}
enemy::~enemy() {

}
