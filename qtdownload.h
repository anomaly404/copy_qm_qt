#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QWidget>
#include <QDebug>

class QtDownload : public QObject {
    Q_OBJECT
public:
    explicit QtDownload(QWidget *parent=0);
    ~QtDownload();

    void setTarget(const QString& t);
    void setlocalfile(const QString& t);
    QByteArray returnData();

private:
    QByteArray sdata;
    QNetworkAccessManager manager;
    QString target;
    QString file;

signals:
    void done();

public slots:
    void download();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);
};
