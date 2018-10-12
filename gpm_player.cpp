#include "gpm_player.h"
#include "ui_gpm_player.h"

gpm_player::gpm_player(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gpm_player)
{
    ui->setupUi(this);

    showMaximized();

    connect(ui->webEngineView->page(),
            SIGNAL(featurePermissionRequested(const QUrl &, QWebEnginePage::Feature)),
            this,
            SLOT(grantFeaturePermission(const QUrl &, QWebEnginePage::Feature)));

    ui->webEngineView->setUrl(QUrl("https://play.google.com/music/listen#/home"));
}

gpm_player::~gpm_player()
{
    delete ui;
}

void gpm_player::grantFeaturePermission(const QUrl &q, QWebEnginePage::Feature f) {
    qDebug() << q << f;

    QString s;
    QDebug d(&s);
    d << "Grant \"" << q << "\" permission to use \"" << f << "\"?";

    QMessageBox::StandardButton r;
    r = QMessageBox::question(this, "Grant permission", s,
            QMessageBox::Yes | QMessageBox::No);

    if (r == QMessageBox::Yes) {
        ui->webEngineView->page()->setFeaturePermission(q, f,
            QWebEnginePage::PermissionGrantedByUser);
    } else {
        ui->webEngineView->page()->setFeaturePermission(q, f,
            QWebEnginePage::PermissionDeniedByUser);
    }
}

void gpm_player::on_webEngineView_titleChanged(const QString &title)
{
    setWindowTitle(title);
}

void gpm_player::on_webEngineView_iconChanged(const QIcon &arg1)
{
    setWindowIcon(arg1);
}
