#ifndef FINDPAGE_H
#define FINDPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QTextStream>
#include <QMediaPlayer>
#include <QFont>
#include <QDir>
#include <QComboBox>
#include <QListWidget>

#include "mythread.h"
#include "playpage.h"
#include "playlist.h"

namespace Ui {
class Findpage;
}

class Findpage : public QWidget
{
    Q_OBJECT
public:
    explicit Findpage(QWidget *parent = nullptr);
    ~Findpage();
public:
    QLineEdit *findname=new QLineEdit(this);
    QPushButton *Exitbtn=new QPushButton(this);
    QMediaPlayer *player=new QMediaPlayer(this);
    QListWidget *Musiclist=new QListWidget(this);//设置界面控件
    PlayPage *playpage;
    QVector<QString>Musicname;
    QVector<QLineEdit*> NameEdit;
    QVector<QPushButton*> Playbtn;//界面控件存储容器
public slots:

private:
    Ui::Findpage *ui;
};

#endif // FINDPAGE_H
