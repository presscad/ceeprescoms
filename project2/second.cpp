// second.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "project2.h"
#include "second.h"
#include "afxdialogex.h"
#include "second_one.h"
#include "second_two.h"

// second �Ի���

IMPLEMENT_DYNAMIC(second, CDialogEx)

second::second(CWnd* pParent /*=NULL*/)
	: CDialogEx(second::IDD, pParent)
{

}

second::~second()
{
}

void second::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(second, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &second::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &second::OnBnClickedButton2)
END_MESSAGE_MAP()


// second ��Ϣ�������


void second::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	second_one p;
	p.DoModal();
}


void second::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	second_two p;
	p.DoModal();
}
