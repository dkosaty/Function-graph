#include <QApplication>
#include <cmath>
#include "Graph.h"

float f(float x){ return x * sin(x); }

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int N = 100;
    float xmin = -6.f, xmax = 6.f;

    Graph graph(N, xmin, xmax, f);
    graph.show();

    return app.exec();
}
