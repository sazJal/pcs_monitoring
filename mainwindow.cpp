#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    established_connection();
    connect(ui->button_send, &QPushButton::clicked, this, &MainWindow::send_data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::received_data(void)
{
    QHostAddress hostAddr;
    quint32 dataip;
    QByteArray datagram;
    uint8_t data[4];
    quint16 port1;
    qDebug() << "OK";
    while(socketReceive->hasPendingDatagrams()) {

        datagram.resize(socketReceive->pendingDatagramSize());
        socketReceive->readDatagram(datagram.data(), datagram.size(),&hostAddr,&port1);
    }
    dataip = hostAddr.toIPv4Address();
    data[3] = dataip >> 24;
    data[2] = dataip >> 16;
    data[1] = dataip >> 8;
    data[0] = dataip;
    qDebug() << QString(datagram);
    qDebug() << QString::number(data[3])+QStringLiteral(".")+QString::number(data[2])+QStringLiteral(".")+QString::number(data[1])+QStringLiteral(".")+QString::number(data[0]);
}

void MainWindow::established_connection(void)
{
    socketSend      = new QUdpSocket(this);
    socketReceive   = new QUdpSocket(this);

    remotePort      = 3003;
    remoteIP.append("172.16.14.96");

    socketReceive->bind(QHostAddress::AnyIPv4, 3003);
    connect(socketReceive, SIGNAL(readyRead()), this, SLOT(received_data()));
}

void MainWindow::send_data(void)
{
    QByteArray Data;

    Data.append("Hello World");
    hostAddress.setAddress("172.16.14.96");
    socketSend->writeDatagram(Data, hostAddress, remotePort);
}
