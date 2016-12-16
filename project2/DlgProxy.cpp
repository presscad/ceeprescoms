
// DlgProxy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "project2.h"
#include "DlgProxy.h"
#include "project2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cproject2DlgAutoProxy

IMPLEMENT_DYNCREATE(Cproject2DlgAutoProxy, CCmdTarget)

Cproject2DlgAutoProxy::Cproject2DlgAutoProxy()
{
	EnableAutomation();
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ������ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(Cproject2Dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(Cproject2Dlg)))
		{
			m_pDialog = reinterpret_cast<Cproject2Dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

Cproject2DlgAutoProxy::~Cproject2DlgAutoProxy()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void Cproject2DlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(Cproject2DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Cproject2DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_Iproject2 ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {138BD86D-7208-4D55-92AF-7D388F8DB8CC}
static const IID IID_Iproject2 =
{ 0x138BD86D, 0x7208, 0x4D55, { 0x92, 0xAF, 0x7D, 0x38, 0x8F, 0x8D, 0xB8, 0xCC } };

BEGIN_INTERFACE_MAP(Cproject2DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(Cproject2DlgAutoProxy, IID_Iproject2, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {4E19AEBB-D321-4A0B-B5B7-B9BE7E723ED4}
IMPLEMENT_OLECREATE2(Cproject2DlgAutoProxy, "project2.Application", 0x4e19aebb, 0xd321, 0x4a0b, 0xb5, 0xb7, 0xb9, 0xbe, 0x7e, 0x72, 0x3e, 0xd4)


// Cproject2DlgAutoProxy ��Ϣ�������
