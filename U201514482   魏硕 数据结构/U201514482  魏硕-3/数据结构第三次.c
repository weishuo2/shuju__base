#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef struct Data TElemType;

#define FORESTSIZE    20
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  20

//树的数据域的定义
struct Data {
	int number;//结点的编号 
	char name[20];//结点存的名字 
};

//树节点定义
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//栈的定义 
typedef struct Stack {
	BiTree *base;
	int top;
	int stacksize;
}*Stack,stack;

BiTree Forest[FORESTSIZE];//森林

//栈的操作 
int InitStack(Stack S);//栈的初始化
int Push(Stack S, BiTree BT);//入栈 
BiTree Pop(Stack S);//出栈
int IsStackEmpty(Stack S);//判空栈 
int DestroyStack(Stack S);//摧毁栈 

//树的操作 
int InitBiTree(void);//初始化森林 
int DestroyBiTree(BiTree *T);//摧毁树 
BiTree CreateBiTree(BiTree T);//创建树 
int ClearBiTree(BiTree *T);//清空树 
int BiTreeEmpty(BiTree T);//判断树是否为空 
int BiTreeDepth(BiTree T);//求树的深度 
int Root(BiTree T);//返回根节点 
BiTree Value(BiTree T,int e);//输入结点的编号，返回结点
int Assign(BiTree *T,int e);//找到结点e，并改变它的值 
BiTree Parent(BiTree T,int e);//返回双亲结点 
BiTree LeftChild(BiTree T,int e);//返回左孩子结点 
BiTree RightChild(BiTree T,int e);//返回右孩子
BiTree LeftSibling(BiTree T,int e);//返回左兄弟 
BiTree RightSibling(BiTree T,int e);//返回右兄弟
int InsertChild(BiTree *T,int e,int LR);//插入子树 ,LR为1则是左子树 
int DeleteChild(BiTree *T,int e,int LR);//删除子树，LR为1则是左子树 
int PreOrderTraverse(BiTree T);//前序遍历
int InOrderTraverse(BiTree T);//中序遍历 
int PostOrderTraverse(BiTree T);//后序遍历
int LevelTraverse(BiTree T);//层次遍历 
void PrintLevel(BiTree T,int level);//层次遍历的一部分
int SaveBiTree(BiTree T);//写入文件 
int LoadBiTree(BiTree *T);//读出文件 

