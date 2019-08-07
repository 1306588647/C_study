1. strlen 是函数，sizeof 是运算符。      

2. strlen 测量的是字符的实际长度，以'\0' 结束。而sizeof 测量的是字符的分配大小。   
比如：    

```
char str[20] = "hello";
 
printf("strlen: %d\n", strlen(str));
printf("sizeof: %d\n", sizeof(str));

```
结果显示为：  

```
strlen: 5
sizeof: 20

```
3. 我们知道字符数组的初始化一次性赋值，也可以逐个赋值。可以指定数组的大小，也可以不指定数组长度。  

```
#include <stdio.h>
#include <string.h>
 
int main()
{
    char str1[] = "hello";
    char str2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str3[] = {'h', 'e', 'l', 'l', 'o'};
    
    printf("str1:%s\n",str1);
    printf("str2:%s\n",str2);
    printf("str3:%s\n",str3);
    printf("str1:%d\n", strlen(str1));
    printf("str2:%d\n", strlen(str2));
    printf("str3:%d\n", strlen(str3));
 
    return 0;
}

```
结果显示为：  

```
str1:hello
str2:hello
str3:hellohello
str1:5
str2:5
str3:10

```
这是为什么呢？  
我们知道字符串是以 '\0' 为结束标志的，所以char str1[ ] = "hello" 等效于char str2[ ] = {'h' , 'e' , 'l' , 'l' , 'o' , '\0'} 。strlen函数求的是字符串的实际长度，它求得方法是从开始到遇到第一个'\0'，如果你只定义没有给它赋初值，这个结果是不定的，它会从首地址一直找下去，直到遇到'\0'停止。而如果不在字符数组初始化的时候加上\0，那么strlen 得到的值就不是正确的数值，打印出来的结果也不是想要的结果。因此我们要避免这种情况，在初始化的时候要记得加上 \0，或者一次性赋初值。

