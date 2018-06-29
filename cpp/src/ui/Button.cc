#include "Button.hh"

MyButton::MyButton( QWidget* parent )
        : QPushButton( parent ),
          m_py() {
    connect( this, SIGNAL(clicked()), this, SLOT(run()));
}

MyButton::~MyButton() {}

void MyButton::run()  {
    py::exec(R"(
            kwargs = dict(name="World", answer="Python")
            message = "Hello, {name}! I'm running in Python".format(**kwargs)
            print(message)
        )");
};