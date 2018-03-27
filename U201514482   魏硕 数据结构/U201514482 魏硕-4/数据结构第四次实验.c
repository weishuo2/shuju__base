#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20

typedef int status;
typedef char VertexType;

typedef struct ArcNode { //������Ϣ 
	int adjvex; //�û���ָ��Ķ����λ�� 
	struct ArcNode *nextarc; //ָ����һ������ָ��
	int Weight; //������¼����Ȩֵ 
}ArcNode;

typedef struct VNode { //�����Ϣ 
	VertexType data;//������Ϣ 
	ArcNode *firstarc; //ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {//ͼ��Ϣ 
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ��� 
	int kind; //ͼ�������־ 
}aLGraph, *ALGraph;

typedef struct Queue {
	int *base;
	int capacity;  //�������
	int front;
	int rear;
	int now; //��ǰ����
}*Queue;

ALGraph G[MAX_VERTEX_NUM];//�洢���ͼ 
int visited[MAX_VERTEX_NUM];//���ʱ�ǣ�0��ʾδ���ʹ���1��ʾ���ʹ�

//ͼ 
int InitGraphs(void);//ͼ��Ϊ�� 
ALGraph CreateGraph(ALGraph G);//����ͼ 
ALGraph DestroyGraph(ALGraph T);//����ͼ 
status LocateVex(ALGraph G, VertexType ch);//�������ݣ��ж��ýڵ�λ�� 
VNode* GetVex(ALGraph G, VertexType ch);//���ָ������ָ�� 
status PutVex(ALGraph G, VertexType v, VertexType ch);//�滻ָ������ֵ 
status FirstAdjVex(ALGraph G, VertexType ch);//���ָ�������һ���ڽӵ�λ�� 
status NextAdjVex(ALGraph G, VertexType v, VertexType ch);//������һ���ڽӵ� 
status InsertVex(ALGraph G, VertexType ch);//���붥��
status DeleteVex(ALGraph G, VertexType ch);//ɾ������ 
status InsertArc(ALGraph G, VertexType v1, VertexType v2);//����һ���� 
status DeleteArc(ALGraph G, VertexType v1, VertexType v2);//ɾ��һ���� 
status DFSTraverse(ALGraph G);//������ȱ��� 
status DFS(ALGraph G, int v);
status BFSTraverse(ALGraph G);//������ȱ��� 
int Save(ALGraph G);//���浽�ļ� 
ALGraph Load(ALGraph G);//���ļ��ж��� 

//���в�������
int InitQueue(Queue Q);//�������� 
int EnQueue(Queue Q, int e);//��� 
int DeQueue(Queue Q);//���� 
int IsQueueEmpty(Queue Q); //�п� 
int DestroyQueue(Queue Q);//�ݻٶ��� 

