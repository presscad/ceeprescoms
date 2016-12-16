// first.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "project2.h"
#include "first.h"
#include "afxdialogex.h"

#include <iostream>
#include <stdio.h>
#include<fstream>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h> 
#include <cstdlib> 
#include <string>
#include <math.h>
using namespace std;

#define CLRSCR	system("cls")
#define PRINT_TITLE "\n���\t����\t\t����\t����\t��ѧ\tӢ��\t�ܷ�\n"
#define PRINT_FORMAT "%d\t%s\t%s\t%d\t%d\t%d\t%d\n",i,p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define WRITE_FORMAT "%s\t%s\t%d\t%d\t%d\t%d\n",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define READ_FORMAT "%s %s %d %d %d %d",&p->stu.num,&p->stu.name,&p->stu.Chinese,&p->stu.math,&p->stu.English,&p->stu.count_score
// first �Ի���

IMPLEMENT_DYNAMIC(first, CDialogEx)

first::first(CWnd* pParent /*=NULL*/)
	: CDialogEx(first::IDD, pParent)
	, m_value10(_T(""))
{

}

first::~first()
{
}

void first::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_value10);
}


BEGIN_MESSAGE_MAP(first, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &first::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &first::OnBnClickedButton2)
END_MESSAGE_MAP()


// first ��Ϣ�������
//����ѧ����
class student_bx
{	
public:
	char	num[40];
	char    name[20];//�������ֳ���Ϊ6���ֽڣ�Ӧ�ඨ��һ���ֽ�������ַ���������'\0'
	int	Chinese;
	int	math;
	int	English;
	int	count_score;
};

//���嵥������
class node	 
{	
public:
	 student_bx stu;
	 node *next;
};

int MySelect(node * head,node *temp)   
{	
	int  i=0; 
	node *p,*tp=temp;
	p=head->next;
	FILE *fp;
	char file[15]="f:\\English.txt";
	if((fp=fopen(file,"w+"))==NULL)
	{
		printf("\n\t�ļ�����ʧ��\n");

		exit(0);
	}


	while (NULL!=p)
	{
		if(p->stu.English>100&&p->stu.count_score>300)
		{
			node *end;
			end = (node *)malloc(sizeof(node));
			tp->next=end;
			tp=end;
			tp->next=NULL;
			tp->stu=p->stu;
		
			if(i==0)
				printf (PRINT_TITLE);
			i++;
			printf(PRINT_FORMAT);
			if(p->next==NULL)//��Ҫ���һ�еĻس��������Ļ�������ļ�ʱ�Ͳ�����ĩβ������
				fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
			else
				fprintf(fp,WRITE_FORMAT);				

		}
		p=p->next;
	}
	fclose(fp);	
	if(i==0)
		printf("\n\tӢ�ﳬ��100�����ֳܷɼ�����300�ֵ�ѧ������Ϊ��\n");
	return i;
}



void Fprintf(node *head)
{
	char file[40]={"f:\\boxiang_stu.txt"};
	FILE *fp;
	if((fp=fopen(file,"w"))==NULL)
	{
		printf("\n\t�ļ���ʧ�ܣ���������˳�\n");
		getch();
		exit(0);
	}
	
	node *p=head->next;
	while(NULL!=p)
	{	
		if(p->next==NULL)//��Ҫ���һ�еĻس��������Ļ�������ļ�ʱ�Ͳ�����ĩβ������
			fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
		else
			fprintf(fp,WRITE_FORMAT);
		p=p->next;
	}		
		fclose(fp);
}
void InsertSort(node *head)//�ִܷӴ�С����
{ 
	node *p,*q,*u,*h,*w,*n;
	int j=0;
    p=head->next;
    while(p!=NULL)
    {
		j++;
		p=p->next;
	}
	for(int i=0;i<j-1;i++)
	{
		p=head;
		q=p->next;
		for(int z=0;z<=j-2-i;z++)
		{
			int y=0;
			if((q->next->stu.count_score)>(p->next->stu.count_score))
			{
				n=q->next;
				u=n->next;
				w=p->next;
				p->next=n;
				n->next=w;
				q->next=u;
				p=p->next;
				y=1;
			}
			if(y==0)
			{
			p=p->next;
			q=q->next;		
			}
		}
	}
}


