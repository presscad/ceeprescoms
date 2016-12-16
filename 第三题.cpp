/*	
		��Ŀʵѵ��������ʹ��˵��:

		ֱ������,����txt�ļ�(student.txt && data.txt )Ҫ�ŵ�F�̵ĸ�Ŀ¼��

		�ŵ�:
		ͨ���ж�ѧ��_type�������ж��Ƕ�һ�ƿγ̻������ƿγ�
		������sort�����Ե÷ǳ�����

		����:
		��û��ʵ����ķ�װ,����д��������Ҫ��ס�þ�̬����
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
	unsigned  int _course1;     //�γ�һ
	unsigned  int _course2;     //�γ̶�
	unsigned int _sum;          //�ܳɼ�
	unsigned int _list_num;     //���	
	fstream *_fp;               //�ļ�ָ��

};
/*----------------------�������------------------------------*/
//Ӣ��ɼ���������
static bool   lessEnglish(const   Student&   s1, const   Student&   s2)
{
	return   s1._English <   s2._English;
}
//Ӣ��ɼ���������
static bool   greaterEnglish(const   Student&   s1, const   Student&   s2)
{
	return   s1._English   >   s2._English;
}
//�ܷ���������
static bool   lesssum(const   Student&   s1, const   Student&   s2)
{
	return   s1._sum <   s2._sum;
}
//�ֽܷ�������
static bool   greatersum(const   Student&   s1, const   Student&   s2)
{
	return   s1._sum   >   s2._sum;
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
	cout << _num <<"	"<< _name<<"	"												//����̨���ѧ������
		<< _sex <<" "<< _age<<"	"														//����̨����Ա������
		<< _place <<"	"<< _type<<" "													//����̨����ص�Ϳ�������
		<< _wchar[0] << _chinese << _wchar[1] << _math << _wchar[2] << _English;        //����̨��3�Ƴɼ�
	if (_type == "�Ŀ�")
	{
		cout << _wchar[3] << _course1 << _wchar[4] << _course2;							//����̨����ʷ�͵���
	}
	else
	{
		cout << _wchar[3] << _course1 ;													//����̨����ʷ�͵���
	}
	cout << "�ܷ� " << _sum << endl;
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
	vector<Student>data_two[5];                //���������������
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
			if (it->_type=="�Ŀ�")       
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
	//��Ҫ�������õ��ļ�
	fstream file_two("F://student.txt");
	if (!file_two)//�����ʧ��
	{
		cout << "open error!" << endl;//��ʾ������Ϣ
		abort();//�����˳�
	}
	for (size_t i = 0; i < 5; ++i)
	{
		file_two<<(*data_two[i].begin())._place<<endl<<endl;
		for (size_t j = 0; j < 3; ++j)
		{
			file_two << (*data_three[i][j].begin())._type << " : " << endl;
			//���ֽܷ�������
			sort(data_three[i][j].begin(), data_three[i][j].end(), greatersum);
			for (auto it = data_three[i][j].begin(); it != data_three[i][j].end(); ++it)
			{   
				//�����ݶ���student.txt
				it->fdisplay(&file_two);
			}
		}

	}
	//�ر��ļ�
	file_two.close();
}