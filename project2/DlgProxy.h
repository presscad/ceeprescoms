
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class Cproject2Dlg;


// Cproject2DlgAutoProxy ����Ŀ��

class Cproject2DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(Cproject2DlgAutoProxy)

	Cproject2DlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	Cproject2Dlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~Cproject2DlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(Cproject2DlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

