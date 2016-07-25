// cntritem.h : interface of the CWordPadCntrItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1998 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
#pragma once

#include <afxdocob.h>


class CDocObject : public CDocObjectServer
{
public:
	CDocObject(COleServerDoc* pOwner,
		LPOLEDOCUMENTSITE pDocSite = NULL);
	~CDocObject();
};

/////////////////////////////////////////////////////////////////////////////
