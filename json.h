#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QWidget>
#include "qjson/parser.h"
class JSON : public QObject
{
    Q_OBJECT
public:
    explicit JSON(QWidget *parent=0);
    ~JSON();

    void setTarget(const QString& t);
    QByteArray return_Data();
    void display();


private:
    QByteArray json;
    QNetworkAccessManager manager;
    QString target;

signals:
    void done();

public slots:
    void download();
    void downloadFinished(QNetworkReply *data);
};
