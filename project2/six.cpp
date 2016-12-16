// six.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "project2.h"
#include "six.h"
#include "afxdialogex.h"

#include<iostream>
#include<string>
#include<fstream>    //�ļ�����ͷ�ļ�
#include<vector>     //����ͷ�ļ�
#include <algorithm> //������������ͷ�ļ�
#include <functional>//������������ͷ�ļ�
using namespace std;
/*
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::vector;
using std::sort;
using std::greater;          //���������ʱ����õ�
using std::less;             //���������ʱ����õ�*/
//string BOOL_GRADE;
int BOOL__[5][3]={0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0};       //����
// six �Ի���

IMPLEMENT_DYNAMIC(six, CDialogEx)

six::six(CWnd* pParent /*=NULL*/)
	: CDialogEx(six::IDD, pParent)
	, m_seek_six(_T(""))
	, m_value_six(_T(""))
{

}

six::~six()
{
}

void six::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_seek_six);
	DDX_Text(pDX, IDC_EDIT2, m_value_six);
}


BEGIN_MESSAGE_MAP(six, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &six::OnBnClickedButton1)
END_MESSAGE_MAP()


// six ��Ϣ�������
/*void  System()
{
	cout << "�����ѯ����ʽ����:" << endl
		<< "(����1,����)+(����1,����)" << endl;
}

class Student_yong3                 //ѧ����
{
public:
	Student_yong3();
	~Student_yong3();
	int finput(fstream *fp);	//�ļ���������
	void fdisplay(fstream *fp); //�ļ���������
	void input();				//����̨��������
	void display();				//����̨�������
	void setMath();				//�趨��ѧ�ɼ�
	void setChinese();			//�趨���ĳɼ�
	void setEnglish();			//�趨Ӣ��ɼ�
	void getMath();				//��ȡ��ѧ�ɼ�
	void getChinese();			//��ȡ���ĳɼ�
	void getEnglish();			//��ȡӢ��ɼ�


	string _num;				//����
	string _name;               //����
	string _sex;                //�Ա�
	unsigned int _age;          //����
	string _place;	            //�ص�
	string _type;               //��������
	string _wchar[5];           //����ǰ׺
	unsigned int _chinese;      //����
	unsigned int _math;         //��ѧ
	unsigned int _English;      //Ӣ��
	unsigned int _course1;     //�γ�һ
	unsigned int _course2;     //�γ̶�
	unsigned int _sum;          //�ܳɼ�
	unsigned int _list_num;     //���	
	fstream *_fp;               //�ļ�ָ��

};*/

