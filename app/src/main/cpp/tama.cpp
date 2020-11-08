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
    x+=tama_vector.x;
    y+=tama_vector.y;
}

tama::tama(int x, int y, VECTOR vector, int* graph) {
    tama::x=x;
    tama::y=y;
    tama::tama_vector=vector;
    tama::graph=graph;
}
