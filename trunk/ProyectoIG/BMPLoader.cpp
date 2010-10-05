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
 *   This file is part of BMPLoader.h
 *
 *   BMPLoader.h is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   BMPLoader.h is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "BMPLoader.h"


BYTE& BMPClass::obtenerPixel(int x,int y,int c){
    return pixel[(y*width+x)*3+c];
}
void BMPClass::allocateMem(){
    pixel.resize(width*height*3);
}

std::string BMPClass::TranslateBMPError(BMPError err)
{
	switch(err)
	{
	case(BMPNOTABITMAP):
		return "This file is not a bitmap, specifically it doesn't start 'BM'";
	case(BMPNOOPEN):
		return "Failed to open the file, suspect it doesn't exist";
	case(BMPFILEERROR):
		return "ferror said we had an error. This error seems to not always mean anything, try ignoring it";
	case(BMPBADINT):
		return "sizeof(int)!=4 quite a lot of rewriting probably needs to be done on the code";
	case(BMPNOERROR):
		return "No errors detected";
	case(BMPUNKNOWNFORMAT):
		return "Unknown bmp format, ie not 24bit, 256,16 or 2 colour";
	default:
		return "Not a valid error code";
	}
}

BMPError BMPClass::BMPLoad(std::string fname, _vertex4f colores)
{
	if(sizeof(int)!=4) return BMPBADINT;
		
        FILE* f=fopen(fname.c_str(),"rb");	//open for reading in binary mode
	if(!f) return BMPNOOPEN;
	char header[54];
	fread(header,54,1,f);			//read the 54bit main header

	if(header[0]!='B' || header[1]!='M') 
	{
		fclose(f);
		return BMPNOTABITMAP;		//all bitmaps should start "BM"
	}

	//it seems gimp sometimes makes its headers small, so we have to do this. hence all the fseeks
	int offset=*(unsigned int*)(header+10);
	
        width=*(int*)(header+18);
        height=*(int*)(header+22);
	//now the bitmap knows how big it is it can allocate its memory
        allocateMem();

	int bits=int(header[28]);		//colourdepth

	int x,y,c;
        BYTE cols[256*4];			//colourtable
	switch(bits)
	{
	case(24):
		fseek(f,offset,SEEK_SET);
                fread(&pixel[0],width*height*3,1,f);	//24bit is easy
                for(x=0;x<width*height*3;x+=3)		//except the format is BGR, grr
		{
                        BYTE temp=pixel[x];
                        pixel[x]=pixel[x+2];
                        pixel[x+2]=temp;
		}
		break;

	case(8):
                fread(cols,256*4,1,f);			//read colortable
		fseek(f,offset,SEEK_SET);
                for(y=0;y<height;++y)			//(Notice 4obtenerPixel/col for some reason)
                        for(x=0;x<width;++x)
			{
				BYTE byte;			
                                fread(&byte,1,1,f);				//just read byte
				for(int c=0;c<3;++c)
                                        obtenerPixel(x,y,c)=cols[byte*4+2-c];	//and look up in the table
			}
		break;

	case(4):
		fread(cols,16*4,1,f);
		fseek(f,offset,SEEK_SET);
		for(y=0;y<256;++y)
			for(x=0;x<256;x+=2)
			{
				BYTE byte;
                                fread(&byte,1,1,f);				  //as above, but need to exract two
                                for(c=0;c<3;++c)				  //obtenerPixels from each byte
                                        obtenerPixel(x,y,c)=cols[byte/16*4+2-c];
				for(c=0;c<3;++c)
                                        obtenerPixel(x+1,y,c)=cols[byte%16*4+2-c];
			}
		break;

	case(1):
		fread(cols,8,1,f);
		fseek(f,offset,SEEK_SET);
                for(y=0;y<height;++y)
                        for(x=0;x<width;x+=8)
			{
				BYTE byte;
				fread(&byte,1,1,f);
                                //Every byte is eight obtenerPixels
				//so I'm shifting the byte to the relevant position, then masking out
				//all but the lowest bit in order to get the index into the colourtable.
				for(int x2=0;x2<8;++x2)
					for(int c=0;c<3;++c)
                                                obtenerPixel(x+x2,y,c)=cols[((byte>>(7-x2))&1)*4+2-c];
			}
		break;

	default:
		fclose(f);
		return BMPUNKNOWNFORMAT;
	}

	if(ferror(f))
	{
		fclose(f);
		return BMPFILEERROR;
	}
        /* color
        color.r=colores.r;
        color.g=colores.g;
        color.b=colores.b;
        color.a=colores.a;
        */

        textura.resize(4);
        textura[0].x=1;//1
        textura[0].y=1;//1
        textura[1].x=0;//0;
        textura[1].y=1;//1
        textura[2].x=1;//1;
        textura[2].y=0;//0
        textura[3].x=0;//0;
        textura[3].y=0;//0;

        fclose(f);
	return BMPNOERROR;
}


#ifdef __gl_h
BMPError BMPClass::BMPLoadGL(std::string fname)
{
	BMPClass bmp;
	BMPError e=BMPLoad(fname,bmp);
	if(e!=BMPNOERROR) return e;
		
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,0,3,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,&pixel[0]);

	return BMPNOERROR;
}
#endif
