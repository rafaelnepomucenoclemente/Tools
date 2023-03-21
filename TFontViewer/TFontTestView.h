#pragma once

class CTFontTestView :	public CScrollView
{
	DECLARE_DYNCREATE(CTFontTestView)

protected:
	CTFontTestView();
	virtual ~CTFontTestView();

public:
	LOGFONT m_lf;
	CGDIFont* m_pGDIFont;
	CD3DFont  m_Font;
	CD3DImage m_Img;

	CString m_strText;
	CRect m_rtPos;

public:
	virtual void OnInitialUpdate();     // ������ �� ó���Դϴ�.
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

public:
	void		Render();
	void		DrawContent();

	void		SetFont( LOGFONT* of, BOOL bOutline, BOOL bShadow, DWORD dwColor, INT nFontRender, CRect rt );
	void		SetText( CString str );

	void		LoadImage( CString str );

protected:
	DECLARE_MESSAGE_MAP()
};
