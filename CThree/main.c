#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#define SIZE 500


typedef struct User
{
	int age;
	char name[50];
	int score;
}User;

typedef struct Order
{
	int no;
	//�����ָ�����,д�ļ���ʱ��,ֻ�ǰ�ָ���ֵд��ȥ
	char *name;
	int len;
}Order;


void write_order()
{
	Order order;
	order.no = 12;
	order.len = strlen("�ɹ�");
	order.name = (char *)malloc(order.len+1);
	strcpy(order.name, "�ɹ�");

	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\2.txt", "w");
	fwrite(&order, 1, sizeof(Order), fp);
	//�ٽ�name��Ӧ��ֵд���ļ�
	fwrite(order.name, order.len, 1, fp);
	fclose(fp);
}

void read_order()
{
	Order order;
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\2.txt", "r");

	//�Ƚ��ṹ�������
	fread(&order, 1, sizeof(Order), fp);

	//���·���name�Ķ��ڴ��ַ
	order.name = (char *)malloc(order.len + 1);
	//�������
	memset(order.name, 0, order.len + 1);

	//�ٴζ�ȡname��ֵ
	int ret=fread(order.name, order.len, 1,fp);

	if (ret<0)
	{
		perror("read");
		return -1;
	}

	printf("%s\n", order.name);
	printf("%d\n", order.no);
	printf("%d\n", order.len);

	fclose(fp);
	free(order.name);
	order.name = NULL;
}
int main()
{
	//write_order();
	read_order();
	return 0;
}

int main012()
{
	struct stat st;
	stat("C:\\Users\\vons0\\Desktop\\1.txt", &st);
	printf("%ld\n", st.st_size);//�ļ���С
	printf("%ld\n", st.st_atime);

	//������
	rename("C:\\Users\\vons0\\Desktop\\1.txt", "C:\\Users\\vons0\\Desktop\\2.txt");
	//ɾ���ļ�
	remove("C:\\Users\\vons0\\Desktop\\2.txt");
	return 0;
}

int main011()
{
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\1.txt", "r");
	fseek(fp, 3, SEEK_SET);//���ļ���ʼ����ƫ��3��ƫ����
	//fseek(fp, 0, SEEK_SET);//�ص��ʼ��λ��
	rewind(fp);//�������Ч��һ��
	char buf[1024] = {0};
	fread(buf, 1, sizeof(buf), fp);
	printf("%s\n", buf);

	//�ļ�Ĭ�ϵ�ʱ���ǻ���������ʱ��Ż��Զ�ˢ�»�����
	//�����ļ��رյ�ʱ��
	//fflush(fp);//�ֶ�ˢ�»�����


	//����ƶ���ĩβ
	fseek(fp, 0, SEEK_END);
	//��ȡ�ļ��Ĵ�С
	long size = ftell(fp);
	printf("%ld", size);

	return 0;
}

//�߶ȱ�д
int main010(int argc, char *argv[])
{
	char buf[4 * 1024];
	//�����windowsƽ̨�¶�ȡ�������ļ�,Ҫ��r w ..�������b
	//�����Ĭ�ϰ����ı��ļ�������,�������ݶ�ʧ
	FILE *fp = fopen(argv[1], "rb");
	FILE *dest = fopen(argv[2], "wb");
	int len;
	while (1) {
		len = fread(buf, 1, sizeof(buf), fp);
		printf("%d\n", len);
		if (len == 0)
		{
			break;
		}
		fwrite(buf, 1, len, dest);
	}
	fclose(fp);
	fclose(dest);
	fp = NULL;
	return 0;
}


//ʵ��CP���� 
int main009(int argc,char *argv[])
{
	User u[4];
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\8.txt", "r");

	fread(u, 1, sizeof(User), fp);
	printf("%s %d %d", (*u).name, (*u).age, (*u).score);
	fclose(fp);
	fp = NULL;
	fp = fopen("C:\\Users\\vons0\\Desktop\\9.txt", "w");
	fwrite(&u, sizeof(User), 1,  fp);
	fclose(fp);
	return 0;
}

