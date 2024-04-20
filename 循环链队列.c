//初始化建空队列时，令front=rear=0
//插入新元素时，rear+1;删除元素时，front+1.
//在非空队列中，头指针始终指向队列头元素，尾指针始终指向队列尾元素的下一个位置

//--------循环队列——队列的顺序存储结构----------
#define MAXQSIZE 100
typedef struct{
  QElemType *base;  //初始化动态分配存储空间
  int front;
  int rear;
}SqQueue;

//-----循环队列的基本操作的算法描述--------
Status InitQueue(SqQueue &Q){
  //构造一个空队列Q
  Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
  if(!Q.base) exit(OVERFLOW);
  Q.front = Q.rear;
  return ok;
}

int QueueLength(SqQueue Q){
  return (Q.rear-Q.front+MAXQSZIE)*MAXQSIZE;
}

Status EnQueue(SqQueue &Q,QElemType e){
  //插入元素e作为Q的新的队尾元素
  if((Q.rear+1) % MAXQSIZE == Q.front) return error;//队满
  Q.base[Q.rear] = e;
  //Q.rear 指向下一个位置，如果 Q.rear 已经达到了队列的最大容量 MAXQSIZE - 1，
  //那么取模运算 (Q.rear + 1) % MAXQSIZE 就会将 Q.rear 的值重新置为 0，以循环到数组的头部。
  Q.rear = (Q.rear + 1) %MAXQSZIE;
  return ok;
}

Status DeQueue(SqQueue &Q,QElemType &e){
  //若队列不为空，则删除e的队头元素，用e返回其值，并返回Ok;
  //否则返回error;
  if(Q.front == Q.rear) return error;
  e = Q.base[Q.front];
  Q.front = (Q.front+1) % MAXQSIZE;
  return ok;
}
  
