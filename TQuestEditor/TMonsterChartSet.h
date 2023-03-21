// TMonsterChartSet.h : CTMonsterChartSet�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2008�� 1�� 16�� ������, ���� 5:33

class CTMonsterChartSet : public CRecordset
{
public:
	CTMonsterChartSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTMonsterChartSet)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA: ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.
// ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	int	m_wID;
	CStringA	m_szName;
	BYTE	m_bRace;
	BYTE	m_bClass;
	int	m_wKind;
	BYTE	m_bLevel;
	BYTE	m_bAIType;
	BYTE	m_bRange;
	int	m_wChaseRange;
	BYTE	m_bRoamProb;
	BYTE	m_bMoneyProb;
	long	m_dwMinMoney;
	long	m_dwMaxMoney;
	BYTE	m_bItemProb;
	BYTE	m_bDropCount;
	int	m_wExp;
	BYTE	m_bIsSelf;
	BYTE	m_bRecallType;
	BYTE	m_bCanSelect;
	BYTE	m_bCanAttack;
	BYTE	m_bTame;
	BYTE	m_bCall;
	BYTE	m_bIsSpecial;
	BYTE	m_bRemove;
	int	m_wMonAttr;
	int	m_wSummonAttr;
	int	m_wTransSkillID;
	float	m_fSize;
	int	m_wSkill1;
	int	m_wSkill2;
	int	m_wSkill3;
	int	m_wSkill4;

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


