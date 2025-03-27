
#define debug_mode false
#define show_data false

using namespace std;


#include <QApplication>
#include <QWidget>
#include <QCoreApplication>

#include "Phone.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Phone window;
    window.resize(1200, 700);
    window.show();
    return app.exec();
}
