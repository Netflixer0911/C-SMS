#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50


struct student
{
    int id;
    char name[10];
    char sex[5];
    int score;
};
typedef student ElemType;
struct banji
{
    ElemType stu[N+1];
    int length;
};


void Login();//注册登录函数
void UI();//界面函数
void Create(banji *L);//创建函数
void Showdata(banji *L);//查看函数
void Deletedata(banji *L);//删除函数
void Alter(banji *L);//修改函数
void Save(banji *L);//保存函数
void Load(banji *L);//读取函数


int main()//主函数
{
	int z;
    int n;
    banji *L=(banji*)malloc(sizeof(banji));
	L->length = 0;
	Login();
start:
	UI();
    printf("   请输入功能前的序号：\n");
    scanf("%d",&n);
        switch(n)
        {
        case 1:
            Showdata(L);break;           
        case 2:
			Create(L);break;
        case 3:
            Alter(L);break;
        case 4:
            Deletedata(L);break;
		case 5:
			Save(L);break;
		case 6:
			Load(L);break;
        case 0:
            exit(0);
        default:
            printf("   请输入已有且符合规范的序号！\n");
			goto start;
        }
		while(1)
		{
		printf("\n     操作成功！");
		printf("\n     1.返回主菜单");
		printf("\n     2.直接退出");
		printf("\n     请输入序号:");
		scanf("%d", &z);
		if(z == 1 )
		{
			goto start;
		}
		if(z == 2 )
		{
			exit(0);
		}
		else
		{
			printf("\n   请输入已有且符合规范的序号！\n");
		}
		}
    return 0;
}


void Login()//注册登录函数
{
	FILE *fp;
	char str[2][10];
	char idpw[2][10];
	//str是用来存放字符串的二维数组
	int i,a,n=2;
	int times = 0;
	printf("   输入新的用户名和密码，用回车分隔：\n");	//提示输入字符串
	for(i=0;i<n;i++) 
		gets(str[i]);			//输入字符串
	if((fp=fopen("D:\\SystemAdmin.txt","w"))==NULL)	//打开磁盘文件
	{
		printf("   打开文件失败！\n");
		exit(0);
	}
	printf("\n创建成功：\n");
	for(i=0;i<n;i++)
	{	fputs(str[i],fp);fputs("\n",fp);
		//向磁盘文件写一个字符串，然后输出一个换行符
	}
	while(1)
	{
		if(times == 4)
		{
			printf("   登录次数过多，系统已自动退出！\n");
			exit(0);
			}
		printf("   请输入您的帐户名及密码，用回车分隔：\n");
		for(a=0;a<n;a++)
		{
			gets(idpw[a]);
		}
		if(strcmp(idpw[0],str[0])!=0)
		{
			printf("   用户名不存在!\n");
			times++;
			printf("   还有%d次输入机会\n",4-times);
		}
		else if(strcmp(idpw[0],str[0])==0 && strcmp(idpw[1],str[1])!=0)
		{
			printf("   密码错误！\n");
			times++;
			printf("   还有%d次输入机会\n",4-times);	
		}
		else if(strcmp(idpw[0],str[0])==0 && strcmp(idpw[1],str[1])==0)
		{
			printf("   登录成功！\n");
			break;
		}
	}
}


void UI()//界面函数
{
	printf("*****************************************|\n");
	printf("|                                        |\n");
	printf("|            山财大学生管理系统          |\n");
	printf("|                                        |\n");
	printf("|      班级：计算机科学与技术1701班      |\n");
	printf("|                                        |\n");
	printf("|          1.查看所有学生个人信息        |\n");
	printf("|          2.添加学生个人信息            |\n");
	printf("|          3.查找与修改学生个人信息      |\n");
	printf("|          4.删除学生个人信息            |\n");
	printf("|          5.保存到本地磁盘              |\n");
	printf("|          6.从本地磁盘读取              |\n");
	printf("|          0.退出                        |\n");
	printf("|                                        |\n");
	printf("******************************************\n");
}


void Create(banji *L)//创建函数
{
    int n;
	printf("   系统中已有%d条数据\n",L->length);
    printf("   请输入要添加的学生人数：\n");
    scanf("%d",&n);
    for(int i=L->length; i<L->length+n; i++)
    {
		printf("   请输入学生学号：\n");
		scanf("%d", &L->stu[i].id);
	    printf("   请输入学生姓名：\n");
	    scanf("%s", L->stu[i].name);
     	printf("   请输入学生性别：\n");
    	scanf("%s", L->stu[i].sex);
    	printf("   请输入学生成绩：\n");
    	scanf("%d", &L->stu[i].score);
    }
    L->length += n;
}


void Showdata(banji *L)//查看函数
{
	printf("            学生信息                \n");
	printf("  学号  |  姓名  |  性别  |  成绩 \n");
    for(int i=0; i<L->length; i++)
    {
        printf("  %d   |   %s   |   %s   |   %d\n",L->stu[i].id,L->stu[i].name,L->stu[i].sex,L->stu[i].score);
    }
}


