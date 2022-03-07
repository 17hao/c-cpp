linking(链接)

关键词：relocatable object file、shared object file、symbol table、symbol resolution、
relocation、static linking、dynamic linking、PIC(position independent code)、library interpositioning

```
首先回顾一下（广义的）编译的几个阶段
xxx.c
|
|--> preprocessor(预处理) cpp xxx.c -o xxx.preprocessed or gcc -E xxx.c
|
|--> compiler(狭义的编译) gcc -S xxx.c 产物是xxx.s
|
|--> assembler(汇编器) gcc -c xxx.c 产物是xxx.o
|
|--> linker(链接器) ld xx1.o xx2.o 产物是a.out
```

链接的输入是object file或archive file

object file有
- relocatable obj file
- shared obj file
- executable obj file

archive file是多个object file的合集，可以通过`ar`命令将多个object file制作成archive file（例子见addvec.c）

最直接的链接方式就是通过gcc直接将多个object file生成可执行文件，`gcc -o prog a.o b.o c.o`

这样的链接方式有一些缺点
- 如果a.o被ld链接到10个可执行文件，那么需要在硬盘上占用10个a.o文件的容量；当10个程序运行时，内存中会有10个a.o的拷贝
- 如果a.o对应的源码有修改，应用了a.o的程序需要重新链接，如果a.o的体积非常大，重新链接会非常耗时

如果将不同类型的函数放到不同的obj file时，如果程序应用了许多obj file，linker的输入会非常多，耗时且容易出错。

如果将c的类库采用上述的这些做法，缺点就会非常明显。

通过静态库可以解决上述提到的大部分缺点，将多个obj file打包到一个文件中 i.e. archive file，linker的输入只需要打包的这个文件（列子见addvec.c和main2.c）。

当使用静态库时，只有被引用到的obj file才会被用于生成可执行文件。

静态库没有解决这些问题：
- 当源码修改后，引用它的程序需要重新链接。
- 即使只有一小部分obj file需要用于生成可执行文件，但是如果用多了，还是会占用大量空间。

使用动态链接可以解决这些问题。

在Windows中大量使用了这种链接方式，也就是xxx.dll文件（dynamic link library），在Linux中动态链接库为xxx.so文件。

案例见addvec.c、main2.c、dll.c

动态链接需要生成的库为PIC(position independent code)，因为只有这样，在relocation阶段才可以在多个程序中重复使用这个库。

基于link还可以实现library interpositioning，类似Spring框架中AOP的功能，案例见interpose文件夹。

备注：进一步加深理解还需要学习virtual memory等知识。