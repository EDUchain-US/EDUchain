#ifndef ADDEDITEDCNODE_H
#define ADDEDITEDCNODE_H

#include <QDialog>

namespace Ui {
class AddEditEdcNode;
}


class AddEditEdcNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditEdcNode(QWidget *parent = 0);
    ~AddEditEdcNode();

protected:

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::AddEditEdcNode *ui;
};

#endif // ADDEDITEDCNODE_H
