#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "define.h"
#include "login.h"
#include "contents.h"
#include "info.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    login* m_login;
    contents* m_contents;

    int m_total_page;
signals:
public slots:
    void contentsShow();
};

#endif // MAINWINDOW_H
