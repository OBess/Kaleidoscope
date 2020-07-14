#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);

    this->image = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    this->painter = new QPainter(this->image);
    this->painter->translate(width()/2, height()/2);

    this->enable = false;

    this->color = QColor(Qt::gray);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete image;
}


//Slots
void MainWindow::on_actionClear_triggered()
{
    this->clearField();
}
void MainWindow::on_actionColor_triggered()
{
    this->color = QColorDialog::getColor(Qt::black, this, "Color of line");
}
void MainWindow::on_actionSlices_triggered()
{
    this->clearField();
    this->slices = QInputDialog::getInt(this, "Slices", "How many slices?", this->slices, 1, 100);
}
void MainWindow::on_actionQuit_triggered()
{
    close();
}
//End slots


//Static methods
QString MainWindow::str_to_qstr(std::string str){
    return QString(str.c_str());
}
QString MainWindow::int_to_qstr(int n){
    return QString(std::to_string(n).c_str());
}
//End static methods


//All events of widget
void MainWindow::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    qp.fillRect(this->image->rect(), Qt::black);
    qp.drawImage(0, 0, *this->image);
    e->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *e){
    this->enable = true;

    this->begin.setX(e->x() - width()/2);
    this->begin.setY(e->y() - height()/2);

    e->accept();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e){
    if(!this->enable){
        e->accept();
        return;
    }
    this->painter->setPen(QPen(this->color, 4, Qt::SolidLine));

    this->end.setX(e->x() - width()/2);
    this->end.setY(e->y() - height()/2);

    float deg = 360 / this->slices;

    for(int i = 0; i < this->slices; i++){
        this->painter->drawLine(begin, end);
        this->painter->rotate(deg);
    }

    this->begin = this->end;
    update();
    e->accept();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *e){
    this->enable = false;
    e->accept();
}
void MainWindow::resizeEvent(QResizeEvent *e){
    clearField();
}
//End all events of widget


//Logics
void MainWindow::clearField(){
    delete painter;
    delete image;
    this->image = new QImage(QApplication::desktop()->size(), QImage::Format_ARGB32_Premultiplied);
    this->painter = new QPainter(this->image);
    this->painter->translate(width()/2, height()/2);
    update();
}
//End logics
