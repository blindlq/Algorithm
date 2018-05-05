#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "string.h"

//author: blindlq

typedef struct Node pNode;

struct Node{
    char data[20];//数据域
    pNode * pPre;//前驱
    pNode * pNext;//后继
};

//函数声明
pNode * InitList(void);//创建链表
void TraverseList(pNode *);//遍历链表
void FreeList(pNode **);//释放链表
int InseteList(pNode *,int,char *);//链表插入
int DeleteList(pNode *,int);//链表删除
int UpdateList(pNode *,int,char *);//链表修改
int SearchList(pNode *,int);//链表查询
int LengthList(pNode *);//链表长度
int IsEmptyList(pNode *);


int main(void)
{
    int node;
    char data[20];

    pNode * pHead = NULL;//初始化首结点

    pHead = InitList();
    
    TraverseList(pHead);
    
    int length = LengthList(pHead);
    printf("链表长度为%d\n",length);
    
    printf("请输入要插入的结点位置: ");
    scanf("%d",&node);
    printf("请输入要插入的值: ");
    scanf("%s",data);


    TraverseList(pHead);
    FreeList(&pHead);
    
    if(NULL == pHead){
        printf("释放成功!\n");
    }else{
        printf("释放失败!\n");
    }
    return 0;
}

//创建双链表
pNode * InitList(void)
{
    int len;//节点个数
    char data[20];//节点的数据
    
    pNode * pTail;//定义尾结点

    pNode * pHead = (pNode *)malloc(sizeof(pNode));//定义首结点

    if(NULL == pHead)
    {
        printf("malloc fail");
        exit(-1);
    }
    //此时首结点和尾结点指向一个
    
    pHead->pPre = NULL;
    pHead->pNext = NULL;
    pTail = pHead;

    printf("请输入需要生成的链表节点个数: ");
    scanf("%d",&len);

    for(int i=0;i<len;i++)
    {
        printf("请输入第%d节点的值: ",i+1);
        scanf("%s",data);

        pNode * pNew = (pNode *)malloc(sizeof(pNode));
        if(NULL == pNew){
            printf("malloc fail");
            exit(-2);  
        }

        sprintf(pNew->data,"%s",data);
        pNew->pNext = NULL;
        pNew->pPre = pTail;
        pTail->pNext = pNew;
        pTail = pNew;//尾结点总是指向最后一个插入的节点

    }

    return pHead;
}

//遍历双链表
void TraverseList(pNode * pHead)
{
    pNode * p = pHead->pNext;

    while(NULL != p)
    {
        printf("%s",p->data);
        p = p->pNext;
    }

    printf("\n");
    return ;
}

//删除双链表
void FreeList(pNode **pHead)
{ 
    pNode * p = NULL;

    while(NULL != *pHead)
    {
        p = (*pHead)->pNext;
        free(*pHead);
        if(NULL != p){
            p->pPre = NULL;
        }
        *pHead = p;
    }

    return ;
}

//链表的插入
int InseteList(pNode * pHead,int node,char data[20])
{
    pNode * p = pHead;
    int len = 0;

    while(NULL != p)
    {
        if(len == node-1)
        {
            pNode * pNew = (pNode *)malloc(sizeof(pNode));
            if(NULL == pNew)
            {
                printf("malloc fail");
                exit(-3);
            }
            pNode * q = p->pNext;
            sprintf(pNew->data,"%s",data);
            p->pNext = pNew;
            pNew->pPre = p;
            pNew->pNext = q;

            return 1;
        }
        len++;
        p = p->pNext;

    }

    return 0;
}
//链表的删除
int DeleteList(pNode * pHead,int node)
{
    pNode * p = pHead;
    int len = 0;
    char data[20];

    while(NULL != p)
    {
        if(len == node-1 && p->pNext != NULL)
        {
            pNode * q = p->pNext->pNext;
            sprintf(data,"%s",p->pNext->data);
            printf("删除的节点值为: %s\n",data);
            free(p->pNext);
            p->pNext = q;
            if(q != NULL){
                q->pPre = p;
            }
            return 1;

        }
        len++;
        p = p->pNext;
    }
    return 0;
}
//链表修改
int UpdateList(pNode * pHead,int node,char data[20])
{
     pNode * p = pHead;
     int len= 0;

    while(NULL != p && node>0){
        if(len == node){
            memset(p->data,0,sizeof(p->data));
            sprintf(p->data,"%s",data);
            p->data[strlen(data)] = '\0';

            return 1;
        }

        len++;
        p = p->pNext;
    }
    return 0;
}
//查找链表的某个值
int SearchList(pNode * pHead,int node)
{
    pNode * p = pHead;
    int len = 0;

    while(NULL != p )
    {
        if(len == node)
        {
            printf("第%d个节点的值是:%s\n",node,p->data);
            
            return 1;
        }
    len++;
    p = p->pNext;

    }
    return 0;
}

//计算链表长度
int LengthList(pNode * pHead)
{
    int len = 0;
    pNode * p = pHead->pNext;
    
    while(NULL != p)
    {
        len++;
        p = p->pNext;

    }
    return len;
}
//判断链表是否为空
int IsEmptyList(pNode * pHead)
{
    pNode * p = pHead->pNext;

    if(NULL != p){
        return 1;
    }

    return 0;
    
}