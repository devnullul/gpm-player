#ifndef GPM_PLAYER_H
#define GPM_PLAYER_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QMessageBox>

namespace Ui {
class gpm_player;
}

class gpm_player : public QMainWindow
{
    Q_OBJECT

public:
    explicit gpm_player(QWidget *parent = 0);
    ~gpm_player();

private slots:
    void on_webEngineView_titleChanged(const QString &title);

    void on_webEngineView_iconChanged(const QIcon &arg1);

    void grantFeaturePermission(const QUrl &q, QWebEnginePage::Feature f);

private:
    Ui::gpm_player *ui;
};

#endif // GPM_PLAYER_H
