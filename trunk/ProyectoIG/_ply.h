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
