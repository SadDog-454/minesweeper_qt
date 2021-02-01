#ifndef PLAYAREA_H
#define PLAYAREA_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class PlayArea : public QWidget
{
    Q_OBJECT
public:
    explicit PlayArea(QWidget *parent = nullptr);

    int height = 16, width = 16, mines = 12;
    QLabel **cell;
    QGridLayout *grid;

signals:

};

#endif // PLAYAREA_H
