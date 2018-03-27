#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct ListNode {  
	ElemType data;
	struct ListNode *next;
}ListNode,*pListNode;

status IntiaList(ListNode **L);// 建立链表 
status DestroyList(ListNode *L); //摧毁链表 
status ClearList(ListNode *L);//清空链表 
status ListEmpty(ListNode * L);//判空链表 
status ListLength(ListNode * L);//求链表长度 
status GetElem(ListNode *L, int i, ElemType *e); //获取指定元素 
status LocateElem(ListNode * L, ElemType e);//指定元素位置 
status PriorElem(ListNode * L, ElemType e, ElemType* pre);//指定元素前驱 
status NextElem(ListNode * L, ElemType cur_e, ElemType* next_e);//指定元素后继 
status ListInsert(ListNode **L, int i, ElemType e);//插入指定元素 
status ListDelete(ListNode **L, int i, ElemType* e);//删除指定元素 
status ListTrabverse(ListNode * L);//遍历链表 
status SaveFile(ListNode * L);//保存文件 
status LoadFile(ListNode **L);//读出文件 
status creat_kindlist(ListNode **L);//大量写入 

int main(void) 
{
	int op = 1, e,pre, next, m;
	ListNode *L;
	int i;
	while (op) {
		system("cls");
		system("color 1F");//系统命令，调颜色
		printf("\t\t********************************************************************\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                     ◆链表功能实现菜单 ◆                        *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                      0.退出系统                                  *\n");
		printf("\t\t*                      1.初始化表                                  *\n");
		printf("\t\t*                      2.销毁已有表                                *\n");
		printf("\t\t*                      3.清空已有表                                *\n");
		printf("\t\t*                      4.判定是否为空表                            *\n");
		printf("\t\t*                      5.求表的长度                                *\n");
		printf("\t\t*                      6.获取指定元素                              *\n");
		printf("\t\t*                      7.查找指定元素                              *\n");
		printf("\t\t*                      8.获得指定元素前驱                          *\n");
		printf("\t\t*                      9.获得指定元素后继                          *\n");
		printf("\t\t*                      10.插入指定元素                             *\n");
		printf("\t\t*                      11.删除指定元素                             *\n");
		printf("\t\t*                      12.遍历表                                   *\n");
		printf("\t\t*                      13.存入文件                                 *\n");
		printf("\t\t*                      14.读出文件                                 *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t********************************************************************\n\n");
		printf("\t\t                       请输入你的选择：");
		scanf("%d",&op); 
		switch (op)
		{
		case 1:
			//printf("\n----IntiaList功能待实现！\n");
			if (IntiaList(&L) == OK) 
				printf("线性表创建成功！\n");
			else 
				printf("线性表创建失败！\n");
			getchar();getchar();
			break;
		case 2:
			//printf("\n----DestroyList功能待实现！\n");
			if (DestroyList(L) == OK) 
				printf("线性表销毁成功！\n");
			else 
				printf("线性表销毁失败！\n");
			getchar();getchar();
			break;
		case 3:
			//printf("\n----ClearList功能待实现！\n");
			if (ClearList(L) == OK) 
				printf("线性表清空成功！\n");
			else 
				printf("线性表清空失败！\n");
			getchar();getchar();
			break;
		case 4:
			//printf("\n----ListEmpty功能待实现！\n");
			if (ListEmpty(L) == OK) 
				printf("线性表为空！\n");
			else 
				printf("线性表不为空！\n");
			getchar();getchar();
			break;
		case 5:
			//printf("\n----ListLength功能待实现！\n");
			printf("线性表长度为%d\n", ListLength(L));
			getchar();getchar();
			break;
		case 6:
			//printf("\n----GetElem功能待实现！\n");
			if (ListEmpty(L) == OK)
			{
				printf("表为空，不可进行该项操作\n");
				getchar();getchar();
			}
			else
			{
				printf("请输入要查询的数据的序数：");
				scanf("%d", &i);
				if (GetElem(L, i, &e) == OK) 
					printf("表中第%d个数据为%d\n", i, e);
				else 
					printf("查询失败！\n");
				getchar();getchar();
			}
			break;
		case 7:
			//printf("\n----LocateElem功能待实现！\n");
			if (ListEmpty(L) == OK)
			{
				printf("表为空，不可进行该项操作\n");
				getchar();getchar();
			}
			else
			{
				printf("请输入要查询的数据：\n");
				scanf("%d", &e);
				m = LocateElem(L, e);
				if (m != ERROR)
				{
					printf("L中第一个与查询数据相等的数据的位序为%d\n", m);
				}
				else
				{
					printf("该数据元素不存在！\n");
				}
				getchar();getchar();
			}
			break;
		case 8:
			if (ListEmpty(L) == OK)
			{
				printf("表为空，不可进行该项操作\n");
				getchar();getchar();
			}
			else
			{
				printf("请输入要查询的元素：");
				scanf("%d", &e);
				if (PriorElem(L, e, &pre) == OK) printf("前驱为%d\n", pre);
				else printf("此元素无前驱\n");
				getchar();getchar();
			}
			break;
		case 9:
			if (ListEmpty(L) == OK)
			{
				printf("表为空，不可进行该项操作\n");
				getchar();getchar();
			}
			else
			{
					printf("请输入要查询的元素：");
				scanf("%d", &e);
				if (NextElem(L, e, &next) == OK) printf("后继为%d\n", next);
				else printf("此元素无后继\n");
				getchar();getchar();
			}
			break;
		case 10:
			printf("请输入插入位置i：");
			scanf("%d", &i);
			printf("请输入数字e：");
			scanf("%d", &e);
			if (ListInsert(&L, i, e) == OK) 
				printf("线性表插入成功\n");
			else 
				printf("线性表插入失败\n");
			getchar();getchar();
			break;
		case 11:
			if (ListEmpty(L))
			{
				printf("表为空，不可进行该项操作\n");
				getchar();getchar();
			}
			else
			{
				printf("请输入要删除的元素的序列：");
				scanf("%d", &i);
				if (ListDelete(&L, i, &e) == OK) 
				{
					printf("元素删除成功\n");
					printf("删除元素为%d\n",e);
				}
				else printf("元素删除失败\n");
				getchar();getchar();
			}
			break;
		case 12:
			//printf("\n----ListTrabverse功能待实现！\n");     
			if (!ListTrabverse(L)) 
				printf("线性表是空表！\n");
			getchar();getchar();
			break;
		case 13:
			if(SaveFile(L))
				printf("数据保存成功!\n"); 
			getchar();getchar();
			break;
		case 14:
			if(LoadFile(&L))
				printf("数据载入成功！\n");
			getchar();getchar();
			break;
		case 0:
			SaveFile(L);
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}

status IntiaList(ListNode **L) 
{
	(*L)= (ListNode *)malloc(sizeof(ListNode));
	(*L)->next = NULL;
	(*L)->data = 0;
	return OK;
}

status DestroyList(ListNode *L) 
{
	if(L==NULL) return OK;
	ListNode *pcrs,*p;
	pcrs=L;
	p=pcrs->next; 
	while(p != NULL)
	{
		free(pcrs);
		pcrs =p ;
		p = p->next;
	}
	free(pcrs);
	return OK;
}

status ClearList(ListNode *L) 
{
	if(L==NULL) return ERROR;
	L->data=0;
	ListNode  *pcrs,*p;
	pcrs=L->next;
	p=pcrs->next;
	while(p != NULL)
	{
		free(pcrs);
		pcrs = p;
		p =p->next;
	}
	free(pcrs);
	return OK;
}

status ListEmpty(ListNode * L) 
{
	if (L == NULL || L->data == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(ListNode * L) 
{
	if(L == NULL)
		return 0;
	return L->data;
}

status GetElem(ListNode * L, int i, ElemType *e) 
{
	int j=1; //计数器 
	ListNode *p;
	if(!ListEmpty(L))
	{
		if (i<1 || i>L->data)
		return ERROR;
		p = L->next;
		while(j!=i)
		{
			p = p->next;
			j++;
		}
		(*e)=p->data;
		return OK;
	}
	else
		return FALSE;
}

status LocateElem(ListNode * L, ElemType e)
{
	pListNode p = L->next;
	int i = 1;
	while (p)
	{
		if(p->data==e)
			return i;
		else
		{
			i++;
			p = p->next;
		}
	}
	return 0;
}

status PriorElem(ListNode * L, ElemType e, ElemType* pre)
{
		pListNode pcrs,p;
		pcrs = L->next,p= pcrs->next;
		while (p)
		{
			if(p->data==e)
			{
				*pre=pcrs->data;
				return OK;
			}	
			pcrs=p;
			p=p->next;
		}
		return ERROR;
}

status NextElem(ListNode * L, ElemType e, ElemType* next)
{
	pListNode p = L->next;
	while(p)
	{
		if(p->data==e)
		{
			*next=(p->next)->data;
			return OK;
		}
		p=p->next;
	}
	return ERROR;
}

status ListInsert(ListNode **L, int i, ElemType e) 
{
	int j=1;//计数器 
	if ( *L != NULL )
	{
		pListNode Lhead = *L,p,p1;
		if (i<1|| i>Lhead->data + 1)
			return ERROR;
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data=e;	
		p1=Lhead; 
		if (Lhead->data == 0)
		{
			Lhead->next = p;
			p->next = NULL;
			Lhead->data = 1;
			return OK;
		}
		while(p1->next!=NULL)
		{
			if(j==i)
			{
				p->next=p1->next;
				p1->next=p;
				p->data = e;
				Lhead->data+=1;
				return OK;
			}
			else
			{
				p1=p1->next;
				j++;
			}
		}
	}
	else
		return ERROR;
}

status ListDelete(ListNode **L, int i, ElemType* e)
{
	if( !ListEmpty(*L) )
	{
		pListNode Lhead = *L,p1,p2;
		int j;
		if (i<1 || i>Lhead->data)
			return ERROR;
		if (Lhead->data)
		{
			p1 = Lhead, p2 = Lhead->next;
			j = 1;
			while (p2 && j<i)
			{
				p1 = p2;
				p2 = p2->next;
				j++;
			}
			p1->next = p2->next;
			*e = p2->data;
			Lhead->data-=1;
			free(p2);
			return OK;
		}
		return ERROR;
	}
	else
		return ERROR;
}

status ListTrabverse(pListNode L)
{
	if (!L->data)return ERROR;
	pListNode p = L->next;
	int i = 1;
	printf("\n-----------对所有元素进行间访-----------------------\n");
	while (p)
	{
		printf("第%d个元素的元素值为%d\n\n", i, p->data);
		i++;
		p = p->next;
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}

status SaveFile(pListNode L)
{
	FILE *in;
	if((in = fopen("shuju.txt","w")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	} 
	L = L->next;
	while(L != NULL)
	{
		fprintf(in, "%d\n", L->data);
		L = L->next;
	}
	fclose(in);
	return OK;	
}


status LoadFile(ListNode **L)
{
	FILE *out;
	ElemType e;
	pListNode p;
	if((out= fopen("shuju.txt","r")) == NULL)
  	{
  		printf("文件打开失败！\n"); 
  		return ERROR;
  	}
	IntiaList(&p);
	while( !feof(out) )
	{
		fscanf(out, "%d\n", &e);
		ListInsert(&p, 1, e);//以插入形式读元素 
	}
	fclose(out);
	*L = p;
	return OK;
}

