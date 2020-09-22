#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    void paintEvent(QPaintEvent* )override;//重绘画图
    void keyReleaseEvent(QKeyEvent* event)override;//按键释放时的反应
    void keyPressEvent(QKeyEvent* event)override;
    ~MainWindow();
public slots:
    void startgame();//与按钮有关
    void timerstart();//定时器
    void newgame();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    engine* ge;
    QTimer* timer;
    bool gameisstarted;
};

#endif // MAINWINDOW_H