int main(void)   
{				
	int i,op=1,back;
	char e1,e2;
	VNode* p=NULL;
	InitGraphs(); 
	while (op)
	 {
		system("cls");
		system("color 1F");//ϵͳ�������ɫ
		printf("\t\t********************************************************************\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                     ��ͼ�Ĺ���ʵ�ֲ˵� ��                        *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                      0.�˳�ϵͳ                                  *\n");
		printf("\t\t*                      1.����ͼ                                    *\n");
		printf("\t\t*                      2.����ͼ                                    *\n");
		printf("\t\t*                      3.���Ҷ���                                  *\n");
		printf("\t\t*                      4.��ö���ֵ                                *\n");
		printf("\t\t*                      5.���㸳ֵ                                  *\n");
		printf("\t\t*                      6.��õ�һ�ڽӵ�                            *\n");
		printf("\t\t*                      7.�����һ�ڽӵ�                            *\n");
		printf("\t\t*                      8.���붥��                                  *\n");
		printf("\t\t*                      9.ɾ������                                  *\n");
		printf("\t\t*                      10.���뻡                                   *\n");
		printf("\t\t*                      11.ɾ����                                   *\n");
		printf("\t\t*                      12.������ȱ���                             *\n");
		printf("\t\t*                      13.������ȱ���                             *\n");
		printf("\t\t*                      14.�����ļ�                                 *\n");
		printf("\t\t*                      15.���ļ��ж�����                           *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t********************************************************************\n\n");
		printf("\t\t                       ���������ѡ��");
		scanf("%d",&op);getchar();
		switch(op)
		{
			case 1:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				G[i]=CreateGraph(G[i]);
				printf("�ɹ�����ͼ��\n");
				getchar();
				break;
			case 2:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 
				G[i]=DestroyGraph(G[i]);
				printf("��ͼ���ٳɹ���\n");
				getchar();
				break;
			case 3:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("��������Ҫ���ҵĽ���ֵ��");
				e1=getchar();getchar(); 
				back=LocateVex(G[i],e1);
				if(back == -1)
					printf("�ý�㲻����\n");
				else
					printf("�ý��λ��Ϊ%d\n",back);		
				getchar();
				break;
			case 4:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("��������Ҫ���ҵĽ���ֵ��");
				e1=getchar();getchar(); 
				p=GetVex(G[i],e1);
				if(p == NULL)
					printf("�ý�㲻����\n");
				else
					printf("�ý��ֵΪ%c\n",p->data);
				getchar();
				break;
			case 5:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 		
				printf("��������Ҫ�ı�Ľ���ֵ��");
				e1=getchar();getchar(); 
				printf("�ı���ֵ��");
				e2=getchar();getchar();
				if(PutVex(G[i],e1,e2))
					printf("�޸ĳɹ���\n");
				else 
					printf("�ý�㲻����!\n"); 
				getchar();break;
			case 6:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("��������Ҫ���ҵĽ���ֵ��");
				e1=getchar();getchar(); 
				back=FirstAdjVex(G[i],e1);
				if(back == -1)
					printf("�õ�һ�ڽӵ㲻����\n");
				else
					printf("�õ�һ�ڽӵ�λ��Ϊ%d\n",back);		
				getchar();break;
			case 7:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("��������Ҫ���ҵĽ���ֵ��");
				e1=getchar();getchar(); 
				printf("������ָ�����ڽӵ㣺");
				e2=getchar();getchar();
				back=NextAdjVex(G[i],e1,e2);
				if(back == -1)
					printf("���ڽӵ㲻����\n");
				else
					printf("���ڽӵ�λ��Ϊ%d\n",back);
				getchar();break;
			case 8:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();	
				printf("��������Ҫ����Ľ���ֵ��");
				e1=getchar();getchar(); 
				back=InsertVex(G[i],e1);
				printf("����ɹ���\n");
				getchar();break;
			case 9:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 		
				printf("��������Ҫɾ���Ľ���ֵ��");
				e1=getchar();getchar();
				back=DeleteVex(G[i],e1);
				if(back == 0)
					printf("�ý�㲻����\n");
				else
					printf("ɾ���ɹ���\n");
				getchar();break;
			case 10:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("�����������Ļ��ĵ�һ������ֵ��");
				e1=getchar();getchar(); 
				printf("�����������Ļ��ĵڶ�������ֵ��");
				e2=getchar();getchar();
				back=InsertArc(G[i],e1,e2);
				if(back == 0)
					printf("��㲻����\n");
				else
					printf("����ɹ���\n");
				getchar();break; 
			case 11:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 		
				printf("������ɾ���Ļ��ĵ�һ������ֵ��");
				e1=getchar();getchar(); 
				printf("������ɾ���Ļ��ĵڶ�������ֵ��");
				e2=getchar();getchar();
				back=DeleteArc(G[i],e1,e2);
				if(back == 0)
					printf("��㲻����\n");
				else
					printf("ɾ���ɹ���\n");
				getchar();break; 
			case 12:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("ͼ��������ȱ������Ϊ��\n");
				DFSTraverse(G[i]);
				getchar();break;
			case 13:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				printf("ͼ�Ĺ�����ȱ������Ϊ��\n");
				BFSTraverse(G[i]);
				getchar();break; 
			case 14:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("��ͼΪ��ͼ��\n");
					getchar();
					break;
				} 	
				if(Save(G[i]))
					printf("�ļ�����ɹ���\n");
				else
					printf("�ļ�����ʧ�ܣ�\n");
				getchar();break; 
			case 15:
				system("cls");
				printf("�������ͼ�ı�ţ�0-19����");
				scanf("%d",&i);getchar();
				G[i]=Load(G[i]);
				printf("�ļ���ȡ�ɹ���\n");
				getchar();break;	
		}
	}
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
} 

