#include "../headers/Engine.h"

Engine::Engine() {
    createMap();
    createHero();
}

void Engine::createMap() {
    size = 10;

    tab = new int* [size];
    temp = new int* [size];

    for(int i=0; i<size; i++) {
        tab[i]=new int[size];
        temp[i]=new int[size];
        for(int j=0; j<size; j++) {
            tab[i][j]=0;
        }
    }
}

void Engine::createHero() {
    //Hero kuba;
};

Engine::~Engine(){
    if(tab && temp){
        for(int i=0;i<size;i++){
            delete [] temp[i];
            delete [] tab[i];
        }
        delete [] temp;
        delete [] tab;
        temp = 0;
        tab = 0;
    }
}




