#pragma once
//
// Created by spyk4 on 2020/11/08.
//
#include "DxLib.h"
#include "vector"
#include "player.h"

#ifndef TEST_DXLIB_TAMA_H
#define TEST_DXLIB_TAMA_H
class tama {
public:
    double x=0.0,y=0.0;
    int* graph;
    int size=30;
    std::vector<double> tama_vector;
    int frame;
    bool mikata;
    tama();
    tama(int x,int y,std::vector<double> vector,int* graph,player* pl,bool mikata);
    ~tama();
    void draw();
    void control();
    bool collision(int fx,int fy);
};


#endif //TEST_DXLIB_TAMA_H
