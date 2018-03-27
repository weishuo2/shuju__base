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

//����������Ķ���
struct Data {
	int number;//���ı�� 
	char name[20];//��������� 
};

//���ڵ㶨��
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//ջ�Ķ��� 
typedef struct Stack {
	BiTree *base;
	int top;
	int stacksize;
}*Stack,stack;

BiTree Forest[FORESTSIZE];//ɭ��

//ջ�Ĳ��� 
int InitStack(Stack S);//ջ�ĳ�ʼ��
int Push(Stack S, BiTree BT);//��ջ 
BiTree Pop(Stack S);//��ջ
int IsStackEmpty(Stack S);//�п�ջ 
int DestroyStack(Stack S);//�ݻ�ջ 

//���Ĳ��� 
int InitBiTree(void);//��ʼ��ɭ�� 
int DestroyBiTree(BiTree *T);//�ݻ��� 
BiTree CreateBiTree(BiTree T);//������ 
int ClearBiTree(BiTree *T);//����� 
int BiTreeEmpty(BiTree T);//�ж����Ƿ�Ϊ�� 
int BiTreeDepth(BiTree T);//��������� 
int Root(BiTree T);//���ظ��ڵ� 
BiTree Value(BiTree T,int e);//������ı�ţ����ؽ��
int Assign(BiTree *T,int e);//�ҵ����e�����ı�����ֵ 
BiTree Parent(BiTree T,int e);//����˫�׽�� 
BiTree LeftChild(BiTree T,int e);//�������ӽ�� 
BiTree RightChild(BiTree T,int e);//�����Һ���
BiTree LeftSibling(BiTree T,int e);//�������ֵ� 
BiTree RightSibling(BiTree T,int e);//�������ֵ�
int InsertChild(BiTree *T,int e,int LR);//�������� ,LRΪ1���������� 
int DeleteChild(BiTree *T,int e,int LR);//ɾ��������LRΪ1���������� 
int PreOrderTraverse(BiTree T);//ǰ�����
int InOrderTraverse(BiTree T);//������� 
int PostOrderTraverse(BiTree T);//�������
int LevelTraverse(BiTree T);//��α��� 
void PrintLevel(BiTree T,int level);//��α�����һ����
int SaveBiTree(BiTree T);//д���ļ� 
int LoadBiTree(BiTree *T);//�����ļ� 

