#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QMainWindow>

namespace Ui {
class startPage;
}

class startPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit startPage(QWidget *parent = nullptr);
    ~startPage();

private slots:
    void on_exit_clicked();

    void on_start_clicked();

    void on_ok_clicked();

    void on_pushButton_clicked();

    void on_Gallery_clicked();

private:
    Ui::startPage *ui;


};

#endif // STARTPAGE_H
