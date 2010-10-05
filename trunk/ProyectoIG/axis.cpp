/*************************************************************************/
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*                                                                       */
/*     License: GPL3                                                     */
/*                                                                       */
/*************************************************************************/
/**
 *
 *   This file is part of axis.h
 *
 *   axis.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   axis.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "axis.h"

Axis::Axis() {
}

void Axis::draw() {
	glBegin(GL_LINES);
// eje X, color rojo
	glColor3f(0.7,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(0,0,0);
	glColor3f(1,0,0);
	glVertex3f(0,0,0);
	glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
	glColor3f(0,0.7,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,0,0);
	glColor3f(0,1,0);
	glVertex3f(0,0,0);
	glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
	glColor3f(0,0,0.7);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,0);
	glColor3f(0,0,1);
	glVertex3f(0,0,0);	
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}