void Deletedata(banji *L)//删除函数
{
	
	int x = 0;
    ElemType temp;
    int k;
	int number;
    char name1[10];
	while (1)
	{
		printf("\n    请选择:");
		printf("\n    1.按学号删除");
		printf("\n    2.按姓名删除");
		printf("\n    请输入序号:");
		scanf("%d", &x);
		if (x == 1 || x == 2)
			break;
		else
			printf("\n   请输入已有且符合规范的序号！");
	}
	if (x == 1)
	{
		printf("   请输入要删除的学生的学号：\n");
		scanf("%d",&number);
		for(int i=0; i<L->length; i++)
		{
			if(L->stu[i].id== number)
			{
				temp=L->stu[i];
				k=i;
			}
		}
		for(int j=k; j<L->length-1; j++)
		{
			L->stu[j]=L->stu[j+1];
		}
		L->length--;
	}
	else if (x == 2)
	{
		printf("   请输入要删除的学生的姓名：\n");
		scanf("%s",name1);
		for(int i=0; i<L->length; i++)
		{
			if(strcmp(L->stu[i].name,name1)==0)
			{
				temp=L->stu[i];
				k=i;
			}
		}
		for(int j=k; j<L->length-1; j++)
		{
			L->stu[j]=L->stu[j+1];
		}
		L->length--;
	}
}


void Alter(banji *L)//修改函数
{
	int i;
	int x = 0;
	int number;
	while(1)
	{
		printf("\n   （输入“0”结束修改）");
		printf("\n    请输入要修改的学生的学号：");
		scanf("%d", &number);
		if(number == 0)
		{
			goto endalter;
		}
		for(i = 0;i<=L->length-1;i++)
		{
			if (L->stu[i].id==number)
			{
				printf("\n     该学生信息如下：");
				goto startalter;
			}
			else
			{
				printf("\n    此学号不存在！\n");
			}
		}
	}
startalter:
	printf("\n  -----------------------------------------------");
	printf("\n  | 学号:%d  |姓名:%s  |性别:%s  |成绩:%d | ",
		    L->stu[i].id, L->stu[i].name, L->stu[i].sex, L->stu[i].score);
	printf("\n  -----------------------------------------------");
	printf("\n     请选择:");
	printf("\n     1.修改学号");
	printf("\n     2.修改姓名");
	printf("\n     3.修改性别");
	printf("\n     4.修改成绩");
	printf("\n     0.退出修改");
	printf("\n     请输入序号:");
	scanf("%d", &x);
	if (x == 1)
	{
		printf("\n     请输入修改后的学号:");
		scanf("%d", &L->stu[i].id);
	}
	else if (x == 2)
	{
		printf("\n     请输入修改后的姓名:");
		scanf("%s", L->stu[i].name);
	}
	else if (x == 3)
	{
		printf("\n     请输入修改后的性别:");
		scanf("%s", L->stu[i].sex);
	}
	else if (x == 4)
	{
		printf("\n     请输入修改后的成绩:");
		scanf("%d", &L->stu[i].score);
	}
	else if (x == 0)
	{
		printf("\n     正在退出修改...");
		goto endalter;
	}
	else
	{
		printf("\n     请输入已有且符合规范的序号！\n");
		goto startalter;
	}
endalter:
	printf("\n");
}


void Save(banji *L)//保存函数
{
	int i;
	printf("   即将保存%d条学生数据...\n",L->length);
	FILE *fp;
	if((fp=fopen("D:\\SystemData.txt","w"))==NULL)	//打开输出文件
	{	
		printf("   打开文件失败！\n");
		return;
	}
	for(i=0;i<L->length;i++)
	{
		
		int a = fprintf(fp,"%d %s %s %d\n", L->stu[i].id, L->stu[i].name, L->stu[i].sex,L->stu[i].score);
		if(a<0)
		{
			printf("   保存失败！\n");
			return;
		}
	}
	fclose(fp);
	printf("   保存成功！路径：D:\\\\SystemData.txt",L->length);
}


void Load(banji *L)//读取函数
{
	int i ;
	int row = 0;
	int flag = 0;
	printf("   读取本地D:\\\\SystemData.txt中的数据...\n");
	FILE *fp;
	FILE *fp1;
	if((fp=fopen("D:\\SystemData.txt","r"))==NULL)	//打开输出文件
	{	
		printf("   打开文件失败！\n");
		return;
	}
	while(!feof(fp))
	{
		flag = fgetc(fp);
		if(flag == '\n')
		row++;
	}
	if((fp1=fopen("D:\\SystemData.txt","r"))==NULL)	//打开输出文件
	{	
		printf("   打开文件失败！\n");
		return;
	}
	for(i = 0;i<row;i++)
	{
		int a = fscanf(fp1,"%d %s %s %d\n", &L->stu[i].id, L->stu[i].name, L->stu[i].sex, &L->stu[i].score);
		if(a<0)
		{
			printf("   读取失败！\n");
		}
	}
	fclose(fp);
	L->length = row;
	printf("   成功读取%d条学生数据，请返回主菜单查看！\n",L->length);
}