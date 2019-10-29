#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QString>
#include <QLineEdit>

typedef struct {
    QString id;
    QString pw;
}INFO;

class login : public QWidget
{
    Q_OBJECT
public:
    explicit login(QWidget *parent = nullptr);
    ~login() override;
    void SetIDString(QString id);
    void SetPWString(QString pw);
    QString GetIDString();
    QString GetPWString();
    int GetStatePage();
protected:
private:
    void Initialize();
public:
protected:
    QPushButton *m_btn; //Login button
    QLineEdit* m_le_id;
    QLineEdit* m_le_pw;
    QLabel* m_label_id;
    QLabel* m_label_pw;
private:
    INFO m_info;
    int m_state_page;
signals:
    void signal_contents();
public slots:
    void onClickButton();
};

#endif // LOGIN_H
