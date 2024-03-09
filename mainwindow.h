#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QString>
#include <QAction>
#include <QDebug>
#include <QFont>
#include <QVector>
#include <QSlider>
#include <QLabel>
#include <QMouseEvent>
#include <QDesktopServices>

#include "findpage.h"
#include "mymusic.h"
#include "playlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    QSlider *getSlider();
    QLabel *getlabel();
    ~MainWindow();
private:
    int imgnum;
    int Maxtime;
    int Nowtime;
    int musicnum=0;
    int musiclistMax=0;
    int Playstate=0;
    QVector<QString> Musicname;
    QString imgpath;
    Ui::MainWindow *ui;
    QMediaPlayer *player=nullptr;
    QString durationTime;
    QString positionTime;
    Findpage *Findwidget;
    MyMusic *Mymusicpage;
    Playlist *Playmusiclist;
public slots:
    void find_music(QString x);
    void onDurationChanged(qint64 duration); //文件时长变化，更新当前播放文件名显示
    void onPositionChanged(qint64 position); //当前文件播放位置变化，更新进度显示
private:
    void setmouse();
    bool event(QEvent *event) override;
};
#endif // MAINWINDOW_H
