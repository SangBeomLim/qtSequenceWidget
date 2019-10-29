#ifndef CONTENTS_H
#define CONTENTS_H

#include <QWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QDebug>
#include "info.h"

namespace Ui {
class contents;
}

class contents : public QWidget
{
    Q_OBJECT

public:
    explicit contents(QWidget *parent = nullptr);
    ~contents();
    void SetIDString(QString id);
    void SetPWString(QString pw);
    QString GetIDString();
    QString GetPWString();
    void UpdateWidget();
private slots:
    void on_ct_vision_clicked();
    void on_ct_haptic_clicked();
    void on_btn_vision_clicked();
    void on_vision_close_clicked();
    void on_btn_haptic_clicked();
    void on_haptic_close_clicked();

private:

private:
    Ui::contents *ui;
    QLabel* m_label;
    info* m_info;
    QStackedWidget* m_stkWidget;
    QString m_id;
    QString m_pw;

    int m_state_page;
};

#endif // CONTENTS_H
