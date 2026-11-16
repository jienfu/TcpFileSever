#ifndef TCPFILESEVER_H
#define TCPFILESEVER_H

#include <QDialog>
#include <QtNetwork>
#include <QtWidgets>

class TcpFileSever : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileSever(QWidget *parent = nullptr);
    ~TcpFileSever() override;

public slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QProgressBar     *serverProgressBar;
    QLabel           *serverStatusLabel;
    QPushButton      *startButton;
    QPushButton      *quitButton;
    QDialogButtonBox *buttonBox;

    QTcpServer       tcpServer;
    QTcpSocket       *tcpServerConnection;
    qint64           totalBytes;
    qint64           byteReceived;
    qint64           fileNameSize;
    QString          fileName;
    QFile            *localFile;
    QByteArray       inBlock;
};
#endif // TCPFILESEVER_H