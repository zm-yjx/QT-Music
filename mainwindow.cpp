#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setmouse();
    ui->setupUi(this);
    setAttribute(Qt::WA_Hover,true);//设置鼠标事件
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->MainwidgetSlider->hide();
    ui->Musictimelabel_14->hide();

    ui->label_2->setPixmap(QPixmap(":/logo.jpg"));
    ui->label_2->resize(20,20);
    ui->pushButton->setText(tr("发现音乐"));
    ui->pushButton->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_2->setText(tr("我的音乐"));
    ui->pushButton_2->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_3->setText(tr("关注"));
    ui->pushButton_3->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_4->setText(tr("商城"));
    ui->pushButton_4->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_5->setText(tr("音乐人"));
    ui->pushButton_5->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_6->setText(tr("云推歌"));
    ui->pushButton_6->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_9->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_10->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_11->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_12->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_13->setStyleSheet("background-color: gray;color: white;");
    ui->pushButton_15->setText("循环列表");
    ui->pushButton_16->setText("播放");
    ui->pushButton_17->setText("下一首");

    QFont font;
    font.setPointSize(36);
    ui->label_4->setPixmap(QPixmap(":/test2.jpg"));
    ui->label_6->setPixmap(QPixmap(":/musicimg1.jpg"));
    ui->label_7->setPixmap(QPixmap(":/musicimg2.jpg"));
    ui->label_8->setPixmap(QPixmap(":/musicimg3.jpg"));
    ui->label_9->setPixmap(QPixmap(":/musicimg4.jpg"));
    ui->pushButton_7->setText(tr("<"));
    ui->pushButton_7->setFont(font);
    ui->pushButton_7->setStyleSheet("background-color: white;");
    ui->pushButton_8->setText(tr(">"));
    ui->pushButton_8->setFont(font);
    font.setPointSize(7);
    ui->pushButton_15->setFont(font);
    ui->pushButton_16->setFont(font);
    ui->pushButton_17->setFont(font);
    ui->pushButton_8->setStyleSheet("background-color: white;");
    ui->pushButton_7->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    ui->pushButton_8->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    QString imgdata=":/test";
    imgnum=2;
    QString imgdata2=".jpg";
    connect(ui->pushButton_7,&QPushButton::clicked,ui->label_4,[=](){
        if(imgnum>1)
        {
          imgnum=imgnum-1;
        }
        QString num;
        num=QString::number(imgnum);
        imgpath=imgdata+num+imgdata2;
        qDebug()<<imgpath;
        ui->label_4->setPixmap(QPixmap(imgpath));
    });
    connect(ui->pushButton_8,&QPushButton::clicked,ui->label_4,[=](){
        if(imgnum<6)
        {
          imgnum=imgnum+1;
        }
        QString num;
        num=QString::number(imgnum);
        imgpath=imgdata+num+imgdata2;
        qDebug()<<imgpath;
        ui->label_4->setPixmap(QPixmap(imgpath));
    });//图片切换
    connect(ui->lineEdit,&QLineEdit::returnPressed,[=](){
        this->Findwidget=new Findpage;
        this->Findwidget->show();
        this->find_music(ui->lineEdit->text());
    });//搜索框转入到查找音乐界面
    ui->label_5->setStyleSheet("font-size: 20px;");
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->Findwidget=new Findpage;
        this->Findwidget->show();
        this->find_music(ui->lineEdit->text());
    });//发现音乐转入到查找音乐界面
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        this->Mymusicpage=new MyMusic;
        this->Mymusicpage->show();
    });//转到我的音乐界面
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/#/friend");
        QDesktopServices::openUrl(url);
    });//转到我的关注界面
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/store/product");
        QDesktopServices::openUrl(url);
    });//转到我的商场界面
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/st/musician");
        QDesktopServices::openUrl(url);
    });//转到音乐人界面
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/st/ad-song");
        QDesktopServices::openUrl(url);
    });//转到云推歌界面
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/#/discover/playlist/?cat=%E5%8D%8E%E8%AF%AD");
        QDesktopServices::openUrl(url);
    });//转到华语歌界面
    connect(ui->pushButton_10,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/#/discover/playlist/?cat=%E6%B5%81%E8%A1%8C");
        QDesktopServices::openUrl(url);
    });//转到流行歌界面
    connect(ui->pushButton_11,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/#/discover/playlist/?cat=%E6%91%87%E6%BB%9A");
        QDesktopServices::openUrl(url);
    });//转到摇滚歌界面
    connect(ui->pushButton_12,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/#/discover/playlist/?cat=%E6%B0%91%E8%B0%A3");
        QDesktopServices::openUrl(url);
    });//转到民谣歌界面
    connect(ui->pushButton_13,&QPushButton::clicked,[=](){
        QUrl url("https://music.163.com/#/discover/playlist/?cat=%E7%94%B5%E5%AD%90");
        QDesktopServices::openUrl(url);
    });//转到电子歌界面
    connect(ui->pushButton_14,&QPushButton::clicked,[=](){
        this->Playmusiclist=new Playlist();
        Playmusiclist->show();
    });//显示播放列表

    int key=0;
    connect(ui->pushButton_15,&QPushButton::clicked,[=]()mutable{
        key=key+1;
        QFile file("C:/Users/33746/Desktop/MusicList.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open the file for reading";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            this->Musicname.push_back(line);
            this->musiclistMax=this->musiclistMax+1;
        }
        file.close();
        if(this->player==nullptr)
        {
           this->player=new QMediaPlayer;
        }
        if(key%2==1)
        {
            this->ui->pushButton_15->setText("循环列表");
            this->Playstate=1;
            QString path;
            path="C:/Users/33746/Desktop/FindMusic/"+Musicname.at(musicnum);
            QString Musicpath=QDir::toNativeSeparators(path);
            qDebug()<<Musicpath;
            player->setMedia(QUrl::fromLocalFile(Musicpath));
            player->setVolume(100); // 设置音量
            connect(this->player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
            connect(this->player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));//连接播放界面的进度条控件
            player->play();
        }
        else if(key%2==0)
        {
            ui->pushButton_15->setText("单一循环");
            QFile file("C:/Users/33746/Desktop/MusicList.txt");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << "Failed to open the file for reading";
                return;
            }
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                this->Musicname.push_back(line);
            }
            file.close();
            QString path;
            path="C:/Users/33746/Desktop/FindMusic/"+Musicname.at(musicnum);
            QString Musicpath=QDir::toNativeSeparators(path);
            qDebug()<<Musicpath;
            if(this->player==nullptr)
            {
               this->player=new QMediaPlayer;
            }

            player->setMedia(QUrl::fromLocalFile(Musicpath));
            player->setVolume(100); // 设置音量
            this->Playstate=0;
            connect(this->player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
            connect(this->player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));//连接播放界面的进度条控件
            player->play();
        }
    });//设置循环方式

    connect(ui->pushButton_16,&QPushButton::clicked,[=](){
        this->player=new QMediaPlayer();
        QFile file("C:/Users/33746/Desktop/MusicList.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open the file for reading";
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            this->Musicname.push_back(line);
        }
        file.close();
        QString path;
        path="C:/Users/33746/Desktop/FindMusic/"+Musicname.at(0);
        QString Musicpath=QDir::toNativeSeparators(path);
        qDebug()<<Musicpath;
        player->setMedia(QUrl::fromLocalFile(Musicpath));
        player->setVolume(100); // 设置音量
        qDebug()<<"播放";
        player->play();
        connect(this->player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
        connect(this->player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));//连接播放界面的进度条控件
    });//从列表第一个开始播放

    connect(ui->pushButton_16,&QPushButton::clicked,[=](){
        if(this->musicnum<this->musiclistMax-1)
        {
            this->musicnum=this->musicnum+1;
        }
        else
        {
            this->musicnum=0;
        }
    });//下一首播放
}

