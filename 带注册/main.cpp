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


void Login();//ע���¼����
void UI();//���溯��
void Create(banji *L);//��������
void Showdata(banji *L);//�鿴����
void Deletedata(banji *L);//ɾ������
void Alter(banji *L);//�޸ĺ���
void Save(banji *L);//���溯��
void Load(banji *L);//��ȡ����


int main()//������
{
	int z;
    int n;
    banji *L=(banji*)malloc(sizeof(banji));
	L->length = 0;
	Login();
start:
	UI();
    printf("   �����빦��ǰ����ţ�\n");
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
            printf("   �����������ҷ��Ϲ淶����ţ�\n");
			goto start;
        }
		while(1)
		{
		printf("\n     �����ɹ���");
		printf("\n     1.�������˵�");
		printf("\n     2.ֱ���˳�");
		printf("\n     ���������:");
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
			printf("\n   �����������ҷ��Ϲ淶����ţ�\n");
		}
		}
    return 0;
}


void Login()//ע���¼����
{
	FILE *fp;
	char str[2][10];
	char idpw[2][10];
	//str����������ַ����Ķ�ά����
	int i,a,n=2;
	int times = 0;
	printf("   �����µ��û��������룬�ûس��ָ���\n");	//��ʾ�����ַ���
	for(i=0;i<n;i++) 
		gets(str[i]);			//�����ַ���
	if((fp=fopen("D:\\SystemAdmin.txt","w"))==NULL)	//�򿪴����ļ�
	{
		printf("   ���ļ�ʧ�ܣ�\n");
		exit(0);
	}
	printf("\n�����ɹ���\n");
	for(i=0;i<n;i++)
	{	fputs(str[i],fp);fputs("\n",fp);
		//������ļ�дһ���ַ�����Ȼ�����һ�����з�
	}
	while(1)
	{
		if(times == 4)
		{
			printf("   ��¼�������࣬ϵͳ���Զ��˳���\n");
			exit(0);
			}
		printf("   �����������ʻ��������룬�ûس��ָ���\n");
		for(a=0;a<n;a++)
		{
			gets(idpw[a]);
		}
		if(strcmp(idpw[0],str[0])!=0)
		{
			printf("   �û���������!\n");
			times++;
			printf("   ����%d���������\n",4-times);
		}
		else if(strcmp(idpw[0],str[0])==0 && strcmp(idpw[1],str[1])!=0)
		{
			printf("   �������\n");
			times++;
			printf("   ����%d���������\n",4-times);	
		}
		else if(strcmp(idpw[0],str[0])==0 && strcmp(idpw[1],str[1])==0)
		{
			printf("   ��¼�ɹ���\n");
			break;
		}
	}
}


void UI()//���溯��
{
	printf("*****************************************|\n");
	printf("|                                        |\n");
	printf("|            ɽ�ƴ�ѧ������ϵͳ          |\n");
	printf("|                                        |\n");
	printf("|      �༶���������ѧ�뼼��1701��      |\n");
	printf("|                                        |\n");
	printf("|          1.�鿴����ѧ��������Ϣ        |\n");
	printf("|          2.���ѧ��������Ϣ            |\n");
	printf("|          3.�������޸�ѧ��������Ϣ      |\n");
	printf("|          4.ɾ��ѧ��������Ϣ            |\n");
	printf("|          5.���浽���ش���              |\n");
	printf("|          6.�ӱ��ش��̶�ȡ              |\n");
	printf("|          0.�˳�                        |\n");
	printf("|                                        |\n");
	printf("******************************************\n");
}


void Create(banji *L)//��������
{
    int n;
	printf("   ϵͳ������%d������\n",L->length);
    printf("   ������Ҫ��ӵ�ѧ��������\n");
    scanf("%d",&n);
    for(int i=L->length; i<L->length+n; i++)
    {
		printf("   ������ѧ��ѧ�ţ�\n");
		scanf("%d", &L->stu[i].id);
	    printf("   ������ѧ��������\n");
	    scanf("%s", L->stu[i].name);
     	printf("   ������ѧ���Ա�\n");
    	scanf("%s", L->stu[i].sex);
    	printf("   ������ѧ���ɼ���\n");
    	scanf("%d", &L->stu[i].score);
    }
    L->length += n;
}


void Showdata(banji *L)//�鿴����
{
	printf("            ѧ����Ϣ                \n");
	printf("  ѧ��  |  ����  |  �Ա�  |  �ɼ� \n");
    for(int i=0; i<L->length; i++)
    {
        printf("  %d   |   %s   |   %s   |   %d\n",L->stu[i].id,L->stu[i].name,L->stu[i].sex,L->stu[i].score);
    }
}


