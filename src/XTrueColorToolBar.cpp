// XTrueColorToolBar.cpp  Version 1.0 - article available at www.codeproject.com
//
// Author:  Hans Dietrich
//          hdietrich@gmail.com
//
// Description:
//     XTrueColorToolBar is an MFC class derived from CToolBar that provides 
//     support for true-color bitmaps, with optional support for an 
//     Office-style color picker button.  It is based on Peter Lee's
//     article "Full-Featured 24-bit Color Toolbar", which you can find
//     at http://www.codeguru.com/Cpp/controls/toolbar/article.php/c2537.
//
// History
//     Version 1.0 - 2007 December 17
//     - Initial public release
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

#include "stdafx.h"
#include "XTrueColorToolBar.h"

#pragma warning(disable : 4996)	// disable bogus deprecation warning


//=============================================================================
CXTrueColorToolBar::CXTrueColorToolBar()
//=============================================================================
{
	m_nNumImages        = 0;
	m_nImageWidth       = 16;
	m_nImageHeight      = 16;
	m_nToolBarBitDepth  = ILC_COLOR24;
	m_crCurrentColor    = RGB(0,0,0);
	m_crMaskColor       = RGB(0,0,1);
	m_crBackgroundColor = RGB(192,192,192);
}

//=============================================================================
// Create copy of toolbar image list
BOOL CXTrueColorToolBar::CreateTemplate(COLORREF rgb)
//=============================================================================
{
	BOOL rc = FALSE;

	SetMaskColor(rgb);

	if (m_ImageTemplate.GetSafeHandle() != NULL)
		m_ImageTemplate.DeleteImageList();

	CToolBarCtrl& ctrl = GetToolBarCtrl();
	CImageList *pList = ctrl.GetImageList();

	if (pList)
	{
		// create copy of toolbar image list
		rc =  m_ImageTemplate.Create(pList);

		if (!rc)
		{
			TRACE(_T("ERROR - failed to create image template\n"));
			ASSERT(FALSE);
		}
	}
	else
	{
		TRACE(_T("ERROR - failed to get toolbar image list\n"));
		ASSERT(pList);
	}

	return rc;
}

//=============================================================================
// Find every pixel of the default background color in the specified
// bitmap and set each one to the user's button color.
void CXTrueColorToolBar::ReplaceBackgroundColor(CBitmap& bm, 
												COLORREF OldColor, 
												COLORREF NewColor)
//=============================================================================
{
	// figure out how many pixels there are in the bitmap
	BITMAP bmInfo;
	VERIFY(bm.GetBitmap(&bmInfo));
	
	// add support for additional bit depths here if you choose
	VERIFY(bmInfo.bmBitsPixel == 24);
	VERIFY(bmInfo.bmWidthBytes == (bmInfo.bmWidth * 3));

	UINT nPixels = bmInfo.bmHeight * bmInfo.bmWidth;

	// get a pointer to the pixels
    DIBSECTION ds;

    VERIFY(bm.GetObject(sizeof(DIBSECTION), &ds) == sizeof(DIBSECTION));

	RGBTRIPLE *pixels = reinterpret_cast<RGBTRIPLE*>(ds.dsBm.bmBits);
	VERIFY(pixels);

	RGBTRIPLE NewBackgroundColor = {
		GetBValue(NewColor), GetGValue(NewColor), GetRValue(NewColor) };

	RGBTRIPLE OldBackgroundColor = {
		GetBValue(OldColor), GetGValue(OldColor), GetRValue(OldColor) };

	// search through the pixels, substituting the new background
	// color for any pixel that has the old background color

	int nCount = 0;
	for (UINT i = 0; i < nPixels; ++i)
	{
		if (pixels[i].rgbtBlue  == OldBackgroundColor.rgbtBlue &&
			pixels[i].rgbtGreen == OldBackgroundColor.rgbtGreen &&
			pixels[i].rgbtRed   == OldBackgroundColor.rgbtRed)
		{
			pixels[i] = NewBackgroundColor;
			nCount++;
		}
	}
	TRACE(_T("ReplaceColor: replaced %d pixels\n"), nCount);
}

