#include "Graph.h"

Graph::Graph(QWidget* parent) : QGLWidget(parent){}

Graph::Graph(int N, float xmin, float xmax, float (*f)(float x)) : N(N), xmin(xmin), xmax(xmax), f(f)
{
    Graph();
    setExtrema();
}

void Graph::initializeGL(){ qglClearColor(Qt::white); }

void Graph::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    glOrtho(0, width, height, 0, -1, 1);
}

void Graph::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    showAxes();
    Draw();
}

float Graph::xi(float x){ return this->width() * (x - xmin) / (xmax - xmin); }

float Graph::eta(float y){ return this->height() * (1 - (y - ymin) / (ymax - ymin)); }

void Graph::setExtrema()
{
    float h = (xmax - xmin) / float(N), x;
    ymin = f(xmin);
    ymax = ymin;
    for(int i = 0; i <= N; ++i)
    {
        x = xmin + i * h;
        if (f(x) < ymin)
            ymin = f(x);
        if(f(x) > ymax)
            ymax = f(x);
    }
}

void Graph::showAxes()
{
    glBegin(GL_LINES);
        glColor3f(0.f, 0.f, 0.f);
        glVertex2f(xi(xmin), eta(0));
        glVertex2f(xi(xmax), eta(0));

        glVertex2f(xi(0), eta(ymin));
        glVertex2f(xi(0), eta(ymax));
    glEnd();
}

void Graph::Draw()
{
    float h = (xmax - xmin) / float(N), x, y;
    glBegin(GL_LINE_STRIP);
        glColor3f(1.f, 0.f, 0.f);
        for (int i = 0; i <= N; ++i)
        {
            x = xmin + i * h; y = f(x);
            glVertex2f(xi(x), eta(y));
        }
    glEnd();
}
