#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QImage>
#include <QApplication>
#include <QDesktopWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPen>
#include <QInputDialog>
#include <QColorDialog>
#include <QColor>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clearField();

    static QString str_to_qstr(std::string);
    static QString int_to_qstr(int);

protected:
    void paintEvent(QPaintEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void resizeEvent(QResizeEvent* e) override;

private slots:
    void on_actionClear_triggered();
    void on_actionColor_triggered();
    void on_actionSlices_triggered();
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;

    QImage* image;
    QPainter* painter;
    QPoint begin;
    QPoint end;
    QColor color;

    bool enable;

    int slices = 6;
};
#endif // MAINWINDOW_H
