#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct Person ���������ǽṹ������
//�ṹ���ڶ���ı��� ����ֱ�Ӹ�ֵ
//�ṹ��ֻ��һ������,û�ж������ǰû�з����ڴ�ռ�,���ܸ�ֵ
struct Person
{
	int age;
	char name[50];
	float score;
}p5 = {19,"mkei",23.0}, p3;//ͬʱ�������(ȫ�ֱ���)

int main3(int argc,char *argv[])
{
	//����ṹ�����
	struct Person stu;


	//�ṹ�������ʼ��������һ�� ʹ��{},����ֻ���ڶ����ʱ����ܳ�ʼ��
	struct Person p1 = {18,"marry",99.0};

	struct Person p2;
	p2.age = 18;
	//p2.name = "mike";// error->  name��������,����һ������,�����޸�
	strcpy(p2.name, "mike");
	p2.score = 99.9;

	struct Person *p;
	p = &p2;
	p->age = 23;
	strcpy(p->name, "mk");
	p->score = 23;

	printf("%d %s %f", p5.age, p5.name, p5.score);
	return 0;
}



void fun1(int *tmp)
{
	tmp = (int *)malloc(sizeof(int));
	*tmp = 100;
}

int main1()
{
	int *p = NULL;
	fun1(p);//������ֵ���� p=NULL,��������ջ�����ڴ��ͷ�,p����NULL
	printf("%d\n", *p);//�δ���
	return 0;
}




void funOO(int **tmp)
{
	*tmp = (int *)malloc(sizeof(int));
	*(*tmp) = 100;
}

int main2()
{
	int a = 10;
	int *p = &a;
	funOO(&p);
	printf("%d\n", *p);
	printf("%d\n", a);
	return 0;
}