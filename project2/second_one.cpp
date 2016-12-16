// second_one.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "project2.h"
#include "second_one.h"
#include "afxdialogex.h"

#include <iostream>
#include <stdio.h>
#include<fstream>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h> 
//#include <cstdlib> 
#include <string>
#include <math.h>
using namespace std;

#define CLRSCR	system("cls")
#define PRINT_TITLE "\n���\t����\t\t����\t����\t��ѧ\tӢ��\t�ܷ�\n"
#define PRINT_FORMAT "%d\t%s\t%s\t%d\t%d\t%d\t%d\n",i,p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define WRITE_FORMAT "%s\t%s\t%d\t%d\t%d\t%d\n",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define READ_FORMAT "%s %s %d %d %d %d",&p->stu.num,&p->stu.name,&p->stu.Chinese,&p->stu.math,&p->stu.English,&p->stu.count_score
// second_one �Ի���

IMPLEMENT_DYNAMIC(second_one, CDialogEx)

second_one::second_one(CWnd* pParent /*=NULL*/)
	: CDialogEx(second_one::IDD, pParent)
	, m_stu(_T(""))
{

}

second_one::~second_one()
{
}

void second_one::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_stu);
}


BEGIN_MESSAGE_MAP(second_one, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &second_one::OnBnClickedButton1)
END_MESSAGE_MAP()


// second_one ��Ϣ�������
class student_bx2
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
class node2	 
{	
public:
	 student_bx2 stu;
	 node2 *next;
};

int MySelect(node2 * head,node2 *temp)   
{	
	int  i=0; 
	node2 *p,*tp=temp;
	p=head->next;
	FILE *fp;
	char file[15]={"f:\\English.txt"};
	if((fp=fopen(file,"w+"))==NULL)
	{
	//	printf("\n\t�ļ�����ʧ��\n");

		exit(0);
	}


	while (NULL!=p)
	{
		if(p->stu.English>100&&p->stu.count_score>300)
		{
			node2 *end;
			end = (node2 *)malloc(sizeof(node2));
			tp->next=end;
			tp=end;
			tp->next=NULL;
			tp->stu=p->stu;
		
			if(i==0)
			//	printf(PRINT_TITLE);
			i++;
		//	printf(PRINT_FORMAT);
			if(p->next==NULL)//��Ҫ���һ�еĻس��������Ļ�������ļ�ʱ�Ͳ�����ĩβ������
				fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%d",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
			else
				fprintf(fp,WRITE_FORMAT);				

		}
		p=p->next;
	}
//	fclose(fp);	
	if(i==0)
		//printf("\n\tӢ�ﳬ��100�����ֳܷɼ�����300�ֵ�ѧ������Ϊ��\n");
	return i;
}



void Fprintf(node2 *head)
{
	char file[40]={"f:\\boxiang_stu2.txt"};
	FILE *fp;
	if((fp=fopen(file,"w+"))==NULL)
	{
		//printf("\n\t�ļ���ʧ�ܣ���������˳�\n");
		getch();
		exit(0);
	}
	
	node2 *p=head->next;
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
void InsertSort(node2 *head)//�ִܷӴ�С����
{ 
	node2 *p,*q,*u,*h,*w,*n;
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


void FscanfFromFile(node2 *head)//cdsgfdgfhhhhhhhhhhhhhhhhhhhhhhh
{	
	char file[25]="f:\\boxiang_stu.txt";

	FILE *fp;
	if((fp=fopen(file,"r"))==NULL)
	{
		//printf("\n\t�ļ���ʧ�ܣ���������˳�\n");
		getch();
		exit(0);
	}
	
	node2 *p=head;
	while(!feof(fp))
	{	
		node2 *end; 	
		end = (node2 *)malloc(sizeof(node2));
		p->next=end;

		p=end;
     	p->next=NULL;	
		fscanf(fp,READ_FORMAT);		
	}

	//printf("\n\t��Ϣ����ɹ�\n");

		

	InsertSort(head);
	Fprintf(head);
	fclose(fp);
}

void ShowList(node2 *head)//��ͷ��������
{
	node2 *p=head->next;
	int i=0;
	//printf ("\t\t\t�ɼ����������\n");
//	printf (PRINT_TITLE);
	while(NULL!=p )
	{	i++;
		printf (PRINT_FORMAT);
		p=p->next;
	}

}

void FprintfToFile(node2 *head)
{
	char file[50]={"f:\\boxiang_stu2.txt"};

	//printf("\n����Ҫд����ļ���:");
	//scanf("%s",file);

	FILE *fp;
	if((fp=fopen(file,"w+"))==NULL)
	{
		printf("\n\t�ļ�����ʧ��\n");

		exit(0);
	}
	node2 *p=head->next;
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


node2 *ClearList(node2 *head)
{
	node2 *p=head->next;
	while(NULL!=p)
	{
		node2 *tp=p->next;
		free(p);
		p=tp;
	}
	return head->next=NULL;

}

void second_one::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 UpdateData(TRUE);  
	ofstream out;
	string num,name;
	int chinese,math,english,sum;
	out.open("f:\\stu.txt",ios::out);
	out<<m_stu;
	out.close();
	ifstream in2("f:\\stu.txt",ios::in);
	ofstream out2("f:\\boxiang_stu.txt",ios::app);
	while(!in2.eof())
	{
		in2>>num>>name>>chinese>>math>>english;
		sum=chinese+math+english;
		out2<<endl<<num<<"\t"<<name<<"\t"<<chinese<<"\t"<<math<<"\t"<<english<<"\t"<<sum;
	}
	in2.close();
	out2.close();
	////////////////////
	 node2 *head;
	int i=0;
	head = (node2 *)malloc(sizeof(node2));
	strcpy(head->stu.num," ");
	strcpy(head->stu.name," ");
	head->stu.Chinese=0;
	head->stu.math=0;
	head->stu.English=0;
	head->stu.count_score=0;
	node2 *temp= (node2 *)malloc(sizeof(node2));//������ҽ����ͷ���

	FscanfFromFile(head);
	ShowList(head);

	//����д������
	ifstream in3;
	ofstream out3;
	in3.open("f:\\boxiang_stu2.txt",ios::in);
	out3.open("f:\\boxiang_stu.txt",ios::out);
	while(!in3.eof())
	{
		in3>>num>>name>>chinese>>math>>english>>sum;
	
		out3<<endl<<num<<"\t"<<name<<"\t"<<chinese<<"\t"<<math<<"\t"<<english<<"\t"<<sum;

	}
	//��ʾ����������
	ifstream in4;
	in4.open("f:\\boxiang_stu.txt",ios::out);
	string str,str2;
	while(!in4.eof())
	{
		getline(in4,str,'\n');
		str2+=str+"\r\n";
		CString cstr(str2.c_str());
		cstr=str2.c_str();
		m_stu=cstr;  //
	}
	  UpdateData(FALSE);   
}
