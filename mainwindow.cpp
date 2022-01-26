#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button_send, &QPushButton::clicked, this, &MainWindow::send_data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::received_data(void)
{
    while(socketReceive->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socketReceive->pendingDatagramSize());
        socketReceive->readDatagram(datagram.data(), datagram.size());
    }
}

void MainWindow::established_connection(void)
{
    socketSend      = new QUdpSocket(this);
    socketReceive   = new QUdpSocket(this);

    remotePort      = 3003;
    remoteIP.append("192.168.100.1");

    socketReceive->bind(QHostAddress::AnyIPv4, 25000);
    connect(socketReceive, SIGNAL(readyRead()), this, SLOT(received_data()));
}

void MainWindow::send_data(void)
{
    QByteArray Data;

    Data.append("Hello World");
    hostAddress.setAddress("192.168.100.1");
    socketSend->writeDatagram(Data, hostAddress, remotePort);
}
