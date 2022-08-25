#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFont>
#include <QFileDialog>
#include <QMessageBox>
#include <QByteArray>
#include <QTextCursor>
#include <QDebug>
#include <QtCore/QTextCodec>
#include <QTextBlock>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->setFont(QFont("微软雅黑", 11));
    ui->textEdit_2->setFont(QFont("微软雅黑", 11));




}

Widget::~Widget()
{
    delete ui;
}



void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F3){

        share11 = "";
        QTextCursor tc;
        qDebug() <<"22222";
        tc = ui->textEdit_2->textCursor();
        QTextBlock aa = tc.block();
        share11 = aa.text();
        share11 = ui->textEdit_2->textCursor().selectedText();
        qDebug() <<"---" << share11 << "---";
        my_so();

    }

    //if(event->key() == Qt::Key_F1){
   //    ui->textEdit_2->moveCursor(QTextCursor::EndOfBlock);
   // }

    if(event->key() == Qt::Key_F1){
     //  ui->textEdit->moveCursor(QTextCursor::EndOfBlock);
      ui->textEdit_2->textCursor().insertText("对");
    }

    if(event->key() == Qt::Key_F2){
     //  ui->textEdit_2->moveCursor(QTextCursor::EndOfBlock);
        ui->textEdit_2->textCursor().insertText("错");
    }
}

void Widget::insert()
{
    ui->textEdit_2->textCursor().insertText("对");
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MidButton){

        share11 = "";
        QTextCursor tc;
        qDebug() <<"22222";
        tc = ui->textEdit_2->textCursor();
        QTextBlock aa = tc.block();
        share11 = aa.text();
        share11 = ui->textEdit_2->textCursor().selectedText();
        qDebug() <<"---" << share11 << "---";
        my_so();
         ui->textEdit_2->moveCursor(QTextCursor::EndOfBlock);
    }}


void Widget::on_pushButton_clicked()
{
//    QString filename = QFileDialog::getOpenFileName(this, "open", ".");
//    QFile file(filename);
//    file.open(QFile::ReadOnly);
//    QByteArray co = file.readAll();
//    ui->textEdit->setHtml(co);

      QFile file(fileName);
      file.open(QFile::ReadWrite | QIODevice::Truncate);
      QString str = ui->textEdit_2->toPlainText();
      file.write(str.toUtf8());

}

void Widget::my_so()
{
    /* ui->textEdit->moveCursor(QTextCursor::Start);
        //QString findtext=ui->textEdit_2->toPlainText();
      if(ui->textEdit->find(share11))
      {
          // 查找到后高亮显示
          QPalette palette = ui->textEdit->palette();
          palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
          ui->textEdit->setPalette(palette);


          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);
          ui->textEdit->moveCursor(QTextCursor::Down);

           palette = ui->textEdit->palette();
          palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
          ui->textEdit->setPalette(palette);

          palette = ui->textEdit->palette();
          palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
          ui->textEdit->setPalette(palette);

      }
      else
      {

      }

      */

    ui->textEdit->moveCursor(QTextCursor::Start);

    if(ui->textEdit->find(share11))
    {
        // 查找到后高亮显示
        QPalette palette = ui->textEdit->palette();
    palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        ui->textEdit->setPalette(palette);


        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);
        ui->textEdit->moveCursor(QTextCursor::Down);


        ui->textEdit->find(share11, QTextDocument::FindBackward);

        palette = ui->textEdit->palette();
        palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        ui->textEdit->setPalette(palette);

        palette = ui->textEdit->palette();
        palette.setColor(QPalette::Highlight,palette.color(QPalette::Active,QPalette::Highlight));
        ui->textEdit->setPalette(palette);

    }
    else
    {

    }


}

void Widget::aa(){


    QString search_text = share11;
    if (search_text.trimmed().isEmpty()) {
        QMessageBox::information(this, tr("Empty search field"), tr("The search field is empty."));
    } else {
        QTextDocument *document = ui->textEdit_2->document();
        bool found = false;
        QTextCursor highlight_cursor(document);
        QTextCursor cursor(document);

        //开始
        cursor.beginEditBlock();

        QTextCharFormat color_format(highlight_cursor.charFormat());
        color_format.setForeground(Qt::red);
        while (!highlight_cursor.isNull() && !highlight_cursor.atEnd()) {

            //查找指定的文本，匹配整个单词
            highlight_cursor = document->find(search_text, highlight_cursor, QTextDocument::FindWholeWords);
            if (!highlight_cursor.isNull()) {
                if(!found)
                    found = true;
                highlight_cursor.mergeCharFormat(color_format);
            }
        }
        cursor.endEditBlock();
        //结束

        if (found == false) {
            QMessageBox::information(this, tr("Word not found"), tr("Sorry,the word cannot be found."));
        }
    }
}



void Widget::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "open file", ".");
    QFile file(filename);
    file.open(QIODevice::ReadWrite);

    QByteArray encodedString = file.readAll();
    QTextCodec::ConverterState state;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QString text = codec->toUnicode(encodedString.constData(), encodedString.size(), &state);
    if (state.invalidChars > 0) {
        text = QTextCodec::codecForName( "GBK" )->toUnicode(encodedString);
    } else {
        text = encodedString;
    }
    ui->textEdit_2->setText(text);
    file.close();

    fileName = filename;
}

void Widget::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "open document", ".");
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.readAll();

    ui->textEdit->setPlainText(QString(array));
}