int InitQueue(Queue Q)
{
	Q->base = (int *)malloc(sizeof(int) * MAX_VERTEX_NUM);
	Q->capacity = MAX_VERTEX_NUM;
	Q->front = 0;
	Q->rear = 0;
	Q->now = 0;
	return OK;
}

int EnQueue(Queue Q, int e)
{
	Q->now++;
	Q->base[Q->rear] = e;
	Q->rear++;
	return OK;
}

int DeQueue(Queue Q)
{
	int e;
	if (IsQueueEmpty(Q))
		return -1;
	else
	{
		e = Q->base[Q->front];
		Q->now--;
		Q->front++;
		return e;
	}
}

int IsQueueEmpty(Queue Q)
{
	if (Q->now == 0)
		return TRUE;
	else
		return FALSE;
}

int DestroyQueue(Queue Q)
{
	free(Q->base);
	free(Q);
	Q = NULL;
	return OK;
}

int InitGraphs(void)
{
	int i;
	for (i = 0; i<MAX_VERTEX_NUM; i++)
		G[i] = NULL;
	return OK;
}

ALGraph CreateGraph(ALGraph T)
{
	int i, j, weight;
	char tou, wei;
	ArcNode *p;
	T = (ALGraph)malloc(sizeof(aLGraph));
	printf("������ͼ������:");
	scanf("%d", &i); getchar();
	if(i<1 || i>4)
	{
		printf("���ʹ���\n");
		return NULL;
	}
	T->kind=i;
	printf("������ͼ�Ķ�����:");
	scanf("%d", &T->vexnum); getchar();
	printf("������ͼ�ı���:");	
	scanf("%d", &T->arcnum); getchar();	
	printf("����ͼ:0  ������:1  ����ͼ:2  ������:3\n");
	for (i = 0; i < T->vexnum; i++)
	{
		printf("�����%d������ֵ:", i);
		scanf("%c", &T->vertices[i].data); getchar();
		T->vertices[i].firstarc = NULL;
	} 
	for (i = 0; i < T->arcnum; i++)
	{
		if (T->kind == 1 || T->kind == 3)
		{
			printf("�������%d������Ȩֵ:",i);
			scanf("%d", &weight); getchar();
			printf("�����뻡ͷ:");
			scanf("%c", &tou); getchar();
			printf("�����뻡β:");
			scanf("%c", &wei); getchar();
		}
		else
		{
			printf("�����뻡ͷ:");
			scanf("%c", &tou); getchar();
			printf("�����뻡β:");
			scanf("%c", &wei); getchar();
		}
		p = (ArcNode*)malloc(sizeof(ArcNode));
		j = LocateVex(T, wei);	
		i = LocateVex(T, tou);
		p->adjvex = j;
		if (T->kind == 1 || T->kind == 3)
			p->Weight = weight;
		else
			p->Weight = 0;
		p->nextarc = T->vertices[i].firstarc;//���ڱ�ͷ 
		T->vertices[i].firstarc = p;
		if (T->kind >= 2)//Ϊ����Ļ�����Ҫ�������ӻ� 
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			p->nextarc = T->vertices[j].firstarc; //���ڱ�ͷ
			T->vertices[j].firstarc = p;
		}
	}
	return T;
}

ALGraph DestroyGraph(ALGraph T)
{
	int i;
	ArcNode *p, *pcrs;
	if (T == NULL)
		return NULL;
	for (i = 0; i < T->vexnum; i++)
	{
		p = T->vertices[i].firstarc;
		while (p != NULL)
		{
			pcrs = p->nextarc;
			free(p);
			p = pcrs;
		}
	}
	free(T);
	T = NULL;
	return T;
}

status LocateVex(ALGraph G, VertexType ch)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
		if (G->vertices[i].data == ch)
			return i;
	return -1;
}

VNode* GetVex(ALGraph G, VertexType ch)
{
	int e;
	e = LocateVex(G, ch);
	if (e != -1)
		return &G->vertices[e];
	else
		return NULL;
}

status PutVex(ALGraph T, VertexType v, VertexType ch)
{
	int e;
	e = LocateVex(T, v);
	if (e != -1)
	{
		T->vertices[e].data = ch;
		return OK;
	}
	else
		return 0;
}

