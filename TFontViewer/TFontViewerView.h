// TFontViewerView.h : iCTFontViewerView Ŭ������ �������̽�
//


#pragma once


class CTFontViewerView : public CView
{
protected: // serialization������ ��������ϴ�.
	CTFontViewerView();
	DECLARE_DYNCREATE(CTFontViewerView)

// Ư��
public:
	CTFontViewerDoc* GetDocument() const;

// �۾�
public:

// ������
	public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����
public:
	virtual ~CTFontViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // TFontViewerView.cpp�� ����� ����
inline CTFontViewerDoc* CTFontViewerView::GetDocument() const
   { return reinterpret_cast<CTFontViewerDoc*>(m_pDocument); }
#endif

