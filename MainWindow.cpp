#include "MainWindow.h"
#include "ui_MainWindow.h"

class MainWindowPrivate
{
public:
    MainWindowPrivate();

    QScopedPointer<Ui::MainWindow> ui;
};

MainWindowPrivate::MainWindowPrivate() :
    ui(new Ui::MainWindow)
{
}

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent, flags),
    d(new MainWindowPrivate)
{
    d->ui->setupUi(this);
}

MainWindow::~MainWindow()
{
}
