#include "playarea.h"

PlayArea::PlayArea(QWidget *parent) : QWidget(parent){
    area = new Cell*[height];
    for(int i = 0; i < height; ++i) area[i] = new Cell[width];
    grid = new QGridLayout;
    grid->setSpacing(0);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++){
            grid->addWidget(&area[i][j],i,j);
        }
    setLayout(grid);
    PrepareArea();
}

void PlayArea::PrepareArea(){
    int mines_set = 0;
    while(mines_set != mines){
        int y = rand() % height , x = rand() % width;
        if(!area[y][x].isMine()) {
            area[y][x].setMine();
            area[y][x].setText("*");
            mines_set++;
        }
    }
}

