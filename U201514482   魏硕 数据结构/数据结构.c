void union(List &La,List Lb){
	//��������b�в���a��Ԫ�ز���a��
	La_len=ListLength(La);Lb_len=ListLength(Lb);
	for(i=1;i<Lb_len;i++){
		GetElem(Lb,i,e);
		if(!LocateElem(La,e,eaqul)) ListInsert(La,++La_len,e);//++La_len��ʾ�ڱ��ĩβ���� 
	} 
} //union

//�ϲ�a��b�� 
void MergeList(List La,List Lb,List &Lc){//&��ʾ�������ò���
	InitList(Lc);
	i=j=1;k=0;//i��a�ļ�������j��b�ļ����� 
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

//���䴢��ռ� 
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	if(i<1 || i>L.Length+1) return ERROR;
	if(L.Length>=L.listsize){//��ǰ�ռ��Ѿ�����
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT) * sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=mewbase;
		L.lsitsize+=LISTINCREMENT; 
	} 
	q=&(L.elem[i-1]);//����λ��
	p=&(L.elem[L.length-1]);
	for(;p>=q;--p) *(p+1)=*(p); 
	*q=e;
	++L.length;
	return Ok;
}

//����ת��
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

//�б��봦��#ɾ��ǰһλ��@ɾ��ǰ������
void LineEdit()
{
	InitStack(s);
	ch=getchar();
	while(ch !=EOF)//�������е����� 
	{
		while(ch!='\n' && ch!=EOF)//������ 
		{
			switch(ch)
			{
				case '#':Pop(s,c);  break;//δ���ǿ�ջ 
				case '@':ClearStack(s); break;
				default :Push(s,ch); break; //δ������ջ 
			}
			ch=getchar();
		}
		����ջ�׵�ջ����ջ���ַ����������ù��̵���������
		ClearStack(s);
		if(ch !=EOF)  ch=getchar(); 
	}
	DestroyStack(S);
} //LineEdit


//����Ԫ�صĶ��壬����һ���Ϸ�����
Status InitArray(Array &A,int dim,...){
	if(dim<1 || dim>MAX_ARRAY_DIM) return ERROR;
	A.dim=dim;
	A.bounds=(int *)malloc(dim * sizeof(int));   //�������ÿһά�ж��ٸ���0Ԫ��
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
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];//��ǵ�iά֮ǰ�ܹ��ж��ٸ�Ԫ��
	return OK; 
} 

Status TransposeSMatrix(TSMatrix M,TSMatrix &T)//����ת�� 
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
		for(t=1;t<=M.tu;++t) ++num[M.data[t].j];//������Tÿһ�н����ж��ٸ�Ԫ��
		cpot[1]=1;//���col���е�һ������Ԫ����b.data�е����
		for(col=2;col<=M.nu;++col) cpDFot[col]=cpot[col-1]+num[col-1];
		for(p=1;p<=M.tu;++p)
		{
			col=M.data[p].j;q=cpot[col];
			T.data[q].i=M.data[p].j;T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e;++cpot[col];//�൱����ÿһ��д���ݣ�д��һ������������һ�� 
		} 
	}
} 
