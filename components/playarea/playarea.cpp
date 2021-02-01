#include "playarea.h"

PlayArea::PlayArea(QWidget *parent) : QWidget(parent){
    cell = new QLabel*[height];
    for(int i = 0; i < height; ++i) cell[i] = new QLabel[width];
    grid = new QGridLayout;
    grid->setSpacing(0);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++){
            cell[i][j].setFrameStyle(QFrame::Panel | QFrame::Raised);
            cell[i][j].setLineWidth(3);
            cell[i][j].setFixedSize(20,20);
            grid->addWidget(&cell[i][j],i,j);
        }
    setLayout(grid);
}
