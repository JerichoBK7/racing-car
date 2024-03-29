/*************************************************************************/
/*                             W I N D O W                               */
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file ventana.h
 * Implementation of window of the game
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


