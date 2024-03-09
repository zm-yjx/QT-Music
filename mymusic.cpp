#include "mymusic.h"
#include "ui_mymusic.h"

MyMusic::MyMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyMusic)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("我的音乐"));
    this->setStyleSheet("background-color: lightblue;");
    this->Exitbtn->setText("<");
    this->Exitbtn->move(10,10);
    this->Exitbtn->show();
    connect(this->Exitbtn,&QPushButton::clicked,[=](){
       this->~MyMusic();
    });//返回上一个界面
    QDir dir("C:/Users/33746/Desktop/FindMusic");
    QDir::Filters filters = QDir::Files | QDir::NoDotAndDotDot;
    QStringList nameFilters;
    nameFilters << "*.mp3";//创建过滤器，只包含指定后缀的文件
    QFileInfoList fileList = dir.entryInfoList(nameFilters, filters);
    foreach (QFileInfo fileInfo, fileList) {
        Musicname.append(fileInfo.fileName());
        qDebug() << fileInfo.fileName();
        qDebug()<<fileInfo.path();
    }//遍历获取的mp3文件
    QVector<QString>::iterator key=Musicname.begin();
    int firstway=40;
    NameEdit.clear();
    Playbtn.clear();
    while (key!=Musicname.end()) {
      qDebug()<<*key;
      QLineEdit* Name=new QLineEdit(this);
      Name->setFixedSize(600,20);
      Name->setText(*key);
      Name->setStyleSheet("background-color: white;");
      Name->move(50,firstway);
      Name->show();
      NameEdit.push_back(Name);
      QPushButton* Action=new QPushButton(this);
      Action->move(645,firstway-1);
      Action->setText("播放");
      Action->setStyleSheet("background-color: gray;color: white;");
      Action->show();
      int keydata=1;
      connect(Action,&QPushButton::clicked,[=]()mutable{
          Mythread *Playthread =new Mythread;
          Playthread->setplaypage();
          keydata=keydata+1;
          Action->setText("开始");
          Playthread->setname(*key);
          if(keydata%2==0)
          {
              Playthread->playpage->setWindowTitle(Playthread->getMusicName());
              Playthread->playpage->show();
              connect(Playthread->player,SIGNAL(positionChanged(qint64)),Playthread->playpage,SLOT(onPositionChanged(qint64)));
              connect(Playthread->player,SIGNAL(durationChanged(qint64)),Playthread->playpage,SLOT(onDurationChanged(qint64)));
              int playkey=1;
              connect(Playthread->playpage->Stopbtn,&QPushButton::clicked,[=]()mutable{
                  playkey=playkey+1;
                  if(playkey%2==1)
                  {
                      Playthread->playpage->Stopbtn->setText("暂停");
                      Playthread->player->play();
                      qDebug()<<playkey;
                  }
                  else
                  {
                      Playthread->playpage->Stopbtn->setText("播放");
                      Playthread->player->pause();
                      qDebug()<<playkey;
                  }
              });
              Action->setText("播放");
              Playthread->start();
              connect(Playthread->playpage,&PlayPage::Exitpage,Playthread->player,&QMediaPlayer::stop);
              qDebug()<<keydata;
          }
          Action->setText("暂停");
      });
      Playbtn.push_back(Action);
      firstway+=25;    
      key++;
    }
    Musicname.clear();
}

MyMusic::~MyMusic()
{
    delete ui;
}
