#include "cell.h"

Cell::Cell() : QLabel(){
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    setLineWidth(3);
    setFixedSize(20,20);
}

