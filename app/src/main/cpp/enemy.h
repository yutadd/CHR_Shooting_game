#pragma once
//
// Created by student03 on 2020/11/05.
//

#include "DxLib.h"
#include "vector"
#ifndef TEST_DXLIB_ENEMY_H
#define TEST_DXLIB_ENEMY_H


class enemy {
public:
enemy();
int x,y;
int type;
int graph;
int ene_frame;
int gazo=LoadGraph("exit.bmp");
//vector<kome>;
VECTOR enemy_vector;
enemy(int x,int y,int type, int graph);
bool control();
~enemy();
};


#endif //TEST_DXLIB_ENEMY_H
