/*****************************************************************************/
/*                                                                           */
/*                                 declare.h                                 */
/*                                                                           */
/*                 Parse variable and function declarations                  */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2009, Ullrich von Bassewitz                                      */
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



#ifndef DECLARE_H
#define DECLARE_H



/* common */
#include "coll.h"

/* cc65 */
#include "scanner.h"
#include "symtab.h"



/*****************************************************************************/
/*                                   Data                                    */
/*****************************************************************************/



/* Type specifier parser flags */
typedef enum typespec_t typespec_t;
enum typespec_t {
    TS_NONE                 = 0x00,

    /* Default type */
    TS_MASK_DEFAULT_TYPE    = 0x03,
    TS_DEFAULT_TYPE_NONE    = 0x00,     /* No default type */
    TS_DEFAULT_TYPE_INT     = 0x01,     /* Good old int */
    TS_DEFAULT_TYPE_AUTO    = 0x02,     /* C23 type inference with auto */

    /* Whether to allow certain kinds of specifiers */
    TS_STORAGE_CLASS_SPEC   = 0x04,    /* Allow storage storage class specifiers */
    TS_FUNCTION_SPEC        = 0x08,    /* Allow function specifiers */
};

/* Masks for the Flags field in DeclSpec */
#define DS_DEF_STORAGE          0x0001U /* Default storage class used   */
#define DS_NO_TYPE              0x0002U /* No type explicitly specified */
#define DS_DEF_TYPE             0x0006U /* Default type used            */
#define DS_EXTRA_TYPE           0x0008U /* Extra type declared          */
#define DS_NEW_TYPE_DECL        0x0010U /* New type declared            */
#define DS_NEW_TYPE_DEF         0x0020U /* New type defined             */
#define DS_NEW_TYPE             (DS_NEW_TYPE_DECL | DS_NEW_TYPE_DEF)

/* Result of ParseDeclSpec */
typedef struct DeclSpec DeclSpec;
struct DeclSpec {
    unsigned    StorageClass;           /* One of the SC_xxx flags      */
    Type        Type[MAXTYPELEN];       /* Type of the declaration spec */
    unsigned    Flags;                  /* Bitmapped flags              */
};

/* Result of ParseDecl */
typedef struct Declarator Declarator;
struct Declarator {
    unsigned    StorageClass;           /* A set of SC_xxx flags */
    Type        Type[MAXTYPELEN];       /* The type */
    ident       Ident;                  /* The identifier, if any*/
    Collection* Attributes;             /* Attributes if any */

    /* Working variables */
    unsigned    Index;              /* Used to build Type */
};

/* Modes for ParseDecl */
typedef enum {
    DM_NEED_IDENT,                      /* We must have an identifier */
    DM_NO_IDENT,                        /* We won't read an identifier */
    DM_ACCEPT_IDENT,                    /* We will accept an id if there is one */
} declmode_t;



/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/



void InitDeclSpec (DeclSpec* D);
/* Initialize the DeclSpec struct for use */

Type* ParseType (Type* Type);
/* Parse a complete type specification */

void ParseDecl (const DeclSpec* Spec, Declarator* D, declmode_t Mode);
/* Parse a variable, type or function declarator */

void ParseDeclSpec (DeclSpec* D, typespec_t TSFlags, unsigned DefStorage);
/* Parse a declaration specification */

void CheckEmptyDecl (const DeclSpec* D);
/* Called after an empty type declaration (that is, a type declaration without
** a variable). Checks if the declaration does really make sense and issues a
** warning if not.
*/



/* End of declare.h */

#endif
