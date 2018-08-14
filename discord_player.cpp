#include "discord_player.h"
#include "ui_discord_player.h"

#include <QtWebEngineCore>
#include <QtWebEngineWidgets/QWebEnginePage>

//#include <QDesktopServices>

//#include <iostream>

discord_player::discord_player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::discord_player)
{
    ui->setupUi(this);

    showMaximized();

    connect(ui->webEngineView->page(),
            SIGNAL(featurePermissionRequested(const QUrl&, QWebEnginePage::Feature)),
            SLOT(on_webEngineView_permissionRequested(const QUrl&, QWebEnginePage::Feature)));

    ui->webEngineView->setUrl(QUrl("https://discordapp.com/channels/@me"));
}

discord_player::~discord_player()
{
    delete ui;
}

void discord_player::on_webEngineView_permissionRequested(const QUrl& q, QWebEnginePage::Feature f) {
    qDebug() << q << f;

    ui->webEngineView->page()->setFeaturePermission(q, f,
        QWebEnginePage::PermissionGrantedByUser);
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
