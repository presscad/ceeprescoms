#pragma once


// four �Ի���

class four : public CDialogEx
{
	DECLARE_DYNAMIC(four)

public:
	four(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~four();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_seek1;
	CString m_value2;
};