QSlider *MainWindow::getSlider()
{
    return this->ui->MainwidgetSlider;
}

QLabel *MainWindow::getlabel()
{
    return  this->ui->Musictimelabel_14;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::find_music(QString x)
{
    this->Findwidget->findname->setText(x);
    qDebug()<<this->Findwidget->findname->text();
}

void MainWindow::onDurationChanged(qint64 duration)
{
    QSlider *Play;
    QLabel *Playlabel;
    Play=this->getSlider();
    Play->setMaximum(duration); //设置进度条最大值 也就是歌曲时长 ms
    int secs = duration/1000; //全部秒数
    this->Maxtime=secs;
    int mins = secs/60;//分
    secs = secs % 60;//秒
    durationTime = QString::asprintf("%d:%d",mins,secs);

    Playlabel=this->getlabel();
    Playlabel->setText(positionTime+"/"+durationTime);
}

void MainWindow::onPositionChanged(qint64 position)
{
    QSlider *Play;
    QLabel *Playlabel;
    Play=this->getSlider();
    Play->setValue(position);
    int secs = position/1000;
    this->Nowtime=secs;
    int mins = secs/60;
    secs = secs % 60;
    connect(Play,&QSlider::sliderPressed,[=](){
        connect(Play,&QSlider::sliderMoved,[=](int newvalue){
                Play->setValue(newvalue);
                this->player->setPosition(newvalue);
                this->player->play();
        });
    });
    positionTime = QString::asprintf("%d:%d",mins,secs);
    Playlabel=this->getlabel();
    Playlabel->setText(positionTime+"/"+durationTime);

    if(this->Nowtime>=this->Maxtime)
    {
        if(this->Playstate==0)
        {
            musicnum=0;
            QString path;
            path="C:/Users/33746/Desktop/FindMusic/"+Musicname.at(musicnum);
            QString Musicpath=QDir::toNativeSeparators(path);
            qDebug()<<Musicpath;
            player->setMedia(QUrl::fromLocalFile(Musicpath));
            player->setVolume(100); // 设置音量
            connect(this->player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
            connect(this->player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));//连接播放界面的进度条控件
            player->play();
        }
        else if(this->Playstate==1&&this->musicnum<this->musiclistMax-1)
        {
            musicnum=musicnum+1;
            QString path;
            path="C:/Users/33746/Desktop/FindMusic/"+Musicname.at(musicnum);
            QString Musicpath=QDir::toNativeSeparators(path);
            qDebug()<<Musicpath;
            player->setMedia(QUrl::fromLocalFile(Musicpath));
            player->setVolume(100); // 设置音量
            connect(this->player,SIGNAL(positionChanged(qint64)),this,SLOT(onPositionChanged(qint64)));
            connect(this->player,SIGNAL(durationChanged(qint64)),this,SLOT(onDurationChanged(qint64)));//连接播放界面的进度条控件
            player->play();
        }
        qDebug()<<this->Playstate;
        qDebug()<<this->musicnum;
        qDebug()<<"max time"<<this->Maxtime;
        qDebug()<<"now time"<<this->Nowtime;
        qDebug()<<"end";
    }

}

void MainWindow::setmouse()
{
    this->setMouseTracking(true);
}

bool MainWindow::event(QEvent *event)
{
    int ykey=0;
    if(QEvent::HoverMove == event->type())//鼠标移动
    {
        QHoverEvent *hoverEvent = static_cast<QHoverEvent*>(event);
        ykey=hoverEvent->pos().y();
        if(ykey>580)
        {
            this->ui->pushButton_15->show();
            this->ui->pushButton_16->show();
            this->ui->pushButton_17->show();
            this->ui->MainwidgetSlider->show();
            this->ui->Musictimelabel_14->show();
        }
        else
        {
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->MainwidgetSlider->hide();
            ui->Musictimelabel_14->hide();
        }
    }
    return QWidget::event(event);
}
