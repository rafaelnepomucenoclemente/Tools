// TFontViewerDoc.h : CTFontViewerDoc Ŭ������ �������̽�
//


#pragma once

class CTFontViewerDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CTFontViewerDoc();
	DECLARE_DYNCREATE(CTFontViewerDoc)

// Ư��
public:

// �۾�
public:

// ������
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ����
public:
	virtual ~CTFontViewerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �޽��� �� �Լ��� �����߽��ϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};