int main(void)   
{				
	BiTree T,p;
	int e,LR,num,op=1;
	while (op)
	 {
		system("cls");
		system("color 1F");//系统命令，调颜色
		printf("\t\t********************************************************************\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                     ◆树的功能实现菜单 ◆                        *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                      0.退出系统                                  *\n");
		printf("\t\t*                      1.初始化二叉树                              *\n");
		printf("\t\t*                      2.销毁二叉树                                *\n");
		printf("\t\t*                      3.创建二叉树                                *\n");
		printf("\t\t*                      4.清空二叉树                                *\n");
		printf("\t\t*                      5.判空二叉树                                *\n");
		printf("\t\t*                      6.求二叉树深度                              *\n");
		printf("\t\t*                      7.获得根节点                                *\n");
		printf("\t\t*                      8.获得指定结点                              *\n");
		printf("\t\t*                      9.指定结点赋值                              *\n");
		printf("\t\t*                      10.获得结点双亲                             *\n");
		printf("\t\t*                      11.获得结点左孩子                           *\n");
		printf("\t\t*                      12.获得结点右孩子                           *\n");
		printf("\t\t*                      13.获得结点左兄弟                           *\n");
		printf("\t\t*                      14.获得结点右兄弟                           *\n");
		printf("\t\t*                      15.插入子树                                 *\n");
		printf("\t\t*                      16.删除子树                                 *\n");
		printf("\t\t*                      17.前序遍历                                 *\n");
		printf("\t\t*                      18.中序遍历                                 *\n");
		printf("\t\t*                      19.后序遍历                                 *\n");
		printf("\t\t*                      20.按层遍历                                 *\n");
		printf("\t\t*                      21.存入文件                                 *\n");
		printf("\t\t*                      22.从文件中读取数据                         *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t********************************************************************\n\n");
		printf("\t\t                       请输入你的选择：");
		scanf("%d",&op);getchar();
		switch(op)
		{
			case 1:
				system("cls");
				if(InitBiTree())
					printf("成功创建森林！\n");
				getchar();
				break;
			case 2:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else if(DestroyBiTree(&(Forest[num])))
					printf("摧毁成功！\n");
				getchar();
				break;
			case 3:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();	
				Forest[num]=CreateBiTree(Forest[num]);		
				printf("创建成功！\n");
				getchar();
				break;
			case 4:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else if(ClearBiTree(&(Forest[num])))
					printf("清空成功！\n");
				getchar();
				break;
			case 5:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(BiTreeEmpty(Forest[num])) 
					printf("该树为空树！\n");
				else
					printf("该树不为空树！\n");
				getchar();break;
			case 6:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				printf("该树的深度为%d\n",BiTreeDepth(Forest[num]));	
				getchar();break;
			case 7:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				Root(Forest[num]);
				getchar();break;
			case 8:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					p=Value(Forest[num],e);
					if(!p)
						printf("该节点不存在！\n");
					else
						printf("该节点为 %d %s\n",p->data.number,p->data.name);
				}
				getchar();break;
			case 9:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					if(!Assign(&Forest[num],e))
						printf("该节点不存在！\n");
					else
						printf("该节点的值修改成功！\n");
				}
				getchar();break;
			case 10:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					p=Parent(Forest[num],e);
					if(!p)
						printf("该节点不存在！\n");
					else
						printf("该节点双亲为 %d %s\n",p->data.number,p->data.name);
				}
				getchar();break; 
			case 11:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					p=LeftChild(Forest[num],e);
					if(!p)
						printf("该节点不存在！\n");
					else
						printf("该节点左孩子为 %d %s\n",p->data.number,p->data.name);		 		
				} 
				getchar();break; 
			case 12:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					p=RightChild(Forest[num],e);
					if(!p)
						printf("该节点不存在！\n");
					else
						printf("该节点右孩子为 %d %s\n",p->data.number,p->data.name);		 		
				} 
				getchar();break;
			case 13:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					p=LeftSibling(Forest[num],e);
					if(!p)
						printf("该节点不存在！\n");
					else
						printf("该节点左兄弟为 %d %s\n",p->data.number,p->data.name);		 		
				} 	
				getchar();break; 
			case 14:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					p=RightSibling(Forest[num],e);
					if(!p)
						printf("该节点不存在！\n");
					else
						printf("该节点右兄弟为 %d %s\n",p->data.number,p->data.name);		 		
				} 
				getchar();break; 
			case 15:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					printf("请输入插入左子树还是右子树(左为1，右为0)：");
					scanf("%d",&LR);getchar();
					if(!InsertChild(&Forest[num],e,LR))
						printf("该节点不存在！\n");	
					else
						printf("插入成功！\n");	 		
				} 
				getchar();break;
			case 16:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("请输入结点的编号：");
					scanf("%d",&e);getchar();
					printf("请输入删除左子树还是右子树(左为1，右为0)：");
					scanf("%d",&LR);getchar();
					if(!DeleteChild(&Forest[num],e,LR))
						printf("该节点不存在！\n");
					else
						printf("删除成功！\n");		 		
				} 
				getchar();break;
			case 17:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("前序遍历的结果为：\n");
					PreOrderTraverse(Forest[num]);
				}
				getchar();break;
			case 18:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("中序遍历的结果为：\n");
					InOrderTraverse(Forest[num]);
				}
				getchar();break;
			case 19:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("中序遍历的结果为：\n");
					PostOrderTraverse(Forest[num]);
				}
				getchar();break;
			case 20:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					printf("层次遍历的结果为：\n");
					LevelTraverse(Forest[num]);
				}
				getchar();break;
			case 21:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("该树为空树！\n");
				else
				{
					SaveBiTree(Forest[num]);
					printf("写入文件成功！\n");
				}
				getchar();break;
			case 22:
				system("cls");
				printf("请输入该树的编号（0-19）：");
				scanf("%d",&num);getchar();
				LoadBiTree(&Forest[num]);
				printf("文件读出成功！\n");
				getchar();break;	
		}
	}
	printf("欢迎下次再使用本系统！\n");
} 

//栈 
int InitStack(Stack S)
{
	S->base=(BiTree *)malloc(sizeof(BiTree)*STACK_INIT_SIZE);
	if(!S->base) exit(OVERFLOW);
	S->stacksize=STACK_INIT_SIZE;
	S->top=-1;
	return OK;
}

int Push(Stack S, BiTree T)
{
	if ((S->top+1) >= S->stacksize)
	{
		S->base=(BiTree *)realloc(S->base, sizeof(BiTree)*(S->stacksize+STACKINCREMENT));
		if(!S->base) exit(OVERFLOW);
		S->stacksize=S->stacksize+STACKINCREMENT;
	}
	S->top++;
	S->base[S->top]=T;
	return OK;
}

BiTree Pop(Stack S)
{
	if (IsStackEmpty(S) == TRUE)
		return NULL;	
	return S->base[S->top--];
}

