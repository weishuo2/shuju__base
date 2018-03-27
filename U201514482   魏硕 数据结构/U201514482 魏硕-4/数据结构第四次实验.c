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

typedef struct ArcNode { //弧的信息 
	int adjvex; //该弧所指向的顶点的位置 
	struct ArcNode *nextarc; //指向下一条弧的指针
	int Weight; //用来记录网的权值 
}ArcNode;

typedef struct VNode { //结点信息 
	VertexType data;//顶点信息 
	ArcNode *firstarc; //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {//图信息 
	AdjList vertices;
	int vexnum, arcnum; //图的当前顶点数和弧数 
	int kind; //图的种类标志 
}aLGraph, *ALGraph;

typedef struct Queue {
	int *base;
	int capacity;  //最大容量
	int front;
	int rear;
	int now; //当前个数
}*Queue;

ALGraph G[MAX_VERTEX_NUM];//存储多个图 
int visited[MAX_VERTEX_NUM];//访问标记，0表示未访问过，1表示访问过

//图 
int InitGraphs(void);//图置为空 
ALGraph CreateGraph(ALGraph G);//创建图 
ALGraph DestroyGraph(ALGraph T);//销毁图 
status LocateVex(ALGraph G, VertexType ch);//给定数据，判定该节点位置 
VNode* GetVex(ALGraph G, VertexType ch);//获得指定顶点指针 
status PutVex(ALGraph G, VertexType v, VertexType ch);//替换指定结点的值 
status FirstAdjVex(ALGraph G, VertexType ch);//获得指定顶点第一个邻接点位置 
status NextAdjVex(ALGraph G, VertexType v, VertexType ch);//返回下一个邻接点 
status InsertVex(ALGraph G, VertexType ch);//插入顶点
status DeleteVex(ALGraph G, VertexType ch);//删除顶点 
status InsertArc(ALGraph G, VertexType v1, VertexType v2);//新增一条弧 
status DeleteArc(ALGraph G, VertexType v1, VertexType v2);//删除一条弧 
status DFSTraverse(ALGraph G);//深度优先遍历 
status DFS(ALGraph G, int v);
status BFSTraverse(ALGraph G);//广度优先遍历 
int Save(ALGraph G);//保存到文件 
ALGraph Load(ALGraph G);//从文件中读出 

//队列操作函数
int InitQueue(Queue Q);//创建队列 
int EnQueue(Queue Q, int e);//入队 
int DeQueue(Queue Q);//出队 
int IsQueueEmpty(Queue Q); //判空 
int DestroyQueue(Queue Q);//摧毁队列 

