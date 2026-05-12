#include <QApplication>
#include "passwordgenerator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PasswordGeneratorWindow window;
    window.show();

    return app.exec();
}
