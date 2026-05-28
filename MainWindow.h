#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindowPrivate;

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    virtual ~MainWindow();

private:
    Q_DISABLE_COPY(MainWindow)
    QScopedPointer<MainWindowPrivate> d;
};

#endif // MAINWINDOW_H
