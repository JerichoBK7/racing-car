/*************************************************************************/
/*                                 P L Y                                 */
/*                                                                       */
/*                                                                       */
/*     (c)   Miguel Ángel Díaz López [2010]                              */
/*                                                                       */
/*     License: GPL3                                                     */
/*************************************************************************/
/**
 *
 * @file _ply.h
 * Implementation of .ply for read objects in 3D and build
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
#ifndef _PLY_H
#define _PLY_H

#include <iostream>
#include <GL/gl.h>
#include <math.h>
#include <vertex.h>
#include "_object3d.h"
#include "file_ply_stl.h"
using namespace std;

class _ply : public _object3D
{
private:
    void CajaFrontera(void);

public:
    _ply();
    void LecturaPly(char *File_name);
};

#endif // _PLY_H
