/*	
		��Ŀʵѵ���Ĳ���ʹ��˵��:

		ֱ������,����txt�ļ�(student.txt && data_student.txt )Ҫ�ŵ�F�̵ĸ�Ŀ¼��
		Ϊ�˷�������2ά������

		�ŵ�:
		ͨ���ж�ѧ��_type�������ж��Ƕ�һ�ƿγ̻������ƿγ�
		��������sort�����Ե÷ǳ�����
		д�÷ǳ��Ұ�,������ʲô�ŵ������

		����:
		�ҵ�ֻ�б༭���ſ��ö�
		��ȡ�ַ�����Ч���ݵķ�������׸
		����̨������ݵķ����ܲٵ�
		��û��ʵ����ķ�װ,����д��������Ҫ��ס�þ�̬����
		û��ʵ��ģ�黯
		Student�����_fp�����е����
		����������洢������㷨�ǲ��ǿ����Ż�?
		���κ�ҳ�����
											by2014/6/30
*/

#include<iostream>
#include<string>
#include<fstream>    //�ļ�����ͷ�ļ�
#include<vector>     //����ͷ�ļ�
#include <algorithm> //������������ͷ�ļ�
#include <functional>//������������ͷ�ļ�

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::vector;
using std::sort;
using std::greater;          //���������ʱ����õ�
using std::less;             //���������ʱ����õ�
string BOOL_GRADE;
int BOOL_TYPE[3]{0, 0, 0};       //����
int BOOL_PLACE[5]{0, 0, 0, 0, 0};//����
int BOOL_S[4]{ 0, 0, 0, 0 };	 //����
int BOOL_T[6]{ 0, 0, 0, 0, 0,0 };  //����
 
void  System()
{
	cout << "�����ѯ����ʽ����:"<<endl
		<<"P(����1...)+Q(����1...)+S(������Ϣ)+T(������Ϣ)-P(����)%T(��ʲô����)" << endl;
}

class Student                 //ѧ����
{
public:
	Student  ();
	~Student  ();
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

};

/*----------------------�������------------------------------*/
//�ֽܷ�������
bool   greatersum(const   Student&   s1, const   Student&   s2)
{
	return   s1._sum   >   s2._sum;
}
//Ӣ��ɼ���������
bool   greaterEnglish(const   Student&   s1, const   Student&   s2)
{
	return   s1._English   >   s2._English;
}
//���ĳɼ���������
bool   greaterchinese(const   Student&   s1, const   Student&   s2)
{
	return   s1._chinese   >   s2._chinese;
}
//��ѧ�ɼ���������
bool   greatermath(const   Student&   s1, const   Student&   s2)
{
	return   s1._math   >   s2._math;
}
//��һ�ƽ�������
bool   greatercourse1(const   Student&   s1, const   Student&   s2)
{
	return   s1._course1   >   s2._course1;
}
//�ڶ��ƽ�������
bool   greatercourse2(const   Student&   s1, const   Student&   s2)
{
	return   s1._course2   >   s2._course2;
}
/*-------------------------�������--------------------------*/
Student  ::Student  ()
{
	_fp = 0;                    //��ʼ���ļ�ָ��
}

