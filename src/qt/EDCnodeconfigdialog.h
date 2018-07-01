#ifndef EDCNODECONFIGDIALOG_H
#define EDCNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class EdcNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class EdcNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EdcNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:28666", QString privkey="MASTERNODEPRIVKEY");
    ~EdcNodeConfigDialog();

private:
    Ui::EdcNodeConfigDialog *ui;
};

#endif // EDCNODECONFIGDIALOG_H
