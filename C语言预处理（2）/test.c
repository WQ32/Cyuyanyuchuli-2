#include <stdio.h>

extern int Add(int x, int y);     //这里只是声明函数
//Linux 
// ls 保存
// 
// 预编译
// gcc -E test.c    预编译，预处理（文本操作）  1. 进行头文件的包含(#include ),将头文件中的内容都放在.c文件中去了
//                   2.注释删除，使用空格替换注释  3.主要完成预处理指令，如#define（定义一个符号），会被替换
// gcc -E test.c >test.i 将test.c中的内容写到test.i中去(默认生成a.out)，vim test.i是打开test.i这个文件
//
//rm -f test.s 删除文件
//
// 预编译      --  把C代码翻译成汇编代码，由编译来完成 - 语法分析 词法分析 语义分析 符号汇总（把全局变量，函数名进行汇总）
// 讲编译原理 - 书  - 《程序员的自我修养》
// gcc -S test.c   
// gcc -S test.i   自动生成test.s文件，里面存的是汇编指令（代码）

//汇编        -- 1.把汇编代码转化成二进制指令  2.形成符号表
//gcc -c test.c   自动生成test.o文件，相当于Windows下的.obj文件
// 
////形成符号表
//int main()
//{
//	int a = 10;            //每个文件进行汇编时都会生成.o 或者 .obj文件，然后会形成符号表
//	int b = 20;            //这个程序中有两个符号：main 和 Add
//	int c = Add(a, b);	  // 符号表里面存的是 符号名称和它对应的地址
//	printf("%d\n", c);    // 假设这里符号表内容是    Add  0x0000
//													 main 0x2000
//	return 0;			//引入的Add函数符号表内容是  Add  0x1000
//}						//进行链接时，就会将两个符号表合并，调用Add函数时，就能找到这个函数，并使用
						//如果没有Add这个函数就会报错

////链接          --  1.合并段表(将多个目标文件合并在一起，最终生成一个可执行程序)  2.符号表的合并和重定位
//// 符号表的合并是将多个符号表合并在一起，如Add和main形成的符号表，如果有同名，就将有效的合并在一起
//// 
////可执行程序   test.exe
//
////预编译详讲 （预处理）
//#define MAX 100   //自定义符号
////预定义符号
//
//int main()
//{
//	//printf("%s\n", __FILE__);     // __FILE__是代码所在的完全地址+文件名称
//	//printf("%d\n", __LINE__);    // __LINE__是代码所在的行
//	//printf("%s\n", __DATE__);	//__DATE__是现在的日期
//	//printf("%s\n", __TIME__);	//__TIME__是现在的时间
//	//写日志文件
//	int i = 0;
//	int arr[10] = { 0 };
//	FILE* pf = fopen("log.txt", "w");
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//		fprintf(pf,"file: %s line: %d date: %s time: %s i: %d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//		printf("%s\n", __FUNCTION__);    //这个打印的是这个函数的名字，这里就是main
//	}
//	fclose(pf);
//	pf = NULL;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//int main()
//{
//	printf("%d\n", __STDC__);        //如果该编译器严格按照C语言标准，就会打印1，否者就会报错,VS就没有严格按照C标准
//	return 0;
//}

//预处理指令
//#define     1.定义标识符（#define STR "hehe"） 2.定义宏
//#include    #开头的都叫预处理指令
//还有 #pragma pack(4)
//#if , #endif , #line , #ifdef