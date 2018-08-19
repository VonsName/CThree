#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void write_file()
{
	FILE *fp = NULL;
	fp = fopen("C:\\Users\\vons0\\Desktop\\3.txt", "w");
	if (fp == NULL)
	{
		perror("open");
		return -1;
	}

	char ch = 'a';
	while (ch < 'z')
	{
		fputc(ch, fp);
		ch++;
	}

	fclose(fp);
}

void read_file()
{
	FILE *fp = NULL;
	fp = fopen("C:\\Users\\vons0\\Desktop\\3.txt", "r");
	if (fp == NULL)
	{
		perror("open");
		return -1;
	}

	//�����ļ�ĩβ����-1
	//int a=fgetc(fp);
	//������ı��ļ� EOF ������ 
	/*while (a!=EOF)
	{
		fputc(a, stdout);
		a = fgetc(fp);
	}
*/
	//while (1)
	//{
	//	if (feof(fp))
	//	{
	//		break;
	//	}
	//	fputc(a, stdout);
	//	a = fgetc(fp);
	//}

	char ch= fgetc(fp);
	//feof()�ж��Ƿ����ļ���β �Ƿ���true
	while (!feof(fp))
	{
		fputc(ch, stdout);
		ch = fgetc(fp);
	}


	fclose(fp);
}

int main10()
{
	//write_file();
	read_file();
	return 0;
}

int main9()
{
	FILE *fp=NULL;
	// r -> ����ļ�������,��ʧ��
	//w ->����ļ�������,�򴴽�,�������������������ٴ�
	//a ->����ļ������ھʹ���,������ڹ���Զ��ƶ����ļ�ĩβ
	//a+ w+ r+��ʾ�ɶ���д
	fp = fopen("C:\\Users\\vons0\\Desktop\\2.txt", "a");
	if (fp == NULL) {
		perror("open");
		printf("%s", "ʧ��");
		return -1;
	}
	printf("%s", "success");

	//fputc(),һ��ֻ��дһ���ַ�
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);

	fclose(fp);//�ر��ļ�
	fp = NULL;
	return 0;
}


int main8()
{
	printf("%s\n", "before");
	close(1);
	int fd = open("C:\\Users\\vons0\\Desktop\\1.txt",O_WRONLY,0777);
	printf("%s\n", "after");
	printf("%d\n", fd);
	return 0;
}

//��һ����Ա���û�и�ֵ,Ĭ��Ϊ0,��һ����Աһ�ε���1
enum MyColor
{
	RED,
	YELLOW,
	BLUE,
	BLACK
};

//������(������)
//������Ĵ�С������Ա �Ĵ�С
//�������ǹ���һ���ڴ�,���г�Ա�ĵ�ַ��һ��
union Book
{
	unsigned int no;
	unsigned short b;
	unsigned char ch;
	//double d;//8�ֽ� 32λ������
};

//�ṹ��Ĵ�С���Լ򵥵���Ϊ�����г�Ա�Ĵ�С�ۼ�
struct Teacher
{
	int age;
	int score;
	char *name;
};

//ps:sizeof()�Ǽ����������ڴ�����ռ���ֽ���
  //:strlen() ֻ�Ǽ����ַ����ĳ���,Ҫ�����ֽ������ĳ���ÿ���ַ����ֽڴ�С
int main7()
{
	
	printf("Book sizeof=%d\n", sizeof(union Book));//���8-> ������ԱInt���͵Ĵ�С
	printf("Teacher sizeof=%d\n", sizeof(struct  Teacher));//���12 ���г�Ա��С���ۼӺ�

	////�������ǹ���һ���ڴ�,���г�Ա�ĵ�ַ��һ��
	//�ı�����һ����Ա�ĵ�ַ,������Ա�ĵ�ַҲ���ܵ�Ӱ��
	union Book bxx;
	printf("%p %p %p %p\n", &bxx, &bxx.b, &bxx.ch, &bxx.no);
	bxx.ch = 0x44332211;
	printf("%x\n", bxx.ch);
	printf("%x\n", bxx.b);
	printf("%x\n", bxx.no);

	bxx.ch = 0xcc;
	printf("%x\n", bxx.ch);
	printf("%x\n", bxx.b);
	printf("%x\n", bxx.no);

	//ö�ٳ���
	enum MyColor c;
	c = BLACK;
	//typedef �����ڱ���׶�
	//�궨�巢����Ԥ����׶�
	typedef int x;
	x m = 10;
	return 0;
}

int main6()
{
	struct Teacher* t;
	t = (struct Teacher*)malloc(sizeof(struct Teacher));
	t->name = (char *)malloc(strlen("mike")+1);//�ַ���ʹ��strlen,+1����ΪҪ��Ԥ��һ���ֽڱ���\0
	//t->name = "mike"; ������ֵ��������������ڴ� �������൱��ֱ�Ӱ�"mike"���׵�ַ��ֵ��t->name
	strcpy(t->name, "mike");
	t->age = 23;
	t->score = 99;
	printf("%d %s %d", t->age, t->name, t->score);

	//�ͷ��ڴ��ʱ��,����Ԫ�ؿ�ʼ�ͷ�,�ͷ����ڴ��ʱ���෴
	if (t->name != NULL) {
		free(t->name);
		t->name = NULL;
	}
	if (t != NULL) {
		free(t);
		t = NULL;
	}
	return 0;
}


struct Info
{
	char hobby[50];
};

struct Student
{
	int age;
	struct Info info;
	char name[50];
	int score;
};



int main05()
{
	struct Student p[5] = {
		{18,"mkie",23.33},
		{ 18,"mkie",23.33 },
		{ 18,"mkie",23.33 },
		{ 18,"mkie",23.33 },
		{ 18,"mkie",23.33 },
	};
	int len = sizeof(p) / sizeof(*p);
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", (*(p + i)).age);
		printf("%s\n", (*(p + i)).name);
//		printf("%lf\n", (*(p + i)).score);
	}

	//char  a[65] = {"mike","marry"}; error
	return 0;
}


int main04()
{
	struct Student pX[5];
	pX[0].age = 23;
	strcpy(pX[0].name, "����");
	pX[0].score = 23;

	(pX + 1)->age = 25;
	strcpy((pX + 1)->name, "����");
	(pX + 1)->score = 30;

	(*(pX + 2)).age = 35;
	strcpy((*(pX + 2)).name, "����");
	(*(pX + 2)).score = 99;

	struct Student* pY= pX;
	(pY + 3)->age = 55;
	strcpy((pY + 3)->name, "����");
	(pY + 3)->score = 88;

	pY[4].age = 18;
	strcpy(pY[4].name, "��������");
	pY[4].score = 88;


	int len = sizeof(pX) / sizeof(*pX);
	for (int i=0;i<len;i++)
	{
		printf("%d\n", (*(pX + i)).age);
		printf("%s\n", (*(pX + i)).name);
		printf("%d\n", (*(pX + i)).score);
	}
	return 0;
}
