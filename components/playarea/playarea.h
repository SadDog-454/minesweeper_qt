#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QMouseEvent>
#include "components/cell/cell.h"

class PlayArea : public QWidget
{
    Q_OBJECT

    int height = 16, width = 16, mines = 26;
    bool first_click = true;
    bool left = false, mid = false;
    Cell **area;
    QGridLayout *grid;

public:
    explicit PlayArea(QWidget *parent = nullptr);
    void PrepareArea(int i, int j);
    int minesAround(int x, int y);
    bool inArea(int x,int y);
    void showBombs();
    void bfs(int x, int y);
    void clear();

protected:
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
signals:

};

#endif // PLAYAREA_H
