#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
{

    this->w = new authWidget(this);
    // qDebug() << this->w->size();
    // this->resize(this->w->size()); //设置窗口大小
    this->resize(640, 480);
    setCentralWidget(this->w);

    this->t = new TrayWidget(this);

}

MainWindow::~MainWindow()
{
    delete this->w;
    delete this->t;
}

/* slot */

void MainWindow::trayAction( QSystemTrayIcon::ActivationReason reason ) {
    if ( reason == QSystemTrayIcon::Trigger ) {
        this->showNormal();
    }
}


/* rewrite */

void MainWindow::changeEvent( QEvent *e ) {
    if ( ( e->type() == QEvent::WindowStateChange ) && this->isMinimized() ) {
        QTimer::singleShot(100, this, SLOT(close()));
    }
}

void MainWindow::closeEvent( QCloseEvent *e ) {
    e->ignore();
    this->hide();
}
