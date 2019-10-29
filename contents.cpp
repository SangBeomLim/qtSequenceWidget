#include "contents.h"
#include "ui_contents.h"
#include "define.h"
contents::contents(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contents)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 500, 500);

    m_state_page = PAGE::CONTENT;
}

contents::~contents()
{
    delete ui;
}

void contents::UpdateWidget()
{
    m_info = new info(this);
    m_info->SetIDString(m_id);
    m_info->SetPWString(m_pw);
    m_info->UpdateWidget();
    m_info->show();

    m_stkWidget = ui->stWidget;
    m_stkWidget->setGeometry(0, 100, 500, 400);

    if(m_state_page == PAGE::CONTENT)
    {
        qDebug() << "this page index : " << m_stkWidget->currentIndex();
        m_stkWidget->setCurrentIndex(0);
    }
    else if(m_state_page == PAGE::VISION)
    {
        m_stkWidget->setCurrentIndex(1);
    }
    else if(m_state_page == PAGE::HAPTIC)
    {
        m_stkWidget->setCurrentIndex(2);
    }

}

void contents::SetIDString(QString id)
{
    m_id = id;
}

void contents::SetPWString(QString pw)
{
    m_pw = pw;
}

QString contents::GetIDString()
{
    return m_id;
}

QString contents::GetPWString()
{
    return m_pw;
}


void contents::on_ct_vision_clicked()
{
    m_state_page = PAGE::VISION;
    m_stkWidget->setCurrentIndex(1);
}

void contents::on_ct_haptic_clicked()
{
    m_state_page = PAGE::HAPTIC;
    m_stkWidget->setCurrentIndex(2);
}

void contents::on_btn_vision_clicked()
{
    qDebug() << "this page index : " << m_stkWidget->currentIndex();
}

void contents::on_vision_close_clicked()
{
    m_state_page = PAGE::CONTENT;
    if(m_state_page == PAGE::CONTENT)
    {
        m_stkWidget->setCurrentIndex(0);
    }
}

void contents::on_btn_haptic_clicked()
{
    qDebug() << "this page index : " << m_stkWidget->currentIndex();
}

void contents::on_haptic_close_clicked()
{
    m_state_page = PAGE::CONTENT;
    if(m_state_page == PAGE::CONTENT)
    {
        m_stkWidget->setCurrentIndex(0);
    }

}
