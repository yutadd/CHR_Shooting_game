//
// Created by student03 on 2020/11/05.
//
#include "enemy.h"
#include "DxLib.h"
int graph=0;
enemy::enemy(){

}
enemy::enemy(int x,int y,int type){

};
bool enemy::control(){
    DrawRotaGraphFast(0, 0, (float)1.2, (float)0.0,0,0);
    return true;
}
