#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnParseLogs_clicked();
    bool parse_line(QString);
    void add404(QRegExp);
    void add_404_to_model();
    void save_report();

    void on_pushButton_save_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model_404;
    QHash<QString, int> hash_404;

    int total_lines;
};

#endif // MAINWINDOW_H
