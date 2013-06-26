#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMap>
#include <QWebFrame>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QtWebKit/QWebView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    QByteArray txt;
    void display();
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QMap <QPushButton *,int> but_map;
public slots:
    void download();
};

#endif // MAINWINDOW_H