void Deletedata(banji *L)//ɾ������
{
	
	int x = 0;
    ElemType temp;
    int k;
	int number;
    char name1[10];
	while (1)
	{
		printf("\n    ��ѡ��:");
		printf("\n    1.��ѧ��ɾ��");
		printf("\n    2.������ɾ��");
		printf("\n    ���������:");
		scanf("%d", &x);
		if (x == 1 || x == 2)
			break;
		else
			printf("\n   �����������ҷ��Ϲ淶����ţ�");
	}
	if (x == 1)
	{
		printf("   ������Ҫɾ����ѧ����ѧ�ţ�\n");
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
		printf("   ������Ҫɾ����ѧ����������\n");
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


void Alter(banji *L)//�޸ĺ���
{
	int i;
	int x = 0;
	int number;
	while(1)
	{
		printf("\n   �����롰0�������޸ģ�");
		printf("\n    ������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
		scanf("%d", &number);
		if(number == 0)
		{
			goto endalter;
		}
		for(i = 0;i<=L->length-1;i++)
		{
			if (L->stu[i].id==number)
			{
				printf("\n     ��ѧ����Ϣ���£�");
				goto startalter;
			}
			else
			{
				printf("\n    ��ѧ�Ų����ڣ�\n");
			}
		}
	}
startalter:
	printf("\n  -----------------------------------------------");
	printf("\n  | ѧ��:%d  |����:%s  |�Ա�:%s  |�ɼ�:%d | ",
		    L->stu[i].id, L->stu[i].name, L->stu[i].sex, L->stu[i].score);
	printf("\n  -----------------------------------------------");
	printf("\n     ��ѡ��:");
	printf("\n     1.�޸�ѧ��");
	printf("\n     2.�޸�����");
	printf("\n     3.�޸��Ա�");
	printf("\n     4.�޸ĳɼ�");
	printf("\n     0.�˳��޸�");
	printf("\n     ���������:");
	scanf("%d", &x);
	if (x == 1)
	{
		printf("\n     �������޸ĺ��ѧ��:");
		scanf("%d", &L->stu[i].id);
	}
	else if (x == 2)
	{
		printf("\n     �������޸ĺ������:");
		scanf("%s", L->stu[i].name);
	}
	else if (x == 3)
	{
		printf("\n     �������޸ĺ���Ա�:");
		scanf("%s", L->stu[i].sex);
	}
	else if (x == 4)
	{
		printf("\n     �������޸ĺ�ĳɼ�:");
		scanf("%d", &L->stu[i].score);
	}
	else if (x == 0)
	{
		printf("\n     �����˳��޸�...");
		goto endalter;
	}
	else
	{
		printf("\n     �����������ҷ��Ϲ淶����ţ�\n");
		goto startalter;
	}
endalter:
	printf("\n");
}


void Save(banji *L)//���溯��
{
	int i;
	printf("   ��������%d��ѧ������...\n",L->length);
	FILE *fp;
	if((fp=fopen("D:\\SystemData.txt","w"))==NULL)	//������ļ�
	{	
		printf("   ���ļ�ʧ�ܣ�\n");
		return;
	}
	for(i=0;i<L->length;i++)
	{
		
		int a = fprintf(fp,"%d %s %s %d\n", L->stu[i].id, L->stu[i].name, L->stu[i].sex,L->stu[i].score);
		if(a<0)
		{
			printf("   ����ʧ�ܣ�\n");
			return;
		}
	}
	fclose(fp);
	printf("   ����ɹ���·����D:\\\\SystemData.txt",L->length);
}


void Load(banji *L)//��ȡ����
{
	int i ;
	int row = 0;
	int flag = 0;
	printf("   ��ȡ����D:\\\\SystemData.txt�е�����...\n");
	FILE *fp;
	FILE *fp1;
	if((fp=fopen("D:\\SystemData.txt","r"))==NULL)	//������ļ�
	{	
		printf("   ���ļ�ʧ�ܣ�\n");
		return;
	}
	while(!feof(fp))
	{
		flag = fgetc(fp);
		if(flag == '\n')
		row++;
	}
	if((fp1=fopen("D:\\SystemData.txt","r"))==NULL)	//������ļ�
	{	
		printf("   ���ļ�ʧ�ܣ�\n");
		return;
	}
	for(i = 0;i<row;i++)
	{
		int a = fscanf(fp1,"%d %s %s %d\n", &L->stu[i].id, L->stu[i].name, L->stu[i].sex, &L->stu[i].score);
		if(a<0)
		{
			printf("   ��ȡʧ�ܣ�\n");
		}
	}
	fclose(fp);
	L->length = row;
	printf("   �ɹ���ȡ%d��ѧ�����ݣ��뷵�����˵��鿴��\n",L->length);
}