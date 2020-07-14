#include "panel.h"

//Initial
Panel::Panel(QWidget *parent) : QWidget(parent), FONT_SIZE(parent->width()/6), parent(parent)
{
    setMouseTracking(true);

}

Panel::~Panel(){}

//End initial


//All events of widget
void Panel::paintEvent(QPaintEvent *e){
    Q_UNUSED(e);
    QPainter qp(this);
    draw(&qp);
}

void Panel::mousePressEvent(QMouseEvent *e){

    this->repaint();
}
//End all events of widget


//Static methods
QString Panel::str_to_qstr(std::string str){
    return QString(str.c_str());
}
QString Panel::int_to_qstr(int n){
    return QString(std::to_string(n).c_str());
}
//End static methods


//Logics
void Panel::changeSlice(int n){
    this->slices = n;
    this->clearField();
}
void Panel::clearField(){

}
//End logics


//Output
void Panel::draw(QPainter *qp){
    qp->setPen(QPen(Qt::black, 10, Qt::SolidLine));

}
//End Output
