#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
#include <string.h>  

//author：blindlq



struct Node{
	char data[20];//数据域
	struct Node * pNext;//指针域
};
//函数声明
struct Node * creat_list(void);//创建
static void traverse_list(struct Node *);//遍历
int is_empty(struct Node *);
int length_list(struct Node *);//计算长度
int insert_list(struct Node *,int,char *);//增
int delete_list(struct Node *,int,char *);//删
int change_list(struct Node *,int,char *);//改
int query_list(struct Node *,int);//查



int main(void)
{	
	int node;
	char data[20];
	struct Node * pHead = NULL;//头接点
	
	pHead = creat_list();//头接点指向单链表
	
	traverse_list(pHead);
/* 	if(is_empty(pHead))
	{
		printf("链表为空!\n");
	}else{
		printf("链表不为空!\n");
		int length = length_list(pHead);
		printf("链表长度为:%d\n",length);
	}
	printf("请输入想插入节点的位置：");
	scanf("%d",&node);
	query_list(pHead,node);
	printf("请输入想插入节点的值: ");
	scanf("%s",data);
	
	if(change_list(pHead,node,data))
	{
		traverse_list(pHead);
	}else{
		printf("修改失败!\n");
	}
	

	printf("请输入想删除节点的位置：");
	scanf("%d",&node);
	
	if(delete_list(pHead,node,data))
	{
		printf("删除后链表为：");
		traverse_list(pHead);
	}else{
		printf("删除失败!\n");
	}
	
	if(insert_list(pHead,node,data))
	{
		traverse_list(pHead);
	}else{
		printf("插入失败!\n");
	} */
	
	
	return 0;
	
}

/*
 * 新建链表
 */
struct Node * creat_list(void)
{
	int len;
	char data[20];
	struct Node * pTail;//定义尾结点
	//动态分配内存,不存数据的头结点
	struct Node * pHead = (struct Node *)malloc(sizeof(struct Node));
	
	if(NULL == pHead)
	{
		printf("malloc fail");
		exit(-1);
	}
	//此时头结点和尾结点是同一个
	pTail = pHead;
	pTail->pNext = NULL;
	
	printf("请输入需要生成链表的个数：len= ");
	scanf("%d",&len);
	
	for(int i=0;i<len;i++)
	{
		printf("请输入第%d个节点的值：",i+1);
		scanf("%s",data);
		
		struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
		if(NULL == pNew)
		{
			printf("malloc fail");
			exit(-1);
		}
		
		sprintf(pNew->data, "%s", data);//pNew->data = data;//数据域存放
		pTail->pNext = pNew;//新结点挂在尾结点后
		//新结点变成尾结点
		pNew->pNext = NULL;
		pTail = pNew;
	}
	
	return pHead;
}

/*
 * 遍历链表
 */
static void traverse_list(struct Node *pHead)
{
	struct Node * p = pHead->pNext;
	
	while(NULL != p)
	{
		printf("%s ",p->data);
		p = p->pNext;
		
	}
	
	printf("\n");
		
	return ;
}

/*
 * 判断链表是否为空
 */
 int is_empty(struct Node *pHead)
 {
	 if(NULL == pHead->pNext)
	 {
		 return 1;
	 }
	 
	 return 0;
 }
 
/*
*计算链表长度
*/
int length_list(struct Node *pHead)
{
	int len = 0;
	struct Node * p = pHead->pNext;
	
	while(NULL != p)
	{	
		len++;
		p = p->pNext;
	}
	
	return len;
	
}
/*
 * 链表的插入
 */
int insert_list(struct Node *pHead,int node,char data[20])
{
	struct Node * p = pHead;
	int len = 0;

	
	while(NULL != p)
	{
		if(len == node-1)
		{
			struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
			if(NULL == pNew)
			{
				exit(-1);
			}
			sprintf(pNew->data, "%s", data);
			struct Node * q = p->pNext;
			p->pNext = pNew;
			pNew->pNext = q;
			
			return 1;
		}
			
		len++;
		p = p->pNext;
	}
	
/* 	if(len>node-1 || NULL == p)
	{
		return 0;
	}
	
	struct Node * pNew = (struct Node *)malloc(sizeof(struct Node));
	if(NULL == pNew)
	{
		exit(-1);
	}
	sprintf(pNew->data, "%s", data);
	struct Node * q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q; */
	
	return 0;
}
/*
* 链表的删除 
*/
int delete_list(struct Node *pHead,int node,char data[20])
{
	struct Node * p = pHead;
	int len = 0;
	
	while(NULL != p)
	{
		if(len == node-1 && p->pNext != NULL)
		{
			
			struct Node * q = p->pNext;
			sprintf(data, "%s", q->data);
			printf("删除的值为: %s\n",data);
			
			
			p->pNext = p->pNext->pNext;
			free(q);
			q = NULL;
			
			
			return 1;
		}
		len++;
		p = p->pNext;
	}
	
	return 0;
}
/*
* 链表修改
*/
int change_list(struct Node *pHead,int node,char data[20])
{
	struct Node * p = pHead;
	int len = 0;
	while(NULL != p)
	{
		if(len == node )
		{
			memset(p->data, 0, sizeof(p->data));  
			sprintf(p->data, "%s", data);
			p->data[strlen(data)] = '\0';  
			
			return 1;
		}
		len++;
		p = p->pNext;
	}
	return 0;
}
/*
 *链表询
 */
 int query_list(struct Node *pHead,int node)
 {
	struct Node * p = pHead;
	int len = 0;
	while(NULL != p)
	{
		if(len == node)
		{
			printf("第%d个节点的值是：%s\n",node,p->data);
			return 1;
		}
		len++;
		p = p->pNext;
	}
	
	return 0;	
 }

















