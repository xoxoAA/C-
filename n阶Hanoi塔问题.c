//假设有3个分别命名为X，Y和Z的塔座，在塔座X上插有n个直径大小各不相同，依小到大编号为1、2、3...n的圆盘。现要求将X轴上的n个圆盘移到塔座Z上并按同样顺序叠排，圆盘移动时必须遵循以下原则：
//（1）每次只能移动一个圆盘；
//（2）圆盘可以插在X、Y和Z中任意一个塔座上；
//（3）任何时刻都不能将大圆盘叠在小圆盘上。

//递归求解
#include <stdio.h>
#include <stdblio.h>

void hanoi(int n,char x,char y,char z){
  if(n == 1)
    move(x,1,z);
  else{
    hanoi(n-1,x,z,y);
    move(x,n,z);
    hanoi(n-1,y,x,z);
  }
}

int main(){
  int n = 3;
  hanoi(n,'A','B','C');
  return 0;
}
    