//=============================================================================
// Find every pixel set to old color in mask bitmap and set corresponding
// pixel in toolbar bitmap to new color.
void CXTrueColorToolBar::ReplaceMaskColor(CBitmap& bm1,		// toolbar bitmap
										  CBitmap& bm2,		// mask bitmap
										  COLORREF OldColor, 
										  COLORREF NewColor)
//=============================================================================
{
	// figure out how many pixels there are in the bitmap
	BITMAP bmInfo1, bmInfo2;
	VERIFY(bm1.GetBitmap(&bmInfo1));
	VERIFY(bm2.GetBitmap(&bmInfo2));
	
	// add support for additional bit depths here if you choose
	VERIFY(bmInfo1.bmBitsPixel == 24);
	VERIFY(bmInfo1.bmWidthBytes == (bmInfo1.bmWidth * 3));
	VERIFY(bmInfo2.bmBitsPixel == 24);
	VERIFY(bmInfo2.bmWidthBytes == (bmInfo2.bmWidth * 3));

	UINT nPixels1 = bmInfo1.bmHeight * bmInfo1.bmWidth;
	UINT nPixels2 = bmInfo2.bmHeight * bmInfo2.bmWidth;
	//TRACE(_T("bmInfo1.bmHeight=%d  bmInfo1.bmWidth=%d\n"), bmInfo1.bmHeight, bmInfo1.bmWidth);
	//TRACE(_T("bmInfo2.bmHeight=%d  bmInfo2.bmWidth=%d\n"), bmInfo2.bmHeight, bmInfo2.bmWidth);
	//TRACE(_T("nPixels1=%d  nPixels2=%d\n"), nPixels1, nPixels2);
	ASSERT(nPixels1 == nPixels2);

	// get a pointer to the pixels
    DIBSECTION ds1, ds2;

    VERIFY(bm1.GetObject(sizeof(DIBSECTION), &ds1) == sizeof(DIBSECTION));
    VERIFY(bm2.GetObject(sizeof(DIBSECTION), &ds2) == sizeof(DIBSECTION));

	RGBTRIPLE *pixels1 = reinterpret_cast<RGBTRIPLE*>(ds1.dsBm.bmBits);
	VERIFY(pixels1 != NULL);
	RGBTRIPLE *pixels2 = reinterpret_cast<RGBTRIPLE*>(ds2.dsBm.bmBits);
	VERIFY(pixels2 != NULL);

	RGBTRIPLE NewMaskColor = {
		GetBValue(NewColor), GetGValue(NewColor), GetRValue(NewColor) };

	RGBTRIPLE OldMaskColor = {
		GetBValue(OldColor), GetGValue(OldColor), GetRValue(OldColor) };

	// search through the pixels, substituting the new mask
	// color for any pixel that has the old mask color

	int nCount = 0;
	for (UINT i = 0; i < nPixels1; ++i)
	{
		if (pixels2[i].rgbtBlue  == OldMaskColor.rgbtBlue &&
			pixels2[i].rgbtGreen == OldMaskColor.rgbtGreen &&
			pixels2[i].rgbtRed   == OldMaskColor.rgbtRed)
		{
			pixels1[i] = NewMaskColor;
			nCount++;
		}
	}
	TRACE(_T("ReplaceMaskColor: replaced %d pixels\n"), nCount);
}

//=============================================================================
// create an image list for the specified BMP resource
void CXTrueColorToolBar::MakeToolbarImageList(UINT inBitmapID, 
											  CImageList& outImageList)