int main008()
{
	User u [4];
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\7.txt", "r");
	
	fread(u, sizeof(User), 1, fp);
	printf("%s %d %d", (*u).name, (*u).age, (*u).score);
	return 0;
}

//fwrite()
int main007()
{
	User u = { 23,"mike",88 };
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\7.txt", "w");
	//��һ��Ϊ���ݵ��׵�ַ,�ڶ�������Ϊ���ݵĿ��С,������Ϊ����Ŀ
	//�ܹ��ļ���С=���С*����Ŀ;
	fwrite(&u, sizeof(User), 1, fp);
	return 0;
}

int main006()
{
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\5.txt", "r+");
	int num = 0;
	fscanf(fp, "%d\n", &num);
	while (!feof(fp))
	{
		printf("%d ", num);
		fscanf(fp, "%d\n", &num);
	}
	
	return 0;
}

int main005()
{
	int n = 10;
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\5.txt", "w+");
	srand((unsigned int)time(NULL));
	int num = 0;
	for (int i=0;i<n;i++)
	{
		num = rand() % 100;
		fprintf(fp, "%d\n", num);
	}
	
	return 0;
}


void _rand()
{
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\num.txt", "w");
	srand((unsigned int)time(NULL));
	int i = 0;
	int num[SIZE];
	for (i;i<SIZE;i++)
	{
		int a=rand()%100;
		num[i] = a;
	}
	for (int j = 0; j < SIZE; j++)
	{
		for (int k=j;k<SIZE -1;k++)
		{
			if (num[j]>num[k+1])
			{
				int tmp = num[k+1];
				num[k + 1] = num[j];
				num[j] = tmp;
			}
		}
	}

	for (int i=0;i<500;i++)
	{
		int n = num[i];
		char buf[20];
		sprintf(buf, "%d\n", n);
		fputs(buf, fp);
	}
	fclose(fp);
}
void _read()
{
	char buf[1024];
	int tmp[500];
	FILE *fp=fopen("C:\\Users\\vons0\\Desktop\\num.txt", "r");
	fgets(buf, sizeof(buf), fp);
	int i = 0;
	while (!feof(fp))
	{
		int tmp1;
		sscanf(buf, "%d", &tmp1);
		//printf("%d\n", tmp1);
		tmp[i] = tmp1;
		i++;
		fgets(buf, sizeof(buf), fp);
	}
	int len = sizeof(tmp) / sizeof(int);
	for (int i=0;i<len;i++)
	{
		if (i==50)
		{
			printf("%s","\n");
		}
		printf("%d ", tmp[i]);
	}
	fclose(fp);
}
int main004()
{
	//_rand();
	_read();
	return 0;
}

int main003()
{
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\aa.txt", "r");
	char buf[1024];
	fgets(buf, sizeof(buf), fp);
	while (!feof(fp))
	{
		printf("%s", buf);
		fgets(buf, sizeof(buf), fp);
	}
	

	
	return 0;
}

//vi 
int main002(int agrc, char* argv[])
{
	FILE *fp = fopen(argv[1], "a");
	char buf[1024];
	while (1)
	{
		fgets(buf, sizeof(buf), stdin);
		if (strncmp(buf,":wq",3)==0)
		{
			break;
		}
		int i = 0;
		while (buf[i]!='\0')
		{
			fputc(buf[i], fp);
			i++;
		}
	}
	fclose(fp);
	return 0;
}

int main001(int argc,char *argv[])
{
	FILE *fp = fopen("C:\\Users\\vons0\\Desktop\\3.txt", "r");

	char ch = fgetc(fp);
	while (!(feof(fp)))
	{
		fputc(ch,stdout);
		ch = fgetc(fp);
	}

	fclose(fp);
	return 0;
}