#获取当前目录所有的.c文件
SRC = $(wildcard *.c)
#将.c文件替换为.o文件
OBJS = $(patsubst %.c,%.o,$(SRC))
#OBJS = add.o sub.o mul.o div.o test.o
TARGET = test

#这些变量是makefile中的隐式变量，不能单独使用，必须在命令中使用
#$@ 表示目标
#$^ 表示所有依赖
#$< 表示第一个依赖

${TARGET}: ${OBJS}
	gcc $^ -o $@

	

#模式匹配，%.o表示所有的.o文件，%.c表示所有的.c文件

%.o:%.c
	@gcc -c $< -o $@
#@可以不显示命令，这样就不会显示编译过程了

#若是当前文件夹下有clean文件，执行make clean就没用，因为此时make已经认为clean目标已经完成了，解决办法为申明clean为伪目标
.PHONY:clean  #无条件执行命令
clean:
	-rm -rf ${OBJS} ${TARGET}

#-  忽略错误，继续执行，不会显示错误信息

