/*
	* File     : setting_window.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2021年02月13日 星期六 15时05分17秒
*/

#include "setting_window.h"

setting_window::setting_window( QWidget *parent ) : QMainWindow(parent) {
    this->setFixedSize(300, 300);
    this->setWindowTitle(tr("rj-aux设置"));
    this->setWindowFlag(Qt::SubWindow);

    this->st = new setting_widget(this);
    this->setCentralWidget(this->st);
    
    this->centralWidget()->setLayout(this->st->get_layout());
}

setting_window::~setting_window() {
    this->st->close();
    delete this->st;
}


/* rewrite */

void setting_window::changeEvent( QEvent *e ) {
    if ( ( e->type() == QEvent::WindowStateChange ) && this->isMinimized() ) {
        QTimer::singleShot( 100, this, SLOT( close() ) );
    }
}


void setting_window::closeEvent( QCloseEvent *e ) {
    e->ignore();
    this->hide();
}


