#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct Person 加起来才是结构体类型
//结构体内定义的变量 不能直接赋值
//结构体只是一个类型,没有定义变量前没有分配内存空间,不能赋值
struct Person
{
	int age;
	char name[50];
	float score;
}p5 = {19,"mkei",23.0}, p3;//同时定义变量(全局变量)

int main3(int argc,char *argv[])
{
	//定义结构体变量
	struct Person stu;


	//结构体变量初始化和数组一样 使用{},并且只有在定义的时候才能初始化
	struct Person p1 = {18,"marry",99.0};

	struct Person p2;
	p2.age = 18;
	//p2.name = "mike";// error->  name是数组名,它是一个常量,不能修改
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
	fun1(p);//这里是值传递 p=NULL,函数结束栈区的内存释放,p还是NULL
	printf("%d\n", *p);//段错误
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