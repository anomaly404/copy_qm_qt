#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtdownload.h"
#include "json.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    display();

}

void MainWindow::display()
{
    JSON *js=new JSON(this);
    js->setTarget("http://prereleases.musescore.org/extensions/languages/details.json");
    js->download();
    QByteArray json=js->return_Data();
    ui->textBrowser->setText(json);
    QJson::Parser parser;
    bool ok;
    int row_count=0;
    QVariant result = parser.parse (json, &(ok));
    if (!ok)
    {
      qFatal("An error occured during parsing");
      return ;
    }
    row_count=result.toMap()["packs"].toList().count();
    ui->table->setRowCount(row_count);
//    ui->languages->t ("Languages");

    int row=0,col=0;
    QPushButton *button[10],*temp;
    temp=new QPushButton;

    foreach (QVariant dis,result.toMap()["packs"].toList())
    {
        col=0;
        ui->table->setItem(row,col++,new QTableWidgetItem (dis.toMap()["title"].toString()));
        ui->table->setItem(row,col++,new QTableWidgetItem (dis.toMap()["file_name"].toString()));
        ui->table->setItem(row,col++,new QTableWidgetItem (dis.toMap()["last-modified"].toString()));
        button[row]=new QPushButton("Update");

        temp=button[row];
        but_map[temp]=row;
        ui->table->setIndexWidget(ui->table->model()->index(row,col++),temp);
        connect(temp, SIGNAL(clicked()), this, SLOT(download()));
        row++;
    }

}
void MainWindow::download()
{
    QPushButton *button = dynamic_cast<QPushButton*>( sender() );

    QString base_addr="http://prereleases.musescore.org/extensions/languages/";
    int index=but_map[button];

    QString data=ui->table->model()->index(index,1).data().toString();
    base_addr+=data;
    QtDownload *dl=new QtDownload(this);
    dl->setTarget(base_addr);
    dl->setlocalfile(data);
    dl->download();
}

MainWindow::~MainWindow()
{
    delete ui;
}