status FirstAdjVex(ALGraph G, VertexType ch)
{
	ArcNode *p;
	int e;
	e = LocateVex(G, ch);
	if (e == -1)
		return -1;
	else
	{
		p = G->vertices[e].firstarc;
		if (p != NULL)
			return p->adjvex;
		else
			return -1;
	}
}

status NextAdjVex(ALGraph G, VertexType v, VertexType ch)
{
	ArcNode *p;
	int e1, e2;
	e1 = LocateVex(G, v);
	e2 = LocateVex(G, ch);
	if (e1 == -1 || e2 == -1)
		return -1;
	p = G->vertices[e1].firstarc;
	while ((p != NULL) && (p->adjvex != e2))
		p = p->nextarc;
	if (p == NULL)
		return -1;
	else if (p->nextarc == NULL)
		return -1;
	else
		return p->nextarc->adjvex;
}

status InsertVex(ALGraph T, VertexType ch)//��������λ�� 
{
	if(LocateVex(T,ch) != -1)
	{
		printf("����Ѿ����ڣ�\n");
		return FALSE;
	}
	T->vertices[T->vexnum].data = ch;
	T->vertices[T->vexnum].firstarc = NULL;
	T->vexnum++;
	return OK;
}

status DeleteVex(ALGraph G, VertexType ch)
{
	ArcNode *p, *pcrs;
	int i, j;
	j = LocateVex(G, ch);
	if (j == -1)
		return ERROR;
	p = G->vertices[j].firstarc;	
	while (p)//�ͷ�������chΪͷ���Ļ� 
	{
		pcrs = p;
		p = p->nextarc;
		free(pcrs);
		G->arcnum--;
	}
	for (i = j; i < G->vexnum - 1; i++) //���нڵ�ǰ��һλ 
		G->vertices[i] = G->vertices[i + 1];
	G->vexnum--;
	for (i = 0; i < G->vexnum; i++)
	{
		p = G->vertices[i].firstarc;
		while (p != NULL)
		{
			if (p->adjvex != j)
			{	
				if (p->adjvex > j)//�ڵ���Ÿı� 
					p->adjvex--;
				pcrs = p;
				p = p->nextarc;
			
			}
			else
			{
				if (G->vertices[i].firstarc == p)
				{
					G->vertices[i].firstarc = p->nextarc;
					free(p);
					p = G->vertices[i].firstarc;
					if (G->kind < 2)
						G->arcnum--;
				}
				else
				{
					pcrs->nextarc = p->nextarc;
					free(p);
					p = pcrs->nextarc;
					if (G->kind < 2)
						G->arcnum--;
				}
			}
		}
	}
	return OK;
}

status InsertArc(ALGraph T, VertexType v1, VertexType v2)
{
	ArcNode *p,*adj;
	int i, j;
	i = LocateVex(T, v1);
	j = LocateVex(T, v2);
	if (i == -1 || j == -1)
		return ERROR;
	adj=T->vertices[i].firstarc;
	while(adj != NULL)
	{
		if(adj->adjvex == j)
			return FALSE;
		adj=adj->nextarc;
	}
	p = (ArcNode*)malloc(sizeof(ArcNode));
	if (T->kind == 2 || T->kind == 4)
	{
		printf("�����뻡��Ȩֵ:");
		scanf("%d", &p->Weight); getchar();
	}
	else
		p->Weight = 0;
	p->adjvex = j;
	p->nextarc = T->vertices[i].firstarc;
	T->vertices[i].firstarc = p;
	T->arcnum++;
	if (T->kind >= 2)
	{
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = T->vertices[j].firstarc;
		T->vertices[j].firstarc = p;
	}
	return OK;
}

status DeleteArc(ALGraph T, VertexType v1, VertexType v2)
{
	int i, j;
	ArcNode *p, *pcrs;
	i = LocateVex(T, v1);
	j = LocateVex(T, v2);
	if (i == -1 || j == -1)
		return ERROR;
	p = T->vertices[i].firstarc;
	if (p->adjvex == j)
		T->vertices[i].firstarc = p->nextarc;
	else
	{
		while ((p != NULL) && (p->adjvex != j))
		{
			pcrs = p;
			p = p->nextarc;
		}
	}
	if (p->adjvex == j)
	{
		pcrs->nextarc = p->nextarc;
		free(p);
		T->arcnum--;
		if (T->kind >= 2)
		{
			p = T->vertices[j].firstarc;
			if (p->adjvex == i)
				T->vertices[j].firstarc = p->nextarc;
			else
			{
				while ((p != NULL) && (p->adjvex != i))
				{
					pcrs = p;
					p = p->nextarc;
				}
			}
			if (p->adjvex == i)
			{
				pcrs->nextarc = p->nextarc;
				free(p);
			}
			if (p == NULL)
				return FALSE;
		}
	}
	if (p == NULL)
		return FALSE;
	return OK;
}

