#ifndef MYMUSIC_H
#define MYMUSIC_H

#include <QWidget>
#include <QDialog>
#include <QDir>
#include <QDebug>
#include <QMediaPlayer>
#include <QLineEdit>
#include <QVector>
#include <QPushButton>
#include <QFont>
#include <QFileDialog>

#include "mythread.h"
#include "playpage.h"
#include "playlist.h"

namespace Ui {
class MyMusic;
}

class MyMusic : public QWidget
{
    Q_OBJECT
public:
    explicit MyMusic(QWidget *parent = nullptr);
    ~MyMusic();
    QPushButton *Exitbtn=new QPushButton(this);
    QVector<QLineEdit*> NameEdit;
    QVector<QPushButton*> Playbtn;//设置控件
    QVector<QString>Musicpath;
    QVector<QString>Musicname;// 存储音乐地址与名字
private:
    Ui::MyMusic *ui;
};

#endif // MYMUSIC_H