int main(void)   
{				
	int i,op=1,back;
	char e1,e2;
	VNode* p=NULL;
	InitGraphs(); 
	while (op)
	 {
		system("cls");
		system("color 1F");//系统命令，调颜色
		printf("\t\t********************************************************************\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                     ◆图的功能实现菜单 ◆                        *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t*                      0.退出系统                                  *\n");
		printf("\t\t*                      1.创建图                                    *\n");
		printf("\t\t*                      2.销毁图                                    *\n");
		printf("\t\t*                      3.查找顶点                                  *\n");
		printf("\t\t*                      4.获得顶点值                                *\n");
		printf("\t\t*                      5.顶点赋值                                  *\n");
		printf("\t\t*                      6.获得第一邻接点                            *\n");
		printf("\t\t*                      7.获得下一邻接点                            *\n");
		printf("\t\t*                      8.插入顶点                                  *\n");
		printf("\t\t*                      9.删除顶点                                  *\n");
		printf("\t\t*                      10.插入弧                                   *\n");
		printf("\t\t*                      11.删除弧                                   *\n");
		printf("\t\t*                      12.深度优先遍历                             *\n");
		printf("\t\t*                      13.广度优先遍历                             *\n");
		printf("\t\t*                      14.存入文件                                 *\n");
		printf("\t\t*                      15.从文件中读数据                           *\n");
		printf("\t\t*                                                                  *\n");
		printf("\t\t********************************************************************\n\n");
		printf("\t\t                       请输入你的选择：");
		scanf("%d",&op);getchar();
		switch(op)
		{
			case 1:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				G[i]=CreateGraph(G[i]);
				printf("成功创建图！\n");
				getchar();
				break;
			case 2:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 
				G[i]=DestroyGraph(G[i]);
				printf("该图销毁成功！\n");
				getchar();
				break;
			case 3:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("请输入需要查找的结点的值：");
				e1=getchar();getchar(); 
				back=LocateVex(G[i],e1);
				if(back == -1)
					printf("该结点不存在\n");
				else
					printf("该结点位置为%d\n",back);		
				getchar();
				break;
			case 4:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("请输入需要查找的结点的值：");
				e1=getchar();getchar(); 
				p=GetVex(G[i],e1);
				if(p == NULL)
					printf("该结点不存在\n");
				else
					printf("该结点值为%c\n",p->data);
				getchar();
				break;
			case 5:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 		
				printf("请输入需要改变的结点的值：");
				e1=getchar();getchar(); 
				printf("改变后的值：");
				e2=getchar();getchar();
				if(PutVex(G[i],e1,e2))
					printf("修改成功！\n");
				else 
					printf("该结点不存在!\n"); 
				getchar();break;
			case 6:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("请输入需要查找的结点的值：");
				e1=getchar();getchar(); 
				back=FirstAdjVex(G[i],e1);
				if(back == -1)
					printf("该第一邻接点不存在\n");
				else
					printf("该第一邻接点位置为%d\n",back);		
				getchar();break;
			case 7:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("请输入需要查找的结点的值：");
				e1=getchar();getchar(); 
				printf("请输入指定的邻接点：");
				e2=getchar();getchar();
				back=NextAdjVex(G[i],e1,e2);
				if(back == -1)
					printf("该邻接点不存在\n");
				else
					printf("该邻接点位置为%d\n",back);
				getchar();break;
			case 8:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();	
				printf("请输入需要插入的结点的值：");
				e1=getchar();getchar(); 
				back=InsertVex(G[i],e1);
				printf("插入成功！\n");
				getchar();break;
			case 9:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 		
				printf("请输入需要删除的结点的值：");
				e1=getchar();getchar();
				back=DeleteVex(G[i],e1);
				if(back == 0)
					printf("该结点不存在\n");
				else
					printf("删除成功！\n");
				getchar();break;
			case 10:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();	
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("请输入新增的弧的第一个结点的值：");
				e1=getchar();getchar(); 
				printf("请输入新增的弧的第二个结点的值：");
				e2=getchar();getchar();
				back=InsertArc(G[i],e1,e2);
				if(back == 0)
					printf("结点不存在\n");
				else
					printf("插入成功！\n");
				getchar();break; 
			case 11:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 		
				printf("请输入删除的弧的第一个结点的值：");
				e1=getchar();getchar(); 
				printf("请输入删除的弧的第二个结点的值：");
				e2=getchar();getchar();
				back=DeleteArc(G[i],e1,e2);
				if(back == 0)
					printf("结点不存在\n");
				else
					printf("删除成功！\n");
				getchar();break; 
			case 12:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("图的深度优先遍历结果为：\n");
				DFSTraverse(G[i]);
				getchar();break;
			case 13:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				printf("图的广度优先遍历结果为：\n");
				BFSTraverse(G[i]);
				getchar();break; 
			case 14:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				if(G[i] == NULL)
				{
					printf("该图为空图！\n");
					getchar();
					break;
				} 	
				if(Save(G[i]))
					printf("文件保存成功！\n");
				else
					printf("文件保存失败！\n");
				getchar();break; 
			case 15:
				system("cls");
				printf("请输入该图的编号（0-19）：");
				scanf("%d",&i);getchar();
				G[i]=Load(G[i]);
				printf("文件读取成功！\n");
				getchar();break;	
		}
	}
	printf("欢迎下次再使用本系统！\n");
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
	printf("请输入图的类型:");
	scanf("%d", &i); getchar();
	if(i<1 || i>4)
	{
		printf("类型错误！\n");
		return NULL;
	}
	T->kind=i;
	printf("请输入图的顶点数:");
	scanf("%d", &T->vexnum); getchar();
	printf("请输入图的边数:");	
	scanf("%d", &T->arcnum); getchar();	
	printf("有向图:0  有向网:1  无向图:2  无向网:3\n");
	for (i = 0; i < T->vexnum; i++)
	{
		printf("输入第%d个结点的值:", i);
		scanf("%c", &T->vertices[i].data); getchar();
		T->vertices[i].firstarc = NULL;
	} 
	for (i = 0; i < T->arcnum; i++)
	{
		if (T->kind == 1 || T->kind == 3)
		{
			printf("请输入第%d条弧的权值:",i);
			scanf("%d", &weight); getchar();
			printf("请输入弧头:");
			scanf("%c", &tou); getchar();
			printf("请输入弧尾:");
			scanf("%c", &wei); getchar();
		}
		else
		{
			printf("请输入弧头:");
			scanf("%c", &tou); getchar();
			printf("请输入弧尾:");
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
		p->nextarc = T->vertices[i].firstarc;//插在表头 
		T->vertices[i].firstarc = p;
		if (T->kind >= 2)//为无向的话，需要额外增加弧 
		{
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			p->nextarc = T->vertices[j].firstarc; //插在表头
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

status InsertVex(ALGraph T, VertexType ch)//插在最后的位置 
{
	if(LocateVex(T,ch) != -1)
	{
		printf("结点已经存在！\n");
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
	while (p)//释放所有以ch为头结点的弧 
	{
		pcrs = p;
		p = p->nextarc;
		free(pcrs);
		G->arcnum--;
	}
	for (i = j; i < G->vexnum - 1; i++) //所有节点前移一位 
		G->vertices[i] = G->vertices[i + 1];
	G->vexnum--;
	for (i = 0; i < G->vexnum; i++)
	{
		p = G->vertices[i].firstarc;
		while (p != NULL)
		{
			if (p->adjvex != j)
			{	
				if (p->adjvex > j)//节点序号改变 
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
		printf("请输入弧的权值:");
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
		printf("文件打开失败！\n");
		return ERROR;
	}
	fprintf(fp, "结点数： %d\n", G->vexnum);
	fprintf(fp, "弧数： %d\n", G->arcnum);
	fprintf(fp, "图的种类为： %d\n", G->kind);
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
