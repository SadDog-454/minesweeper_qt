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

    int height = 16, width = 16, mines = 12;
    Cell **area;
    QGridLayout *grid;

public:
    explicit PlayArea(QWidget *parent = nullptr);
    void PrepareArea();
    int minesAround(int x, int y);
    bool inArea(int x,int y);

protected:
    virtual void mouseReleaseEvent(QMouseEvent *e);

signals:

};

#endif // PLAYAREA_H
