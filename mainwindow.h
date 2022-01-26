#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include "data_group.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QHostAddress hostAddress;

private:
    Ui::MainWindow *ui;
    QUdpSocket *socketSend;
    QUdpSocket *socketReceive;
    quint16 remotePort;
    QString remoteIP;

private slots:
    void established_connection(void);
    void send_data(void);
    void received_data(void);
};
#endif // MAINWINDOW_H
