#include "qtdownload.h"
#include <QCoreApplication>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <QWidget>

QtDownload::QtDownload(QWidget *parent) :QObject(parent)
{

}


QtDownload::~QtDownload()
{

}


void QtDownload::setTarget(const QString &t)
{
    this->target = t;
}

void QtDownload::setlocalfile(const QString &t)
{
    this->file=t;
}

void QtDownload::downloadFinished(QNetworkReply *data)
{
    QString addr="/home/anomaly/"+file;
    QFile localFile(file);
    if (!localFile.open(QIODevice::WriteOnly))
     {
        qDebug()<<"cant access";
        return;
    }
    sdata = data->readAll();
    localFile.write(sdata);
    localFile.close();

    emit done();
}
QByteArray QtDownload::returnData()
{
    return sdata;
}

void QtDownload::download()
{
    QUrl url = QUrl::fromEncoded(this->target.toLocal8Bit());
    QNetworkRequest request(url);
    QEventLoop loop;
    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
    QObject::connect(manager.get(request),SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();

}

void QtDownload::downloadProgress(qint64 recieved, qint64 total)
{

    qDebug() << (double(recieved)/total)*100<<"%";
}

