#pragma once
//
// Created by student03 on 2020/11/05.
//

#include "DxLib.h"
#include "tama.h"
#include "player.h"
#include "vector"
#ifndef TEST_DXLIB_ENEMY_H
#define TEST_DXLIB_ENEMY_H


class enemy {
public:
    std::vector<tama> tamas;
    enemy();
    player* pl;
    int x,y;
    int type;
    int ene_ani=0;
    int health=0;
    int ext=3;
    int* graph;
    int ususa=0;
    int dieing=-1;
    int kaiwa=0;
    int* tama_gra;
    bool show_ani=false;
    int ene_frame=0;
    bool isdead=false;
//vector<kome>;
    VECTOR enemy_vector;
    enemy(int x,int y,int type, int* graph,int* tama_gra,player* pl);
    void control();
    ~enemy();
    void draw();
};


#endif //TEST_DXLIB_ENEMY_H
