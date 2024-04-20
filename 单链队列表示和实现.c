// =========ADT Queue的表示与实现========
#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0
#define OVERFLOW -2
#defien ok 1
#define error 0
typedef int Status;
typedef int QElemType;

//-------单链队列——队列的链式存储结构---------
typedef struct QNode{
  QElemType data;
  struct QNode *next;
}QNode,*QueuePtr;
typedef struct 
{
  QueuePtr front; //队头指针
  QueuePtr rear;  //队尾指针
}LinkQueue;

//--------基本操作函数------------
Status InitQueue(LinkQueue &Q){
  //构造一个空队列
  Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
  if(!Q.front) exit(OVERFLOW);
  Q.front->next=NULL;
  return ok;
}

Status DestoryQueue(LinkQueue &Q){
  //销毁队列Q
  while(Q.front){
    Q.rear = Q.front->next;
    free(Q.front);
    Q.rear=Q.front;
  }
  return ok;
}

//在申明'p'的时候，使用'QueuePtr p'可以清晰的表明'p'是一个指向'struct QNode'结构的指针
Status ClearQueue(LinkQueue &Q){
  //将Q清空，为空队列
  QueuePtr p =Q.front->next;
  while(p != Q.rear){
    Q.rear = Q.front->next;
    Q.front->next = p->next;
    free(p);
    p = Q.front->next;
  }
  Q.front == Q.rear;
  return ok;
}

Status QueueEmpty(LinkQueue Q){
  //若队列Q为空队列，返回TUER；否则返回FALSE
  if(Q.front == Q.rear) return TURE;
  else return FALUSE;
}

int QueueLength(LinkQueue Q){
  //返回队列Q元素的个数，即Q队列的长度
  int len = 0;
  QueuePtr p = Q.front->next
  while(p != Q.rear){
    Q.front = p->next;
    len++;
    p = Q.front;
  }
  return len;
}

Status GetQueue(LinkQueue Q,QElemType &e){
  //若队列不为空，则用e返回Q的队头元素，并返回ok,否则返回error
  if(Q.front == Q.rear) return error;
  *e = Q.front->next->data;
  return ok;
}

Status EnQueue(LinkQueue &Q){
  //插入一个元素e作为Q的新的队尾元素
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  if(!p) exit(OVERFLOW);
  p->data = e; p->next = NULL:
  Q.rear->next = p;
  Q.rear = p;
  return ok;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
  //若队列不为空，则删除队列Q的队头元素，并用e返回队头元素的值
  //最后返回ok,否则返回error
  if(Q.front == Q.rear) return error;
  QueuePtr p=Q.front->next;
  *e=p->data;
  Q.front->next = p->next;
  if(Q.rear == p) Q.front = Q.rear;
  free(p);
  return ok;
}



