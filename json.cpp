#include "json.h"
#include <QCoreApplication>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <QEventLoop>

JSON::JSON(QWidget *parent):QObject(parent)
{

}


JSON::~JSON()
{

}


void JSON::setTarget(const QString &t)
{
    this->target = t;
}

void JSON::downloadFinished(QNetworkReply* data)
{
    json = data->readAll();
    emit done();
}

QByteArray JSON::return_Data()
{
    return json;
}

void JSON::download()
{
    QUrl url = QUrl::fromEncoded(this->target.toLocal8Bit());
    QNetworkRequest request(url);
    QEventLoop loop;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
    QObject::connect(manager.get(request),SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
}




