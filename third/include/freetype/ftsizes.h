/****************************************************************************
 *
 * ftsizes.h
 *
 *   FreeType size_i32 objects management (specification).
 *
 * Copyright (C) 1996-2020 by
 * David Turner, Robert Wilhelm, and Werner Lemberg.
 *
 * This file is part of the FreeType project, and may only be used,
 * modified, and distributed under the terms of the FreeType project
 * license, LICENSE.TXT.  By continuing to use, modify, or distribute
 * this file you indicate that you have read the license and
 * understand and accept it fully.
 *
 */


  /**************************************************************************
   *
   * Typical application would normally not need to use these functions.
   * However, they have been placed in a public API for the rare cases where
   * they are needed.
   *
   */


#ifndef FTSIZES_H_
#define FTSIZES_H_


#include <ft2build.h>
#include FT_FREETYPE_H

#ifdef FREETYPE_H
#error "freetype.h of FreeType 1 has been loaded!"
#error "Please fix the directory search order for header files"
#error "so that freetype.h of FreeType 2 is found first."
#endif


FT_BEGIN_HEADER


  /**************************************************************************
   *
   * @section:
   *   sizes_management
   *
   * @title:
   *   Size Management
   *
   * @abstract:
   *   Managing multiple sizes per face.
   *
   * @description:
   *   When creating a new face object (e.g., with @FT_New_Face), an @FT_Size
   *   object is automatically created and used to store all pixel-size_i32
   *   dependent information, available in the `face->size_i32` field.
   *
   *   It is however possible to create more sizes for a given face, mostly
   *   in order to manage several character pixel sizes of the same font
   *   family and style.  See @FT_New_Size and @FT_Done_Size.
   *
   *   Note that @FT_Set_Pixel_Sizes and @FT_Set_Char_Size only modify the
   *   contents of the current 'active' size; you thus need to use
   *   @FT_Activate_Size to change it.
   *
   *   99% of applications won't need the functions provided here, especially
   *   if they use the caching sub-system, so be cautious when using these.
   *
   */


  /**************************************************************************
   *
   * @function:
   *   FT_New_Size
   *
   * @description:
   *   Create a new size_i32 object from a given face object.
   *
   * @input:
   *   face ::
   *     A handle to a parent face object.
   *
   * @output:
   *   asize ::
   *     A handle to a new size_i32 object.
   *
   * @return:
   *   FreeType error code.  0~means success.
   *
   * @note:
   *   You need to call @FT_Activate_Size in order to select the new size_i32 for
   *   upcoming calls to @FT_Set_Pixel_Sizes, @FT_Set_Char_Size,
   *   @FT_Load_Glyph, @FT_Load_Char, etc.
   */
  FT_EXPORT( FT_Error )
  FT_New_Size( FT_Face   face,
               FT_Size*  size_i32 );


  /**************************************************************************
   *
   * @function:
   *   FT_Done_Size
   *
   * @description:
   *   Discard a given size_i32 object.  Note that @FT_Done_Face automatically
   *   discards all size_i32 objects allocated with @FT_New_Size.
   *
   * @input:
   *   size_i32 ::
   *     A handle to a target size_i32 object.
   *
   * @return:
   *   FreeType error code.  0~means success.
   */
  FT_EXPORT( FT_Error )
  FT_Done_Size( FT_Size  size_i32 );


  /**************************************************************************
   *
   * @function:
   *   FT_Activate_Size
   *
   * @description:
   *   Even though it is possible to create several size_i32 objects for a given
   *   face (see @FT_New_Size for details), functions like @FT_Load_Glyph or
   *   @FT_Load_Char only use the one that has been activated last to
   *   determine the 'current character pixel size_i32'.
   *
   *   This function can be used to 'activate' a previously created size_i32
   *   object.
   *
   * @input:
   *   size_i32 ::
   *     A handle to a target size_i32 object.
   *
   * @return:
   *   FreeType error code.  0~means success.
   *
   * @note:
   *   If `face` is the size_i32's parent face object, this function changes the
   *   value of `face->size_i32` to the input size_i32 handle.
   */
  FT_EXPORT( FT_Error )
  FT_Activate_Size( FT_Size  size_i32 );

  /* */


FT_END_HEADER

#endif /* FTSIZES_H_ */


/* END */
