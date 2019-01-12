#include "serialportreader.h"
#include "windows.h"

#include <QCoreApplication>

SerialPortReader::SerialPortReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortReader::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialPortReader::handleError);
    //connect(&m_timer, &QTimer::timeout, this, &SerialPortReader::handleTimeout);

    //m_timer.start(50); //period between reading input port
}

void SerialPortReader::handleReadyRead()
{
//    m_readData.append(m_serialPort->readAll());

//    if (!m_timer.isActive())
//        m_timer.start(5000);
    while (!m_serialPort->atEnd()) {
            QByteArray data = m_serialPort->read(100);
            //m_standardOutput << data << endl;
            toggleKey(data);
    }
}

void SerialPortReader::handleTimeout()
{
    if (m_readData.isEmpty()) {
        m_standardOutput << QObject::tr("No data was currently available "
                                        "for reading from port %1")
                            .arg(m_serialPort->portName())
                         << endl;
    } else {
        m_standardOutput << QObject::tr("Data successfully received from port %1")
                            .arg(m_serialPort->portName())
                         << endl;
        m_standardOutput << m_readData << endl;
    }
//    keybd_event(65,0,0,0);
//    keybd_event(65,0,KEYEVENTF_KEYUP,0);
    //65 = A
    return;
    //QCoreApplication::quit();
}

void SerialPortReader::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
        QCoreApplication::exit(1);
    }
}

void SerialPortReader::initKeyMapping()
{
    keyMap.insert("enter", 13);
    keyMap.insert("shift", 16);
    keyMap.insert("esc", 27);
    keyMap.insert("space", 32);
    keyMap.insert("left", 37);
    keyMap.insert("up", 38);
    keyMap.insert("right", 39);
    keyMap.insert("down", 40);
    keyMap.insert("a", 65);
    keyMap.insert("a", 65);
    keyMap.insert("b", 66);
    keyMap.insert("c", 67);
    keyMap.insert("d", 68);
    keyMap.insert("e", 69);
    keyMap.insert("f", 70);
    keyMap.insert("g", 71);
    keyMap.insert("h", 72);
    keyMap.insert("i", 73);
    keyMap.insert("j", 74);
    keyMap.insert("k", 75);
    keyMap.insert("l", 76);
    keyMap.insert("m", 77);
    keyMap.insert("n", 78);
    keyMap.insert("o", 79);
    keyMap.insert("p", 80);
    keyMap.insert("q", 81);
    keyMap.insert("r", 82);
    keyMap.insert("s", 83);
    keyMap.insert("t", 84);
    keyMap.insert("u", 85);
    keyMap.insert("v", 86);
    keyMap.insert("w", 87);
    keyMap.insert("x", 88);
    keyMap.insert("y", 89);
    keyMap.insert("z", 90);
}

void SerialPortReader::keyDown(int keyID)
{
    keybd_event(keyID,0,0,0);
    return;
}

void SerialPortReader::keyRelease(int keyID)
{
    keybd_event(keyID,0,KEYEVENTF_KEYUP,0);
    return;
}

void SerialPortReader::toggleKey(QByteArray keyCode)
{
    if(keyCode=="W")
        keyDown(keyMap.value("w"));
    else if(keyCode=="w")
        keyRelease(keyMap.value("w"));
    else if(keyCode=="A")
        keyDown(keyMap.value("a"));
    else if(keyCode=="a")
        keyRelease(keyMap.value("a"));
    else if(keyCode=="S")
        keyDown(keyMap.value("s"));
    else if(keyCode=="s")
        keyRelease(keyMap.value("s"));
    else if(keyCode=="D")
        keyDown(keyMap.value("d"));
    else if(keyCode=="d")
        keyRelease(keyMap.value("d"));
    else if(keyCode=="R")
        keyDown(keyMap.value("r"));
    else if(keyCode=="r")
        keyRelease(keyMap.value("r"));
    else if(keyCode=="I")
        keyDown(keyMap.value("up"));
    else if(keyCode=="i")
        keyRelease(keyMap.value("up"));
    else if(keyCode=="J")
        keyDown(keyMap.value("left"));
    else if(keyCode=="j")
        keyRelease(keyMap.value("left"));
    else if(keyCode=="K")
        keyDown(keyMap.value("down"));
    else if(keyCode=="k")
        keyRelease(keyMap.value("down"));
    else if(keyCode=="L")
        keyDown(keyMap.value("right"));
    else if(keyCode=="l")
        keyRelease(keyMap.value("right"));
    else if(keyCode=="N")
        keyDown(keyMap.value("n"));
    else if(keyCode=="n")
        keyRelease(keyMap.value("n"));
    else if(keyCode=="O")
        keyDown(keyMap.value("space"));
    else if(keyCode=="o")
        keyRelease(keyMap.value("space"));
    else if(keyCode=="B")
        keyDown(keyMap.value("b"));
    else if(keyCode=="b")
        keyRelease(keyMap.value("b"));
    else if(keyCode=="X")
        keyDown(keyMap.value("x"));
    else if(keyCode=="x")
        keyRelease(keyMap.value("x"));
    else if(keyCode=="Y")
        keyDown(keyMap.value("y"));
    else if(keyCode=="y")
        keyRelease(keyMap.value("y"));
    else if(keyCode=="P")
        keyDown(keyMap.value("esc"));
    else if(keyCode=="p")
        keyRelease(keyMap.value("esc"));
    else if(keyCode=="V")
        keyDown(keyMap.value("v"));
    else if(keyCode=="v")
        keyRelease(keyMap.value("v"));
    else if(keyCode=="R")
        keyDown(keyMap.value("shift"));
    else if(keyCode=="r")
        keyRelease(keyMap.value("shift"));
    else if(keyCode=="C")
        keyDown(keyMap.value("c"));
    else if(keyCode=="c")
        keyRelease(keyMap.value("c"));
    else if(keyCode=="Z")
        keyDown(keyMap.value("z"));
    else if(keyCode=="z")
        keyRelease(keyMap.value("z"));
    else if(keyCode=="0")
        keyDown(keyMap.value("up"));
    else if(keyCode=="1")
        keyRelease(keyMap.value("up"));
    else if(keyCode=="2")
        keyDown(keyMap.value("left"));
    else if(keyCode=="3")
        keyRelease(keyMap.value("left"));
    else if(keyCode=="4")
        keyDown(keyMap.value("down"));
    else if(keyCode=="5")
        keyRelease(keyMap.value("down"));
    else if(keyCode=="6")
        keyDown(keyMap.value("right"));
    else if(keyCode=="7")
        keyRelease(keyMap.value("right"));

}
