#include "Button.hh"
#include "Window.hh"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
//
//    MyButton button;
//    button.setText( "click me" );
//    button.show();

    Window window;
    window.show();

    return app.exec();
}
//
//
//int main(int argc, char *argv[])
//{
//    Q_INIT_RESOURCE(application);
//
//    QApplication app(argc, argv);
//    QCoreApplication::setOrganizationName("QtProject");
//    QCoreApplication::setApplicationName("Application Example");
//    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
//
//    Window mainWin;
//    mainWin.show();
//
//    return app.exec();
//}