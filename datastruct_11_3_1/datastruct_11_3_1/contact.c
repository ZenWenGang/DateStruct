#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
#include"SList.h"
// 初始化通讯录
void LoadContact(contact* con)
{
	//打开文件
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen fail！");
		return;
	}
	//定义通讯录变量
	PeoInfo info;
	//依次读取文件数据
	while (fread(&info, sizeof(info), 1, pf))
	{
		//将文件数据尾插到通讯录中
		SLTPushBack(con, info);
	}
	printf("历史通讯录数据导入成功！\n");
	//关闭文件
	fclose(pf);
}
void InitContact(contact** con)//实际调⽤的是链表的初始化接⼝（可以简单做⼀个头结点的初始化）
{
	LoadContact(con);
}
//添加通讯录数据
void AddContact(contact** con)//  链表尾插/头插
{
	PeoInfo info;
	printf("请输入要添加的联系人姓名：");
	scanf("%s", info.name);
	printf("请输入要添加的联系人性别：");
	scanf("%s", info.sex);
	printf("请输入要添加的联系人年龄：");
	scanf("%d", &info.age);
	printf("请输入要添加的联系人电话：");
	scanf("%s", info.tel);
	printf("请输入要添加的联系人地址：");
	scanf("%s", info.addr);
	SLTPushBack(con, info);//传到链表实现好的“尾插”
	printf("添加联系人成功！\n");
}
//查找姓名
contact* FindByName(contact* con, char name[])
{
	contact* cur = con;
	while (cur)
	{
		if (0==strcmp(name,con->data.name))//不能把0放后面
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//删除通讯录数据
void DelContact(contact** con)//链表的删除指定位置的数据
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人的姓名：");
	scanf("%s", name);
	contact* pos=FindByName(*con, name);
	if (pos == NULL)
	{
		printf("你要删除的联系人姓名不存在！\n");
		return;
	}
	SLTErase(con, pos);//传到链表实现好的“删除pos节点”
	printf("删除成功！\n");
}
//展⽰通讯录数据
void ShowContact(contact* con)//链表的打印
{
	printf("%3s %4s %4s %4s %4s\n", "姓名", "性别", "年龄", "电话", "地址");
	contact* cur = con;
	while (cur)
	{
		printf("%3s %4s %4d %4s %4s\n",
			cur->data.name,
			cur->data.sex,
			cur->data.age,
			cur->data.tel,
			cur->data.addr
		);
		cur = cur->next;
	}
}
//查找通讯录数据
void FindContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名：");
	scanf("%s", name);
	contact* bro = FindByName(*con, name);
	if (bro == NULL)
	{
		printf("你要查找的联系人姓名不存在！\n");
		return;
	}
	printf("找到了！\n");
	printf("%3s %4s %4s %4s %4s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%3s %4s %4d %4s %4s\n",
		bro->data.name,
		bro->data.sex,
		bro->data.age,
		bro->data.tel,
		bro->data.addr
	);
}
//修改通讯录数据
void ModifyContact(contact** con)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：");
	scanf("%s", name);
	contact* pos = FindByName(*con, name);
	if (pos == NULL)
	{
		printf("你要修改的联系人不存在！");
			return;
	}
	printf("请输入要修改的姓名:");
	scanf("%s", pos->data.name);
	printf("请输入要修改的性别:");
	scanf("%s", pos->data.sex);
	printf("请输入要修改的年龄:");
	scanf("%d", &pos->data.age);
	printf("请输入要修改的电话:");
	scanf("%s", pos->data.tel);
	printf("请输入要修改的地址:");
	scanf("%s", pos->data.addr);

	printf("修改成功！\n");
}
//保存通讯录数据
void SaveContact(contact* con)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen fail!");
		return;
	}
	contact* cur = con;
	while (cur)
	{
		fwrite(&(cur->data), sizeof(PeoInfo), 1, pf);
		cur = cur->next;
	}
	printf("保存成功！\n");
	fclose(pf);
}
//销毁通讯录数据
void DestroyContact(contact** con)
{
	SaveContact(*con);
	SListDesTroy(con);
}