#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"telebook_def.h"

Telebook *Tele_Insert(Telebook *head,Telebook *s)
{
	Telebook *s1,*s2;
	if(head==NULL)/*������ǰΪ������*/
	{
		head=s;
		s->next=NULL;
		return head;
	}
	s2=s1=head;
	while(strcmp(s->num,s1->num)>0 && s1->next!=NULL)/*Ѱ�Ҵ�����λ��*/
	{
		s2=s1;
		s1=s1->next;
		            /*s1ָ���һ����㣬s2ָ��s1ָ��Ľ��֮ǰ*/
	}
	if(strcmp(s->num,s1->num)<=0)/*����s1֮ǰ*/
	{
		s->next=s1;
		if(head==s1) 
			head=s;             /*���������ײ�*/
		else
			s2->next=s;          /*���������м�*/
	}
	else                        /*��������β���֮��*/
	{
		s1->next=s;
		s->next=NULL;
	}
	return head;
}

Telebook *Create()/*�������������������������ָ��*/                                                                               
{
	Telebook *p,*head=NULL;
	char num[4],name[10],phonenum[15],email[20];
	int a;
	printf("������һ�����֣��������-1�����˳���");
	scanf("%d",&a);
	while(a!=-1)
	{
		printf("������һ����¼��\n");
	    scanf("%s%s%s%s",num,name,phonenum,email);
	    p=(Telebook *) malloc(sizeof(Telebook));
	    strcpy(p->num,num);
        strcpy(p->name,name);
	    strcpy(p->phonenum,phonenum);
	    strcpy(p->email,email);
	    head=Tele_Insert(head,p);
	    printf("ȷ���Ƿ�������һ����¼�����������������-1��������������һ�����֣�\n��");
        scanf("%d",&a);
	}
    return head;
}

void Display(Telebook *head)/*��������������ݣ�ÿ10����ͣһ��*/
{
	Telebook *p;
	int i=0;
	p=head;
	printf("����绰����¼��\n");
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
	printf("������������¼��\n");
	scanf("%s%s%s%s",num,name,phonenum,email);
	p=(Telebook *) malloc(sizeof(Telebook));
	strcpy(p->num,num);
    strcpy(p->name,name);
	strcpy(p->phonenum,phonenum);
	strcpy(p->email,email);
	head=Tele_Insert(head,p);
	printf("�ɹ�����һ����¼��\n");
	return head;
}

Telebook *Delete(Telebook *head,char *num)
{
	Telebook *p1,*p2;
	if(head==NULL)        /*����Ϊ��*/
	{
		printf("����Ϊ�ա�\n");
		return NULL;
	}
	p1 = head; p2 = p1;
	while(strcmp(p1->num,num)!=0 && p1->next!=NULL) /*ѭ�����Ҵ�ɾ����*/
	{
		p2=p1;
		p1=p1->next;     /*p1���Ų��һ����㣬p2ָ��p1ָ��Ľ��֮ǰ*/
	}
	if(strcmp(p1->num,num)==0)        /*�ҵ���ɾ����㣬��p1ָ��*/
	{
		if(p1==head)                  /*���ҵ��Ľ�����׽��*/
			head=p1->next;
		else                          /*���ҵ��Ĳ����׽��*/
			p2->next=p1->next;
		printf("���Ϊ%s�ļ�¼��ɾ����\n",p1->num);
		free(p1);
	}
	else      /*δ�ҵ���ɾ�����*/
		printf("���Ϊ%s�ļ�¼δ�ҵ���\n",p1->num);
	return head;
}

Telebook *Delete_a_record(Telebook *head)
{
	char num[4];
	printf("��������Ҫɾ���ļ�¼��š�\n");
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
			return p;                  /*���ҵ����򷵻ظý��ָ��*/
		else 
			p=p->next;
	}
	return NULL;                       /*���Ҳ������򷵻ؿ�ָ��*/
}

void Query_a_record(Telebook *head)
{
	char num[4];
	Telebook *p;
	printf("��������Ҫ���ҵļ�¼��š�\n");
	scanf("%s",num);
	p=Query(head,num);
	if(p!=NULL)
	{
		printf("�ɹ��ҵ����Ϊ%s�ļ�¼��\n",num);
		printf("%s\t%s\t%s\t%s\n",p->num,p->name,p->phonenum,p->email);
	}
	else
		printf("δ�ܳɹ��ҵ����Ϊ%s�ļ�¼��\n",num);
}

Telebook *AddfromText(Telebook *head,char *filename)
{
	Telebook *p;
	FILE *fp;
	int n,i;
	p=(Telebook *)malloc(sizeof(Telebook));
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("���ܴ򿪸��ļ���\n");
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
		printf("���ܴ򿪸��ļ���\n");
		exit(1);
	}
	p=head;
	if(p==NULL)
		printf("������Ϊ�գ�\n");
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
	if(head==NULL)              /*������ǰΪ������*/
	{
		head=s;
		s->next=NULL;
		return head;
	}
	s2=s1=head;
	while(strcmp(s->name,s1->name)<0 && s1->next!=NULL)/*Ѱ�Ҵ�����λ��*/
	{
		s2=s1;
		s1=s1->next;
		            /*s1ָ���һ����㣬s2ָ��s1ָ��Ľ��֮ǰ*/
	}
	if(strcmp(s->num,s1->num)>=0)/*����s1֮ǰ*/
	{
		s->next=s1;
		if(head==s1) 
			head=s;             /*���������ײ�*/
		else
			s2->next=s;          /*���������м�*/
	}
	else                        /*��������β���֮��*/
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
		printf("���ܴ򿪸��ļ���\n");
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

