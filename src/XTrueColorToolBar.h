// XTrueColorToolBar.h  Version 1.0 - article available at www.codeproject.com
//
// Author:  Hans Dietrich
//          hdietrich@gmail.com
//
// License:
//     This software is released into the public domain.  You are free to use
//     it in any way you like, except that you may not sell this source code.
//
//     This software is provided "as is" with no expressed or implied warranty.
//     I accept no liability for any damage or loss of business that this 
//     software may cause.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef XTRUECOLORTOOLBAR_H
#define XTRUECOLORTOOLBAR_H

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' precompiled header before including this file
#endif

//=============================================================================
class CXTrueColorToolBar : public CToolBar
//=============================================================================
{
//=============================================================================
// Construction
//=============================================================================
public:
	CXTrueColorToolBar();

//=============================================================================
// Attributes
//=============================================================================
public:
	COLORREF	GetBackgroundColor()				{ return m_crBackgroundColor; }
	void		SetBackgroundColor(COLORREF rgb)	{ m_crBackgroundColor = rgb; }
	void		GetImageDimensions(int& nWidth, int& nHeight)
				{ nWidth = m_nImageWidth; nHeight = m_nImageHeight; }
	void		SetImageDimensions(int nWidth, int nHeight)
				{ m_nImageWidth = nWidth; m_nImageHeight = nHeight; }
	COLORREF	GetMaskColor()						{ return m_crMaskColor; }
	void		SetMaskColor(COLORREF rgb)			{ m_crMaskColor = rgb; }

//=============================================================================
// Operations
//=============================================================================
public:
	void AttachToolbarImages(UINT nBitmapId, int nNumImages, int nToolbar);	// 0 = normal, 1 = disabled, 2 = hot
	BOOL CreateTemplate(COLORREF rgb);
	COLORREF GetColorButton() { return m_crCurrentColor; }
	void SetColorButton(UINT nCommandId, COLORREF rgb);

//=============================================================================
// Implementation
//=============================================================================
protected:
	CImageList	m_TrueColorImages;		// toolbar image list
	CImageList	m_ImageTemplate;		// copy of initial toolbar image list 
	int			m_nNumImages;			// number of images in toolbar bitmap
	int			m_nImageWidth;			// width of a single image in toolbar bitmap
	int			m_nImageHeight;			// height of a single image in toolbar bitmap
	UINT		m_nToolBarBitDepth;		// currently must be ILC_COLOR24;
	COLORREF	m_crCurrentColor;		// current color of bar under "A" on color button
	COLORREF	m_crMaskColor;			// mask color of bar under "A" on color button
	COLORREF	m_crBackgroundColor;	// background color of buttons in 
										// toolbar resource

	BOOL GetBitmapFromImageList(CBitmap& bm, CImageList* pList);
	int GetImageIndex(UINT nCommandId);
	void MakeToolbarImageList(UINT inBitmapID, 
							 CImageList& outImageList);
	void ReplaceBackgroundColor(CBitmap& bm, COLORREF OldColor, COLORREF NewColor);
	void ReplaceMaskColor(CBitmap& bm1,			// toolbar images
						  CBitmap& bm2,			// image mask
						  COLORREF OldColor, 
						  COLORREF NewColor);
};

#endif //XTRUECOLORTOOLBAR_H
