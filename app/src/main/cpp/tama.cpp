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
    DrawRotaGraphF((int)x,(int)y,10,0,*graph,1);
}

void tama::control() {
    frame++;
    x+=(int)tama_vector[0];
    y+=(int)tama_vector[1];
}

tama::tama(int x,int y,std::vector<double> vector, int* graph,player* pl) {
   pla=pl;
    tama::x=x;
    tama::y=y;
    tama::tama_vector=vector;
    tama::graph=graph;
}

bool tama::collision() {
    float a = pla->x - x;
    float b = pla->y - y;
    float c = sqrt(a * a + b * b);
    float sum_radius = pla->size + size;
    if (c <= sum_radius)return true;
    return false;
}
