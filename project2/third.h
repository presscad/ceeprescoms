#pragma once


// third �Ի���

class third : public CDialogEx
{
	DECLARE_DYNAMIC(third)

public:
	third(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~third();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_value;
};