status DFSTraverse(ALGraph G)
{
	int i, j;
	for (i = 0; i < G->vexnum; i++)
		visited[i] = 0;
	for (j = 0; j < G->vexnum; j++)
		if (visited[j] == 0)
			DFS(G, j);
	return OK;
}

status DFS(ALGraph G, int v)
{
	ArcNode* arc;
	if (visited[v] != 1)
	{
		printf("%d %c\n", v, G->vertices[v].data);
		visited[v] = 1;
	}
	arc = G->vertices[v].firstarc;
	while (arc != NULL)
	{
		if (!visited[arc->adjvex])
			DFS(G, arc->adjvex);
		arc = arc->nextarc;
	}
	return OK;
}

status BFSTraverse(ALGraph G)
{
	int i, v;
	ArcNode* arc;
	Queue Q;
	Q = (Queue)malloc(sizeof(struct Queue));
	InitQueue(Q);
	for (i = 0; i < G->vexnum; i++)
		visited[i] = 0;
	for (v = 0; v < G->vexnum; v++)
	{
		if (visited[v] == 0)
		{
			EnQueue(Q,v);
			while (!IsQueueEmpty(Q))
			{
				v = DeQueue(Q);
				if (visited[v] != 1)
				{
					printf("%d %c\n", v, G->vertices[v].data);
					visited[v] = 1;
				}
				arc = G->vertices[v].firstarc;
				for(;arc != NULL;arc = arc->nextarc)
					EnQueue(Q, arc->adjvex);
			}
		}
	}
	DestroyQueue(Q);
	return OK;
}

int Save(ALGraph G)
{
	FILE *fp;
	int i;
	ArcNode* arc;
	if ((fp = fopen("shuju.txt", "w+")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return ERROR;
	}
	fprintf(fp, "������� %d\n", G->vexnum);
	fprintf(fp, "������ %d\n", G->arcnum);
	fprintf(fp, "ͼ������Ϊ�� %d\n", G->kind);
	for(i = 0 ; i < G->vexnum; i++)
		 fprintf(fp, "%c ", G->vertices[i].data);
	fprintf(fp, "\n");
	for (i = 0; i < G->vexnum; i++)
	{
		fprintf(fp, "%d %c ", i, G->vertices[i].data);
		arc = G->vertices[i].firstarc;
		while (arc != NULL)
		{
			fprintf(fp, "%d ", arc->adjvex);
			arc = arc->nextarc;
		}
		fprintf(fp, "-1\n");
	}
	fclose(fp);
	return OK;
}

ALGraph Load(ALGraph G)
{
	FILE *fp;
	char line[256];
	int i, e;
	G = (ALGraph)malloc(sizeof(aLGraph));
	fp = fopen("shuju.txt", "r");
	fgets(line, 250, fp);
	sscanf(line, "%*s%d", &(G->vexnum));
	fgets(line, 250, fp);
	sscanf(line, "%*s%d", &G->arcnum);
	fgets(line, 250, fp);
	sscanf(line, "%*s%d", &G->kind);
	fgets(line, 250, fp);
	for (i = 0; i < G->vexnum; i++)
		G->vertices[i].firstarc = NULL;
	for (i = 0; i < G->vexnum; i++)
		G->vertices[i].data = line[i * 2];
	for (i = 0; i < G->vexnum; i++)
	{
		fscanf(fp, "%*d	%c", &G->vertices[i].data);
		fscanf(fp, "%d", &e);
		while (e != -1)
		{
			InsertArc(G, G->vertices[i].data, G->vertices[e].data);
			G->arcnum--;
			fscanf(fp, "%d", &e);
		}
		fgetc(fp);
	}
	fclose(fp);
	return G;
}
