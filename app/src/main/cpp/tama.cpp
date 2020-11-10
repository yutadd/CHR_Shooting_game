//
// Created by spyk4 on 2020/11/08.
//

#include "tama.h"

tama::~tama() {

}

tama::tama() {

}

void tama::draw() {
    DrawRotaGraphF((int)x,(int)y,4,0,*graph,1);
}

void tama::control() {
    frame++;
    x+=tama_vector[0];
    y+=tama_vector[1];
}

tama::tama(int x,int y,std::vector<double> vector, int* graph,player* pl) {
    tama::pl=pl;
    tama::x=x;
    tama::y=y;
    tama::tama_vector=vector;
    tama::graph=graph;
}

bool tama::collision() {
    float a = pl->x - x;
    float b = pl->y - y;
    float c = sqrt(a * a + b * b);
    float sum_radius = pl->size + size;
    if (c <= sum_radius)return true;
    return false;
}
