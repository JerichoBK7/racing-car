/*************************************************************************/
/*                                                                       */
/*                       R A C I N G      C A R                          */
/*                                                                       */
/*************************************************************************/
/*                                                                       */
/*                                                                       */
/*         Copyright (C) Miguel Ángel Díaz López [2010]                  */
/*                                                                       */
/*                                                                       */
/*     License: GPL3                                                     */
/*                                                                       */
/*************************************************************************/
/**
 *
 *  Videojuego en 3D acerca de una carrera de coches en miniatura a través de
 *  una casa como escenario.
 *
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
 *
 * @footnote e-mail: admin at etsiit.es
 *
 */

#include <QApplication>

#include "ventana.h"
#include "visoropengl.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Ventana ventana;
     ventana.show();
     return app.exec();
 }