//=============================================================================
{
	CBitmap bm;

	// If we use CBitmap::LoadBitmap() to load the bitmap, the colors
	// will be reduced to the bit depth of the main screen and we won't
	// be able to access the pixels directly. To avoid those problems,
	// we'll load the bitmap as a DIBSection instead and attach the
	// DIBSection to the CBitmap.
	VERIFY(bm.Attach(::LoadImage(
		::AfxFindResourceHandle(MAKEINTRESOURCE(inBitmapID), RT_BITMAP),
								MAKEINTRESOURCE(inBitmapID), IMAGE_BITMAP, 0, 0,
								(LR_DEFAULTSIZE | LR_CREATEDIBSECTION))));

	// replace the background color in the toolbar bitmap with the 
	// current system toolbar background color
	ReplaceBackgroundColor(bm, m_crBackgroundColor, GetSysColor(COLOR_BTNFACE));

	// create a 24 bit image list with the same dimensions and number
	// of buttons as the toolbar
	VERIFY(outImageList.Create(m_nImageWidth, 
							   m_nImageHeight, 
							   m_nToolBarBitDepth, 
							   m_nNumImages, 
							   0));

	// attach the bitmap to the image list
	VERIFY(outImageList.Add(&bm, RGB(0,0,0)) != -1);
}

//=============================================================================
// load the high color toolbar images and attach them to toolbar
void CXTrueColorToolBar::AttachToolbarImages(UINT nBitmapId,
											 int nNumImages,
											 int nToolbar)	// 0 = normal, 1 = disabled, 2 = hot
//=============================================================================
{
	ASSERT(nNumImages > 0);

	m_nNumImages = nNumImages;

	if (m_TrueColorImages.GetSafeHandle())
		m_TrueColorImages.DeleteImageList();

	// make true-color image list for the bitmap
	MakeToolbarImageList(nBitmapId, m_TrueColorImages);
	ASSERT(m_TrueColorImages.GetSafeHandle());

	// get the toolbar control associated with the CToolbar object
	CToolBarCtrl& ctrl = GetToolBarCtrl();

	// attach the image list to the toolbar control
	switch (nToolbar)
	{
		default:
		case 0:
			ctrl.SetImageList(&m_TrueColorImages);
			break;
		case 1:
			ctrl.SetDisabledImageList(&m_TrueColorImages);
			break;
		case 2:
			ctrl.SetHotImageList(&m_TrueColorImages);
			break;
	}
}

//=============================================================================
// Get image list index from command ID
int CXTrueColorToolBar::GetImageIndex(UINT nCommandId)
//=============================================================================
{
	CToolBarCtrl& ctrl = GetToolBarCtrl();

	int nButtonIndex = ctrl.CommandToIndex(nCommandId);

	UINT nID = 0;
	UINT nStyle = 0;
	int iImage = 0;
	GetButtonInfo(nButtonIndex, nID, nStyle, iImage);

	return iImage;
}

//=============================================================================
// Get bitmap from image list
BOOL CXTrueColorToolBar::GetBitmapFromImageList(CBitmap& bm, CImageList* pList)
//=============================================================================
{
	BOOL rc = FALSE;

	ASSERT(pList && pList->GetSafeHandle());

	if (pList && pList->GetSafeHandle())
	{
		IMAGEINFO ImageInfo;
		rc = pList->GetImageInfo(0, &ImageInfo);

		if (rc)
		{
			rc = bm.Attach(ImageInfo.hbmImage);

			if (!rc)
			{
				TRACE(_T("ERROR - Attach failed\n"));
				ASSERT(FALSE);
			}
		}
		else
		{
			TRACE(_T("ERROR - GetImageInfo failed\n"));
			ASSERT(FALSE);
		}
	}

	return rc;
}

//=============================================================================
// Set color of color button 
void CXTrueColorToolBar::SetColorButton(UINT nCommandId, COLORREF rgb)
//=============================================================================
{
	CToolBarCtrl& ctrl = GetToolBarCtrl();
	CImageList *pList = ctrl.GetImageList();

	if (pList && pList->GetSafeHandle())
	{
		CBitmap bmTemplate;
		VERIFY(GetBitmapFromImageList(bmTemplate, &m_ImageTemplate));

		int iImage = GetImageIndex(nCommandId);

		// restore original toolbar image from saved image template
		VERIFY(pList->Replace(iImage, &bmTemplate, NULL));

		CBitmap bmToolbar;
		VERIFY(GetBitmapFromImageList(bmToolbar, pList));

		// replace mask color in toolbar image list with new color
		ReplaceMaskColor(bmToolbar, bmTemplate, m_crMaskColor, rgb);

		m_crCurrentColor = rgb;

		RedrawWindow();
	}
}
