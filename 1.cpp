#include <iostream>
using namespace std;
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>


#define CLRSCR	system("cls")
#define PRINT_TITLE "\n���\t����\t\t����\t����\t��ѧ\tӢ��\t�ܷ�\n"
#define PRINT_FORMAT "%d\t%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",i,p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define WRITE_FORMAT "%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score
#define READ_FORMAT "%s %s %lf %lf %lf %lf",&p->stu.num,&p->stu.name,&p->stu.Chinese,&p->stu.math,&p->stu.English,&p->stu.count_score

//����ѧ����
class student
{	
public:
	char	num[9];
	char    name[7];//�������ֳ���Ϊ6���ֽڣ�Ӧ�ඨ��һ���ֽ�������ַ���������'\0'
	double	Chinese;
	double	math;
	double	English;
	double	count_score;
};

//���嵥������
class node	 
{	
public:
	 student stu;
	 node *next;
};

int MySelect(node * head,node *temp)   
{	
	int  i=0; 
	node *p,*tp=temp;
	p=head->next;
	FILE *fp;
	char file[15]="English.txt";
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
				fprintf(fp,"%s\t%s\t%lf\t%lf\t%lf\t%lf",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
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
	char file[15]="student.txt";
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
			fprintf(fp,"%s\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
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


void FscanfFromFile(node *head)
{	
	char file[20]="student1.txt";
	FILE *fp;
	if((fp=fopen(file,"r"))==NULL)
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
	char file[15];

	printf("\n����Ҫд����ļ���:");
	scanf("%s",file);

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
			fprintf(fp,"%s\t%s\t%lf\t%lf\t%lf\t%lf",p->stu.num,p->stu.name,p->stu.Chinese,p->stu.math,p->stu.English,p->stu.count_score);
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





int main()
{
	
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



		printf("��ӭʹ��\n");
		printf("\n----------------------------------------------\n");


		FscanfFromFile(head);




	char charget;

	do
	{
		printf("\n----------------------------------------------\n");
		printf("\n[1]��Ϣ��ʾ\n");
		printf("[2]��ѡ\n");
		printf("[3]�˳�����\n");
		do
		{
		charget=getch();
		}while((charget!='1')&&(charget!='2')&&(charget!='3'));

		switch(charget)
		{
		case '1':	ShowList(head);
					printf("\n���������ʾ�ϲ�����˵�\n");
					getch();
					break;
		case '2':	MySelect(head,temp);
					printf("\n���������ʾ�ϲ�����˵�\n");
					getch();
					break;
		}//end switch����������



	}while(charget!='3');

return 0;
}