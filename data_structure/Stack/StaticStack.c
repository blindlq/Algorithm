#include <stdio.h>
#include <stdlib.h> 
#define MAX_SIZE 5

//author: blindlq

typedef struct StaticStack
{
	int data[MAX_SIZE];//静态栈的大小
	int top;//栈底指针
}Stack,*pStack;

void InitStack(pStack);//初始化栈
void TraverseStack(pStack);//遍历栈
void PopStack(pStack);//弹栈
void PushStack(pStack,int);//压栈



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
	//初始化时，定义栈底指针指向0;
	s->top = -1;
}
//压栈
void PushStack(pStack s,int data)
{
	//判断栈是否满
	if (s->top == MAX_SIZE)
	{
		printf("栈已满！");
		exit(-1);
	}
	s->top++;//指向新栈底
	s->data[s->top] = data;
	

}

void PopStack(pStack s)
{
	
	//判断是否为空栈
	if (s->top == -1)
	{
		printf("栈为空！");
		exit(-1);
	}
	
	printf("栈顶的值为：%d\n", s->data[s->top]);
	s->top--;
	
}

void TraverseStack(pStack s)
{
	int len;
	if (s->top == -1)
	{
		printf("栈为空！");
		exit(-1);
	}
	len = s->top;
	while(len != -1)
	{
		printf("%d", s->data[len]);
		len--;
	}

	printf("\n");
}


