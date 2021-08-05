#ifndef SOBREAPP_H
#define SOBREAPP_H

#include <QDialog>

namespace Ui {
class SobreApp;
}

class SobreApp : public QDialog
{
    Q_OBJECT

public:
    explicit SobreApp(QWidget *parent = nullptr);
    ~SobreApp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SobreApp *ui;
};

#endif // SOBREAPP_H
