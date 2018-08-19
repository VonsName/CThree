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

	//读到文件末尾返回-1
	//int a=fgetc(fp);
	//如果是文本文件 EOF 结束符 
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
	//feof()判断是否是文件结尾 是返回true
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
	// r -> 如果文件不存在,打开失败
	//w ->如果文件不存在,则创建,存在则清空里面的内容再打开
	//a ->如果文件不存在就创建,如果存在光标自动移动到文件末尾
	//a+ w+ r+表示可读可写
	fp = fopen("C:\\Users\\vons0\\Desktop\\2.txt", "a");
	if (fp == NULL) {
		perror("open");
		printf("%s", "失败");
		return -1;
	}
	printf("%s", "success");

	//fputc(),一次只能写一个字符
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);

	fclose(fp);//关闭文件
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

//第一个成员如果没有赋值,默认为0,下一个成员一次递增1
enum MyColor
{
	RED,
	YELLOW,
	BLUE,
	BLACK
};

//联合体(共用体)
//共用体的大小是最大成员 的大小
//共用体是公用一块内存,所有成员的地址都一样
union Book
{
	unsigned int no;
	unsigned short b;
	unsigned char ch;
	//double d;//8字节 32位编译器
};

//结构体的大小可以简单的认为是所有成员的大小累加
struct Teacher
{
	int age;
	int score;
	char *name;
};

//ps:sizeof()是计算类型在内存中所占的字节数
  //:strlen() 只是计算字符串的长度,要计算字节数还的乘以每个字符的字节大小
int main7()
{
	
	printf("Book sizeof=%d\n", sizeof(union Book));//输出8-> 是最大成员Int类型的大小
	printf("Teacher sizeof=%d\n", sizeof(struct  Teacher));//输出12 所有成员大小的累加和

	////共用体是公用一段内存,所有成员的地址都一样
	//改变其中一个成员的地址,其他成员的地址也会受到影响
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

	//枚举常量
	enum MyColor c;
	c = BLACK;
	//typedef 发生在编译阶段
	//宏定义发生在预处理阶段
	typedef int x;
	x m = 10;
	return 0;
}

int main6()
{
	struct Teacher* t;
	t = (struct Teacher*)malloc(sizeof(struct Teacher));
	t->name = (char *)malloc(strlen("mike")+1);//字符串使用strlen,+1是因为要多预留一个字节保存\0
	//t->name = "mike"; 这样赋值不用在上面分配内存 这样是相当于直接把"mike"的首地址赋值给t->name
	strcpy(t->name, "mike");
	t->age = 23;
	t->score = 99;
	printf("%d %s %d", t->age, t->name, t->score);

	//释放内存的时候,从子元素开始释放,和分配内存的时候相反
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
	strcpy(pX[0].name, "李四");
	pX[0].score = 23;

	(pX + 1)->age = 25;
	strcpy((pX + 1)->name, "王五");
	(pX + 1)->score = 30;

	(*(pX + 2)).age = 35;
	strcpy((*(pX + 2)).name, "赵六");
	(*(pX + 2)).score = 99;

	struct Student* pY= pX;
	(pY + 3)->age = 55;
	strcpy((pY + 3)->name, "利好");
	(pY + 3)->score = 88;

	pY[4].age = 18;
	strcpy(pY[4].name, "王二麻子");
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
