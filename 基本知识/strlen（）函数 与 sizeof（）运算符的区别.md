## strlen()和sizeof()区别

* 区别一：strlen 是函数，sizeof 是运算符。      

* 区别二：strlen 测量的是字符的**实际长度**，以'\0' 结束。而sizeof 测量的是**字符的分配大小**。   
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

