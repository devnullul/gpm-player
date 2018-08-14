#include "discord_player.h"
#include "ui_discord_player.h"

//#include <QDesktopServices>

//#include <iostream>

discord_player::discord_player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::discord_player)
{
    ui->setupUi(this);

    setStyleSheet("background-color: black;");
    showMaximized();

    ui->webEngineView->setUrl(QUrl("https://discordapp.com/channels/@me"));
}

discord_player::~discord_player()
{
    delete ui;
}

void discord_player::on_webEngineView_titleChanged(const QString &title)
{
    setWindowTitle(title);
}

void discord_player::on_webEngineView_iconChanged(const QIcon &arg1)
{
    setWindowIcon(arg1);
}

void discord_player::on_webEngineView_urlChanged(const QUrl &arg1)
{
    //std::cout << arg1.toString().toStdString() << std::endl;
}
