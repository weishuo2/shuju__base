/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct {  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*-----page 19 on textbook ---------*/
status IntiaList(SqList *L);// 创建链表 
status DestroyList(SqList *L);//摧毁链表 
status ClearList(SqList *L);//清空链表 
status ListEmpty(SqList L);//判空表 
status ListLength(SqList L);//求表长 
status GetElem(SqList L, int i, ElemType *e);//获取元素 
status LocateElem(SqList L, ElemType e); //简化过 定位元素 
status PriorElem(SqList L, ElemType cur_e, ElemType * pre);//求前序 
status NextElem(SqList L,ElemType cur_e,ElemType * next);//求后继 
status ListInsert(SqList * L,int i,ElemType e);//插入元素 
status ListDelete(SqList * L, int i, ElemType * e);//删除元素 
status ListTrabverse(SqList L);  //简化过 遍历链表 
status load_List(SqList *L);// 从文件读出 
status Listfile(SqList *L);//保存到文件
status write(SqList *L);//
status writenew(SqList *L);//

/*--------------------------------------------*/
void main(void) {
	SqList L;
	int op = 1, m,i;
	ElemType e,cur_e, pre, next;
	L.length=0;
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	   1. IntiaList        7. LocateElem\n");
		printf("    	   2. DestroyList      8. PriorElem\n");
		printf("    	   3. ClearList        9. NextElem \n");
		printf("    	   4. ListEmpty       10. ListInsert\n");
		printf("    	   5. ListLength      11. ListDelete\n");
		printf("    	   6. GetElem         12. ListTrabverse\n");
		printf("    	  13. ListFile        14. ListLoad\n");
		printf("    	  15. WriteNew\n");
		printf("    	   0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~15]:");
		scanf("%d", &op);getchar();
		switch (op) 
		{
			case 1:
				if (IntiaList(&L) == OK) printf("    线性表创建成功！\n");
				else printf("    线性表创建失败！\n");
				getchar();
				break;
			case 2:
				if (DestroyList(&L) == OK) printf("    线性表销毁成功！\n");
				else printf("    线性表销毁失败！\n");
				getchar();
				break;
			case 3:
				if (ClearList(&L) == OK) printf("    线性表清空成功！\n");
				else printf("    线性表清空失败！\n");
				getchar();
				break;
			case 4:
				if (ListEmpty(L) == OK) printf("    线性表为空！\n");
				else printf("    线性表不为空！\n");
				getchar();
				break;
			case 5:
				printf("    线性表长度为%d\n", ListLength(L));
				getchar();
				break;
			case 6:
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					printf("    请输入要查询的序数：");
					scanf("%d", &i);getchar();
					GetElem(L, i,&e); 
					if (GetElem(L, i,&e) == OK) printf("    表中第%d个数据为%d\n", i, e);
					else printf("    查询失败！\n");
					getchar();
				}
			
				break;
			case 7:
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					printf("    请输入要查询的数据：");
					scanf("%d", &e);getchar();
					m = LocateElem(L, e);
					if (m != ERROR)
					{
						printf("    L中第一个与查询数据相等的数据的位序为%d\n", m);
					}
					else
					{
						printf("    这样的数据元素不存在！\n");
					}
					getchar();
				}
				break;
			case 8:
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					printf("    请输入要查询的元素：");
					scanf("%d", &cur_e);getchar();
					if (PriorElem(L, cur_e, &pre) == OK) printf("    前驱为%d\n", pre);
					else printf("    无此前驱\n");
					getchar();
				}
				break;
			case 9:
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					printf("    请输入要查询的元素：");
					scanf("%d", &cur_e);getchar();
					if (NextElem(L, cur_e, &next) == OK) printf("    后驱为%d\n", next);
					else printf("    无此后驱\n");
					getchar();
				}
				break;
			case 10:
				printf("    请输入位置i：");
				scanf("%d", &i);
				printf("    请输入e：");
				scanf("%d", &e);getchar();
				if (ListInsert(&L, i, e) == OK) printf("    线性表插入成功\n");
				else printf("    线性表插入失败\n");
				getchar();
				break;
			case 11:
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					printf("    请输入要删除的元素的序列：");
					scanf("%d", &i);getchar();
					if (ListDelete(&L, i, &e) == OK) 
					{ 
						printf("    元素删除成功\n");
						printf("    删除元素值为%d\n",e); 
					} 
					else printf("    元素删除失败\n");
					getchar();
				}
				break;
			case 12:     
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					ListTrabverse(L);
					getchar();	
				}
				break;
			case 13:
				if(L.length == 0)
				{
					printf("    表为空，无法操作\n");
					getchar();
				}
				else
				{
					Listfile(&L);
					getchar();	
				}
				break;
			case 14:
				load_List(&L);
				getchar();
				break;
			case 15:
				writenew(&L);
				break;
			case 0:
				break;
			}//end of switch
		}//end of while
		printf("欢迎下次再使用本系统！\n");
}//end of main()

 /*--------page 23 on textbook --------------------*/
