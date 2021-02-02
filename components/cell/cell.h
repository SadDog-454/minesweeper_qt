#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QEvent>

class Cell : public QLabel
{
    Q_OBJECT

    bool mine = false;
public:
    Cell();
    void setMine(){mine = true;}
    bool isMine(){return mine;}
};

#endif // CELL_H
