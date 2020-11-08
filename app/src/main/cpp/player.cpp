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
        if(tempx>20&&tempy>20&&tempx<920&&tempy<720){
            x=tempx;
            y=tempy;
        }else if(1000<tempx&&tempy>500&&tempx<1057&&552>tempy){
            if(x>=10&&y>=10){
                x-=4;y-=4;
            }

        }else if(1057<tempx&&tempy>500&&tempx<1114&&552>tempy){
            if(y>10){
                y-=4;
            }

        }else if(1114<tempx&&tempy>500&&tempx<1171&&552>tempy){
            if(x<=920&&y>=10){
                x+=4;y-=4;
            }
        }else if(1000<tempx&&tempy>552&&tempx<1057&&612>tempy){
            if(x>10) {
                x-=4;
            }
        }else if(1057<tempx&&tempy>552&&tempx<1114&&612>tempy){

            //何もなし?

        }else if(1114<tempx&&tempy>552&&tempx<1171&&612>tempy){
            if(x<920){
                x+=4;
            }
        }else if(1000<tempx&&tempy>612&&tempx<1057&&664>tempy){
            if(x>10&&y<720) {
                x -= 4;
                y += 4;
            }
        }else if(1057<tempx&&tempy>612&&tempx<1114&&664>tempy){
            if(y<720){
                y+=4;
            }
        }else if(1114<tempx&&tempy>612&&tempx<1174&&664>tempy){
            if(x<920&&y<720){
                x+=4;y+=4;
            }
        }
    }

    DrawRotaGraphF(x,y,1.6,0,pkyara,1);
}
