#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include <QCoreApplication>
#include <QSerialPort>
#include <QStringList>
#include <QTextStream>
#include "serialportreader.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    QGraphicsScene *scene = new QGraphicsScene();
//    QGraphicsRectItem *rect = new QGraphicsRectItem();
//    rect->setRect(0,0,100,100);
//    scene->addItem(rect);

//    QGraphicsView *view = new QGraphicsView(scene);
//    view->setScene(scene);
//    view->show();
//    return a.exec();
    QCoreApplication coreApplication(argc, argv);

    QTextStream standardOutput(stdout);

    QSerialPort serialPort;
    const QString serialPortName = "COM7";//argumentList.at(1);
    serialPort.setPortName(serialPortName);

    const int serialPortBaudRate = QSerialPort::Baud9600;
    serialPort.setBaudRate(serialPortBaudRate);

    if (!serialPort.open(QIODevice::ReadOnly)) {
        standardOutput << QObject::tr("Failed to open port %1, error: %2")
                          .arg(serialPortName)
                          .arg(serialPort.errorString())
                       << endl;
        return 1;
    }

    SerialPortReader serialPortReader(&serialPort);

    return coreApplication.exec();
}
