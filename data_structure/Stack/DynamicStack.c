#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"


//author: blindlq

typedef struct Node{
	int data;//栈的数据域
	struct Node * pNext;//栈的指针域
}Node ,* pNode;

typedef struct Stack{
	pNode pTop;//栈顶
	pNode pButtom;//栈底
}Stack,* pStack;


void InitStack(pStack);//初始化栈
void TraverseStack(pStack);//遍历栈
void PopStack(pStack);//弹栈
void PushStack(pStack,int);//压栈
void FreeStack(pStack *);//释放栈


int main(void)
{
	Stack s;
	
	InitStack(&s);
	
	PushStack(&s,1);
    PushStack(&s,2);
    PushStack(&s,3);
    PushStack(&s,4);
    PushStack(&s,5);
	
	printf("入栈后的遍历: \n");
	TraverseStack(&s);
	
	PopStack(&s);
	
	printf("出栈后的遍历: \n");
    TraverseStack(&s);
	
	return 0;
}
//初始化栈
void InitStack(pStack s)
{
	
	s->pTop = (pNode)malloc(sizeof(Node));//定义首结点,栈底和栈顶同时指向初始化的首节点
	if(NULL == 	s->pTop)
	{
		printf("malloc fail");
        exit(-1);
	}
	
	s->pButtom = s->pTop;
	s->pTop->pNext = NULL;
	
}
//压栈
void PushStack(pStack s,int value)
{
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(NULL == pNew)
    {
        printf("malloc fail");
        exit(-2);
    }

	pNew->data = value;
	pNew->pNext = s->pTop;
	s->pTop = pNew; 
	
	
	
}
//遍历栈
void TraverseStack(pStack s)
{
	pNode p = s->pTop;
	while(p != s->pButtom)
	{
		printf("%d",p->data);
		p = p->pNext;
	}
	
	printf("\n");
}
//弹栈
void PopStack(pStack s)
{
	if(s->pTop == s->pButtom)
	{
		printf("栈为空");
	}

	printf("栈顶的值为：%d\n",s->pTop->data);
	s->pTop = s->pTop->pNext;
	
}
//释放栈
void FreeStack(pStack *s)
{
	pNode p = (*s)->pTop;
	while(p != (*s)->pButtom)
	{
		pNode q = p->pNext;
		free(p);
		p = q;
	}
	//最后删除栈底
	free(p);
}





