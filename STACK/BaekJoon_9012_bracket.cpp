#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
// 연결리스트로 구성된 stack 구현 연습을 위해 구조체로 구현

// 연결리스트 구현
typedef struct struct_LinkedList
{
    char data;
    struct struct_LinkedList *nextNode;
} LinkedList;

// 연결리스트를 이용한 stack 구현
typedef struct struct_Stack
{
    LinkedList *top;
    int size;
} stack;

// stack 초기화
void init(stack *s);
// stack의 push
void push(stack *s, char _data);
int isEmpty(stack *s);
// stack의 최상단 값 보기
char peek(stack *s);
char pop(stack *s);
void answer(int i);

int main()
{
    char str[51];
    int n;
    int isTrue;
    stack s;
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%s", str);
        init(&s);
        isTrue = TRUE;
        for (int i = 0; i < strlen(str); i++)
        {
            // '(' 가 있다면 push
            if (str[i] == '(')
            {
                push(&s, str[i]);
            }
            // ')' 가 있다면 pop
            else if (str[i] == ')')
            {
                // pop 을 할 데이터가 없다 -> 괄호가 맞는게 없다
                if (!pop(&s))
                {
                    isTrue = FALSE;
                }
            }
        }
        // 결과가 TRUE 라도 아직 괄호가 맞지 않는 케이스가 있을 수도 있으니
        isTrue = isTrue ? isEmpty(&s) : isTrue;
        answer(isTrue);
    }
}

void answer(int i)
{
    if (i)
    {
        printf("YES\n");
        return;
    }
    printf("NO\n");
}

void init(stack *s)
{
    s->top = NULL;
    s->size = 0;
}

void push(stack *s, char _data)
{
    LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
    newNode->data = _data;
    newNode->nextNode = s->top;
    s->top = newNode;
    s->size++;
}

int isEmpty(stack *s)
{
    return !(s->size);
}

char peek(stack *s)
{
    if (isEmpty(s))
    {
        return 0;
    }
    return s->top->data;
}

char pop(stack *s)
{
    if (isEmpty(s))
    {
        return 0;
    }

    LinkedList *newNode = s->top;
    char ret = newNode->data;

    s->top = newNode->nextNode;
    s->size--;
    free(newNode);

    return ret;
}
