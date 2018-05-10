#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

//author: blindlq


typedef struct Node pNode;

struct Node{
	int data;//数据域
	pNode * pNext;//指针域
};

pNode * InitList(void);//创建链表
void TraverseList(pNode *);//遍历链表
void FreeList(pNode **);//释放链表
int LengthList(pNode *);//链表长度
int IsEmptyList(pNode *);//链表是否为空
int InseteList(pNode *,int,int);//链表插入
int DeleteList(pNode *,int);//链表删除
int UpdateList(pNode *,int,int);//链表修改
int SearchList(pNode *,int);//链表查询

int main(void)
{
	int data;
	int node;
	
	pNode * pHead = NULL;//初始化首结点
	 
	pHead = InitList();
	TraverseList(pHead);
	printf("\n");
	printf("请输入要插入的结点位置: ");
    scanf("%d",&node);
    printf("请输入要插入的值: ");
    scanf("%d",&data);

    InseteList(pHead,node,data);

	TraverseList(pHead);
	FreeList(&pHead);
	
	if(NULL == pHead){
		printf("释放成功!\n");
    }else{
        printf("释放失败!\n");
    }
	
	return 0;
}
//创建链表
pNode * InitList(void)
{
	int len;//节点个数
	int data;//数据域的值
	
	pNode * pTail;//定义尾结点
	pNode * pHead = (pNode *)malloc(sizeof(pNode));//定义首结点
	
	if(NULL == pHead)
    {
        printf("malloc fail");
        exit(-1);
    }
	pTail = pHead;
	pHead->pNext = pTail;
	
	printf("请输入需要生成链表的个数：len= ");
	scanf("%d",&len);
	
	for(int i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&data);
		
		pNode * pNew = (pNode *)malloc(sizeof(pNode));
		if(NULL == pNew)
		{
			printf("malloc fail");
			exit(-2);	
		}
		
		pNew->data = data;
		
		pNew->pNext = pHead;//最后一个永远指向首结点
		pTail->pNext = pNew;
		pTail = pNew;
	}
	
	return pHead;
}
//遍历链表
void TraverseList(pNode *pHead)
{
	pNode *p = pHead->pNext;
	
	while(p != pHead)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	
	return ;
}

//释放链表
void FreeList(pNode **pHead)
{
	pNode *p = (*pHead)->pNext;
	
	while(p != (*pHead))
	{
		pNode *q = p->pNext; 
		free(p);
		p = q;
	}
	//最后释放首结点
	free(*pHead);
	(*pHead) = NULL;	
	return ;
}
//链表长度
int LengthList(pNode *pHead)
{	
	int len;
	
	pNode *p = pHead->pNext;
	
	while(p != pHead)
	{
		len++;
		p = p->pNext;	
	}
	
	return len;
}
//判断链表是否为空
int IsEmptyList(pNode *pHead)
{
	pNode *p = pHead->pNext;
	
	if(p == pHead)
	{
		return 0;
	}
	
	return 1;
	
}
//链表的插入
int InseteList(pNode *pHead ,int node ,int data)
{
	pNode *p = pHead;
	int len = 0;

	while(p->pNext != pHead)
	{
		if (len == node-1)
		{
			break;
		}
		p = p->pNext;
		++len;

	}

	if (p == pHead || len<node-1)
	{
		return 0;
	}

	pNode * pNew = (pNode *)malloc(sizeof(pNode));

	pNew->data = data;
	pNew->pNext = p->pNext;
	p->pNext = pNew;

	return 1;

}
//链表的删除
int DeleteList(pNode *pHead,int node)
{
	pNode *p = pHead;
	pNode *pNew = NULL;
	int len =0;

	while(p->pNext != pHead)
	{
		if(len == node-1)
		{
			break;
		}
		++len;
		p = p->pNext;
	}

	if (p == pHead || len<node-1)
	{
		return 0;
	}

	q = p->pNext->pNext;
	printf("%d\n", p->pNext->data);
	free(p->pNext);
	p->pNext = q;

	return 1;

}

















