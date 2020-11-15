//
// Created by spyk4 on 2020/11/08.
//

#include "tama.h"
player* pla;
tama::~tama() {

}

tama::tama() {

}

void tama::draw() {
    if(mikata) {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
    }else{
        if(frame<20){
            SetDrawBlendMode(DX_BLENDMODE_ADD,255);
            DrawRotaGraphF((int)x,(int)y,20-frame,0,*graph,1);
        }
    }

    DrawRotaGraphF((int)x,(int)y,11,0,*graph,1);
    if(mikata) {
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND,100);
    }
}

void tama::control() {
    frame++;
    if(mikata||not(frame<5)) {
        x += (int) tama_vector[0];
        y += (int) tama_vector[1];
    }
}

tama::tama(int x,int y,std::vector<double> vector, int* graph,player* pl,bool mikata) {
    tama::mikata=mikata;
    pla=pl;
    tama::x=x;
    tama::y=y;
    tama::tama_vector=vector;
    if(mikata)size=60;
    tama::graph=graph;
}

bool tama::collision(int fx,int fy) {
    float a = fx - x;
    float b = fy - y;
    float c = sqrt(a * a + b * b);
    float sum_radius = pla->size + size;
    if (c <= sum_radius)return true;
    return false;
}