status IntiaList(SqList *L)  //创建一个空的链表 
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	L->listsize = LIST_INIT_SIZE;
	L->length=0;
	return OK;
}

status DestroyList(SqList *L) //清空一个链表并释放存储空间 
{
	free(L->elem);
	L->elem = NULL;
	L->length=0;
	return OK;
}

status ClearList(SqList *L)//将一个链表置为空 
{
	L->length = 0;
	return OK;
}

status ListEmpty(SqList L)//判断表是否为空
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L) //计算表长 
{
	return L.length;
}

status GetElem(SqList L,int i,ElemType *e)//取链表中第i个元素并返回 
{
	if((i < 0) || (i >= L.length))
		return FALSE;
	*e = *(L.elem+i-1);
	return OK;
}

int LocateElem(SqList L,ElemType e)//返回第一个和e相等的数的位置 
{
	int i=1;
	while (*L.elem != e)
	{
		L.elem++;
		i++;
	}
	if (i > L.length)
		return ERROR;
	return i;
}

status PriorElem(SqList L,ElemType cur_e,ElemType *pre)
{
	int i;
	if((i<0) || (i>=L.length))
		return FALSE;
	for (i=1;i < L.length;i++) 
	{
		if (L.elem[i] == cur_e) 
		{
			*pre = L.elem[i-1]; 
			return OK;
		}
	}
	return FALSE;
}

status NextElem(SqList L,ElemType cur_e,ElemType *next)
{
	int i;
	if((i<0) || (i>=L.length))
		return FALSE;
	for (i=0;i < L.length-1;i++) 
	{
		if (L.elem[i] == cur_e) 
		{
			*next=L.elem[i+1];  
			return OK;
		}
	}
	return FALSE;
}


status ListInsert(SqList *L,int i,ElemType e)//在第i个元素前插入值e 
{
	ElemType *newone,*q,*p;
	if (!L->elem) return ERROR;
	if (i<1 || i>+L->length) return ERROR;
	if (L->length >= L->listsize) 
	{
		newone=(ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if (!newone) return ERROR; 
		L->elem =newone; 
		L->listsize += LISTINCREMENT; 
	}
	q=&(L->elem[i-1]); 
	for (p=&(L->elem[L->length-1]);p >= q;p--)
		*(p+1)=*p;
	*q = e;
	L->length++;
	return OK;
}

status ListDelete(SqList *L, int i, ElemType *e)//删除第i个元素，并用e返回 
{
	ElemType *q,*p;
	if (i<1 || i>L->length) return ERROR; 
	p=&(L->elem[i-1]);
	*e=*p;
	q=&(L->elem[L->length-1]);
	for (p++;p <= q;++p)
		*(p-1)=*p;
	L->length--;
	return OK;
}

status ListTrabverse(SqList L) //输出所有的元素 
{
	int i;
	printf("\n-----------all elements -----------------------\n");
	for (i=0;i<L.length;i++) printf("%d  ", L.elem[i]);
	printf("\n---------------end ----------------------------\n");
	return OK;
}

status Listfile(SqList *L)//将数据写到文件 
{
	FILE *out1;
	if((out1 = fopen("sunxu.txt","w")) == NULL)
	{
		printf("    文件打开失败！\n");
		return 1;
	}
	printf("    已保存到文件！\n");
	fwrite(L->elem,sizeof(ElemType),L->length,out1);
	fclose(out1);
}

status load_List(SqList *L) //数据调出 
{
	FILE *in1; 
  	if((in1 = fopen("sunxu.txt","r")) == NULL)
  	{
  		printf("    文件打开失败！\n"); 
  		return 1;
  	}
  	printf("    已从文件导出！\n"); 
  	IntiaList(L);
  	L->length=0;
  	while(fread(&L->elem[L->length],sizeof(ElemType),1,in1))
   		L->length++;
	fclose(in1);
}

status writenew(SqList *L)//在表后加元素 
{
	char ch;
	ch='y';
	ElemType *nw; 
	while(ch=='y' || ch=='Y')
	{
		printf("    输入数据:");
		scanf("%d",&(L->elem[L->length]));
		getchar();
		L->length++;
		if (L->length >= L->listsize) 
		{
			nw = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT)*sizeof(ElemType));
			if (!nw) return ERROR; 
			L->elem = nw; 
			L->listsize += LISTINCREMENT; 
		}
		printf("    继续输入？y or n\n");
		printf("    输入你的选择:");
		ch=getchar();
		getchar();
	}
	return 1; 
}

