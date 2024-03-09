#include "findpage.h"
#include "ui_findpage.h"

Findpage::Findpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Findpage)
{
    ui->setupUi(this);
    setWindowTitle("查找音乐");
    this->setStyleSheet("background-color: lightblue;");
    this->findname->setFixedSize(600,50);
    this->findname->move(100,69);
    this->Musiclist->setFixedSize(800,452);
    this->Musiclist->move(80,150);
    this->Exitbtn->setText("<");
    this->Exitbtn->move(10,10);
    this->Exitbtn->show();//设置界面属性与位置
    connect(this->Exitbtn,&QPushButton::clicked,[=](){
        this->~Findpage();
    });//返回上一个界面
    connect(this->ui->pushButton,&QPushButton::clicked,[=](){
        QFile file("C:/Users/33746/Desktop/Find.txt");//打开存放有搜索内容文本文件
        file.open(QIODevice::WriteOnly | QIODevice::Text);//采取写模式实现往搜索内容文档中写入内容
        QString data=this->findname->text();
        QTextStream out(&file);
        out<<data;
        file.close();//写入数据
        QDir dir("C:/Users/33746/Desktop/FindMusic");
        QDir::Filters filters = QDir::Files | QDir::NoDotAndDotDot;
        QStringList nameFilters;
        nameFilters << "*.mp3";//创建过滤器，只包含指定后缀的文件
        QFileInfoList fileList = dir.entryInfoList(nameFilters, filters);
        foreach (QFileInfo fileInfo, fileList) {
            Musicname.append(fileInfo.fileName());
            Musiclist->addItem(fileInfo.fileName());
            qDebug() << fileInfo.fileName();
            qDebug()<<fileInfo.path();
        }//遍历获取的mp3文件
        connect(this->Musiclist,&QListWidget::itemClicked,[=](QListWidgetItem *item){
            QString name=item->text();
            qDebug()<<name;
            Mythread *Playthread=new Mythread;
            Playthread->setplaypage();
            Playthread->setname(name);
            Playthread->playpage->setWindowTitle(Playthread->getMusicName());
            Playthread->playpage->show();
            connect(Playthread->player,SIGNAL(positionChanged(qint64)),Playthread->playpage,SLOT(onPositionChanged(qint64)));
            connect(Playthread->player,SIGNAL(durationChanged(qint64)),Playthread->playpage,SLOT(onDurationChanged(qint64)));//连接播放界面的进度条控件
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
            });//连接暂停按键
            connect(Playthread->playpage,&PlayPage::Exitpage,Playthread->player,&QMediaPlayer::stop);
            Playthread->start();
        });
        Musicname.clear();
    });
}

Findpage::~Findpage()
{
    delete ui;
}
