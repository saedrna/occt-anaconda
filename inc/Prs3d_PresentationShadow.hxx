// Created on: 2014-03-12
// Created by: Kirill GAVRILOV
// Copyright (c) 2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#ifndef _Prs3d_PresentationShadow_HeaderFile
#define _Prs3d_PresentationShadow_HeaderFile

#include <Prs3d_Presentation.hxx>

//! Defines a "shadow" of existing presentation object with custom aspects.
class Prs3d_PresentationShadow : public Prs3d_Presentation
{

public:

  //! Constructs a shadow of existing presentation object.
  Standard_EXPORT Prs3d_PresentationShadow (const Handle(Graphic3d_StructureManager)& theViewer,
                                            const Handle(Prs3d_Presentation)&         thePrs);

  //! Returns the id of the parent presentation
  inline Standard_Integer ParentId() const { return myParentStructId; }

  //! Returns view affinity of the parent presentation
  inline const Handle(Graphic3d_ViewAffinity)& ParentAffinity() const { return myParentAffinity; }

  //! Do nothing - axis-aligned bounding box should be initialized from parent structure.
  Standard_EXPORT virtual void CalculateBoundBox() Standard_OVERRIDE;

private: 

  DEFINE_STANDARD_RTTIEXT(Prs3d_PresentationShadow,Prs3d_Presentation)

private:
  Standard_Integer               myParentStructId;
  Handle(Graphic3d_ViewAffinity) myParentAffinity;

};

DEFINE_STANDARD_HANDLE(Prs3d_PresentationShadow, Prs3d_Presentation)

#endif // _Prs3d_PresentationShadow_HeaderFile
