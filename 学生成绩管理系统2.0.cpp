#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define Mi 3
int LZC=0;
struct Student
{
	int number;
	char name[20];
	int cla;
	float score[3];
	float Average;
	float Sum;
}stu[N];
void printHello()
{
	system("color f0");
	system("mode con cols=60 lines=15");
	printf("**********************************\n");
	printf("*         ��ӭ����               *\n*      ѧ���ɼ�����ϵͳ!         *\n");
	printf("**********************************\n");
	system("pause");
	system("CLS");
}
void inputRecord()
{
	int i;
	for (i = 0; i<3; i++)
	{
		printf("ѧ��:");scanf("%d", &stu[i].number);
		printf("�༶:"); scanf("%d", &stu[i].cla);
		printf("����:");scanf("%s", &stu[i].name);
		printf("����:");scanf("%f", &stu[i].score[0]);
		printf("Ӣ��:");scanf("%f", &stu[i].score[1]);
		printf("C����:");scanf("%f", &stu[i].score[2]);
		stu[i].Sum = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]);/*�����ܳɼ�*/
		printf("�ܳɼ�:%.2f", stu[i].Sum);
		stu[i].Average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;/*����ƽ���ɼ�*/
		printf("ƽ���ɼ�:%.2f\n", stu[i].Average);
	}
}
void inputDate()
{
	int p,lzc; printf("��Ҫ���뼸�����ݣ�\n");scanf("%d", &LZC);
	lzc = LZC + 2;
	printf("����������!\n");
	for (p = 0; p < LZC; p++)
	{
		printf("ѧ��:"); scanf("%d", &stu[lzc].number);
		printf("�༶:"); scanf("%d", &stu[lzc].cla);
		printf("����:"); scanf("%s", &stu[lzc].name);
		printf("����:"); scanf("%f", &stu[lzc].score[0]);
		printf("Ӣ��:"); scanf("%f", &stu[lzc].score[1]);
		printf("C����:"); scanf("%f", &stu[lzc].score[2]);
	}
	printf("�������!\n");
}
void queryNum()//��query�����а���ѧ�Ų�ѯ
{
	void OutputOneDate(int i);
	int i, j, k, x;
	char c = '1';
	while (c == '1')
	{
		k = -1;
		printf("\n������ѧ��ѧ��:");
		scanf("%d", &x);
		for (i = 0, j = 1; i<Mi; i++)
			if (stu[i].number == x)
			{
				k = i;//�ҵ�Ҫ��ѯ��ͬѧѧ��,����k�������±�
				printf("ѧ��%d����Ϣ:\n", j++);
				OutputOneDate(k);
				printf("\n�����������!\n");
				getchar();
			}
		printf("������ѯ����ѧ����Ϣ��?");
		printf("\n������ѯ�밴1���������밴2\n");
		c = getchar();
		getchar();
	}
	system("pause");
}
void queryName()//��query�����а���������ѯ
{
	void OutputOneDate(int i);
	int i, j, k;
	char xname[20], c = '1';
	while (c == '1')
	{
		k = -1;
		printf("\n������ѧ������:");
		gets(xname);
		for (i = 0, j = 1; i<Mi; i++)/*��ȷ��ѯ*/
			if (strcmp(stu[i].name, xname) == 0)
			{
				k = i;/*�ҵ�Ҫ��ѯ��ͬѧ����,����k�������±�*/
				printf("ѧ��%d����Ϣ:\n", j++);
				OutputOneDate(k);
				system("pause");
			}
		if (k == -1)/*k��ʾû�о�ȷ��ѯ���*/
		{
			printf("\nģ����ѯ�������:\n");
			for (i = 0, j = 1; i<Mi; i++)
				if (strstr(stu[i].name, xname) != NULL)/*ģ����ѯ*/
				{
					k = 1;
					printf("ѧ��%d����Ϣ:\n", j++);
					OutputOneDate(k);
					printf("\n�����������!\n");
					getchar();
				}
			if (j == 1)
				printf("\n��Ǹ!û�и�ѧ����Ϣ!\n");
		}
		printf("������ѯ����ѧ����Ϣ��?");
		printf("\n������ѯ�밴1���������밴2\n");
		c = getchar();
		getchar();
	}/*����while*/
	system("pause");
}
void query()                                                     //getRecord�����в�ѯѧ����Ϣ
{
	printf("��ѡ���ѯ��ʽ:\n1.����ѧ��\n2.��������\n");
	int i;
	scanf("%d", &i);
	if (i == 1)queryNum();
	else queryName();
}
int compareMax(float x, float y, float z)
{
	float Z,i;
	if (x >= 60)x = 0; if (y >= 60)y = 0; if (z >= 60)z = 0;
	if (x > y) Z = x;
	else  Z = y;
	if (z > Z)Z = z;
	return(Z);
}
int compareMaxS(float x, float y, float z)
{
	float Z;
	if (x > y) Z = x;
	else  Z = y;
	if (z > Z)Z = z;
	return(Z);
}
int compareDate(float x, float y,float z,float n)
{
	int P;
	if (n == x)P = 0;
	else if (n == y)P = 1;
	else P = 2;
	return P;
}
int compareDateS(int x, int y, int z, int n)
{
	int P;
	if (n == x)P = 0;
	else if (n == y)P = 1;
	else P = 2;
	return P;
}
int compareDateSS(char x[20], char y[20], char z[20],char n[20])
{
	int P;
	if (n == x)P = 0;
	else if (n == y)P = 1;
	else P = 2;
	return P;
}
void maxFlulk()                                                 //getRecord�����в�ѯ��߷ֵĲ�����ѧ��
{
	void OutputOneDate(int i);
	printf("��ѡ��ѧ��:\n1.����\n2.Ӣ��\n3.C����\n");
	int i,M,P;
	scanf("%d", &i);
	switch (i)
	{
	case 1:M = compareMax(stu[0].score[0], stu[1].score[0], stu[2].score[0]);
		if (M == 0) { printf("�˿�Ŀû�в������"); break; }
		else P = compareDate(stu[0].score[0], stu[1].score[0], stu[2].score[0], M);
		OutputOneDate(P); break;
	case 2:M = compareMax(stu[0].score[1], stu[1].score[1], stu[2].score[1]);
		if (M == 0) { printf("�˿�Ŀû�в������"); break; }
		else P = compareDate(stu[0].score[1], stu[1].score[1], stu[2].score[1], M);
		OutputOneDate(P); break;
	case 3:M = compareMax(stu[0].score[2], stu[1].score[2], stu[2].score[2]);
		if (M == 0) { printf("�˿�Ŀû�в������"); break; }
		else P = compareDate(stu[0].score[2], stu[1].score[2], stu[2].score[2], M);
		OutputOneDate(P); break;
	default:printf("enter date error!!!");
	}
}
void getRecord()
{
	int i;
	printf("��ѡ����:\n1.��ѯѧ����Ϣ\n2.������߷ֵĲ�����ѧ��\n");
	scanf("%d", &i);
	if (i == 1)query();                                         //������ѯ��Ϣ
	else maxFlulk();                                            //����������߷ֵĲ�����ѧ��
}
void changeNum()
{
	int Num1,Num2,i;
	printf("������Ҫ���ĵ�ѧ��:");
	scanf("%d", &Num1);
	printf("��������ĺ��ѧ��:");
	scanf("%d", &Num2);
	i=compareDate(stu[0].number, stu[1].number, stu[2].number,Num1);
	if (i == 0)stu[0].number=Num2;
	else if(i==1)stu[1].number = Num2;
	else stu[2].number = Num2;
	printf("�޸���ɣ�\n");
	system("pause");
}
void changeCls()
{
	int Cla1,Cla2,i;
	printf("������Ҫ���ĵİ༶:");
	scanf("%d", &Cla1);
	printf("������Ҫ���ĵİ༶:");
	scanf("%d", &Cla2);
	i = compareDate(stu[0].cla, stu[1].cla, stu[2].cla, Cla1);
	if (i == 0)stu[0].cla = Cla2;
	else if (i == 1)stu[1].cla = Cla2;
	else stu[2].cla = Cla2;
	printf("�޸���ɣ�\n");
	system("pause");
}
void changeName()
{
	char Name1[20], Name2[20]; int i;
	printf("������Ҫ�ı������:"); scanf("%s", Name1);
	printf("������ı�������:"); scanf("%s", Name2);
	i = compareDateSS(stu[0].name, stu[1].name, stu[2].name, Name1);
	if (i == 0)strcpy(stu[0].name, Name2);
	else if(i==1)strcpy(stu[1].name, Name2);
	else strcpy(stu[2].name, Name2);
}
void changeScore(int x)
{
	int i; float score1, score2;
	printf("������Ҫ���ĵĳɼ�:");
	scanf("%f", &score1);
	printf("��������ĺ�ĳɼ�");
	scanf("%f", &score2);
	i = compareDate(stu[0].score[x], stu[1].score[x], stu[2].score[x], score1);
	if (i == 0)stu[0].score[x] = score2;
	else if (i == 1)stu[1].score[x] = score2;
	else stu[2].score[x] = score2;
	printf("�޸���ɣ�\n");
	system("pause");
}
void changeDate()            //�����޸��Ѿ����������
{
	int i;
	void exportRecord();
	exportRecord();
	printf("��ѡ����Ҫ�޸ĵ�����\n1.ѧ��\n2.�༶\n3.����\n4.�����ɼ�\n5.Ӣ��ɼ�\n6.C���Գɼ�\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:changeNum(); break;
	case 2:changeCls(); break;
	case 3:changeName(); break;
	case 4:changeScore(0); break;
	case 5:changeScore(1); break;
	case 6:changeScore(2); break;
	default:printf("enter date error!\n");
	}
}
void getAverage()
{
	float score1, score2, score3, score4;
	score1 = (stu[0].score[0] + stu[1].score[0] + stu[2].score[0]) / 3;
	score2= (stu[0].score[1] + stu[1].score[1] + stu[2].score[1]) / 3;
	score3= (stu[0].score[2] + stu[1].score[2] + stu[2].score[2]) / 3;
	score4 = (stu[0].score[0] + stu[1].score[0] + stu[2].score[0] + stu[0].score[1] + stu[1].score[1] + stu[2].score[1] + stu[0].score[2] + stu[1].score[2] + stu[2].score[2]) / 3;
	printf("����ƽ����:%.2f\nӢ��ƽ����:%.2f\nC����ƽ����:%.2f\n�ܷ�ƽ����:%.2f\n",score1, score2, score3, score4);
}
void getOrder()
{
	void OutputOneDate(int i);
	int i, j;/*��������*/
	struct Student temp;/*�м���� ����Ϊ�ṹ��*/
	if(stu[0].number>stu[1].number){temp=stu[0];stu[0]=stu[1];stu[1]=temp;}
	if(stu[0].number>stu[2].number){temp=stu[0];stu[0]=stu[2];stu[2]=temp;}
	if(stu[1].number>stu[2].number){temp=stu[1];stu[1]=stu[2];stu[2]=temp;}
	printf("\n������ѧ����Ϣ:\n");
	for (i = 0; i<Mi; i++)
	{
		OutputOneDate(i);
	}/*���������ѧ����Ϣ*/
}
void deleteOnedate()
{
	int i,o;
	printf("������Ҫɾ����Ϣ��ѧ��ѧ��:"); scanf("%d", &i);
	o = compareDateS(stu[0].number, stu[1].number, stu[2].number, i);
	if (o == 0)
	{
		stu[0].number = stu[0].cla  = 0;
		stu[0].name[20] = ' ';
		stu[0].score[0] = stu[0].score[1] = stu[0].score[2] = stu[0].Sum = stu[0].Average = 0;
	}
	else if (o == 1)
	{
		stu[1].number = stu[1].cla = 0;
		stu[1].name[20] = ' ';
		stu[1].score[0] = stu[1].score[1] = stu[1].score[2] = stu[1].Sum = stu[1].Average = 0;
	}
	else
	{
		stu[2].number = stu[2].cla = 0;
		stu[2].name[20] = ' ';
		stu[2].score[0] = stu[2].score[1] = stu[2].score[2] = stu[2].Sum = stu[2].Average = 0;
	}

}
void updateRecord()
{
	int i;
	printf("��ѡ����:\n1.�޸�ѧ����Ϣ\n2.��ѧ����ƽ����\n3.����ѧ������\n4.����ѧ���ɼ�\n5.ɾ��1��ѧ���ɼ�\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:changeDate(); break;
	case 2:getAverage(); break;
	case 3:getOrder(); break;
	case 4:inputDate(); break;
	case 5:deleteOnedate(); break;
	default:printf("enter date error!\n");
	}
}
void printCount(float x,float y,float z)
{
	int i = compareMaxS(x, y, z),j=0; float max;
	if (i == 0)max = x;
	else if (i == 1)max = y;
	else max = z;
	if (x < 60)j++;if (y < 60)j++;if (z < 60)j++;
	printf("�ÿƵ���߷�Ϊ%.2f,����������Ϊ%d\n", max, j);
}
void countRecord()
{
	printf("��ѡ��Ҫͳ�ƵĿ�Ŀ:\n1.����\n2.Ӣ��\n3.C����\n");
	int i; scanf("%d", &i);i -= 1;
	switch (i)
	{
	case 0:printCount(stu[0].score[i], stu[1].score[i], stu[2].score[i]); break;
	case 1:printCount(stu[0].score[i], stu[1].score[i], stu[2].score[i]); break;
	case 2:printCount(stu[0].score[i], stu[1].score[i], stu[2].score[i]); break;
	default:printf("enter date error!!!\n");
	}
}
void OutputOneDate(int i)
{
	printf("ѧ��:%d  �༶:%d  ����:%s\n", stu[i].number, stu[i].cla, stu[i].name);
	printf("����:%.2f  Ӣ��:%.2f  C����:%.2f  �ܷ�:%.2f  ƽ����:%.2f\n", stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].Sum, stu[i].Average);
}
int exportRecord()
{
	int i;
	FILE *p;
	p=fopen("ѧ������ϵͳ����.txt","a");
	printf("**********************************\n");
	for (i = 0; i < 3+LZC; i++){OutputOneDate(i);fprintf(p,"ѧ��%d �༶%d ����%s �����ɼ�%.2f Ӣ��ɼ�%.2f C���Գɼ�%.2f �ܷ�%.2f ƽ����%.2f\n",stu[i].number, stu[i].cla, stu[i].name,stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].Sum, stu[i].Average);}
	printf("���ݵ����ɹ������ڡ�ѧ������ϵͳ����.txt���в鿴����!\n");
	printf("**********************************\n");
}
void choose()
{
	printf("**********************************\n");
	printf("*   ����������ѡ���ܣ�         *\n");
	printf("*   1.���������¼ģ��           *\n*   2.���в�ѯ��¼ģ��           *\n*   3.���и��¼�¼ģ��           *\n*   4.����ͳ�Ƽ�¼ģ��           *\n*   5.���������¼ģ��           *\n*   6.����                       *\n*   7.ע������                   *\n");
	printf("**********************************\n");
	int i;
	scanf("%d", &i);
	switch (i)
	{
	case 1:inputRecord(); break;
	case 2:getRecord(); break;
	case 3:updateRecord(); break;
	case 4:countRecord(); break;
	case 5:exportRecord(); break;
	case 6:system("CLS"); break;
	case 7:printf("\n\n1.��������������ݲ��ɲ�ѯ�����������Ҫ�������롣\n2.ֻ���������ģ����ܽ����ݵ�����\n3.����巰�Ȩ���У�����Ϯ��������\n\n"); break;
	default:printf("There were some errors!\n");
	}
}
int main()
{
	void getRecord();
	printHello();
	while (true)
	{
		choose();
		int i;
		printf("***************************\n*    �Ƿ������           *\n*    1.��������           *\n*    2.�˳�ϵͳ           *\n***************************\n");
		scanf("%d", &i);
		if (i == 2)break;
	}
	return 0;
}