/*----------------------�������------------------------------*/
//�ֽܷ�������
/*
bool   greatersum(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._sum   >   s2._sum;
}
//Ӣ��ɼ���������
bool   greaterEnglish(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._English   >   s2._English;
}
//���ĳɼ���������
bool   greaterchinese(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._chinese   >   s2._chinese;
}
//��ѧ�ɼ���������
bool   greatermath(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._math   >   s2._math;
}
//��һ�ƽ�������
bool   greatercourse1(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._course1   >   s2._course1;
}
//�ڶ��ƽ�������
bool   greatercourse2(const   Student_yong3&   s1, const   Student_yong3&   s2)
{
	return   s1._course2   >   s2._course2;
}*/
/*-------------------------�������--------------------------*/
/*
Student_yong3::Student_yong3()
{
	_fp = 0;                    //��ʼ���ļ�ָ��
}

Student_yong3  ::~Student_yong3()
{
}
int Student_yong3::finput(fstream *fp)              //���廯finput()      
{
	_fp = fp;
	(*_fp) >> _num >> _name                  //�趨ѧ������
		>> _sex >> _age                      //�趨�Ա������
		>> _place >> _type                   //�ص�Ϳ�������
		>> _wchar[0] >> _chinese >> _wchar[1] >> _math >> _wchar[2] >> _English;  //�趨3�Ƴɼ�
	if (_type == "�Ŀ�")
	{
		(*_fp) >> _wchar[3] >> _course1 >> _wchar[4] >> _course2;     //�趨��ʷ�͵���
	}
	else
	{
		(*_fp) >> _wchar[3] >> _course1;                 //�趨���������
	}
	if (_num == "" || _name == "")                             //���û�ж������ݷ���false
	{
		return 0;
	}
	else
	{
		//�����ܳɼ�
		_sum = _math + _English + _chinese + _course1 + _course2;
		return 1;
	}
}
void Student_yong3::fdisplay(fstream *fp)                                        //���廯fdisplay
{
	(*fp) << _num << "	" << _name << "	"						            //�ļ����ѧ������
		<< _sex << " " << _age << "	"										//�ļ�����Ա������
		<< _wchar[0] << _chinese << _wchar[1] << _math << _wchar[2] << _English;  //�ļ����3�Ƴɼ�
	if (_type == "�Ŀ�")
	{
		(*fp) << _wchar[3] << _course1 << _wchar[4] << _course2;          //�ļ������ʷ�͵���
	}
	else
	{
		(*fp) << _wchar[3] << _course1;                                    //�ļ�������������
	}
	(*fp) << "�ܷ� " << _sum << endl;                                     //�ļ�����ܷ�
}

/*       �ַ������� ,���ݷ��ŷ�����ӵ�����                        */
/*
vector<string> splitEx(const string& src, string separate_character)
{
	vector<string> strs;

	int separate_characterLen = separate_character.size();//�ָ��ַ����ĳ���,�����Ϳ���֧���硰,,�����ַ����ķָ���
	int lastPosition = 0, index = -1;
	while (-1 != (index = src.find(separate_character, lastPosition)))
	{
		strs.push_back(src.substr(lastPosition, index - lastPosition));
		lastPosition = index + separate_characterLen;
	}
	string lastString = src.substr(lastPosition);//��ȡ���һ���ָ����������
	if (!lastString.empty())
		strs.push_back(lastString);//������һ���ָ����������ݾ����
	return strs;
}
*/
void six::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 /* UpdateData(TRUE); 

	  fstream file_one("F://data_student6.txt");	 //�򿪵�һ���ļ�
	if (!file_one)						//�����ʧ��
	{
		cout << "open error!" << endl;//��ʾ������Ϣ
		abort();//�����˳�
	}
	vector<Student_yong3>stu_data;					//����һ���յ�stu_date����,�����ļ���ȫ����Ϣ
	do
	{
		Student_yong3 stu;
		if (stu.finput(&file_one))                //����finpu(),����ɼ�
		{
			stu_data.push_back(stu);              //��Ӷ�������ĩ��
		}
		else
		{
			file_one.close();                   //�ر��ļ�
			break;                              //����ѭ��
		}
	} while (true);
	vector<Student_yong3>data_two[5];                //����һ����������
	//����stu_data
	for (auto it = stu_data.begin(); it != stu_data.end(); ++it)
	{
		if ((*it)._place == "����")
		{
			data_two[0].push_back(*it);    //��ӵ�data_two[0]
		}
		else if ((*it)._place == "��ͷ")
		{
			data_two[1].push_back(*it);	   //��ӵ�data_two[1]
		}
		else if ((*it)._place == "�麣")
		{
			data_two[2].push_back(*it);	   //��ӵ�data_two[2]
		}
		else if ((*it)._place == "տ��")
		{
			data_two[3].push_back(*it);    //��ӵ�data_two[3]
		}
		else if ((*it)._place == "����")
		{
			data_two[4].push_back(*it);    //��ӵ�data_two[4]
		}
	}
	vector<Student_yong3>data_three1[5][3];
	for (size_t i = 0; i < 5; ++i)
	{
		for (auto it = data_two[i].begin(); it != data_two[i].end(); ++it)
		{
			if (it->_type == "�Ŀ�")
			{
				data_three1[i][0].push_back(*it); // ��ӵ�data_two[i][0]
			}
			else if (it->_type == "���")
			{
				data_three1[i][1].push_back(*it);//��ӵ�data_two[i][1]
			}
			else if (it->_type == "����")
			{
				data_three1[i][2].push_back(*it); //��ӵ�data_two[i][2]
			}
		}
	}
	System();
	//string str="P(��ͷ)+Q(����,�Ŀ�,���)+S(ѧ��,����,�Ա�)+T(�ܷ�)-Q()-P()-S(ѧ��)%T(�ܷ�)";
	string str_1="";
	//cin >> str;
	str_1=m_seek_six;
	vector<string> strs2 = splitEx(str_1, "+");
	
	//+�����
	for (unsigned int i = 0; i < strs2.size(); i++)
	{
		
			
			if (strs2[i].find("(����") < 1000)
			{
				string str1__= strs2[i].substr(strs2[i].find("����")+5, 4);
				if (str1__ == "�Ŀ�")
				BOOL__[0][0] = 1;
				if (str1__ == "���")
				BOOL__[0][1] = 1;
				if (str1__== "����")
				BOOL__[0][2] = 1;
			}
			if (strs2[i].find("(��ͷ") < 1000)
			{	
				string str2__ = strs2[i].substr(strs2[i].find("��ͷ") + 5, 4);
				if (str2__ == "�Ŀ�")
				BOOL__[1][0] = 1;
				if (str2__ == "���")
				BOOL__[1][1] = 1;
				if (str2__ == "����")
				BOOL__[1][2] = 1;
			}
			if (strs2[i].find("(�麣") < 1000)
			{
				string str3__ = strs2[i].substr(strs2[i].find("�麣") + 5, 4);
				if (str3__ == "�Ŀ�")
					BOOL__[2][0] = 1;
				if (str3__ == "���")
					BOOL__[2][1] = 1;
				if (str3__ == "����")
					BOOL__[2][2] = 1;;
			}
			if (strs2[i].find("(տ��") < 1000)
			{
				string str3__ = strs2[i].substr(strs2[i].find("տ��") + 5, 4);
				if (str3__ == "�Ŀ�")
					BOOL__[3][0] = 1;
				if (str3__ == "���")
					BOOL__[3][1] = 1;
				if (str3__ == "����")
					BOOL__[3][2] = 1;;
			}
			if (strs2[i].find("(����") < 1000)
			{
				{
					string str3__ = strs2[i].substr(strs2[i].find("����") + 5, 4);
					if (str3__ == "�Ŀ�")
						BOOL__[4][0] = 1;
					if (str3__ == "���")
						BOOL__[4][1] = 1;
					if (str3__ == "����")
						BOOL__[4][2] = 1;;
				}
			}
	}
	fstream file_six("F://scholar.txt",std::ios::out);	 //�򿪵�һ���ļ�
	for (size_t i = 0; i < 5; ++i)
	{
		
		for (size_t j = 0; j < 3; ++j)
		{
			//��������ǿ���
			if (BOOL__[i][j])
			{	
				file_six << (*data_three1[i][j].begin())._place  
					<< (*data_three1[i][j].begin())._type << " ״Ԫ:  " << endl;
				//���ֽܷ�������				
					sort(data_three1[i][j].begin(), data_three1[i][j].end(), greatersum);
				auto it = data_three1[i][j].begin();
				//�����ݶ���student.txt
					it->fdisplay(&file_six);
				//(��ͷ,�Ŀ�)+(����,���)
			}
		}

	}
	string _str_one_1;
	string _str_two_1;
	fstream file_six_2("F://scholar.txt");
	while (!file_six_2.eof())
	{
		getline(file_six_2, _str_one_1, '\n');		// ���ļ����ж�����һ���ַ�

		_str_two_1 += _str_one_1 + "\r\n";
		CString cstr(_str_two_1.c_str());
		cstr=_str_two_1.c_str();
		m_value_six=cstr;
	}
	//�ر��ļ�
	//cout << _str_two_1 << endl;
	
	file_six_2.close();
	   UpdateData(FALSE);   */
}
