#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"telebook_def.h"

Telebook *Tele_Insert(Telebook *head,Telebook *s)
{
	Telebook *s1,*s2;
	if(head==NULL)/*若插入前为空链表*/
	{
		head=s;
		s->next=NULL;
		return head;
	}
	s2=s1=head;
	while(strcmp(s->num,s1->num)>0 && s1->next!=NULL)/*寻找待插入位置*/
	{
		s2=s1;
		s1=s1->next;
		            /*s1指向后一个结点，s2指向s1指向的结点之前*/
	}
	if(strcmp(s->num,s1->num)<=0)/*插在s1之前*/
	{
		s->next=s1;
		if(head==s1) 
			head=s;             /*插在链表首部*/
		else
			s2->next=s;          /*插在链表中间*/
	}
	else                        /*插在链表尾结点之后*/
	{
		s1->next=s;
		s->next=NULL;
	}
	return head;
}

Telebook *Create()/*创建有序链表，并返回链表的首指针*/                                                                               
{
	Telebook *p,*head=NULL;
	char num[4],name[10],phonenum[15],email[20];
	int a;
	printf("请输入一个数字（如果输入-1，则退出）");
	scanf("%d",&a);
	while(a!=-1)
	{
		printf("请输入一条记录：\n");
	    scanf("%s%s%s%s",num,name,phonenum,email);
	    p=(Telebook *) malloc(sizeof(Telebook));
	    strcpy(p->num,num);
        strcpy(p->name,name);
	    strcpy(p->phonenum,phonenum);
	    strcpy(p->email,email);
	    head=Tele_Insert(head,p);
	    printf("确认是否输入下一条记录（如果结束，请输入-1，否则输入任意一个数字）\n：");
        scanf("%d",&a);
	}
    return head;
}

void Display(Telebook *head)/*输出链表所有数据，每10个暂停一下*/
{
	Telebook *p;
	int i=0;
	p=head;
	printf("输出电话簿记录：\n");
	while(p!=NULL)
	{
		printf("%s\t%s\t%s\t%s\n",p->num,p->name,p->phonenum,p->email);
		p=p->next;
		i++;
		if(i%10==0)
		{system("pause");}
	}
}

Telebook *Insert_a_record(Telebook *head)
{
	char num[4],name[10],phonenum[15],email[20];
	Telebook *p;
	printf("请输入待插入记录：\n");
	scanf("%s%s%s%s",num,name,phonenum,email);
	p=(Telebook *) malloc(sizeof(Telebook));
	strcpy(p->num,num);
    strcpy(p->name,name);
	strcpy(p->phonenum,phonenum);
	strcpy(p->email,email);
	head=Tele_Insert(head,p);
	printf("成功插入一条记录！\n");
	return head;
}

Telebook *Delete(Telebook *head,char *num)
{
	Telebook *p1,*p2;
	if(head==NULL)        /*链表为空*/
	{
		printf("链表为空。\n");
		return NULL;
	}
	p1 = head; p2 = p1;
	while(strcmp(p1->num,num)!=0 && p1->next!=NULL) /*循环查找待删除点*/
	{
		p2=p1;
		p1=p1->next;     /*p1向后挪动一个结点，p2指向p1指向的结点之前*/
	}
	if(strcmp(p1->num,num)==0)        /*找到待删除结点，由p1指向*/
	{
		if(p1==head)                  /*若找到的结点是首结点*/
			head=p1->next;
		else                          /*若找到的不是首结点*/
			p2->next=p1->next;
		printf("编号为%s的记录已删除。\n",p1->num);
		free(p1);
	}
	else      /*未找到待删除结点*/
		printf("编号为%s的记录未找到。\n",p1->num);
	return head;
}

Telebook *Delete_a_record(Telebook *head)
{
	char num[4];
	printf("请输入想要删除的记录编号。\n");
	scanf("%s",num);
	head=Delete(head,num);
	return head;
}

Telebook *Query(Telebook *head,char *num)
{
	Telebook *p;
	p=head;
	while(p!=NULL)
	{
		if(strcmp(p->num,num)==0)
			return p;                  /*若找到，则返回该结点指针*/
		else 
			p=p->next;
	}
	return NULL;                       /*若找不到，则返回空指针*/
}

void Query_a_record(Telebook *head)
{
	char num[4];
	Telebook *p;
	printf("请输入想要查找的记录编号。\n");
	scanf("%s",num);
	p=Query(head,num);
	if(p!=NULL)
	{
		printf("成功找到编号为%s的记录：\n",num);
		printf("%s\t%s\t%s\t%s\n",p->num,p->name,p->phonenum,p->email);
	}
	else
		printf("未能成功找到编号为%s的记录：\n",num);
}

