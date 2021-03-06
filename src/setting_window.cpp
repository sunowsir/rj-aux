/*
	* File     : setting_window.h
	* Author   : sunowsir
	* Mail     : sunowsir@163.com
	* Github   : github.com/sunowsir
	* Creation : 2021年02月13日 星期六 15时05分17秒
*/

#include "setting_window.h"

setting_window::setting_window(QWidget *parent) {
    this->setFixedSize(350, 350);
    this->setWindowTitle(tr("rj-aux设置"));
    this->setWindowFlag(Qt::SubWindow);

    this->st_widget = new setting_widget(this);
    this->setCentralWidget(this->st_widget);
    
    this->centralWidget()->setLayout(this->st_widget->get_layout());

    QWidget::connect(this->st_widget, SIGNAL(save_cfg_button_released(const QStringList&)),
                      this, SLOT(on_clicked_save_cfg_button(const QStringList&)),
                      Qt::AutoConnection);
}

setting_window::~setting_window() {
    this->st_widget->close();
    delete this->st_widget;
}


/* rewrite */

void setting_window::changeEvent(QEvent *e) {
    if (( e->type() == QEvent::WindowStateChange) && this->isMinimized()) {
        QTimer::singleShot(100, this, SLOT(close()));
    }
}


void setting_window::closeEvent(QCloseEvent *e) {
    e->ignore();

    if (!this->st_widget->get_core_assigned_status()) {
        QMessageBox::critical(this, tr("警告"),  tr("请选择认证核心程序"),
                              QMessageBox::Ok, QMessageBox::Ok);
        return ;
    }

    this->hide();
}

void setting_window::on_clicked_save_cfg_button(const QStringList& set_info) {
    emit this->save_cfg_button_released(set_info);
}
