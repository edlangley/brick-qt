#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QApplication>
#include <QGLWidget>
#include <QGLShaderProgram>
#include <QMouseEvent>
#include <QTextStream>
#include <QFile>
#include <QTimer>
#include <QStringList>

#include <iostream>

#include <GL/glut.h>

#define INERTIA_THRESHOLD       1.0f
#define INERTIA_FACTOR          0.5f
#define SCALE_FACTOR            0.01f
#define SCALE_INCREMENT         0.5f

typedef enum {
    EModelFirst  = 0,
    EModelCube   = 0,
    EModelTeapot = 1,
    EModelSphere = 2,
    EModelTorus  = 3,
    EModelLast   = 3,
} EModelType;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *e);

private:
    void drawCube(void);
    int readShaderSource(QString baseFileName);
    int readShaderFile(QString fileName, QString &shaderSource);
    int installShaders();
    int printOpenGLError(char *file, int line);
    void nextClearColor(void);
    int xRot;
    int yRot;
    int zRot;
    GLfloat fScale;
    QPoint lastPos;
    EModelType gleModel;
    int Rotate;
    int xLastIncr;
    int yLastIncr;
    float fXInertia;
    float fYInertia;
    float fXInertiaOld;
    float fYInertiaOld;
    int clearColor;
    QString vertexShaderSource;
    QString fragmentShaderSource;

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

public slots:
    void animate();

};

#endif // GLWIDGET_H
