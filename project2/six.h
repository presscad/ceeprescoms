#pragma once


// six �Ի���

class six : public CDialogEx
{
	DECLARE_DYNAMIC(six)

public:
	six(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~six();

// �Ի�������
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_seek_six;
	CString m_value_six;
	afx_msg void OnBnClickedButton1();
};