void FscanfFromFile(node *head)//cdsgfdgfhhhhhhhhhhhhhhhhhhhhhhh
{	
	char file[20]="f:\\student1.txt";
	char file2[20]="f:\\student2.txt";
	FILE *fp,*fp2;
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("\n\t�ļ���ʧ�ܣ���������˳�\n");
		getch();
		exit(0);
	}
	
	if((fp2=fopen(file2,"r"))==NULL)
	{
		printf("\n\t�ļ���ʧ�ܣ���������˳�\n");
		getch();
		exit(0);
	}

	node *p=head;
	while(!feof(fp))
	{	
		node *end; 	
		end = (node *)malloc(sizeof(node));
		p->next=end;

		p=end;
     	p->next=NULL;	
		fscanf(fp,READ_FORMAT);		
	}

	while(!feof(fp2))
	{	
		node *end; 	
		end = (node *)malloc(sizeof(node));
		p->next=end;

		p=end;
		p->next=NULL;	
		fscanf(fp2,READ_FORMAT);		
	}
	
	printf("\n\t��Ϣ����ɹ�\n");

		

	InsertSort(head);
	Fprintf(head);
	fclose(fp);
}

void ShowList(node *head)//��ͷ��������
{
	node *p=head->next;
	int i=0;
	printf ("\t\t\t�ɼ����������\n");
	printf (PRINT_TITLE);
	while(NULL!=p )
	{	i++;
		printf (PRINT_FORMAT);
		p=p->next;
	}

}

void FprintfToFile(node *head)
{
	char file[50]={"f:\\boxiang_stu.txt"};

	//printf("\n����Ҫд����ļ���:");
	//scanf("%s",file);

	FILE *fp;
	if((fp=fopen(file,"w+"))==NULL)
	{
		printf("\n\t�ļ�����ʧ��\n");

		exit(0);
	}
	node *p=head->next;
	while(NULL!=p)
	{	
		if(p->next==NULL)//��Ҫ���һ�еĻس��������Ļ�������ļ�ʱ�Ͳ�����ĩβ������
			fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
		else
			fprintf(fp,WRITE_FORMAT);
		p=p->next;
	}
	fclose(fp);
	printf("\n\t����д��ɹ�\n",file);//printf���˫����Ҫ��ת����\"

}


node *ClearList(node *head)
{
	node *p=head->next;
	while(NULL!=p)
	{
		node *tp=p->next;
		free(p);
		p=tp;
	}
	return head->next=NULL;

}


void first::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	  UpdateData(TRUE);   
	 node *head;
	int i=0;
	head = (node *)malloc(sizeof(node));
	strcpy(head->stu.num," ");
	strcpy(head->stu.name," ");
	head->stu.Chinese=0;
	head->stu.math=0;
	head->stu.English=0;
	head->stu.count_score=0;
	node *temp= (node *)malloc(sizeof(node));//������ҽ����ͷ���

	FscanfFromFile(head);
	ShowList(head);

	ifstream in;

	string str,str2;
	m_value10="";
	in.open("f:\\boxiang_stu.txt",ios::in);
	while(!in.eof())
	{
		getline(in,str,'\n');
		str2+=str+"\r\n";
		CString cstr(str2.c_str());
		cstr=str2.c_str();
		m_value10=cstr;
	}

	  UpdateData(FALSE);   
}


void first::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 UpdateData(TRUE);   
	 node *head;
	int i=0;
	head = (node *)malloc(sizeof(node));
	strcpy(head->stu.num," ");
	strcpy(head->stu.name," ");
	head->stu.Chinese=0;
	head->stu.math=0;
	head->stu.English=0;
	head->stu.count_score=0;
	node *temp= (node *)malloc(sizeof(node));//������ҽ����ͷ���

	FscanfFromFile(head);

	MySelect(head,temp);

	ifstream in;
	m_value10="";
	string str="",str2="";
	in.open("f:\\English.txt",ios::in);
	while(!in.eof())
	{
		getline(in,str,'\n');
		str2+=str+"\r\n";
		CString cstr(str2.c_str());
		cstr=str2.c_str();
		m_value10=cstr;
	}

	  UpdateData(FALSE);   
}
