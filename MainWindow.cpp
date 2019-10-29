#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setAttribute(Qt::WA_TranslucentBackground, true); // 배경 투명하게
    setWindowFlags(Qt::FramelessWindowHint); // 프레임 제거

    m_login = new login(this);

    connect(m_login, &login::signal_contents, this, &MainWindow::contentsShow);
}

MainWindow::~MainWindow()
{
    delete m_login;
    delete m_contents;
    delete ui;
}

void MainWindow::contentsShow()
{
    m_total_page = m_login->GetStatePage();
//    qDebug() << m_login->GetStatePage();

    if( m_total_page == PAGE::CONTENT)
    {
        m_contents = new contents(this);
        m_contents->SetIDString(m_login->GetIDString());
        m_contents->SetPWString(m_login->GetPWString());
        m_contents->UpdateWidget();
        m_contents->show();
        m_login->hide();
    }

}
