#pragma once


// second_one �Ի���

class second_one : public CDialogEx
{
	DECLARE_DYNAMIC(second_one)

public:
	second_one(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~second_one();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_stu;
};
