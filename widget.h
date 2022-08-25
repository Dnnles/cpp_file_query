#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent* event);
   void aa();
   void insert();
private slots:
    void on_pushButton_clicked();
    void my_so();

    void on_pushButton_3_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QString share11;
    QString fileName;
};
#endif // WIDGET_H
