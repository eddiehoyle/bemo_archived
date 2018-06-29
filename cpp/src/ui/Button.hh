#ifndef BEMO_APP_HH
#define BEMO_APP_HH

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <pybind11/embed.h>

namespace py = pybind11;

class MyButton : public QPushButton {
    Q_OBJECT
public:
    explicit MyButton( QWidget* parent = nullptr );
    ~MyButton();
private slots:
    void run();
private:
    py::scoped_interpreter m_py;

};

#endif