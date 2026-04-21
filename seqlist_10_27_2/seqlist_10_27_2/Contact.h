#pragma once
#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100
//定义联系人数据结构
//姓名 性别 年龄 电话 地址
typedef struct personinfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoinfo;

//要用到顺序表相关的方法，对通讯录的操作实际就是对顺序表进行操作
typedef struct Seqlist Contact;//给顺序表改个名字，叫做通讯录
//不能使用顺序表定义之后叫的名字‘SL',因为不能交叉包含头文件“Seqlist.h”所以它找不到’SL‘
// 只能使用顺序表最初始的结构：’struct Seqlist‘

//通讯录的相关方法

//通讯录的初始化
void Contactinit(Contact* con);
//通讯录的销毁
void ContactDestroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//通讯录查找数据
void ContactFind(Contact* con);
//展示通讯录
void ContactShow(Contact* con);