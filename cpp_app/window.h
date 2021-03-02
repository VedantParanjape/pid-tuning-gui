#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    QPushButton *m_button;
    QSlider *slider;
    QProgressBar *progressBar;
    int m_counter;

signals:
    void counterReached();
public slots:
    void slotButtonClicked(bool checked);
};

#endif // WINDOW_H