Telebook *AddfromText(Telebook *head,char *filename)
{
	Telebook *p;
	FILE *fp;
	int n,i;
	p=(Telebook *)malloc(sizeof(Telebook));
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("不能打开该文件！\n");
		exit(1);
	}
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",p->num);
		fscanf(fp,"%s",p->name);
		fscanf(fp,"%s",p->phonenum);
		fscanf(fp,"%s",p->email);
		head=Tele_Insert(head,p);
	}
	fclose(fp);
	return head;
}

void WritetoText(Telebook *head,char *filename)
{
	FILE *fp;
	Telebook *p;
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("不能打开该文件！\n");
		exit(1);
	}
	p=head;
	if(p==NULL)
		printf("该链表为空！\n");
	while(p!=NULL)
	{
		fprintf(fp,"%s",p->num);
		fprintf(fp,"%s",p->name);
		fprintf(fp,"%s",p->phonenum);
		fprintf(fp,"%s",p->email);
		p=p->next;
	}
	fclose(fp);
}

Telebook *Insertname(Telebook *head,Telebook *s)
{
	Telebook *s1,*s2;
	if(head==NULL)              /*若插入前为空链表*/
	{
		head=s;
		s->next=NULL;
		return head;
	}
	s2=s1=head;
	while(strcmp(s->name,s1->name)<0 && s1->next!=NULL)/*寻找待插入位置*/
	{
		s2=s1;
		s1=s1->next;
		            /*s1指向后一个结点，s2指向s1指向的结点之前*/
	}
	if(strcmp(s->num,s1->num)>=0)/*插在s1之前*/
	{
		s->next=s1;
		if(head==s1) 
			head=s;             /*插在链表首部*/
		else
			s2->next=s;          /*插在链表中间*/
	}
	else                        /*插在链表尾结点之后*/
	{
		s1->next=s;
		s->next=NULL;
	}
	return head;
}

Telebook *Reverse(Telebook *head)
{
	Telebook a,*p=&a;
	FILE *fp;
	if((fp=fopen("records.txt","r"))==NULL)
	{
		printf("不能打开该文件！\n");
		exit(1);
	}
	while(feof(fp)==0)
	{
		fscanf(fp,"%s",p->num);
		fscanf(fp,"%s",p->name);
		fscanf(fp,"%s",p->phonenum);
		fscanf(fp,"%s",p->email);
		head=Insertname(head,p);
		p=p->next;
	}
	fclose(fp);
	return head;
}

Telebook *DeleteSame(Telebook *head)
{
	Telebook *p1,*p2,*p3;
	p1=head;
	p3=p2=p1->next;
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			if(p2->name==p1->name && p2->phonenum==p1->phonenum && p2->email==p1->email)
			{
				p3->next=p2->next;
				p2=p2->next;
			}
			else
			{
				p3=p2;
				p2=p2->next;
			}
		}
		p1=p1->next;
		p3=p2=p1->next;
	}
    return head;
}

void free_list(Telebook *head)
{
	Telebook *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		free(p);
	}
}

int menu_select()
{
	char c;
	do
	{
		system("cls");
		printf("1.Create List\n");
		printf("2.Display All Records\n");
		printf("3.Insert a Record\n");
		printf("4.Delete a Record\n");
		printf("5.Query\n");
		printf("6.Add Records from a Text File\n");
		printf("7.Wirte to a Text File\n");
		printf("8.Reverse List\n");
		printf("9.Delete the Same Record\n");
		printf("0.Quit\n");
		printf("Input 1-9,0:");
		c=getchar();
	}
	while(c<'0'||c>'9');
	return(c-'0');
}

int main()
{
	Telebook *head=NULL ;
	Telebook *p;
	for( ; ; )
	{
		switch(menu_select())
		{
			case 1:
				head=Create();
				system("pause");
				break;
			case 2:
				Display(head);
				system("pause");
				break;
			case 3:
				head=Insert_a_record(head);
				system("pause");
				break;
			case 4:
				head=Delete_a_record(head);
				system("pause");
				break;
			case 5:
				Query_a_record(head);
				system("pause");
				break;
			case 6:
				head=AddfromText(head,"data.txt");
				system("pause");
				break;
			case 7:
				WritetoText(head,"records.txt");
				system("pause");
				break;
			case 8:
				p=head;
				WritetoText(head,"records.txt");
				free_list(head);
				head=Reverse(head);
				system("pause");
				break;
			case 9:
				head=DeleteSame(head);
				system("pause");
				break;
			case 0:
				printf("Goodbye!\n");
				system("pause");
				exit(0);
		}
	}
}