int IsStackEmpty(Stack S)
{
	if (S->top == -1)
		return TRUE;
	else
		return FALSE;
}

//销毁栈S
int DestroyStack(Stack S)
{
	free(S->base);
	free(S);
	S = NULL;
	return OK;
}

//树 
int InitBiTree(void)//构造空的森林 
{
	int i;
	for(i=0;i<FORESTSIZE;i++)
		Forest[i]=NULL;	
	return OK;	
}

int DestroyBiTree(BiTree *T)
{
	BiTree p=*T;
	if(p == NULL)
		return ERROR; 
	if(p->lchild != NULL)
		DestroyBiTree(&p->lchild);
	if(p->rchild != NULL)
		DestroyBiTree(&p->rchild);
	free(p);
	*T=NULL;
	return OK;
}

BiTree CreateBiTree(BiTree T)
{
	char ch;
	int num;
	char name[20];
	printf("是否为空结点？y or n\n");
	ch=getchar();getchar();
	if((ch == 'y') || (ch == 'Y'))
		T = NULL;
	else
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		printf("输入结点编号及名字\n");
		printf("编号：");
		scanf("%d",&(T->data.number));
		printf("名字：");
		scanf("%s",T->data.name);getchar();
		T->lchild=CreateBiTree(T->lchild);
		T->rchild=CreateBiTree(T->rchild);
	}
	
	return T;
}

int ClearBiTree(BiTree *T)
{
 	BiTree p=*T;
	if(p->lchild != NULL)
		ClearBiTree(&p->lchild);
	if(p->rchild != NULL)
		ClearBiTree(&p->rchild);
	free(p);
	*T=NULL;
	return OK;
}


int BiTreeEmpty(BiTree T)
{
	if((T == NULL) || T->data.number==0)
		return TRUE;
	else
		return FALSE;
}

int BiTreeDepth(BiTree T)
{
	BiTree p=T;
	int l,r,max;
	if(p != NULL)
	{
		l=BiTreeDepth(p->lchild);
		r=BiTreeDepth(p->rchild);
		max=(l>r)?l:r;
		return max+1;
	} 
	else
		return 0;
}

int Root(BiTree T)
{
	if(T == NULL)
	{
		printf("这棵树不存在！\n");
		return 0; 
	}	
	else
	{
		printf("根节点编号为%d,名字为%s\n",T->data.number,T->data.name);
		return 1;	
	}
}

BiTree Value(BiTree T,int e)//先序遍历 
{
	BiTree p=T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return NULL;
	while((p != NULL) || !IsStackEmpty(S) )
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->data.number == e)
			{
				DestroyStack(S);
				return p;
			}	
			p=p->lchild;
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return NULL;
}

int Assign(BiTree *T,int e)
{
 	BiTree p=*T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return FALSE;
	while((p != NULL) || !IsStackEmpty(S)) 
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->data.number == e)
			{
			 	printf("输入结点编号：");
				scanf("%d",&p->data.number);
				printf("输入结点名字：");
				scanf("%s",p->data.name);getchar();
				DestroyStack(S);
				return OK; 
			}
			p=p->lchild;		
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return FALSE;
}

BiTree Parent(BiTree T,int e)
{
	BiTree p=T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return NULL;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{	
			Push(S,p);
			if(p->lchild != NULL)
				if(p->lchild->data.number == e)
					return p;
			if(p->rchild != NULL)
				if(p->rchild->data.number == e)
					return p;		
			p=p->lchild;	
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return NULL;
}

BiTree LeftChild(BiTree T,int e)
{
 	BiTree p=T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return NULL;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{	
			Push(S,p);
			if(p->data.number == e)
				return p->lchild;	
			p=p->lchild;		
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return NULL;
}
 
BiTree RightChild(BiTree T,int e)
{
 	BiTree p=T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return NULL;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->data.number == e)
				return p->rchild;
			p=p->lchild;
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return NULL;
}

BiTree LeftSibling(BiTree T,int e)
{
  	BiTree p=T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return NULL;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->rchild != NULL)
				if(p->rchild->data.number == e)
					return p->lchild;		
			p=p->lchild;				
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return NULL;
}

BiTree RightSibling(BiTree T,int e)
{
 	BiTree p=T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return NULL;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->lchild != NULL)
				if(p->lchild->data.number == e)
					return p->rchild; 
			p=p->lchild;	
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return NULL;
}

