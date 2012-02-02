#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    void grab(qint64 delay);
    void grab(QRectF region, qint64 delay);

private slots:
    void saveScreenShot();
    void on_pushButton_clicked();
};

#endif // WIDGET_H
