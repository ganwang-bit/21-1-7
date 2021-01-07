//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    printf("Hello world!\n");
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n;
//    char m;
//    scanf("%d%c",&n,&m);
//    printf("%d%c",n,m);
//    return 0;
//}
//#include<stdio.h>
//void main()
//{
//	float F,C;
//	char m;
//	int i;
//	printf("input huashi or sheshi:\n");
//	scanf("%d%c",&i,&m);
//	if(m=='F')
//	{
//	    C=5.0/9*(i-32);
//	printf("output the tempemture:%fC",C);
//	}
//	else if(m=='C')
//	{
//		F=9.0/5*i+32;
//	printf("output the tempemture:%fF",F);
//	}
//}
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define ERROR 0

typedef struct node
{
	char *pstr;
	struct node *next;
}node;
typedef struct Stack {
    struct node *pNode;
    int size;
}Stack;
int Menu();
 Stack* CreateStack();
void Push(Stack* s);
char* Pop(Stack* s);
int IsEmpty(Stack* s);
char* Top(Stack* s);
void paixu(Stack*s);
void print(Stack*s);
int main()
{
	Stack* s=NULL;
	char* TopElem;
	while(1)
    {
		int choice = Menu();
		if(choice==0) break;
		switch(choice)
		{
			case 1: s= CreateStack(); break;
			case 2: Push(s); break;
			case 3: puts(Pop(s)); break;
			case 4: if( IsEmpty(s) ) printf("Yes\n"); else printf("No\n"); break;
			case 5: TopElem = Top(s); if(TopElem)puts(TopElem); break;
			case 6: paixu(s); break;
			case 7: print(s); break;
		}
	}
	return 0;
}
void print(Stack*s)
{
    node*p=s->pNode;

        while(p)
        {
            printf("%s\n",p->pstr);
            p=p->next;
        }

}
void paixu(Stack*s)
{
        int i,j;
        node*cur;
        char *arr;
        cur=s->pNode;
        for(i=0;i<s->size-1;i++)
        {
            for(j=0;j<s->size-1-i;j++)
            {
                if(strlen(cur->pstr)<strlen(cur->next->pstr))
                {
                    arr=cur->pstr;
                    cur->pstr=cur->next->pstr;
                    cur->next->pstr=arr;
                }
            }
        }

}

Stack* CreateStack()
{
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	s->pNode = NULL;
	s->size=0;
	return s;
}

void Push(Stack* s)
{
    struct node* tmpcell;
	tmpcell = (node*) malloc(sizeof(node));
	tmpcell->pstr=(char*)malloc(sizeof(char)*100);
	printf("input:");
	scanf("%s",tmpcell->pstr);
	tmpcell->next = s->pNode;
	s->pNode=tmpcell;
	s->size++;
}

char* Pop(Stack* s)
{
	struct node* FirstCell;
	char* TopElem;
	if( IsEmpty(s) ) {
		printf("Õ»Îª¿Õ\n");
        return ERROR;
    }
    else
    {
    	FirstCell = s->pNode;
    	TopElem = FirstCell->pstr;
    	s->pNode = FirstCell->next;
    	free(FirstCell);
    	s->size--;
		return TopElem;
    }
}

int IsEmpty(Stack* s)
{
    if(s&&s->pNode == NULL)
	return 1;
}

char* Top(Stack* s)
{
	char* TopElem;
	if(IsEmpty(s))
    {
		printf("Õ»Îª¿Õ\n");
        return ERROR;
    }
    else
    {
		TopElem = s->pNode->pstr;
		return TopElem;
 	}
}

int Menu()
{
	int choice;
	printf("1.....CreateStack\n");
	printf("2.....Push\n");
	printf("3.....Pop\n");
	printf("4.....IsEmpty\n");
	printf("5.....Top\n");
	printf("6.....paixu\n");
	printf("7.....print\n");
	scanf("%d", &choice);
	return choice;
}


