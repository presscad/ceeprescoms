#pragma once


// second �Ի���

class second : public CDialogEx
{
	DECLARE_DYNAMIC(second)

public:
	second(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~second();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
