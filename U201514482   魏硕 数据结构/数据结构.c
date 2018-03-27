void union(List &La,List Lb){
	//将所有在b中不在a中元素插入a中
	La_len=ListLength(La);Lb_len=ListLength(Lb);
	for(i=1;i<Lb_len;i++){
		GetElem(Lb,i,e);
		if(!LocateElem(La,e,eaqul)) ListInsert(La,++La_len,e);//++La_len表示在表的末尾插入 
	} 
} //union

//合并a，b表 
void MergeList(List La,List Lb,List &Lc){//&表示它是引用参数
	InitList(Lc);
	i=j=1;k=0;//i是a的计数器，j是b的计数器 
	La_len=ListLength(La); 
	Lb_len=ListLength(Lb); 
	while(i<=La_len && j<=Lb_len)
	{
		GetElem(Lb,j,bj);GetElem(La,i,ai);
		if(ai>bj) {
			ListInsert(Lc,++k,bj);
			j++;
		}
		else{
			ListInsert(Lc,++k,ai);
			i++;
		}
	}
	if(i>La_len)
	{
		for(;j<=Lb_len;j++)
		{
			GetElem(Lb,j,bj);
			ListInsert(Lc,++k,bj);
		}		
	}
	else if(j>Lb_len)
	{
		for(;i<=La_len;i++)
		{
			GetElem(La,i,ai);
			ListInsert(Lc,++k,ai);
		}		
	}	
} 

//分配储存空间 
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	if(i<1 || i>L.Length+1) return ERROR;
	if(L.Length>=L.listsize){//当前空间已经满了
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT) * sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=mewbase;
		L.lsitsize+=LISTINCREMENT; 
	} 
	q=&(L.elem[i-1]);//插入位置
	p=&(L.elem[L.length-1]);
	for(;p>=q;--p) *(p+1)=*(p); 
	*q=e;
	++L.length;
	return Ok;
}

//进制转化
void conversion(){
	const int number=8;
	InitStack(S);
	scanf("%d",&N);
	while(N!=0)
	{
		Push(s,N%8);
		N=N/8; 
	}
	while(!StackEmpty(S)){
		Pop(s,e);
		printf("%d",e);
	}
} //conversion

//行编译处理，#删除前一位，@删除前面所有
void LineEdit()
{
	InitStack(s);
	ch=getchar();
	while(ch !=EOF)//处理所有的数据 
	{
		while(ch!='\n' && ch!=EOF)//处理行 
		{
			switch(ch)
			{
				case '#':Pop(s,c);  break;//未考虑空栈 
				case '@':ClearStack(s); break;
				default :Push(s,ch); break; //未考虑满栈 
			}
			ch=getchar();
		}
		将从栈底到栈顶的栈内字符传送至调用过程的数据区；
		ClearStack(s);
		if(ch !=EOF)  ch=getchar(); 
	}
	DestroyStack(S);
} //LineEdit


//数组元素的定义，构建一个合法数组
Status InitArray(Array &A,int dim,...){
	if(dim<1 || dim>MAX_ARRAY_DIM) return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim * sizeof(int));   //用来存放每一维有多少个非0元素
	if(A.bounds) exit(OVERFLOW);
	elemtotal=1;
	va_start(ap,dim); 
	for(i=0;i<dim;++i)
	{
		A.bounds[i]=va_arg(ap,int);
		if(A.bounds[i]<0) return 0;
		elemtotal *= A.bounds[i];
	}
	va_end(ap);
	A.base=(ElemType *)malloc(elemtotal * sizeof(ElemType));
	if(!A.base) exit(OVERFLOW);
	A.constants=(int *)malloc(dim * sizeof(int));
	if(!A.constants) exit(OVERFLOW);
	A.constants[dim-1]=1;
	for(i=dim-2;i>=0;--i)
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];//标记第i维之前总共有多少个元素
	return OK; 
} 

Status TransposeSMatrix(TSMatrix M,TSMatrix &T)//矩阵转置 
{
	T.mu=M.mu;T.nu=M.mu;T.tu=M.tu;
	if(T.tu)
	{
		q=1;
		for(col=1;col<=M.nu;++col)
			for(p=1;p<=M.tu;++p)
				if(M.data[p].j==col)
				{
					T.data[q].i=M.data[p].j;T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;++q;
				}
				
	}
	return OK;
}

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
{
	T.mu=M.mu;T.nu=M.mu;T.tu=M.tu;
	if(T.tu)
	{
		for(col=1;col<=M.nu;++col) num[col]=0;
		for(t=1;t<=M.tu;++t) ++num[M.data[t].j];//即给出T每一行将会有多少个元素
		cpot[1]=1;//求第col列中第一个非零元素在b.data中的序号
		for(col=2;col<=M.nu;++col) cpDFot[col]=cpot[col-1]+num[col-1];
		for(p=1;p<=M.tu;++p)
		{
			col=M.data[p].j;q=cpot[col];
			T.data[q].i=M.data[p].j;T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e;++cpot[col];//相当于在每一行写数据，写了一个就往后面移一个 
		} 
	}
} 