int main(void)   
{				
	BiTree T,p;
	int e,LR,num,op=1;
	while (op)
	 {
		system("cls");
		system("color 1F");//ϵͳ�������ɫ
		printf("\t\t********************************************************************\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                     �����Ĺ���ʵ�ֲ˵� ��                        *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                      0.�˳�ϵͳ                                  *\n");
		printf("\t\t*                      1.��ʼ��������                              *\n");
		printf("\t\t*                      2.���ٶ�����                                *\n");
		printf("\t\t*                      3.����������                                *\n");
		printf("\t\t*                      4.��ն�����                                *\n");
		printf("\t\t*                      5.�пն�����                                *\n");
		printf("\t\t*                      6.����������                              *\n");
		printf("\t\t*                      7.��ø��ڵ�                                *\n");
		printf("\t\t*                      8.���ָ�����                              *\n");
		printf("\t\t*                      9.ָ����㸳ֵ                              *\n");
		printf("\t\t*                      10.��ý��˫��                             *\n");
		printf("\t\t*                      11.��ý������                           *\n");
		printf("\t\t*                      12.��ý���Һ���                           *\n");
		printf("\t\t*                      13.��ý�����ֵ�                           *\n");
		printf("\t\t*                      14.��ý�����ֵ�                           *\n");
		printf("\t\t*                      15.��������                                 *\n");
		printf("\t\t*                      16.ɾ������                                 *\n");
		printf("\t\t*                      17.ǰ�����                                 *\n");
		printf("\t\t*                      18.�������                                 *\n");
		printf("\t\t*                      19.�������                                 *\n");
		printf("\t\t*                      20.�������                                 *\n");
		printf("\t\t*                      21.�����ļ�                                 *\n");
		printf("\t\t*                      22.���ļ��ж�ȡ����                         *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t********************************************************************\n\n");
		printf("\t\t                       ���������ѡ��");
		scanf("%d",&op);getchar();
		switch(op)
		{
			case 1:
				system("cls");
				if(InitBiTree())
					printf("�ɹ�����ɭ�֣�\n");
				getchar();
				break;
			case 2:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else if(DestroyBiTree(&(Forest[num])))
					printf("�ݻٳɹ���\n");
				getchar();
				break;
			case 3:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();	
				Forest[num]=CreateBiTree(Forest[num]);		
				printf("�����ɹ���\n");
				getchar();
				break;
			case 4:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else if(ClearBiTree(&(Forest[num])))
					printf("��ճɹ���\n");
				getchar();
				break;
			case 5:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(BiTreeEmpty(Forest[num])) 
					printf("����Ϊ������\n");
				else
					printf("������Ϊ������\n");
				getchar();break;
			case 6:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				printf("���������Ϊ%d\n",BiTreeDepth(Forest[num]));	
				getchar();break;
			case 7:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				Root(Forest[num]);
				getchar();break;
			case 8:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					p=Value(Forest[num],e);
					if(!p)
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ�Ϊ %d %s\n",p->data.number,p->data.name);
				}
				getchar();break;
			case 9:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					if(!Assign(&Forest[num],e))
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ��ֵ�޸ĳɹ���\n");
				}
				getchar();break;
			case 10:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					p=Parent(Forest[num],e);
					if(!p)
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ�˫��Ϊ %d %s\n",p->data.number,p->data.name);
				}
				getchar();break; 
			case 11:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					p=LeftChild(Forest[num],e);
					if(!p)
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ�����Ϊ %d %s\n",p->data.number,p->data.name);		 		
				} 
				getchar();break; 
			case 12:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					p=RightChild(Forest[num],e);
					if(!p)
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ��Һ���Ϊ %d %s\n",p->data.number,p->data.name);		 		
				} 
				getchar();break;
			case 13:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					p=LeftSibling(Forest[num],e);
					if(!p)
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ����ֵ�Ϊ %d %s\n",p->data.number,p->data.name);		 		
				} 	
				getchar();break; 
			case 14:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					p=RightSibling(Forest[num],e);
					if(!p)
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("�ýڵ����ֵ�Ϊ %d %s\n",p->data.number,p->data.name);		 		
				} 
				getchar();break; 
			case 15:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					printf("�������������������������(��Ϊ1����Ϊ0)��");
					scanf("%d",&LR);getchar();
					if(!InsertChild(&Forest[num],e,LR))
						printf("�ýڵ㲻���ڣ�\n");	
					else
						printf("����ɹ���\n");	 		
				} 
				getchar();break;
			case 16:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������ı�ţ�");
					scanf("%d",&e);getchar();
					printf("������ɾ������������������(��Ϊ1����Ϊ0)��");
					scanf("%d",&LR);getchar();
					if(!DeleteChild(&Forest[num],e,LR))
						printf("�ýڵ㲻���ڣ�\n");
					else
						printf("ɾ���ɹ���\n");		 		
				} 
				getchar();break;
			case 17:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("ǰ������Ľ��Ϊ��\n");
					PreOrderTraverse(Forest[num]);
				}
				getchar();break;
			case 18:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������Ľ��Ϊ��\n");
					InOrderTraverse(Forest[num]);
				}
				getchar();break;
			case 19:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��������Ľ��Ϊ��\n");
					PostOrderTraverse(Forest[num]);
				}
				getchar();break;
			case 20:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					printf("��α����Ľ��Ϊ��\n");
					LevelTraverse(Forest[num]);
				}
				getchar();break;
			case 21:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				if(Forest[num] == NULL)
					printf("����Ϊ������\n");
				else
				{
					SaveBiTree(Forest[num]);
					printf("д���ļ��ɹ���\n");
				}
				getchar();break;
			case 22:
				system("cls");
				printf("����������ı�ţ�0-19����");
				scanf("%d",&num);getchar();
				LoadBiTree(&Forest[num]);
				printf("�ļ������ɹ���\n");
				getchar();break;	
		}
	}
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
} 

//ջ 
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

//����ջS
int DestroyStack(Stack S)
{
	free(S->base);
	free(S);
	S = NULL;
	return OK;
}

//�� 
int InitBiTree(void)//����յ�ɭ�� 
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
	printf("�Ƿ�Ϊ�ս�㣿y or n\n");
	ch=getchar();getchar();
	if((ch == 'y') || (ch == 'Y'))
		T = NULL;
	else
	{
		T=(BiTree)malloc(sizeof(BiTNode));
		printf("�������ż�����\n");
		printf("��ţ�");
		scanf("%d",&(T->data.number));
		printf("���֣�");
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
		printf("����������ڣ�\n");
		return 0; 
	}	
	else
	{
		printf("���ڵ���Ϊ%d,����Ϊ%s\n",T->data.number,T->data.name);
		return 1;	
	}
}

BiTree Value(BiTree T,int e)//������� 
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
			 	printf("�������ţ�");
				scanf("%d",&p->data.number);
				printf("���������֣�");
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
				printf("���ڼ�������Ϊ�������룿\n");
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
	while((p != NULL) || !IsStackEmpty(S))//�޷������㲻���ڵ������ò����ջ������ 
	{
		while(p != NULL)
		{
			Push(S,p);
			if(p->data.number == e)
			{
				if(LR == 1)
					if(DestroyBiTree(&(p->lchild)) == 0)
						printf("����Ϊ����\n");
				if(LR == 0)
					if(DestroyBiTree(&(p->rchild)) == 0)
						printf("����Ϊ����\n");
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
    PrintLevel(T->lchild,  level-1);// �������� level - 1 �� 
    PrintLevel(T->rchild, level-1); // �������� level - 1 ��
}

int SaveBiTree(BiTree T)
{
	BiTree p=T;
	Stack S;
	InitStack(S);
	FILE *in;
	if((in = fopen("shuju.txt","w")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
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
  		printf("�ļ���ʧ�ܣ�\n"); 
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
	 
