#ifndef CELL_H
#define CELL_H

#include <QLabel>
#include <QEvent>

class Cell : public QLabel
{
    Q_OBJECT

    bool mine = false;
    bool visit = false;
    bool flag = false;
public:
    Cell();
    void setMine(){mine = true;}
    bool isMine(){return mine;}

    void setVisit(){visit = true;}
    bool isVisit(){return visit;}

    void setFlag(){flag = !flag;}
    bool isFlag(){return flag;}
};

#endif // CELL_H
