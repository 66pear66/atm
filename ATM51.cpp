#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Account
{
	char name[100];
	char idCard[19];
	char tel[12];
	char username[100];
	char password[7];
	int money;
	
	struct Account *next;
};
typedef struct Account Account;

Account * head=NULL;//ָ��ͷ����ָ��
Account * tail=NULL;//ָ��β����ָ�� 
Account * curAccount=NULL;//ָ��ǰ��¼�˻���ָ�� 

void signUpC()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	printf("����������:\n");
	scanf("%s",newNodeP->name);
	
	printf("����������֤:\n");
	scanf("%s",newNodeP->idCard);
	
	printf("������绰:\n");
	scanf("%s",newNodeP->tel);
	
	printf("�������˺�:\n");
	scanf("%s",newNodeP->username);
	
	printf("����������:\n");
	scanf("%s",newNodeP->password);
	
	newNodeP->money=0;
	newNodeP->next=NULL;
	
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}	
	printf("�����ɹ�!\n");
}

void signUpE()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	
	printf("Please enter your name:\n");
	scanf("%s",newNodeP->name);
	
	printf("Please enter your idCard:\n");
	scanf("%s",newNodeP->idCard);
	
	printf("Please enter your tel:\n");
	scanf("%s",newNodeP->tel);
	
	printf("Please enter your username:\n");
	scanf("%s",newNodeP->username);
	
	printf("Please enter your password:\n");
	scanf("%s",newNodeP->password);
	
	newNodeP->money=0;
	newNodeP->next=NULL;
	
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	}
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	printf("Created successfully!\n");
}

//�ҵ�����1�����򷵻�0 
int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}

void updatePasswordC()
{
	char formerPassword[100]={'\0'};
	printf("����������룺");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("�����������룺");
		scanf("%s",curAccount->password);
		printf("�޸ĳɹ���\n");
	}
	else
	{
		printf("������󣡲����޸ģ�\n");
	}
}

void updatePasswordE()
{
	char formerPassword[100]={'\0'};
	printf("please enter your former password��");
	scanf("%s",formerPassword);
	if(strcmp(formerPassword,curAccount->password)==0)
	{
		printf("please enter your new password��");
		scanf("%s",curAccount->password);
		printf("Modified successfully��\n");
	}
	else
	{
		printf("The password is wrong and cannot be modefied��\n");
	}
}

void saveMoneyC()
{
	printf("���������");
	int money;
	scanf("%d",&money);
	if(money%100==0)
	{
		curAccount->money+=money;
		printf("���ɹ���\n");
	}
	else
	{
		printf("��������޷����");
	}
	
}
void saveMoneyE()
{
	printf("please enter the deposit amount��");
	int money;
	scanf("%d",&money);
	if(money%100==0)
	{
		curAccount->money+=money;
		printf("deposit successful��\n");
	}
	else
	{
		printf("the amount does not match,so the deposit cannot be made");
	}	
}

void drawMoneyC()
{
	printf("������ȡ���");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money&&money%100==0)
	{
		printf("ȡ��ɹ���\n");
		curAccount->money-=money;	
	}
	else
	{
		printf("����!ȡ��ʧ��\n");
	}	
}
void drawMoneyE()
{
	printf("please enter the withdrawal amount��");
	int money;
	scanf("%d",&money);
	if(money<=curAccount->money&&money%100==0)
	{
		printf("withdrawal successful��\n");
		curAccount->money-=money;	
	}
	else
	{
		printf("wiyhdrawal failed due to insufficient balance\n");
	}	
}

Account *otherAccount=NULL;
int findotherAccount(char otherusername[])
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->username,otherusername)==0)
		{
			otherAccount=curP;
			return 1;
		}
		curP=curP->next;
	} 
	return 0;
}
void transferC()
{
	printf("������ת���˻���");
	char otherusername[100];
	scanf("%s",otherusername);
	if(findotherAccount(otherusername))
	{
		printf("������ת�˽�");
		int money;
		scanf("%d",&money);
		if(money<=curAccount->money&&money%100==0)
		{
			curAccount->money-=money;
			otherAccount->money+=money;
			printf("ת�˳ɹ�");
		}
		else
		{
			printf("���㣬�޷�ת�ˣ�");
		}
	}	
	else
	{
		printf("�˻�����");
	}
}

void transferE()
{
	printf("please enter the transfer account��");
	char otherusername[100];
	scanf("%s",otherusername);
	if(findotherAccount(otherusername))
	{
		printf("please enter the transfer amount��");
		int money;
		scanf("%d",&money);
		if(money<=curAccount->money&&money%100==0)
		{			
			curAccount->money-=money;
			otherAccount->money+=money;
			printf("transfer succeeded!");
		}
		else
		{
			printf("Insufficient balance��unable to transfer��");
		}
	}	
	else
	{
		printf("Account error��");
	}
}

