
// project2Dlg.h : ͷ�ļ�
//

#pragma once

class Cproject2DlgAutoProxy;


// Cproject2Dlg �Ի���
class Cproject2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Cproject2Dlg);
	friend class Cproject2DlgAutoProxy;

// ����
public:
	Cproject2Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~Cproject2Dlg();

// �Ի�������
	enum { IDD = IDD_PROJECT2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	Cproject2DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
