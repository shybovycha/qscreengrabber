#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QPixmap>
#include <QFileDialog>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem(QString("Full Screen"));
    //ui->comboBox->addItem(QString("Region"));
}

void Widget::grab(qint64 delay)
{
    this->hide();

    QTimer::singleShot((delay * 1000) + 500, this, SLOT(saveScreenShot()));
}

void Widget::saveScreenShot()
{
    QPixmap screenShot = QPixmap::grabWindow(QApplication::desktop()->winId()); //grabWidget(QApplication::desktop(), QRect())

    this->show();
    ui->label_3->setPixmap(screenShot.scaled(ui->label_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QString format = "jpg";
    QString initialPath = QDir::currentPath() + tr("/untitled.") + format;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath, tr("%1 Files (*.%2);;All Files (*)").arg(format.toUpper()).arg(format));

    if (!fileName.isEmpty())
    {
        screenShot.save(fileName, format.toAscii());
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    grab(ui->spinBox->value());
}
