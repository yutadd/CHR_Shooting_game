//
// Created by spyk4 on 2020/11/06.
//
#include "DxLib.h"
#ifndef TEST_DXLIB_PLAYER_H
#define TEST_DXLIB_PLAYER_H


class player {
public:
    long score=0;
    long frames=0;
    int tama_pushing=0;
    int size=1;
    int x=500,y=500;
    int tempx=0,tempy=0;
    player();
    void control();
    player(int kyara);
    int pkyara;
    ~player();
};


#endif //TEST_DXLIB_PLAYER_H
