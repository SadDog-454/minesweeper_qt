#include "playarea.h"

PlayArea::PlayArea(QWidget *parent) : QWidget(parent){
    area = new Cell*[height];
    for(int i = 0; i < height; ++i) area[i] = new Cell[width];
    grid = new QGridLayout;
    grid->setSpacing(0);
    grid->setContentsMargins(0,0,0,0);
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

int PlayArea::minesAround(int x, int y){
    int ma = 0;
    for(int i = 0; i < 9; ++i){
        if(inArea(x - 1 + i % 3,y - 1 + i / 3))
            if(area[y - 1 + i / 3][x - 1+ i % 3].isMine()) ma++;
    }
    return ma;
}

bool PlayArea::inArea(int x, int y){
    return (x >= 0 && x < width && y >= 0 && y < height);
}

void PlayArea::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        area[e->y()/20][e->x()/20].setFrameStyle(QFrame::Panel | QFrame::Sunken);
        area[e->y()/20][e->x()/20].setText(QString::number(minesAround(e->x()/20,e->y()/20)));
    }
}



