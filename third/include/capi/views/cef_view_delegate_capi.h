// Copyright (c) 2018 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=832f4be1a42081813775621498c1f678d5eace28$
//

#ifndef CEF_INCLUDE_CAPI_VIEWS_CEF_VIEW_DELEGATE_CAPI_H_
#define CEF_INCLUDE_CAPI_VIEWS_CEF_VIEW_DELEGATE_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _cef_view_t;

///
// Implement this structure to handle view events. The functions of this
// structure will be called on the browser process UI thread unless otherwise
// indicated.
///
typedef struct _cef_view_delegate_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Return the preferred size_i32 for |view|. The Layout will use this information
  // to determine the display size.
  ///
  cef_size_t(CEF_CALLBACK* get_preferred_size)(
      struct _cef_view_delegate_t* self,
      struct _cef_view_t* view);

  ///
  // Return the minimum size_i32 for |view|.
  ///
  cef_size_t(CEF_CALLBACK* get_minimum_size)(struct _cef_view_delegate_t* self,
                                             struct _cef_view_t* view);

  ///
  // Return the maximum size_i32 for |view|.
  ///
  cef_size_t(CEF_CALLBACK* get_maximum_size)(struct _cef_view_delegate_t* self,
                                             struct _cef_view_t* view);

  ///
  // Return the height necessary to display |view| with the provided |width|. If
  // not specified the result of get_preferred_size().height will be used by
  // default. Override if |view|'s preferred height depends upon the width (for
  // example, with Labels).
  ///
  int(CEF_CALLBACK* get_height_for_width)(struct _cef_view_delegate_t* self,
                                          struct _cef_view_t* view,
                                          int width);

  ///
  // Called when the parent of |view| has changed. If |view| is being added to
  // |parent| then |added| will be true (1). If |view| is being removed from
  // |parent| then |added| will be false (0). If |view| is being reparented the
  // remove notification will be sent before the add notification. Do not modify
  // the view hierarchy in this callback.
  ///
  void(CEF_CALLBACK* on_parent_view_changed)(struct _cef_view_delegate_t* self,
                                             struct _cef_view_t* view,
                                             int added,
                                             struct _cef_view_t* parent);

  ///
  // Called when a child of |view| has changed. If |child| is being added to
  // |view| then |added| will be true (1). If |child| is being removed from
  // |view| then |added| will be false (0). If |child| is being reparented the
  // remove notification will be sent to the old parent before the add
  // notification is sent to the new parent. Do not modify the view hierarchy in
  // this callback.
  ///
  void(CEF_CALLBACK* on_child_view_changed)(struct _cef_view_delegate_t* self,
                                            struct _cef_view_t* view,
                                            int added,
                                            struct _cef_view_t* child);

  ///
  // Called when |view| gains focus.
  ///
  void(CEF_CALLBACK* on_focus)(struct _cef_view_delegate_t* self,
                               struct _cef_view_t* view);

  ///
  // Called when |view| loses focus.
  ///
  void(CEF_CALLBACK* on_blur)(struct _cef_view_delegate_t* self,
                              struct _cef_view_t* view);
} cef_view_delegate_t;

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_VIEWS_CEF_VIEW_DELEGATE_CAPI_H_
