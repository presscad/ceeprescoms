
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
#include<sstream>

string DoubleToString(double d)
{
    //Need #include <sstream> 
    using namespace std;
    string str;
    stringstream ss;
    ss<<d;
    ss>>str;
    return str;
}
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
int MySelect(node * head,node *temp)   //���ز��ҵ�������������Ŀ��
{	
	int equal,N;
	char CHAR[10];


	printf("----------------------------------------------\n\n");
	printf("����ģʽ:1����Ȳ���,0�ǲ���Ȳ���\n");
	printf("�������:1�ǿ���,2������,3�����ĳɼ�,4����ѧ�ɼ���5��Ӣ��ɼ�,6���ܷ�\n");
	printf("\n--------------------------------------------\n");

	do
	{
	printf("\nѡ�����ģʽ:");
	equal=getche();
	if((equal!='1')&&(equal!='0'))
		printf("\n\t�������\n");
	}while((equal!='1')&&(equal!='0'));
	equal=equal-48;


	
	do 
	{
	printf("\n�����������:");
	N=getche();
	if(N!='1'&&N!='2'&&N!='3'&&N!='4'&&N!='5'&&N!='6')
		printf("\n\t�������\n");
	}while(N!='1'&&N!='2'&&N!='3'&&N!='4'&&N!='5'&&N!='6');
	switch(N)
	{
	case '1':	N=0;break;//NΪ�ֽ���
	case '2':	N=9;break;
	case '3':	break;
	case '4':	break;
	case '5':	break;
	case '6':	break;
	}

	

	printf("\n����ؼ���:");
	scanf("%s",CHAR);

	int  i=0,flag; 
	node *p,*tp=temp;
	p=head->next;
	
	while (NULL!=p)
	{	
		if(N==0||N==9)
		{
		flag=strcmp((char *)p+N,CHAR);//(char *)p+NΪָ��λ��,�Ƚ�ÿһ����¼�еĿ��š������������Ƿ�������Ĺؼ�����ͬ
		if((abs(flag)+equal)==1)//��equalΪ1ʱ����Ȳ���,Ϊ0ʱ�ǲ���Ȳ���;��abs(flag)Ϊ0ʱ��������ؼ�����ͬ,��Ϊ1��ͬ
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
		} 
		p=p->next;

		}

		else
		{
			cout.precision(6);
			if(N=='3')
			{
			flag=strcmp(  (DoubleToString(p->stu.Chinese).c_str()),CHAR  );
			}

			if(N=='4'){
			flag=strcmp(  (DoubleToString(p->stu.math).c_str()),CHAR  );
			}

			if(N=='5'){
			flag=strcmp(  (DoubleToString(p->stu.English).c_str()),CHAR  );
			}

			if(N=='6'){
			flag=strcmp(  (DoubleToString(p->stu.count_score).c_str()),CHAR  );
			}

			if(flag==0)//��equalΪ1ʱ����Ȳ���,Ϊ0ʱ�ǲ���Ȳ���;��abs(flag)Ϊ0ʱ��������ؼ�����ͬ,��Ϊ1��ͬ
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
			} 
			p=p->next;
		}

	}

	if(i==0)
		printf("\n\tû�в��ҵ�������������Ϣ\n");

return i;
}

int SelectScore(node * head)   
{	
	char CHAR[10];


	printf("----------------------------------------------\n\n");
	printf("�����뿼�ţ�\n");	
	scanf("%s",CHAR);

	int  i=0,flag; 
	node *p;
	p=head->next;
	
	while (NULL!=p)
	{	
		flag=strcmp((char *)p,CHAR);//�Ƚ�ÿһ����¼�еĿ����Ƿ����ѯ�Ŀ�����ͬ
		if(flag==0)
		{	
			if(i==0)
				printf (PRINT_TITLE);
			i++;
			printf(PRINT_FORMAT);
		} 
		p=p->next;

	}

	if(i==0)
		printf("\n\tû�в��ҵ���Ӧ���ŵ���Ϣ\n");

return i;
}


void InsertSort(node *head)//�ִܷӸߵ�������
{ 
	node *p,*q,*r,*u;
    p=head->next;  
	head->next=NULL;
    while(p!=NULL)
    {
		r=head;  
		q=head->next;
         
		while(q!=NULL&&((q->stu.count_score)>(p->stu.count_score))) 
		{                       
			r=q; 
			q=q->next;
		}
		u=p->next; 
		p->next=r->next;   
		r->next=p;  

		p=u;
	}
}

