#pragma once
//
// Created by student03 on 2020/11/05.
//

#include "DxLib.h"

#ifndef TEST_DXLIB_ENEMY_H
#define TEST_DXLIB_ENEMY_H


class enemy {
public:
enemy();
int x,y;
int graph;
//vector<kome>;
//std::vector<int,int> enemy_vector;
enemy(int x,int y,int type);
bool control();
~enemy();
};


#endif //TEST_DXLIB_ENEMY_H
