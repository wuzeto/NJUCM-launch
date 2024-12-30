# include <stdio.h>
# include <stdlib.h>
#include  <ctime>
# include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;
typedef struct student
{
	int no;
	int age;
	char name[10];
	char sex[5];
	char inf[100];
	string latetime;
}Student;                                //����洢һ����Ϣ�Ľṹ��
int write(Student *stu, int *len)
{
	FILE *fp = fopen("data.txt","wb");
	if(fp == NULL)
	{
		printf("�򿪻򴴽��ļ�ʧ��\n");
		return -1;
	}
	int j;
	for(j = 0; j < *len ; j++)
	{
		fwrite(&stu[j], sizeof(Student), 1, fp);
		if(ferror(fp))
		{
			printf("�ļ�д��ʧ��\n");
			return -1;
		}
	}
	fclose(fp);
}
int modify(Student *stu, int *len)
{
	printf("-----------�޸Ĳ˵���Ϣ----------\n");
	printf("---------1.������޸�---------\n");
	printf("---------2.�������޸�---------\n");
	printf("��ѡ���޸ı��(1/2):\n");
	int number;
	scanf("%d",&number);
	switch(number)
	{
		case 1:
		{
			printf("������޸�\n");
			printf("��������Ҫ�޸ĵı��:\n");
			int no;
			scanf("%d",&no);
			fflush(stdin);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(no == stu[i].no)
				{
					printf("��ѡ����Ҫ�޸ĵ�ѡ�\n");
					printf("1.����\t2.���\t3.�Ա�\t4.����\t5.��ʷ\n");
					int n;
					scanf("%d",&n);
					switch(n)
					{
						case 1:
						{
							char name[10];
							printf("��Ҫ���޸ĵ�����Ϊ%s",stu[i].name);
							printf("�������µ����֣�\n");
							scanf("%s",name);
							strcpy(stu[i].name, name);
							printf("�޸ĳɹ���");
							break;
						}
						case 2:
						{
							int no;
							printf("��Ҫ���޸ĵı��Ϊ%d",stu[i].no);
							printf("�������µı�ţ�\n");
							scanf("%d",&no);
							stu[i].no = no;
							printf("�޸ĳɹ���");
							break;
						}
						case 3:
						{
							char sex[10];
							printf("��Ҫ���޸ĵ��Ա�Ϊ%s",stu[i].sex);
							printf("�������µ��Ա�\n");
							scanf("%s",sex);
							strcpy(stu[i].sex, sex);
							printf("�޸ĳɹ���");
							break;
						}
						case 4:
						{
							int age;
							printf("��Ҫ���޸ĵ�����Ϊ%d",stu[i].age);
							printf("�������µ����䣺\n");
							scanf("%d",&age);
							stu[i].age = age;
							printf("�޸ĳɹ���");
							break;
						}
						case 5:
						{
							char inf[100];
							printf("��Ҫ���޸ĵĲ�ʷΪ%s",stu[i].inf);
							printf("�������µĲ�ʷ��\n");
							scanf("%s",inf);
							strcpy(stu[i].inf, inf);
							printf("�޸ĳɹ���");
							break;
						}

					}
					break;
				}
			}
			write(stu, len);
			break;
		}
		case 2:
		{
			printf("��ѧ�������޸�\n");
			printf("��������Ҫ�޸�ѧ��������:\n");
			char name[10];
			scanf("%s",name);
			fflush(stdin);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(strcmp(name, stu[i].name) == 0)
				{
					printf("��ѡ����Ҫ�޸ĵ�ѡ�\n");
					printf("1.����\t2.���\t3.�Ա�\t4.����\t5.��ʷ\n");
					int n;
					scanf("%d",&n);
					switch(n)
					{
						case 1:
						{
							char name[10];
							printf("��Ҫ���޸ĵ�����Ϊ%s",stu[i].name);
							printf("�������µ����֣�\n");
							scanf("%s",name);
							strcpy(stu[i].name, name);
							printf("�޸ĳɹ���");
							break;
						}
						case 2:
						{
							int no;
							printf("��Ҫ���޸ĵı��Ϊ%d",stu[i].no);
							printf("�������µı�ţ�\n");
							scanf("%d",&no);
							stu[i].no = no;
							printf("�޸ĳɹ���");
							break;
						}
						case 3:
						{
							char sex[10];
							printf("��Ҫ���޸ĵ��Ա�Ϊ%s",stu[i].sex);
							printf("�������µ��Ա�\n");
							scanf("%s",sex);
							strcpy(stu[i].sex, sex);
							printf("�޸ĳɹ���");
							break;
						}
						case 4:
						{
							int age;
							printf("��Ҫ���޸ĵ�����Ϊ%d",stu[i].age);
							printf("�������µ����䣺\n");
							scanf("%d",&age);
							stu[i].age = age;
							printf("�޸ĳɹ���");
							break;
						}
						case 5:
						{
							char inf[100];
							printf("��Ҫ���޸ĵĲ�ʷΪ%s",stu[i].inf);
							printf("�������µĲ�ʷ��\n");
							scanf("%s",inf);
							strcpy(stu[i].inf, inf);
							printf("�޸ĳɹ���");
							break;
						}

					}
					break;
					}
				}
            write(stu, len);
			break;
			}
		default:
			printf("�����������\n");
			fflush(stdin);
			break;
		}
	return 0;
}
int add(Student *stu, int *len)
{
	int count;
	Student std;
	printf("����Ҫ��Ӽ�����Ϣ��");
	scanf("%d",&count);
	int i;
	for(i = 0; i < count; i++)
	{
		printf("������� %d ��ѧ������Ϣ\n",i+1);
		printf("����(1000):");
		scanf("%d",&std.no);
		fflush(stdin);
		printf("����:");
		scanf("%s",std.name);
		fflush(stdin);
		printf("�Ա�:");
		scanf("%s",&std.sex);
		fflush(stdin);
		printf("����:");
		scanf("%d",&std.age);
		fflush(stdin);
		printf("��ʷ:");
		scanf("%s",&std.inf);
		fflush(stdin);

		if(*len < 100)                            //100Ϊ���鳤��
		{
			stu[*len] = std;                      //����ӵ�ѧ����Ϣ�洢�������У����ȼ�һ
			(*len)++;
		}
	}
	FILE *fp = fopen("data.txt","ab+");            //�ļ���д��
	if(fp == NULL)
	{
		printf("�򿪻򴴽��ļ�ʧ��\n");
		return -1;
	}
	int j;
	for(j = *len-count; j < *len; j++)
	{
		fwrite(&stu[j], sizeof(Student), 1, fp);
		if(ferror(fp))
		{
			printf("�ļ�д��ʧ��\n");
			return -1;
		}
	}
	fclose(fp);                                    //�ļ�д�����

    //���ӣ�����֮����û��ֱ����д�õ�write��������Ϊ�����ļ���д�뷽ʽΪ��ab+������write������д�뷽ʽΪ��wb+����ǰ��Ϊ��ӣ�����Ϊ���ǣ������������ֿ�����

	return 0;
}
int del(Student *stu, int *len)
{
	while(1)
	{
		printf("----------------ɾ����Ϣ��ʽѡ��---------------\n\n");
		printf("\t\t1 ͨ�����ɾ��\n");
		printf("\t\t2 ͨ������ɾ��\n");
		printf("---------------------------------------------------\n");
		printf("��ѡ����Ҫʹ�õķ�ʽ��1/2����");
		int i;
		scanf("%d",&i);
		fflush(stdin);
		if(i == 1)
		{
			int no;
			printf("������Ҫɾ���ı�ţ�\n");
			scanf("%d",&no);
			int j,m = *len+10;
			for(j = 0; j < *len; j++)
			{
				if(stu[j].no == no)
				{
					m = j;
					for(m; m < *len-1; m++)
					{
						stu[m] = stu[m+1];
						j--;
					}
					(*len)--;
					write(stu,len);
				}
			}
			if(m > *len)
			{
				printf("����������δ���ҵ����[ %d ]\n",no);
			}
			else
			{
				break;
			}
		}
		else if(i == 2)
		{
			printf("��������Ҫɾ��������:\n");
			char name[10];
			scanf("%s",name);
			int i,m = *len+10;
			for(i = 0; i < *len; i++)
			{
				if(strcmp(name, stu[i].name) == 0)
				{
					m = i;
					for(m; m < *len-1; m++)
					{
						stu[m] = stu[m+1];
						i--;
					}
					(*len)--;
					write(stu,len);
				}
			}
			if(m > *len)
			{
				printf("�����������δ���ҵ�����[ %s ]\n",name);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("�������ݲ��Ϸ���������ѡ��:\n");
			fflush(stdin);
		}
	}
	return 0;
}int read (Student *stu, int *len);
int seek(Student *stu, int *len)
{
	printf("��������Ҫ��ѯ�ķ�ʽ\n");
	printf("-----1.��������ѯ------\n");
	printf("-----2.����Ų�ѯ------\n");
	int number;
	scanf("%d",&number);
	switch(number)
	{
		case 1:
		{
			printf("��������ѯ\n");
			printf("��������Ҫ��ѯ������\n");
			char name[10];
			scanf("%s",name);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(strcmp(stu[i].name, name) == 0)
				{
					printf("���\t����\t�Ա�\t����\t��ʷ\tʱ��\n");
					printf("%d\t%s\t%s\t%d\t%s\t%d\t\n",stu[i].no, stu[i].name,
					stu[i].sex, stu[i].age, stu[i].inf, stu[i].latetime);
					break;
				}
			}
			break;
		}
		case 2:
		{
			printf("����Ų�ѯ\n");
			printf("��������Ҫ��ѯ�ı��\n");
			int no;
			scanf("%d",&no);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(stu[i].no == no)
				{
					printf("���\t����\t�Ա�\t����\t��ʷ\tʱ��\n");
					printf("%d\t%s\t%s\t%d\t%s\t%d\t\n",stu[i].no, stu[i].name,
					stu[i].sex, stu[i].age, stu[i].inf, stu[i].latetime);
					break;
				}
			}
			break;
		}
	}
	return 0;
}

