/*******************************************************************************
 *  Project: libopencad
 *  Purpose: OpenSource CAD formats support library
 *  Author: Alexandr Borzykh, mush3d at gmail.com
 *  Author: Dmitry Baryshnikov, bishop.dev@gmail.com
 *  Language: C++
 *******************************************************************************
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2016 Alexandr Borzykh
 *  Copyright (c) 2016 NextGIS, <info@nextgis.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *******************************************************************************/

#ifndef OPENCAD_API_H
#define OPENCAD_API_H

#include "cadfile.h"

enum CADVersions
{
    DWG_R13 = 1012,
    DWG_R14 = 1014,
    DWG_R2000 = 1015,
    DWG_R2004 = 1018,
    DWG_R2007 = 1021,
    DWG_R2010 = 1024,
    DWG_R2013 = 1027,
    DXF_UNDEF = -1000,
    DXF_R13 = -DWG_R13,
    DXF_R14 = -DWG_R14,
    DXF_R2000 = -DWG_R2000,
    DXF_R2004 = -DWG_R2004,
    DXF_R2007 = -DWG_R2007,
    DXF_R2010 = -DWG_R2010,
    DXF_R2013 = -DWG_R2013
};

enum CADErrorCodes
{
    SUCCESS = 0,                    /**< operation successfully executed */
    FILE_OPEN_FAILED,               /**< failed to open CAD file */
    UNSUPPORTED_VERSION,            /**< unsupported CAD file version */
    FILE_PARSE_FAILED,              /**< failed to parse file */
    HEADER_SECTION_READ_FAILED,     /**< failed to read header section */
    CLASSES_SECTION_READ_FAILED,    /**< failed to read classes section */
    TABLES_SECTION_READ_FAILED,     /**< failed to read tables section */
    BLOCKS_SECTION_READ_FAILED,     /**< failed to read blocks section */
    ENTITIES_SECTION_READ_FAILED,   /**< failed to read entities section */
    OBJECTS_SECTION_READ_FAILED,    /**< failed to read objects section */
    THUMBNAILIMAGE_SECTION_READ_FAILED,   /**< failed to read thumbnailimage section */
    APPID_TABLE_READ_FAILED,        /**< failed to read appid table*/
    BLOCK_RECORD_TABLE_READ_FAILED, /**< failed to read block record table*/
    DIMSTYLE_TABLE_READ_FAILED,     /**< failed to read dimstyle table*/
    LAYER_TABLE_READ_FAILED,        /**< failed to read layer table*/
    LTYPE_TABLE_READ_FAILED,        /**< failed to read ltype table*/
    STYLE_TABLE_READ_FAILED,        /**< failed to read style table*/
    UCS_TABLE_READ_FAILED,          /**< failed to read ucs table*/
    VIEW_TABLE_READ_FAILED,         /**< failed to read view table*/
    VPORT_TABLE_READ_FAILED,        /**< failed to read vport table*/
    VALUE_EXISTS                    /**< the value already exist in the header */
};

OCAD_EXTERN int GetVersion();
OCAD_EXTERN const char* GetVersionString();
OCAD_EXTERN CADFile* OpenCADFile( CADFileIO* pCADFileIO );
OCAD_EXTERN CADFile* OpenCADFile( const char* pszFileName );
OCAD_EXTERN int GetLastErrorCode();
OCAD_EXTERN CADFileIO* GetDeafultFileIO(const char* pszFileName);
OCAD_EXTERN int IdentifyCADFile( CADFileIO* pCADFileIO );
OCAD_EXTERN const char* GetCADFormats();

#endif // OPENCAD_API_H