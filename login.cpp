#include "login.h"
#include "define.h"

login::login(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,500,500);
    m_state_page = PAGE::LOGIN;
    Initialize();
}

login::~login()
{
    delete m_btn;
    delete m_label_id;
    delete m_label_pw;
    delete m_le_id;
    delete m_le_pw;
}

void login::Initialize()
{
    //button
    m_btn = new QPushButton(this);
    m_btn->setText("LOGIN");
    m_btn->setGeometry(0,0,200,100);

    m_label_id = new QLabel(this);
    m_label_id->setText("ID : ");
    m_label_id->setGeometry(50, 150, 100, 50);
    m_label_pw = new QLabel(this);
    m_label_pw->setText("PW : ");
    m_label_pw->setGeometry(50, 200, 100, 50);
    m_le_id = new QLineEdit(this);
    m_le_id->setGeometry(150, 150, 200, 50);
    m_le_pw = new QLineEdit(this);
    m_le_pw->setGeometry(150, 200, 200, 50);

    connect(m_btn, &QPushButton::clicked, this, &login::onClickButton);

}

void login::onClickButton()
{
    SetIDString(m_le_id->text());
    SetPWString(m_le_pw->text());

    qDebug() << GetIDString();
    qDebug() << GetPWString();

    m_state_page = PAGE::CONTENT;
    emit signal_contents();
}

void login::SetIDString(QString id)
{
    m_info.id = id;
}

void login::SetPWString(QString pw)
{
    m_info.pw = pw;
}

QString login::GetIDString()
{
    return m_info.id;
}

QString login::GetPWString()
{
    return m_info.pw;
}

int login::GetStatePage()
{
    return m_state_page;
}
