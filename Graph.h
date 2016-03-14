#ifndef GRAPH_H
#define GRAPH_H

#include <QGLWidget>

class Graph : public QGLWidget
{
private:
    int N;
    float xmin, ymin, xmax, ymax, (*f)(float x);
    float xi(float x);
    float eta(float x);
    void setExtrema();
    void showAxes();
    void Draw();
protected:
    virtual void initializeGL();
    virtual void resizeGL(int width, int height);
    virtual void paintGL();
public:
    Graph(QWidget* parent = 0);
    Graph(int N, float xmin, float xmax, float (*f)(float x));
};

#endif // GRAPH_H
