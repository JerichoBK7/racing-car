/*************************************************************************/
/*                             V I S O R - O P E N G L                   */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file visoropengl.h
 * Implementation of visor to opengl
 * @author Miguel Ángel Díaz López
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */




#ifndef VISOROPENGL
#define VISOROPENGL

#include <iostream>
#include <QGLWidget>
#include <QEvent>
#include <QMouseEvent>
#include <vertex.h>
#include "escena.h"
#include "matrix.h"
#include "random.h"
#include <QTimer>
#include "_camara.h"
#include "time.h"     /*temporizador*/

using namespace std;

 class VisorOpenGL: public QGLWidget
 {
     Q_OBJECT

 private:
    QTimer *timer;
    QPoint pos_raton;
    // camara:
    _camara camara;
    Escena escena;
    int Draw_type;
    int Window_width;
    int Window_height;
    int Front_plane;
    int Back_plane;
    // tam_actual
    int width_act, height_act;
    // temporizador
    float Temporizador(void);
    time_t time_ini, time_fin;
    bool time_0;

protected slots:
    void desocupado(void);

protected:
   void initializeGL();
   void setCamara();
   void paintGL();
   void resizeGL(int width, int height);
   void mousePressEvent(QMouseEvent *event);
   void keyPressEvent(QKeyEvent *event);
   void setProjection();
   void dibujarEscena();

 public:
     VisorOpenGL(QWidget *parent = 0);
     ~VisorOpenGL();
     QSize minimumSizeHint() const;
     QSize sizeHint() const;
     void setAnimation(int);
 };

#endif

