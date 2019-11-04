#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QtGui>
#include <QMenu>
#include <QList>
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QProcess>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include <QSystemTrayIcon>

#include <dlabel.h>
#include <dlineedit.h>
#include <dtextedit.h>
#include <DMainWindow>
#include <DApplication>
#include <dpasswordedit.h>

#include "inputwidget.h"
#include "netcardwidget.h"

DWIDGET_USE_NAMESPACE

class authWidget : public QWidget
{
    Q_OBJECT

    /* control */

    DLabel          *label_chbox;
    QTextEdit       *show_info_edit;
    QPushButton     *button_confirm;
    QCheckBox       *checkbox;

    /* information */

    QStringList     *cmd_args;
    QProcess        *process;

    /* Input infomation get */

    InputWidget     *inputMaster;
    NetCardWidget   *netcardMaster;

    QString runProOnce(QString pro_name = "", QStringList arg = QStringList());

signals:

public:
    explicit authWidget(DMainWindow *parent = nullptr);
    ~authWidget();

public slots:
    void triggerauthen();
    void getProOutput();
    void getProErrout();
};

#endif // AUTHWIDGET_H