//
// Created by Eddie Hoyle on 1/07/18.
//

#ifndef BEMO_WINDOW_HH
#define BEMO_WINDOW_HH

#include <QMainWindow>
#include <pybind11/embed.h>

namespace py = pybind11;

class Outliner;
class ScriptEditor;

class Window : public QMainWindow {

    Q_OBJECT

public:
    Window();
    ~Window() = default;

private slots:
    void addNode();
    void execScript();

private:

    Outliner* m_outliner;
    ScriptEditor* m_editor;

    py::scoped_interpreter m_py;
};

#endif // BEMO_WINDOW_HH
