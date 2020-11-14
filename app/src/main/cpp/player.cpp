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
bool hyouzi=true;
void player::control() {
    frames++;
    for(int n=0;frames>=10&&n<GetTouchInputNum();n++){
        GetTouchInput(n, &tempx, &tempy);
        if(tempx>100&&tempy>49&&tempx<2361&&tempy<2090){
            x=tempx;
            y=tempy;
        }
    }
    if((muteki>=125&&muteki<=150)||(muteki>75&&muteki<=100)||(muteki>25&&muteki<=50))SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
    DrawRotaGraphF(x,y,3.2,0,pkyara,1);
    if((muteki>=125&&muteki<=150)||(muteki>75&&muteki<=100)||(muteki>25&&muteki<=50))SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
}
