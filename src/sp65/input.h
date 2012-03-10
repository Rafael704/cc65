/*****************************************************************************/
/*                                                                           */
/*                                  input.h                                  */
/*                                                                           */
/*   Input format/file definitions for the sp65 sprite and bitmap utility    */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2012,      Ullrich von Bassewitz                                      */
/*                Roemerstrasse 52                                           */
/*                D-70794 Filderstadt                                        */
/* EMail:         uz@cc65.org                                                */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/



#ifndef INPUT_H
#define INPUT_H



/* sp65 */
#include "bitmap.h"



/*****************************************************************************/
/*                                   Data                                    */
/*****************************************************************************/



enum InputFormat {
    ifAuto      = -1,           /* Auto detect */
    ifPCX,                      /* PCX */

    ifCount                     /* Number of actual input formats w/o ifAuto*/
};
typedef enum InputFormat InputFormat;




/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/



int FindInputFormat (const char* Name);
/* Find an input format by name. The function returns a value less than zero
 * if Name is not a known input format.
 */

Bitmap* ReadInputFile (const char* Name, InputFormat Format);
/* Read a bitmap from a file and return it. If Format is ifAuto, the routine
 * tries to determine the format from the file name extension.
 */



/* End of input.h */

#endif


