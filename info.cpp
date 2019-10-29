#include "info.h"
#include "define.h"

info::info(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,500,100);
    Initialize();
}

info::~info()
{
    delete m_label_info;
}

void info::Initialize()
{
    m_state_page = PAGE::CONTENT;
    m_label_info = new QLabel(this);
    m_label_info->setGeometry(100, 0, 400, 100);
}

void info::UpdateWidget()
{
    QString str;
    str = "ID : ";
    str += GetIDString();
    str += " / PW : ";
    str += GetPWString();

    m_label_info->setText(str);
}

void info::SetIDString(QString id)
{
    m_id = id;
}

void info::SetPWString(QString pw)
{
    m_pw = pw;
}

QString info::GetIDString()
{
    return m_id;
}

QString info::GetPWString()
{
    return m_pw;
}

int info::GetStatePage()
{
    return m_state_page;
}
