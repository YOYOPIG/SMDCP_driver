#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>
#include <QString>
#include <QMap>


class SerialPortReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialPortReader(QSerialPort *serialPort, QObject *parent = nullptr);

private slots:
    void handleReadyRead();
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;
    QTextStream m_standardOutput;
    QTimer m_timer;
    QMap<QString, int> keyMap;
    void initKeyMapping();
    void keyDown(int keyID);
    void keyRelease(int keyID);
    void toggleKey(QByteArray keyCode);
};

#endif // SERIALPORTREADER_H
