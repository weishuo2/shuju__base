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

status IntiaList(ListNode **L);// �������� 
status DestroyList(ListNode *L); //�ݻ����� 
status ClearList(ListNode *L);//������� 
status ListEmpty(ListNode * L);//�п����� 
status ListLength(ListNode * L);//�������� 
status GetElem(ListNode *L, int i, ElemType *e); //��ȡָ��Ԫ�� 
status LocateElem(ListNode * L, ElemType e);//ָ��Ԫ��λ�� 
status PriorElem(ListNode * L, ElemType e, ElemType* pre);//ָ��Ԫ��ǰ�� 
status NextElem(ListNode * L, ElemType cur_e, ElemType* next_e);//ָ��Ԫ�غ�� 
status ListInsert(ListNode **L, int i, ElemType e);//����ָ��Ԫ�� 
status ListDelete(ListNode **L, int i, ElemType* e);//ɾ��ָ��Ԫ�� 
status ListTrabverse(ListNode * L);//�������� 
status SaveFile(ListNode * L);//�����ļ� 
status LoadFile(ListNode **L);//�����ļ� 
status creat_kindlist(ListNode **L);//����д�� 

int main(void) 
{
	int op = 1, e,pre, next, m;
	ListNode *L;
	int i;
	while (op) {
		system("cls");
		system("color 1F");//ϵͳ�������ɫ
		printf("\t\t********************************************************************\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                     ��������ʵ�ֲ˵� ��                        *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                      0.�˳�ϵͳ                                  *\n");
		printf("\t\t*                      1.��ʼ����                                  *\n");
		printf("\t\t*                      2.�������б�                                *\n");
		printf("\t\t*                      3.������б�                                *\n");
		printf("\t\t*                      4.�ж��Ƿ�Ϊ�ձ�                            *\n");
		printf("\t\t*                      5.���ĳ���                                *\n");
		printf("\t\t*                      6.��ȡָ��Ԫ��                              *\n");
		printf("\t\t*                      7.����ָ��Ԫ��                              *\n");
		printf("\t\t*                      8.���ָ��Ԫ��ǰ��                          *\n");
		printf("\t\t*                      9.���ָ��Ԫ�غ��                          *\n");
		printf("\t\t*                      10.����ָ��Ԫ��                             *\n");
		printf("\t\t*                      11.ɾ��ָ��Ԫ��                             *\n");
		printf("\t\t*                      12.������                                   *\n");
		printf("\t\t*                      13.�����ļ�                                 *\n");
		printf("\t\t*                      14.�����ļ�                                 *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t********************************************************************\n\n");
		printf("\t\t                       ���������ѡ��");
		scanf("%d",&op); 
		switch (op)
		{
		case 1:
			//printf("\n----IntiaList���ܴ�ʵ�֣�\n");
			if (IntiaList(&L) == OK) 
				printf("���Ա����ɹ���\n");
			else 
				printf("���Ա���ʧ�ܣ�\n");
			getchar();getchar();
			break;
		case 2:
			//printf("\n----DestroyList���ܴ�ʵ�֣�\n");
			if (DestroyList(L) == OK) 
				printf("���Ա����ٳɹ���\n");
			else 
				printf("���Ա�����ʧ�ܣ�\n");
			getchar();getchar();
			break;
		case 3:
			//printf("\n----ClearList���ܴ�ʵ�֣�\n");
			if (ClearList(L) == OK) 
				printf("���Ա���ճɹ���\n");
			else 
				printf("���Ա����ʧ�ܣ�\n");
			getchar();getchar();
			break;
		case 4:
			//printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
			if (ListEmpty(L) == OK) 
				printf("���Ա�Ϊ�գ�\n");
			else 
				printf("���Ա�Ϊ�գ�\n");
			getchar();getchar();
			break;
		case 5:
			//printf("\n----ListLength���ܴ�ʵ�֣�\n");
			printf("���Ա���Ϊ%d\n", ListLength(L));
			getchar();getchar();
			break;
		case 6:
			//printf("\n----GetElem���ܴ�ʵ�֣�\n");
			if (ListEmpty(L) == OK)
			{
				printf("��Ϊ�գ����ɽ��и������\n");
				getchar();getchar();
			}
			else
			{
				printf("������Ҫ��ѯ�����ݵ�������");
				scanf("%d", &i);
				if (GetElem(L, i, &e) == OK) 
					printf("���е�%d������Ϊ%d\n", i, e);
				else 
					printf("��ѯʧ�ܣ�\n");
				getchar();getchar();
			}
			break;
		case 7:
			//printf("\n----LocateElem���ܴ�ʵ�֣�\n");
			if (ListEmpty(L) == OK)
			{
				printf("��Ϊ�գ����ɽ��и������\n");
				getchar();getchar();
			}
			else
			{
				printf("������Ҫ��ѯ�����ݣ�\n");
				scanf("%d", &e);
				m = LocateElem(L, e);
				if (m != ERROR)
				{
					printf("L�е�һ�����ѯ������ȵ����ݵ�λ��Ϊ%d\n", m);
				}
				else
				{
					printf("������Ԫ�ز����ڣ�\n");
				}
				getchar();getchar();
			}
			break;
		case 8:
			if (ListEmpty(L) == OK)
			{
				printf("��Ϊ�գ����ɽ��и������\n");
				getchar();getchar();
			}
			else
			{
				printf("������Ҫ��ѯ��Ԫ�أ�");
				scanf("%d", &e);
				if (PriorElem(L, e, &pre) == OK) printf("ǰ��Ϊ%d\n", pre);
				else printf("��Ԫ����ǰ��\n");
				getchar();getchar();
			}
			break;
		case 9:
			if (ListEmpty(L) == OK)
			{
				printf("��Ϊ�գ����ɽ��и������\n");
				getchar();getchar();
			}
			else
			{
					printf("������Ҫ��ѯ��Ԫ�أ�");
				scanf("%d", &e);
				if (NextElem(L, e, &next) == OK) printf("���Ϊ%d\n", next);
				else printf("��Ԫ���޺��\n");
				getchar();getchar();
			}
			break;
		case 10:
			printf("���������λ��i��");
			scanf("%d", &i);
			printf("����������e��");
			scanf("%d", &e);
			if (ListInsert(&L, i, e) == OK) 
				printf("���Ա����ɹ�\n");
			else 
				printf("���Ա����ʧ��\n");
			getchar();getchar();
			break;
		case 11:
			if (ListEmpty(L))
			{
				printf("��Ϊ�գ����ɽ��и������\n");
				getchar();getchar();
			}
			else
			{
				printf("������Ҫɾ����Ԫ�ص����У�");
				scanf("%d", &i);
				if (ListDelete(&L, i, &e) == OK) 
				{
					printf("Ԫ��ɾ���ɹ�\n");
					printf("ɾ��Ԫ��Ϊ%d\n",e);
				}
				else printf("Ԫ��ɾ��ʧ��\n");
				getchar();getchar();
			}
			break;
		case 12:
			//printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");     
			if (!ListTrabverse(L)) 
				printf("���Ա��ǿձ�\n");
			getchar();getchar();
			break;
		case 13:
			if(SaveFile(L))
				printf("���ݱ���ɹ�!\n"); 
			getchar();getchar();
			break;
		case 14:
			if(LoadFile(&L))
				printf("��������ɹ���\n");
			getchar();getchar();
			break;
		case 0:
			SaveFile(L);
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
	int j=1; //������ 
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
	int j=1;//������ 
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
	printf("\n-----------������Ԫ�ؽ��м��-----------------------\n");
	while (p)
	{
		printf("��%d��Ԫ�ص�Ԫ��ֵΪ%d\n\n", i, p->data);
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
		printf("�ļ���ʧ�ܣ�\n");
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
  		printf("�ļ���ʧ�ܣ�\n"); 
  		return ERROR;
  	}
	IntiaList(&p);
	while( !feof(out) )
	{
		fscanf(out, "%d\n", &e);
		ListInsert(&p, 1, e);//�Բ�����ʽ��Ԫ�� 
	}
	fclose(out);
	*L = p;
	return OK;
}

