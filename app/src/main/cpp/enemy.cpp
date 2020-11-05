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
    enemy::y=y;
};
bool enemy::control(){
    DrawGraph(x,y,graph,0);
    return true;
}
enemy::~enemy() {

}
