#pragma once


// first �Ի���

class first : public CDialogEx
{
	DECLARE_DYNAMIC(first)

public:
	first(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~first();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_value10;
	afx_msg void OnBnClickedButton2();
};
