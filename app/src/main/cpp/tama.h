//
// Created by spyk4 on 2020/11/08.
//
#include "DxLib.h"
#include "vector"
#ifndef TEST_DXLIB_TAMA_H
#define TEST_DXLIB_TAMA_H


class tama {
public:
    int x=0,y=0;
    int* graph;
    VECTOR tama_vector;
    int frame;
    tama();
    tama(int x,int y,VECTOR vector,int* graph);
    ~tama();
    void draw();
    void control();
};


#endif //TEST_DXLIB_TAMA_H
