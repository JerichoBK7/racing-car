/*************************************************************************/
/*                             W I N D O W                               */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file ventana.h
 * Implementation of window of the game
 * @author Miguel Ángel Díaz López
 *
 */

#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include "visoropengl.h"


 class Ventana : public QWidget
 {
 private:
     VisorOpenGL *visorOpenGL;
 public:
     Ventana();
     void keyPressEvent(QKeyEvent *event);
 };


 #endif


