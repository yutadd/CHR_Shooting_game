//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
enemy::enemy(){

}
enemy::enemy(int x,int y,int type){
    LoadDivGraph("kyara.bmp",96,12,8,48,48,graph);
};
bool enemy::control(){
    DrawFormatString(100, 0, GetColor(255, 255, 255), "AAAAAAAAAAAAAAAAAAAAA");
    return true;
}
enemy::~enemy() {

}
