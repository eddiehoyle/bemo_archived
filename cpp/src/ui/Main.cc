#include "Button.hh"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    MyButton button;
    button.setText( "click me" );
    button.show();

    return app.exec();
}