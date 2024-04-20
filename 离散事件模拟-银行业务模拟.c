#include <stdio.h>

EventList ev;             //事件表
Event en;                 //事件
LinkQueue q[5];           //4个客户队列 
QElemType customer;       //客户记录
int TotalTime,CustomerNum;//累计客户逗留时间，客户数

typedef struct{
  int OccurTime;  //事件发生时刻
  int NType;      //事件类型，0表示到达事件，1至4表示窗口的离开事件
}Event,ElemType;  //事件类型，有序链表Linklist的数据元素类型

typedef LinkList EvenType //事件链表类型，定义为有序链表

typedef struct{
  int ArrivalTime;  //到达时间
  int Duration;     //办理业务时间
}QElemType;         //队列的数据元素类型

int cmp(Event a,Event b);

void OpenForDay(){
  //初始化操作
  TolarTime = 0;  CustomerNum = 0;     //初始化累计时间和客户数为0
  InitList(ev);                        //初始化事件链表为空
  en.OccurTime = 0;  en.NType = 0;     //设定第一个客户到达的事件
  OrderInsert(ev,en,cmp);              //插入事件表
  for(i=1;i<=4;++1) InitQueue(q[i]);   //置空队列
}

void CustomerArrived(){
  //处理客户到达事件
  ++CustomerNum;
  Random(durtime,intertime);
  t = en.OccurTime + intertime;                        //下一个客户到达时间
  if(t<CloseTime)                                      //插入事件表
    OderInsert(ev,(t,0),cmp);
  i = Minimum(q);                                      //求长度最短的队列
  EnQueue(q[i],(en.OccurTime,durtime));
  if(QueueLength(q[i]==1)
    OrderInsert(ev,(en.OccurTime + durTime,i),cmp);
}

void Bank_Simulation(int CloseTime){
  //银行业务模拟，统计一天内客户在银行逗留的平均时间
  OpenForDay();
  while(MoreEvent){
    EventDrived(OccurTime,EventType);
    switch(EventType){
      case'A':CustomerArrived();break;
      case'D':CustomerDeparture();break;
      default:Invalid();
    }
  }
  CloseForDay();
}
