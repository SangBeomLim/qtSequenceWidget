#ifndef INFO_H
#define INFO_H

#include <QObject>
#include <QWidget>
#include <QLabel>


class info : public QWidget
{
    Q_OBJECT
public:
    explicit info(QWidget *parent = nullptr);
    ~info() override;

    void UpdateWidget();
    void SetIDString(QString id);
    void SetPWString(QString pw);
    QString GetIDString();
    QString GetPWString();

    int GetStatePage();
private:
    void Initialize();
private:
    QString m_id;
    QString m_pw;
    QLabel* m_label_info;
    int m_state_page;
signals:

public slots:
};

#endif // INFO_H
