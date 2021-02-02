#include <QQueue>
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
}

void PlayArea::PrepareArea(int i,int j){
    srand(time(0));
    int mines_set = 0;
    while(mines_set != mines){
        int y = rand() % height , x = rand() % width;
        if(!area[y][x].isMine() && !( x == i && y == j)) {
            area[y][x].setMine();
            //area[y][x].setText("*");
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

void PlayArea::showBombs(){
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            if(area[i][j].isMine())area[i][j].setText("*");
            else if(area[i][j].isFlag())area[i][j].setText("#");
}

void PlayArea::bfs(int x, int y){
    QQueue<QPoint> q;
    q.push_back(QPoint(x,y));
    area[y][x].setVisit();
    while(!q.isEmpty()){
        QPoint front = q.front();
        q.pop_front();
        area[front.y()][front.x()].setFrameStyle(QFrame::Panel | QFrame::Sunken);
        area[front.y()][front.x()].setText((minesAround(front.x(),front.y()) ? QString::number(minesAround(front.x(),front.y())) : " "));
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j){
                if(inArea(front.x() - 1 + j,front.y() - 1 + i))
                    if(!area[front.y() - 1 + i][front.x() - 1 + j].isVisit() && !area[front.y() - 1 + i][front.x() - 1 + j].isMine() && !minesAround(front.x(),front.y())
                            && !area[front.y() - 1 + i][front.x() - 1 + j].isFlag()){
                        area[front.y() - 1 + i][front.x() - 1 + j].setVisit();
                        q.push_back(QPoint(front.x() - 1 + j,front.y() - 1 + i));
                    }
            }
    }
}

void PlayArea::clear()
{
    for(int i = 0; i < height ; ++i)
        for(int j = 0; j < width ; ++j){
            if(!area[i][j].isVisit()) area[i][j].setFrameStyle(QFrame::Panel | QFrame::Raised);
        }
}

void PlayArea::mouseReleaseEvent(QMouseEvent *e)
{
    left = false;
    mid = false;
    clear();
    int y = e->y()/20 , x = e->x()/20;
    if(inArea(x,y))
        if(e->button() == Qt::LeftButton && !area[y][x].isFlag()){
        if(first_click){
            first_click = false;
            PrepareArea(x,y);
        }
        if(area[y][x].isMine()) showBombs();
        else bfs(x,y);
     }
}

void PlayArea::mousePressEvent(QMouseEvent *e){
    int y = e->y()/20 , x = e->x()/20;
    if(e->button() == Qt::RightButton && !area[y][x].isVisit()){
        area[y][x].setFlag();
        area[y][x].setText(area[y][x].isFlag() ? "F" : " ");
    }else if(e->button() == Qt::LeftButton) left = true;
    else if(e->button() == Qt::MiddleButton) mid = true;
}

void PlayArea::mouseMoveEvent(QMouseEvent *e)
{
    int y = e->y()/20 , x = e->x()/20;
    if(left)
        for(int i = 0; i < height ; ++i)
            for(int j = 0; j < width ; ++j){
                if(i == y && j == x) area[i][j].setFrameStyle(QFrame::Panel | QFrame::Sunken);
                else if(!area[i][j].isVisit()) area[i][j].setFrameStyle(QFrame::Panel | QFrame::Raised);
            }
    else if(mid)
        for(int i = 0; i < height ; ++i)
            for(int j = 0; j < width ; ++j)
                if(i == y && j == x){
                    for(int k = 0; k < 9; ++k){
                        if(inArea(j - 1 + k % 3,i - 1 + k / 3)) area[i - 1 + k / 3][j - 1 + k % 3].setFrameStyle(QFrame::Panel | QFrame::Sunken);
                    }
                }
                else  if(!area[i][j].isVisit() && !(i==y && j==x+1)&& !(i==y+1 && j==x-1)&& !(i==y+1 && j==x)&& !(i==y+1 && j==x+1) && inArea(x,y)) area[i][j].setFrameStyle(QFrame::Panel | QFrame::Raised);
}




