//
// Created by spyk4 on 2020/11/06.
//

#include "DxLib.h"
#include "player.h"

player::player(int kyara) {
    pkyara=kyara;
}

player::player() {

}

player::~player() {

}

void player::control() {
    frames++;
    for(int n=0;frames>=10&&n<GetTouchInputNum();n++){
        GetTouchInput(n, &tempx, &tempy);
        if(tempx>100&&tempy>49&&tempx<2361&&tempy<2090){
            x=tempx;
            y=tempy;
        }
    }

    DrawRotaGraphF(x,y,1.6,0,pkyara,1);
}