int read(Student stu[],int *m){
    ifstream ifile("data.txt",ios::in|ios::binary);
	int n;
	if (!ifile){
		cout<<"Failure to open data.txt!\n";
		exit(0);
	}
    ifile.read((char*)&m,sizeof(int));  //��ȡ��Ŀ��
	for (n=0;!ifile.eof(); n++) //���ļ���δ���������ȡһ����¼����n����ѧ����Ŀ
	{
	    ifile.read( (char*)&stu[n],sizeof(Student) );
	}
	ifile.close();
	cout<<"Total datas is "<<n<<endl; /* ����ļ��е�ѧ����¼�� */
	return n-1; /* ����ѧ����¼�� */
}
Student stu[100];								//����洢ѧ�����ݵ�����
int len = 0;

int main(void)
{
	read(stu,&len);								//���ļ���������stu[]��
	int number;
	while(1)
	{
        time_t timep;
        time(&timep);
        printf("%s",asctime( gmtime(&timep) ) );
        printf("1����Ǽ�2ɾ��3��ѯ4����\n��ѡ����Ҫִ�еĲ�����\n");
		scanf("%d",&number);
		switch(number)
		{
			case 1: add(stu, &len);
			break;          //�����Ϣ����
			case 2: del(stu, &len);
			break;			//ɾ����Ϣ����
			case 3: seek(stu, &len);
			break;			//��ѯ��Ϣ����
			//case 4: sort(stu, &len); break;			//ͳ����Ϣ����
			case 4: modify(stu, &len);
			break;		//�޸���Ϣ����
			//case 6: print(stu, &len); break;		//��ӡ��Ϣ����
			case 9: return 0;	//�˳�����
			case 0:exit(1);
			default:
			{
				printf("����������ݲ��Ϸ������������룡\n");
			 	fflush(stdin);
			 	break;
			}
		}
	}
	return 0;
}

