#include "calc.h"
//#include "graph.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Calc w;

  // Graph g;

  w.show();
  // g.show();
  return a.exec();
}
