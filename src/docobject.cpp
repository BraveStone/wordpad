

#include "stdafx.h"

#include "docobject.h"

CDocObject::CDocObject(COleServerDoc* pOwner,
		   LPOLEDOCUMENTSITE pDocSite/* = NULL*/)
		   :CDocObjectServer(pOwner, pDocSite)
{

}

CDocObject::~CDocObject()
{

}

/////////////////////////////////////////////////////////////////////////////
