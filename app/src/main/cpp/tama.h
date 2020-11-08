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
    int type;
    VECTOR tama_vector;
    tama();
    ~tama();
    void draw();
    void control();
};


#endif //TEST_DXLIB_TAMA_H