int InsertChild(BiTree *T,int e,int LR)
{
	BiTree p=*T;
	Stack S;
	int num;
	InitStack(S);
	if(p == NULL)
		return 0;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->data.number == e)
			{
				printf("将第几棵树作为子树插入？\n");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					return FALSE;
				if(LR == 1)
					p->lchild=Forest[num];
				if(LR == 0)
					p->rchild=Forest[num];
				return OK;
			}
			p=p->lchild;		
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return 0;
}

int DeleteChild(BiTree *T,int e,int LR)
{
	BiTree p=*T;
	Stack S;
	InitStack(S);
	if(p == NULL)
		return 0;
	while((p != NULL) || !IsStackEmpty(S))//无法处理结点不存在的情况，貌似是栈有问题 
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->data.number == e)
			{
				if(LR == 1)
					if(DestroyBiTree(&(p->lchild)) == 0)
						printf("该树为空树\n");
				if(LR == 0)
					if(DestroyBiTree(&(p->rchild)) == 0)
						printf("该树为空树\n");
				return OK;
			}
			p=p->lchild;				
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	return 0;
}

int PreOrderTraverse(BiTree T)
{
	BiTree p=T;
	if(p != NULL)
	{
		printf("%d %s\n",p->data.number,p->data.name);
		PreOrderTraverse(p->lchild);
		PreOrderTraverse(p->rchild);
		return OK;
	}
	else
		return 0;
}

int InOrderTraverse(BiTree T)
{
	BiTree p=T;
	Stack S;
	InitStack(S);
	while((p != NULL) || !IsStackEmpty(S) )
	{
		while(p != NULL)
		{
			Push(S,p);
			p=p->lchild;	
		}
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			printf("%d %s\n",p->data.number,p->data.name);
			p=p->rchild;
		}	
	}
	return OK;
}

int PostOrderTraverse(BiTree T)
{
	BiTree p=T;
	if(p != NULL)
	{
		PostOrderTraverse(p->lchild);
		PostOrderTraverse(p->rchild);
		printf("%d  %s\n",p->data.number,p->data.name);	
	}
	else 
		return 0;
} 

int LevelTraverse(BiTree T)
{
	int depth,i;
	depth=BiTreeDepth(T);
	for(i=1;i<=depth;i++)
		PrintLevel(T, i);
	return OK;
}

void PrintLevel(BiTree T,int level)
{
    if (T == NULL || level < 1 )
        return;
    if (level == 1)
    {
        printf("%d  %s\n",T->data.number,T->data.name);
        return;
    }
    PrintLevel(T->lchild,  level-1);// 左子树的 level - 1 级 
    PrintLevel(T->rchild, level-1); // 右子树的 level - 1 级
}

int SaveBiTree(BiTree T)
{
	BiTree p=T;
	Stack S;
	InitStack(S);
	FILE *in;
	if((in = fopen("shuju.txt","w")) == NULL)
	{
		printf("文件打开失败！\n");
		return ERROR;
	} 
	if(p == NULL)
		return ERROR;
	while((p != NULL) || !IsStackEmpty(S))
	{
		while(p != NULL)
		{
			Push(S,p);
			fprintf(in, "*%d %s\n",p->data.number,p->data.name);
			p=p->lchild;
		}
		fprintf(in, "#\n");
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p=p->rchild;
		}
	}
	fprintf(in, "#\n");
	fclose(in);
	return OK;
} 

int LoadBiTree(BiTree *T)
{
	FILE *out;
	int flag=0;
	BiTree p,q;
	Stack S=(Stack)malloc(sizeof(struct Stack));
	InitStack(S);
	char ch;
	if((out= fopen("shuju.txt","r")) == NULL)
  	{
  		printf("文件打开失败！\n"); 
  		return ERROR;
  	}	
	p=(BiTree)malloc(sizeof(BiTNode));
	while((ch=fgetc(out))!='#' || !IsStackEmpty(S))
	{
		if(ch == '#')
			fgetc(out);	
		while(ch != '#')
		{	
			fscanf(out,"%d %s\n",&p->data.number,p->data.name); 
			if(flag == 0)
			{
				*T = p;
				flag = 1;
			}
			Push(S,p);
			q=p;
			p->lchild = (BiTree)malloc(sizeof(BiTNode));
			p=p->lchild;
			ch=fgetc(out);
			if(ch == '#')
				fgetc(out);		
		}
 		q->lchild = NULL;
 		q->rchild=NULL;
		if(IsStackEmpty(S) == FALSE)
		{
			p=Pop(S);
			p->rchild=(BiTree)malloc(sizeof(BiTNode));
			q=p;
			p=p->rchild; 
		}
	}
	free(q->rchild);
	q->rchild=NULL;
	fclose(out);
	return OK;
}
	 
