# C 标准库 - <limits.h>

## 简介

**limits.h** 头文件决定了各种变量类型的各种属性。定义在该头文件中的宏限制了各种变量类型（比如 char、int 和 long）的值。

这些限制指定了变量不能存储任何超出这些限制的值，例如一个无符号可以存储的最大值是 255。

## 库宏

下面的值是特定实现的，且是通过 #define 指令来定义的，这些值都不得低于下边所给出的值。

| 宏         | 描述                            |
| :--------- | :------------------------------ |
| CHAR_BIT   | char 类型的位数                 |
| SCHAR_MIN  | signed char 类型的最小值        |
| SCHAR_MAX  | signed char 类型的最大值        |
| UCHAR_MAX  | unsigned char 类型的最大值      |
| CHAR_MIN   | char 类型的最小值               |
| CHAR_MAX   | char 类型的最大值               |
| MB_LEN_MAX | 定义多字节字符中的最大字节数。  |
| SHRT_MIN   | short 类型最小值                |
| SHRT_MAX   | short 类型最大值                |
| USHRT_MAX  | unsigned short 类型最大值       |
| INT_MIN    | int 类型最小值                  |
| INT_MAX    | int 类型最大值                  |
| UINT_MAX   | unsigned int 类型最大值         |
| LONG_MIN   | long 类型最小值                 |
| LONG_MAX   | long 类型最大值                 |
| ULONG_MAX  | unsigned long 类型最大值        |
| LLONG_MAX  | long long 类型的最大值          |
| LLONG_MIN  | long long 类型的最小值          |
| ULLONG_MAX | unsigned long long 类型的最大值 |