void homePageC()
{
	system("cls");
	printf("\n#################################################################################\n");
	printf("\n��                               * ��ӭʹ��  *                                 ��\n");
	printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");	
	printf("          |��|******|��|        �� �޸�����       �밴 1        |��|******|��|\n"); 
	printf("          |��|******|��|        �� ���ҵ��       �밴 2        |��|******|��|\n");
	printf("          |��|******|��|        �� ȡ��ҵ��       �밴 3        |��|******|��|\n"); 
	printf("          |��|******|��|        �� ת��ҵ��       �밴 4        |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
	printf("\n��                          *******************************                    ��\n");
	printf("\n#################################################################################\n");
	printf("\n\n\t\t##���������ѡ��");
	int gn;
	scanf("%d",&gn);
	if(gn==1)
	{
		updatePasswordC();
	}
	else if(gn==2)
	{
        saveMoneyC();
	}
	else if(gn==3)
	{
		drawMoneyC();
	}
	else if(gn==4)
	{
		transferC();
	}
	else
	{
		printf("�������");
	}
}

void homePageE()
{
	system("cls");
	printf("\n#################################################################################\n");
	printf("\n��                               *  welcome  *                                 ��\n");
	printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");	
	printf("          |��|******|��|        �� change the password     1        |��|******|��|\n"); 
	printf("          |��|******|��|        �� deposit by        input 2        |��|******|��|\n");
	printf("          |��|******|��|        �� withdraw by       input 3        |��|******|��|\n"); 
	printf("          |��|******|��|        �� transfer by       input 4        |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
	printf("\n��                          *******************************                    ��\n");
	printf("\n#################################################################################\n");
	printf("\n\n\t\t##input your option��");
	int gn;
	scanf("%d",&gn);
	if(gn==1)
	{
		updatePasswordE();
	}
	else if(gn==2)
	{
        saveMoneyE();
	}
	else if(gn==3)
	{
		drawMoneyE();
	}
	else if(gn==4)
	{
		transferE();
	}
	else
	{
		printf("Input error");
	}
}

void signInC()
{
	for(int i=0;i<3;i++)
	{
		Account a; 
		printf("��ӭ��¼\n");
		printf("�������˺ţ�\n");
		scanf("%s",a.username);
		
		printf("���������룺\n");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			homePageC();
			
			return;
		}
		else
		{
			printf("��¼ʧ��!\n");
		}
	} 
}

void signInE()
{
	int i;
	for(i=0;i<3;i++)
	{
		Account a;
		printf("Please enter your username:");
		scanf("%s",a.username);
		
		printf("Please enter your password:");
		scanf("%s",a.password);
		
		if(findAccount(a)==1)
		{
			homePageE();
			return;
		}
		else
		{
			printf("Login failed��\n");
		}
	}
}

/*
������ݼ��سɹ�����1
���򷵻�0 
*/

int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0; 
	}
	else
	{
		while(!feof(fp))
		{
			//������㣺�ڶ�������һ���ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP
			Account * newNodeP=(Account *)malloc(sizeof(Account)); 
			
			//��㸳ֵ������ʼ��
			newNodeP->next=NULL;
			fscanf(fp,"%s %s %d\n",newNodeP->username,newNodeP->password,&newNodeP->money);
			
			//���ӽ�㵽����
			if(head==NULL)
			{
				head=newNodeP;
				tail=newNodeP;
			}
			else
			{
				tail->next=newNodeP;
				tail=newNodeP;
			}
		}
		return 1;
	}
	fclose(fp);
}

void saveData()
{
	FILE* fp=fopen("D:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s %d\n",curP->username,curP->password,curP->money);
			curP=curP->next;
		}
	}
}

void showMenuC()
{
	system("cls");
	printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          |��|******|��|       �� ����        �밴 1         |��|******|��|\n"); 
	printf("          |��|******|��|       �� ��¼        �밴 2         |��|******|��|\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
	int n;
	scanf("%d",&n);
	
	if(n==1)
	{
		signUpC();
	}
	else if(n==2)
	{		
		signInC();
	}	
	else
	{
		printf("�������");
	}
}

void showMenuE()
{
	printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          |��|******|��|       �� signUp      input 1        |��|******|��|\n"); 
	printf("          |��|******|��|       �� signIn      input 2        |��|******|��|\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
	int n;
	scanf("%d",&n);
	
	if(n==1)
	{
		signUpE();
	}
	else if(n==2)
	{		
		signInE();		
	}
	else
	{
		printf("Input error��");
	}
}

int main()
{
	printf("\n#################################################################################\n");
	printf("\n          ����������������������������������������������������������������\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          |��|******|��|       �� ���ķ���    �밴 1         |��|******|��|\n"); 
	printf("          |��|******|��|       �� English     input2         |��|******|��|\n");
	printf("          |��|******|��|                                     |��|******|��|\n");
	printf("          ����������������������������������������������������������������\n");
	printf("\n#################################################################################\n");
	
	int language;
	scanf("%d",&language);
	if(language==1)
	{
		int status=loadData();
		if(status==1)
		{
			printf("���سɹ���\n");
			showMenuC();
		    saveData();
		}
		else
		{
			printf("����ʧ�ܣ�\n");
		}		
	}
	else if(language==2)
	{
		int status=loadData();
		if(status==1)
		{
			printf("Load successful��\n");
			showMenuE();
			saveData();
		}
		else
		{
			printf("failed to load��\n");
		}	
	}
	else
	{
		printf("�������\n");
		printf("Input error");
	}
	
	return 0;
} 