void CheckNum(node *head)
{
	/*ɾ��ѧ���ظ�����Ŀ*/
		node *release,*p;
		p=head->next;
		int m=0;
		while(NULL!=p->next)
		{
			node *p2=p;
			
			while(NULL!=p2->next)
			{
				if(0==strcmp(p->stu.num,p2->next->stu.num))
				{	m++;
					if(m==1)
					printf("\t\t������Ŀ�򿼺���ǰ�����Ϣ��ͻ��û�е���\n");

			printf("%s\t%s\t%lf\t%lf\t%lf\t%lf",p2->stu.num,p2->stu.name,p2->stu.Chinese,p2->stu.math,p2->stu.English,p2->stu.count_score);

					release=p2->next;
					p2->next=p2->next->next; 
					free(release);				
				}
				p2=p2->next;
			}

			p=p->next;
		}


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
		InsertSort(head);
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

int AddStu(node *head)
{
	cout<<"�����������λѧ����Ϣ��"<<endl;
	int i;
	cin>>i;
	int u=1;
	do
	{
	node *p,*p2=head,*p3;
	p=(node *)malloc(sizeof(node));
	cout<<"�����������"<<u<<"λѧ���Ŀ��š����������ĳɼ�����ѧ�ɼ���Ӣ��ɼ����ÿո��������\n";
	if(u>1)
	{
		cout<<" ��y������ӣ���������ֹͣ���\n\n"<<endl;
		char charget;
		charget=getch();
		if(charget=='y')
			goto loop1;
		else
			break;
	}
	loop1:
	cin>>p->stu.num>>p->stu.name>>p->stu.Chinese>>p->stu.math>>p->stu.English;
	p->stu.count_score = p->stu.Chinese + p->stu.math + p->stu.English;
	int flag=0;
	p2=head;
	while(NULL!=p2->next)
	{	/*�ҳ���һ������ѧ���Ŀ��Ŵ��λ�ã�������Ϣ������ǰ��*/
		if((flag=strcmp(p->stu.num,p2->next->stu.num))<0)
		{
			p3=p2->next;
			p2->next=p;
			p->next=p3;
			break;
		}
		
		p2=p2->next;
	}

	/*��������ѧ���Ŀ��ű����еĶ��󣬷�����ĩβ*/
	if(flag>0)
	{
		p2->next=p;
		p->next=NULL;
	}
	i--;
	u++;
	}while(i>0);

	printf("��Ϣ��ӳɹ�\n");
	printf("\t�����������\n");
	getch();	
	


	return 1;
}


int DeleteByNum(node *head)
{	char num[9];
	int flag=1;
	node *p=head,*p2;
	printf("����Ҫɾ����Ϣ�Ŀ��ţ�");
	scanf("%s",num);
	while(NULL!=p->next)
	{
		if((flag=strcmp(p->next->stu.num,num))==0)
		{
			p2=p->next;
			p->next=p->next->next;
			free(p2);
			printf("ɾ���ɹ�\n");
			break;		
		}
		p=p->next;
	}

	if(flag!=0)
		printf("������Ŀ��Ų�����\n");
	printf("\t�����������\n");
	getche();
		



	return 1;
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
		printf("[2]��Ϣ����\n");
		printf("[3]��ѯ�ɼ�\n");
		printf("[4]�����Ϣ\n");
		printf("[5]ɾ����Ϣ\n");
		printf("[6]�˳�����\n");
		do
		{
		charget=getch();
		}while((charget!='1')&&(charget!='2')&&(charget!='3')&&(charget!='4')&&(charget!='5')&&(charget!='6'));

		switch(charget)
		{
		case '1':	ShowList(head);
					printf("\n���������ʾ�ϲ�����˵�\n");
					getch();
					break;
		case '2':	if(0!=MySelect(head,temp))//���ҽ�����Ϊ�����������Ĳ�����Ϊ���򷵻��ϲ�˵�
					{

						char charget2;
						do
						{
							printf("\n[1]�ڴ˻����ϼ�������\n");
							printf("[2]�����ҽ��д���ļ�\n");
							printf("[3]�˳����β���\n");
							
							
							do
							{
								charget2=getch();
							}while((charget2!='1')&&(charget2!='2')&&(charget2!='3'));

							switch(charget2)
							{
							case '1':	if(0==MySelect(temp,temp))
										{	
											printf("\n��������������β���\n");
											getch();
											charget2='3';	
										}
										break;

							case '2':	FprintfToFile(temp);
										charget2='3';//����д����Զ��������β���
										break;
							case '3':	ClearList(temp);//�������ң��ͷ��ݴ���ҽ��������
										break;
							

							}//end switch���������β���

						}
						while(charget2!='3');//���charget2Ҳ��charget�Ļ����ڲ����а���3��ֱ���˳�����
					}//end if
					break;
		case '3':	SelectScore(head);break;
		case '4':	AddStu(head);Fprintf(head);break;
		case '5':	DeleteByNum(head);Fprintf(head);break;

					
		}//end switch����������



	}while(charget!='6');

return 0;
}



