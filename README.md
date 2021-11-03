# EasyLog

> 此 log 移植自乐鑫esp32

## Feature
原日志系统具有以下特点：
+ log输出等级可配置
+ 不同log等级可采用不同颜色输出
+ 使用简单
+ 格式通用，可打印log文件信息
+ 可支持时间戳输

移植后删除部分非必要功能，具有以下功能：
+ log输出等级可配置
+ 不同log等级可采用不同颜色输出
+ 使用简单
+ 格式通用，可打印log文件信息
+ 可支持时间戳输出

针对此 log 进行优化，可使用在嵌入式mcu平台，是一种不错的 log 输出方式

此 log 中包含一些关于 c 语言的一些冷门的重要知识，特再次作记录说明～！

## Note
1. 通过修改宏定义`#define LOG_LOCAL_LEVEL         3` 可以实现的输出等级的调整，范围0 - 5

2. `void log_write(const char *format, ...)` 函数：

    + 内部采用格式化输出，达到与printf的作用，此处不做深入讲解，理解为printf就行

3. `unsigned int log_timestamp(void)` 函数:

    + 可根据各自的平台，将事件戳作为返回值输出返回

4. `__attribute__ ((format (printf, 1, 2)))` 

    + 用来作语法检查

    + ```c
      / 用法原型
      // archetype:为按照那种风格进行校验，如printf/scanf等
      // string-index:格式化format字符串所在的位置,如void test(testA, format,...)，此时为2
      // first-to-check:第一个可变参数的位置，如void test(testA, format,...)，此时为3
      __attribute__((format(archetype, string-index, first-to-check)))
      ```

    + 详细内容可以参考：https://blog.csdn.net/u014630623/article/details/101107023

    + pass：分析时，可以先将此部分注释
      `void log_write(const char* format, ...); // __attribute__ ((format (printf, 1, 2)));`

5. `#define LOG_FORMAT(letter, format)  #letter " (%d) %s: " format "\n"` 
     + #的作用是将letter转化为字符串
     + 可以使用`gcc main.c -E  >  debug` 查看预编译
     + `LOGE("test", "hello %d", ret);` 预编译结果为
       `if (3 >= LOG_ERROR) { log_write("E" " (%d) %s: " "hello %d" "\n", log_timestamp(), "test"); };` 