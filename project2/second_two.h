#pragma once


// second_two �Ի���

class second_two : public CDialogEx
{
	DECLARE_DYNAMIC(second_two)

public:
	second_two(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~second_two();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_seek;
	CString m_seek2;
};
