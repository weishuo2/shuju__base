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
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;
/*-----page 19 on textbook ---------*/
status IntiaList(SqList *L);// �������� 
status DestroyList(SqList *L);//�ݻ����� 
status ClearList(SqList *L);//������� 
status ListEmpty(SqList L);//�пձ� 
status ListLength(SqList L);//��� 
status GetElem(SqList L, int i, ElemType *e);//��ȡԪ�� 
status LocateElem(SqList L, ElemType e); //�򻯹� ��λԪ�� 
status PriorElem(SqList L, ElemType cur_e, ElemType * pre);//��ǰ�� 
status NextElem(SqList L,ElemType cur_e,ElemType * next);//���� 
status ListInsert(SqList * L,int i,ElemType e);//����Ԫ�� 
status ListDelete(SqList * L, int i, ElemType * e);//ɾ��Ԫ�� 
status ListTrabverse(SqList L);  //�򻯹� �������� 
status load_List(SqList *L);// ���ļ����� 
status Listfile(SqList *L);//���浽�ļ�
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
		printf("    ��ѡ����Ĳ���[0~15]:");
		scanf("%d", &op);getchar();
		switch (op) 
		{
			case 1:
				if (IntiaList(&L) == OK) printf("    ���Ա����ɹ���\n");
				else printf("    ���Ա���ʧ�ܣ�\n");
				getchar();
				break;
			case 2:
				if (DestroyList(&L) == OK) printf("    ���Ա����ٳɹ���\n");
				else printf("    ���Ա�����ʧ�ܣ�\n");
				getchar();
				break;
			case 3:
				if (ClearList(&L) == OK) printf("    ���Ա���ճɹ���\n");
				else printf("    ���Ա����ʧ�ܣ�\n");
				getchar();
				break;
			case 4:
				if (ListEmpty(L) == OK) printf("    ���Ա�Ϊ�գ�\n");
				else printf("    ���Ա�Ϊ�գ�\n");
				getchar();
				break;
			case 5:
				printf("    ���Ա���Ϊ%d\n", ListLength(L));
				getchar();
				break;
			case 6:
				if(L.length == 0)
				{
					printf("    ��Ϊ�գ��޷�����\n");
					getchar();
				}
				else
				{
					printf("    ������Ҫ��ѯ��������");
					scanf("%d", &i);getchar();
					GetElem(L, i,&e); 
					if (GetElem(L, i,&e) == OK) printf("    ���е�%d������Ϊ%d\n", i, e);
					else printf("    ��ѯʧ�ܣ�\n");
					getchar();
				}
			
				break;
			case 7:
				if(L.length == 0)
				{
					printf("    ��Ϊ�գ��޷�����\n");
					getchar();
				}
				else
				{
					printf("    ������Ҫ��ѯ�����ݣ�");
					scanf("%d", &e);getchar();
					m = LocateElem(L, e);
					if (m != ERROR)
					{
						printf("    L�е�һ�����ѯ������ȵ����ݵ�λ��Ϊ%d\n", m);
					}
					else
					{
						printf("    ����������Ԫ�ز����ڣ�\n");
					}
					getchar();
				}
				break;
			case 8:
				if(L.length == 0)
				{
					printf("    ��Ϊ�գ��޷�����\n");
					getchar();
				}
				else
				{
					printf("    ������Ҫ��ѯ��Ԫ�أ�");
					scanf("%d", &cur_e);getchar();
					if (PriorElem(L, cur_e, &pre) == OK) printf("    ǰ��Ϊ%d\n", pre);
					else printf("    �޴�ǰ��\n");
					getchar();
				}
				break;
			case 9:
				if(L.length == 0)
				{
					printf("    ��Ϊ�գ��޷�����\n");
					getchar();
				}
				else
				{
					printf("    ������Ҫ��ѯ��Ԫ�أ�");
					scanf("%d", &cur_e);getchar();
					if (NextElem(L, cur_e, &next) == OK) printf("    ����Ϊ%d\n", next);
					else printf("    �޴˺���\n");
					getchar();
				}
				break;
			case 10:
				printf("    ������λ��i��");
				scanf("%d", &i);
				printf("    ������e��");
				scanf("%d", &e);getchar();
				if (ListInsert(&L, i, e) == OK) printf("    ���Ա����ɹ�\n");
				else printf("    ���Ա����ʧ��\n");
				getchar();
				break;
			case 11:
				if(L.length == 0)
				{
					printf("    ��Ϊ�գ��޷�����\n");
					getchar();
				}
				else
				{
					printf("    ������Ҫɾ����Ԫ�ص����У�");
					scanf("%d", &i);getchar();
					if (ListDelete(&L, i, &e) == OK) 
					{ 
						printf("    Ԫ��ɾ���ɹ�\n");
						printf("    ɾ��Ԫ��ֵΪ%d\n",e); 
					} 
					else printf("    Ԫ��ɾ��ʧ��\n");
					getchar();
				}
				break;
			case 12:     
				if(L.length == 0)
				{
					printf("    ��Ϊ�գ��޷�����\n");
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
					printf("    ��Ϊ�գ��޷�����\n");
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
		printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

 /*--------page 23 on textbook --------------------*/
status IntiaList(SqList *L)  //����һ���յ����� 
{
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	L->listsize = LIST_INIT_SIZE;
	L->length=0;
	return OK;
}

status DestroyList(SqList *L) //���һ�������ͷŴ洢�ռ� 
{
	free(L->elem);
	L->elem = NULL;
	L->length=0;
	return OK;
}

status ClearList(SqList *L)//��һ��������Ϊ�� 
{
	L->length = 0;
	return OK;
}

status ListEmpty(SqList L)//�жϱ��Ƿ�Ϊ��
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L) //����� 
{
	return L.length;
}

status GetElem(SqList L,int i,ElemType *e)//ȡ�����е�i��Ԫ�ز����� 
{
	if((i < 0) || (i >= L.length))
		return FALSE;
	*e = *(L.elem+i-1);
	return OK;
}

int LocateElem(SqList L,ElemType e)//���ص�һ����e��ȵ�����λ�� 
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


status ListInsert(SqList *L,int i,ElemType e)//�ڵ�i��Ԫ��ǰ����ֵe 
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

status ListDelete(SqList *L, int i, ElemType *e)//ɾ����i��Ԫ�أ�����e���� 
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

status ListTrabverse(SqList L) //������е�Ԫ�� 
{
	int i;
	printf("\n-----------all elements -----------------------\n");
	for (i=0;i<L.length;i++) printf("%d  ", L.elem[i]);
	printf("\n---------------end ----------------------------\n");
	return OK;
}

status Listfile(SqList *L)//������д���ļ� 
{
	FILE *out1;
	if((out1 = fopen("sunxu.txt","w")) == NULL)
	{
		printf("    �ļ���ʧ�ܣ�\n");
		return 1;
	}
	printf("    �ѱ��浽�ļ���\n");
	fwrite(L->elem,sizeof(ElemType),L->length,out1);
	fclose(out1);
}

status load_List(SqList *L) //���ݵ��� 
{
	FILE *in1; 
  	if((in1 = fopen("sunxu.txt","r")) == NULL)
  	{
  		printf("    �ļ���ʧ�ܣ�\n"); 
  		return 1;
  	}
  	printf("    �Ѵ��ļ�������\n"); 
  	IntiaList(L);
  	L->length=0;
  	while(fread(&L->elem[L->length],sizeof(ElemType),1,in1))
   		L->length++;
	fclose(in1);
}

status writenew(SqList *L)//�ڱ���Ԫ�� 
{
	char ch;
	ch='y';
	ElemType *nw; 
	while(ch=='y' || ch=='Y')
	{
		printf("    ��������:");
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
		printf("    �������룿y or n\n");
		printf("    �������ѡ��:");
		ch=getchar();
		getchar();
	}
	return 1; 
}

