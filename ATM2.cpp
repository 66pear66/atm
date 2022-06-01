#include<stdio.h>
#include<stdlib.h>

struct Account
{
	char username[100];
	char password[100];	
	
	struct Account * next;
};
typedef struct Account Account;

Account * head=NULL;//指向头结点 
Account * tail=NULL;//指向尾结点 

//加载成功返回1，否则返回0 
void loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//创建结点
			Account * newNode=(Account *)malloc(sizeof(Account)); 
			
			//结点初始化
			newNode->next=NULL;
			fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
			
			//添加结点到链表
			if(head==NULL)
			{
				head=newNode;
				tail=newNode;	
			} 
			else
			{
				tail->next=newNode;
				tail=newNode; 
			}
		}
		fclose(fp);
	} 
} 

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}
}

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w"); 
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s\t%s\n",curP->username,curP->password);
			curP=curP->next; 
		}
		fclose(fp);
	}
}

void signUp()
{
	Account * newNode=(Account *)malloc(sizeof(Account));
	newNode->next=NULL;
	printf("请输入账号：\n");
	scanf("%s",newNode->username);
	
	printf("请输入密码：\n");
	scanf("%s",newNode->password);
	
	tail->next=newNode;
	tail=newNode;
	
	printf("注册成功！\n");
}

int main()
{
	loadData();
	
	
	signUp();
	
	printLinkedList();
	
	
	saveData();
	
	return 0;
}
