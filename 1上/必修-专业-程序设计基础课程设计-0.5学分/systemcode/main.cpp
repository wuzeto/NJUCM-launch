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
}Student;                                //定义存储一个信息的结构体
int write(Student *stu, int *len)
{
	FILE *fp = fopen("data.txt","wb");
	if(fp == NULL)
	{
		printf("打开或创建文件失败\n");
		return -1;
	}
	int j;
	for(j = 0; j < *len ; j++)
	{
		fwrite(&stu[j], sizeof(Student), 1, fp);
		if(ferror(fp))
		{
			printf("文件写入失败\n");
			return -1;
		}
	}
	fclose(fp);
}
int modify(Student *stu, int *len)
{
	printf("-----------修改菜单信息----------\n");
	printf("---------1.按编号修改---------\n");
	printf("---------2.按姓名修改---------\n");
	printf("请选择修改编号(1/2):\n");
	int number;
	scanf("%d",&number);
	switch(number)
	{
		case 1:
		{
			printf("按编号修改\n");
			printf("请输入你要修改的编号:\n");
			int no;
			scanf("%d",&no);
			fflush(stdin);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(no == stu[i].no)
				{
					printf("请选择你要修改的选项：\n");
					printf("1.姓名\t2.编号\t3.性别\t4.年龄\t5.病史\n");
					int n;
					scanf("%d",&n);
					switch(n)
					{
						case 1:
						{
							char name[10];
							printf("需要被修改的名字为%s",stu[i].name);
							printf("请输入新的名字：\n");
							scanf("%s",name);
							strcpy(stu[i].name, name);
							printf("修改成功！");
							break;
						}
						case 2:
						{
							int no;
							printf("需要被修改的编号为%d",stu[i].no);
							printf("请输入新的编号：\n");
							scanf("%d",&no);
							stu[i].no = no;
							printf("修改成功！");
							break;
						}
						case 3:
						{
							char sex[10];
							printf("需要被修改的性别为%s",stu[i].sex);
							printf("请输入新的性别：\n");
							scanf("%s",sex);
							strcpy(stu[i].sex, sex);
							printf("修改成功！");
							break;
						}
						case 4:
						{
							int age;
							printf("需要被修改的年龄为%d",stu[i].age);
							printf("请输入新的年龄：\n");
							scanf("%d",&age);
							stu[i].age = age;
							printf("修改成功！");
							break;
						}
						case 5:
						{
							char inf[100];
							printf("需要被修改的病史为%s",stu[i].inf);
							printf("请输入新的病史：\n");
							scanf("%s",inf);
							strcpy(stu[i].inf, inf);
							printf("修改成功！");
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
			printf("按学生姓名修改\n");
			printf("请输入你要修改学生的姓名:\n");
			char name[10];
			scanf("%s",name);
			fflush(stdin);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(strcmp(name, stu[i].name) == 0)
				{
					printf("请选择你要修改的选项：\n");
					printf("1.姓名\t2.编号\t3.性别\t4.年龄\t5.病史\n");
					int n;
					scanf("%d",&n);
					switch(n)
					{
						case 1:
						{
							char name[10];
							printf("需要被修改的名字为%s",stu[i].name);
							printf("请输入新的名字：\n");
							scanf("%s",name);
							strcpy(stu[i].name, name);
							printf("修改成功！");
							break;
						}
						case 2:
						{
							int no;
							printf("需要被修改的编号为%d",stu[i].no);
							printf("请输入新的编号：\n");
							scanf("%d",&no);
							stu[i].no = no;
							printf("修改成功！");
							break;
						}
						case 3:
						{
							char sex[10];
							printf("需要被修改的性别为%s",stu[i].sex);
							printf("请输入新的性别：\n");
							scanf("%s",sex);
							strcpy(stu[i].sex, sex);
							printf("修改成功！");
							break;
						}
						case 4:
						{
							int age;
							printf("需要被修改的年龄为%d",stu[i].age);
							printf("请输入新的年龄：\n");
							scanf("%d",&age);
							stu[i].age = age;
							printf("修改成功！");
							break;
						}
						case 5:
						{
							char inf[100];
							printf("需要被修改的病史为%s",stu[i].inf);
							printf("请输入新的病史：\n");
							scanf("%s",inf);
							strcpy(stu[i].inf, inf);
							printf("修改成功！");
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
			printf("数据输入错误\n");
			fflush(stdin);
			break;
		}
	return 0;
}
int add(Student *stu, int *len)
{
	int count;
	Student std;
	printf("您需要添加几个信息：");
	scanf("%d",&count);
	int i;
	for(i = 0; i < count; i++)
	{
		printf("请输入第 %d 个学生的信息\n",i+1);
		printf("号吗(1000):");
		scanf("%d",&std.no);
		fflush(stdin);
		printf("姓名:");
		scanf("%s",std.name);
		fflush(stdin);
		printf("性别:");
		scanf("%s",&std.sex);
		fflush(stdin);
		printf("年龄:");
		scanf("%d",&std.age);
		fflush(stdin);
		printf("病史:");
		scanf("%s",&std.inf);
		fflush(stdin);

		if(*len < 100)                            //100为数组长度
		{
			stu[*len] = std;                      //将添加的学生信息存储到数组中，长度加一
			(*len)++;
		}
	}
	FILE *fp = fopen("data.txt","ab+");            //文件的写入
	if(fp == NULL)
	{
		printf("打开或创建文件失败\n");
		return -1;
	}
	int j;
	for(j = *len-count; j < *len; j++)
	{
		fwrite(&stu[j], sizeof(Student), 1, fp);
		if(ferror(fp))
		{
			printf("文件写入失败\n");
			return -1;
		}
	}
	fclose(fp);                                    //文件写入完成

    //附加：这里之所以没有直接用写好的write函数是因为这里文件的写入方式为“ab+”，而write函数中写入方式为“wb+”，前者为添加，后者为覆盖，所以这里区分开来。

	return 0;
}
int del(Student *stu, int *len)
{
	while(1)
	{
		printf("----------------删除信息方式选择---------------\n\n");
		printf("\t\t1 通过编号删除\n");
		printf("\t\t2 通过姓名删除\n");
		printf("---------------------------------------------------\n");
		printf("请选择你要使用的方式（1/2）：");
		int i;
		scanf("%d",&i);
		fflush(stdin);
		if(i == 1)
		{
			int no;
			printf("请输入要删除的编号：\n");
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
				printf("编号输入错误，未查找到编号[ %d ]\n",no);
			}
			else
			{
				break;
			}
		}
		else if(i == 2)
		{
			printf("请输入你要删除的姓名:\n");
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
				printf("姓名输入错误，未查找到姓名[ %s ]\n",name);
			}
			else
			{
				break;
			}
		}
		else
		{
			printf("输入数据不合法，请重新选择:\n");
			fflush(stdin);
		}
	}
	return 0;
}int read (Student *stu, int *len);
int seek(Student *stu, int *len)
{
	printf("请输入你要查询的方式\n");
	printf("-----1.按姓名查询------\n");
	printf("-----2.按编号查询------\n");
	int number;
	scanf("%d",&number);
	switch(number)
	{
		case 1:
		{
			printf("按姓名查询\n");
			printf("请输入你要查询的姓名\n");
			char name[10];
			scanf("%s",name);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(strcmp(stu[i].name, name) == 0)
				{
					printf("编号\t姓名\t性别\t年龄\t病史\t时间\n");
					printf("%d\t%s\t%s\t%d\t%s\t%d\t\n",stu[i].no, stu[i].name,
					stu[i].sex, stu[i].age, stu[i].inf, stu[i].latetime);
					break;
				}
			}
			break;
		}
		case 2:
		{
			printf("按编号查询\n");
			printf("请输入你要查询的编号\n");
			int no;
			scanf("%d",&no);
			int i;
			for(i = 0; i < *len; i++)
			{
				if(stu[i].no == no)
				{
					printf("编号\t姓名\t性别\t年龄\t病史\t时间\n");
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
    ifile.read((char*)&m,sizeof(int));  //读取科目数
	for (n=0;!ifile.eof(); n++) //若文件流未结束，则读取一条记录，用n计算学生数目
	{
	    ifile.read( (char*)&stu[n],sizeof(Student) );
	}
	ifile.close();
	cout<<"Total datas is "<<n<<endl; /* 输出文件中的学生记录数 */
	return n-1; /* 返回学生记录数 */
}
Student stu[100];								//定义存储学生数据的数组
int len = 0;

int main(void)
{
	read(stu,&len);								//将文件读入数组stu[]中
	int number;
	while(1)
	{
        time_t timep;
        time(&timep);
        printf("%s",asctime( gmtime(&timep) ) );
        printf("1首诊登记2删除3查询4复诊\n请选择您要执行的操作：\n");
		scanf("%d",&number);
		switch(number)
		{
			case 1: add(stu, &len);
			break;          //添加信息函数
			case 2: del(stu, &len);
			break;			//删除信息函数
			case 3: seek(stu, &len);
			break;			//查询信息函数
			//case 4: sort(stu, &len); break;			//统计信息函数
			case 4: modify(stu, &len);
			break;		//修改信息函数
			//case 6: print(stu, &len); break;		//打印信息函数
			case 9: return 0;	//退出程序
			case 0:exit(1);
			default:
			{
				printf("您输入的数据不合法，请重新输入！\n");
			 	fflush(stdin);
			 	break;
			}
		}
	}
	return 0;
}

