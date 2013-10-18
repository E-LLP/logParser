#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT
    
public:
    explicit Preferences(QWidget *parent = 0);
    ~Preferences();
    
private slots:
    void on_pushButton_closePrefs_clicked();
    void on_pushButton_savePreferences_clicked();

//    void Save_Settings();

private:
    Ui::Preferences *ui;
};

#endif // PREFERENCES_H