Student  ::~Student  ()
{	
}
int Student::finput(fstream *fp)              //���廯finput()      
{
	_fp = fp;
	(*_fp) >> _num >> _name                  //�趨ѧ������
		   >>_sex>>_age                      //�趨�Ա������
		   >>_place>>_type                   //�ص�Ϳ�������
		   >> _wchar[0] >> _chinese >> _wchar[1] >> _math >> _wchar[2] >> _English;  //�趨3�Ƴɼ�
	if (_type == "�Ŀ�")
	{
		(*_fp) >> _wchar[3] >> _course1 >> _wchar[4] >> _course2;     //�趨��ʷ�͵���
	}
	else
	{
		(*_fp) >> _wchar[3] >> _course1;                 //�趨���������
	}
	if (_num==""||_name=="")                             //���û�ж������ݷ���false
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
void Student::fdisplay(fstream *fp)                                        //���廯fdisplay
{
	(*fp) << _num << "	" << _name << "	"						            //�ļ����ѧ������
		<< _sex << " " << _age << "	"										//�ļ�����Ա������
		<< _wchar[0] << _chinese << _wchar[1] << _math << _wchar[2] << _English;  //�ļ����3�Ƴɼ�
	if (_type == "�Ŀ�")
	{
		(*fp) << _wchar[3] << _course1 << _wchar[4] << _course2 ;          //�ļ������ʷ�͵���
	}
	else
	{
		(*fp) << _wchar[3] << _course1;                                    //�ļ�������������
	}
	(*fp) << "�ܷ� " << _sum << endl;                                     //�ļ�����ܷ�
}
void Student::display()											                        //���廯display(���Ե�ʱ��д��)
{	
	if (BOOL_S[0])
	{
		cout << _num << "	";
	}
	if (BOOL_S[1])
	{
		cout << _name << "	";
	}
	if (BOOL_S[2])
	{
		cout << _sex << "	";
	}
	if (BOOL_S[3])
	{
		cout << _age << "	";
	}
	if (BOOL_T[0])
	{
		cout << _wchar[0] << "	" << _chinese << "	";
	}
	if (BOOL_T[1])
	{
		cout << _wchar[1] << "	" << _math << "	";
	}
	if (BOOL_T[2])
	{
		cout << _wchar[2] << "	" << _English << "	";
	}
	if (BOOL_T[3])
	{
		cout << _wchar[3] << "	" << _course1 << "	";
	}
	if (BOOL_T[4]&&_type=="�Ŀ�")
	{
		cout << _wchar[4] << "	" << _course2 << "	";
	}
	if (BOOL_T[5])
	{
		cout << "�ܷ�	" << _sum << "	";
	}
	cout<< endl;
}
/*       �ַ������� ,���ݷ��ŷ�����ӵ�����                        */
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
int main()
{
	fstream file_one("F://data_student.txt");	 //�򿪵�һ���ļ�
	if (!file_one)						//�����ʧ��
	{
		cout << "open error!" << endl;//��ʾ������Ϣ
		abort();//�����˳�
	}
	vector<Student>stu_data;					//����һ���յ�stu_date����,�����ļ���ȫ����Ϣ
	do
	{
		Student stu;
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
	vector<Student>data_two[5];                //����һ����������
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
	vector<Student>data_three[5][3];
	for (size_t i = 0; i < 5; ++i)
	{
		for (auto it = data_two[i].begin(); it != data_two[i].end(); ++it)
		{
			if (it->_type == "�Ŀ�")
			{
				data_three[i][0].push_back(*it); // ��ӵ�data_two[i][0]
			}
			else if (it->_type == "���")
			{
				data_three[i][1].push_back(*it);//��ӵ�data_two[i][1]
			}
			else if (it->_type == "����")
			{
				data_three[i][2].push_back(*it); //��ӵ�data_two[i][2]
			}
		}
	}
	System();
	//string str="P(��ͷ)+Q(����,�Ŀ�,���)+S(ѧ��,����,�Ա�)+T(�ܷ�)-Q()-P()-S(ѧ��)%T(�ܷ�)";
	string str;
	cin >> str;
	if (str.find("%T(")<1000){
    BOOL_GRADE = str.substr(str.find("%T") + 3, 4);
	str = str.substr(0, str.find("%T"));
	}
	else
	{
		cout << "��������ȷ�﷨" << endl;
	}
	vector<string> strs1 = splitEx(str, "-");
	vector<string> strs2 = splitEx(strs1[0], "+");
	//ɾ����"-"��ǰ���ַ���
	strs1.erase(strs1.begin());
	//+�����
	for (unsigned int i = 0; i < strs2.size(); i++)
	{
		if ( strs2[i].find("P") < 1000)
		{
			int is_ture = 1;
			if ( strs2[i].find("����") < 1000)
			{
				BOOL_PLACE[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("��ͷ") < 1000)
			{
				BOOL_PLACE[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("�麣") < 1000)
			{
				BOOL_PLACE[2] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("տ��") < 1000)
			{
				BOOL_PLACE[3] = 1;
				is_ture = 0;
				
			}
			if ( strs2[i].find("����") < 1000)
			{
				BOOL_PLACE[4] = 1;
				is_ture = 0;
			}
			//�������û���κ���Ϣ
			if (is_ture)
			{
				BOOL_PLACE[0] = 1;
				BOOL_PLACE[1] = 1;
				BOOL_PLACE[2] = 1;
				BOOL_PLACE[3] = 1;
				BOOL_PLACE[4] = 1;
			}

		}
		else if ( strs2[i].find("Q") < 1000)
		{	
			int is_ture = 1;
			if ( strs2[i].find("�Ŀ�") < 1000)
			{
				BOOL_TYPE[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("���") < 1000)
			{
				BOOL_TYPE[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("����") < 1000)
			{
				BOOL_TYPE[2] = 1;
				is_ture = 0;
			}
			//�������û���κ���Ϣ
			if (is_ture)
			{
				BOOL_TYPE[0] = 1;
				BOOL_TYPE[1] = 1;
				BOOL_TYPE[2] = 1;
			}
		}
		else if ( strs2[i].find("S") < 1000)
		{
			int is_ture = 1;
			if ( strs2[i].find("ѧ��") < 1000)
			{
				BOOL_S[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("����") < 1000)
			{
				BOOL_S[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("�Ա�") < 1000)
			{
				BOOL_S[2] = 1;
				is_ture = 0;
			}
			if (strs2[i].find("����") < 1000)
			{
				BOOL_S[3] = 1;
				is_ture = 0;
			}
			//�������û���κ���Ϣ
			if (is_ture)
			{
				BOOL_S[0] = 1;
				BOOL_S[1] = 1;
				BOOL_S[2] = 1;
				BOOL_S[3] = 1;
			}
		}
		else if ( strs2[i].find("T") < 1000)
		{	
			int is_ture = 1;
			if ( strs2[i].find("����") < 1000)
			{
				BOOL_T[0] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("��ѧ") < 1000)
			{
				BOOL_T[1] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("Ӣ��") < 1000)
			{
				BOOL_T[2] = 1;
				is_ture = 0;
			}
			if (strs2[i].find("����") < 1000 || 
				strs2[i].find("��ʷ") < 1000 || 
				strs2[i].find("����") < 1000  )
			{
				BOOL_T[3] = 1;
				is_ture = 0;
			}
			if ( strs2[i].find("����") < 1000)
			{
				BOOL_T[4] = 1;
				is_ture = 0;
			}
			if (strs2[i].find("�ܷ�") < 1000)
			{
				BOOL_T[5] = 1;
				is_ture = 0;
			}
			//�������û���κ���Ϣ
			if (is_ture)
			{
				BOOL_T[0] = 1;
				BOOL_T[1] = 1;
				BOOL_T[2] = 1;
				BOOL_T[3] = 1;
				BOOL_T[4] = 1;
				BOOL_T[5] = 1;
			}
		}
	}

	//-�����
	for (unsigned int i = 0; i < strs1.size(); i++)
	{
		if (strs1[i].find("P") < 1000)
		{	
			if (strs1[i].find("����") < 1000)
			{
				BOOL_PLACE[0] = 0;
			}
			if (strs1[i].find("��ͷ") < 1000)
			{
				BOOL_PLACE[1] = 0;
			}
			if (strs1[i].find("�麣") < 1000)
			{
				BOOL_PLACE[2] = 0;
			}
			if (strs1[i].find("տ��") < 1000)
			{
				BOOL_PLACE[3] = 0;
			}
			if (strs1[i].find("����") < 1000)
			{
				BOOL_PLACE[4] = 0;
			}
			//�������û���κ���Ϣ
			if (!(BOOL_PLACE[0] || BOOL_PLACE[1] || BOOL_PLACE[2] || BOOL_PLACE[3] || BOOL_PLACE[4]))
			{
				BOOL_PLACE[0] = 0;
				BOOL_PLACE[1] = 0;
				BOOL_PLACE[2] = 0;
				BOOL_PLACE[3] = 0;
				BOOL_PLACE[4] = 0;
			}

		}
		else if (strs1[i].find("Q") < 1000)
		{
			if (strs1[i].find("�Ŀ�") < 1000)
			{
				BOOL_TYPE[0] = 0;
			}
			if (strs1[i].find("���") < 1000)
			{
				BOOL_TYPE[1] = 0;
			}
			if (strs1[i].find("����") < 1000)
			{
				BOOL_TYPE[2] = 0;
			}
			//�������û���κ���Ϣ
			if (!(BOOL_TYPE[0] || BOOL_TYPE[1] || BOOL_TYPE[2]))
			{
				BOOL_TYPE[0] = 0;
				BOOL_TYPE[1] = 0;
				BOOL_TYPE[2] = 0;
			}
		}
		else if (strs1[i].find("S") < 1000)
		{
			int is_ture = 1;
			if (strs1[i].find("ѧ��") < 1000)
			{
				BOOL_S[0] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("����") < 1000)
			{
				BOOL_S[1] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("�Ա�") < 1000)
			{
				BOOL_S[2] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("����") < 1000)
			{
				BOOL_S[3] = 0;
				is_ture = 0;
			}
			if (is_ture)
			{
				BOOL_S[0] = 0;
				BOOL_S[1] = 0;
				BOOL_S[2] = 0;
				BOOL_S[3] = 0;
			}
			
		}
		else if (strs1[i].find("T") < 1000)
		{
			int is_ture = 1;
			if (strs1[i].find("����") < 1000)
			{
				BOOL_T[0] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("��ѧ") < 1000)
			{
				BOOL_T[1] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("Ӣ��") < 1000)
			{
				BOOL_T[2] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("����") < 1000 ||
				strs1[i].find("��ʷ") < 1000 ||
				strs1[i].find("����") < 1000)
			{
				BOOL_T[3] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("����") < 1000)
			{
				BOOL_T[4] = 0;
				is_ture = 0;
			}
			if (strs1[i].find("�ܷ�") < 1000)
			{
				BOOL_T[5] = 0;
				is_ture = 0;
			}
			if (is_ture)
			{
				BOOL_T[0] = 0;
				BOOL_T[1] = 0;
				BOOL_T[2] = 0;
				BOOL_T[3] = 0;
				BOOL_T[4] = 0;
				BOOL_T[5] = 0;
			}
			
		}
	}
	for (size_t i = 0; i < 5; ++i)
	{	
		//��������ǿ���
		if (BOOL_PLACE[i])
		{
			cout << (*data_two[i].begin())._place << endl << endl;
		}
		else
		{
			continue;
		}
		for (size_t j = 0; j < 3; ++j)
		{	
			//��������ǿ���
			if (BOOL_TYPE[j])
			{
				cout << (*data_three[i][j].begin())._type << " : " << endl;
				//���ֽܷ�������
				if (BOOL_GRADE == "�ܷ�")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatersum);
				}
				else if (BOOL_GRADE == "Ӣ��")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greaterEnglish);
				}
				else if (BOOL_GRADE == "��ѧ")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatermath);
				}
				else if (BOOL_GRADE == "����")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greaterchinese);
				}
				else if (BOOL_GRADE == "����" || BOOL_GRADE == "��ʷ" || BOOL_GRADE == "����")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatercourse1);
				}
				else if (BOOL_GRADE == "����")
				{
					sort(data_three[i][j].begin(), data_three[i][j].end(), greatercourse2);
				}
				else
				{
					cout << "��������ȷ�﷨" << endl;
					break;
				}				
				for (auto it = data_three[i][j].begin(); it != data_three[i][j].end(); ++it)
				{

					//�����ݶ���student.txt
					it->display();
				}
			}			
		}

	}

}