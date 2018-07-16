#目标：依赖（条件）
#	命令
#app:add.c sub.c dive.c mul.c main.c
#	gcc add.c sub.c dive.c mul.c main.c -o app
#setup one
#
#
#setup two
#app:add.o sub.o dive.o mul.o main.o
#	gcc add.o sub.o dive.o mul.o main.o -o app
#
#add.o:add.c
#	gcc -c add.c
#sub.o:sub.c
#	gcc -c sub.c
#dive.o:dive.c
#	gcc -c dive.c
#mul.o:mul.c
#	gcc -c mul.c
#main.o:main.c
#	gcc -c main.c
#
#.PHONY:clean
#clean:
#	-rm -f *.o
#	-rm -f app
#
#test:
#	@echo "hello world"
#
#setup 3
# $@表示目标，$^表示所有依赖，$<表示依赖中的第一个
#obj=add.o sub.o dive.o mul.o main.o
#
#
#src = $(wildcard *.c)
#obj = $(patsubst %.c,%.o,$(src))
#target = app
#
#$(target):$(obj)
#	gcc $^ -o $@
#
#%.o:%.c
#	gcc -c $< -o $@
#

#阶段4
#
CPPFLAGES= -Iinclude
CFLAGES= -g -Wall
LDFLAGES= 
CC=gcc
src = $(wildcard *.c)
obj = $(patsubst %.c,%.o,$(src))
target = app

$(target):$(obj)
	$(CC) $^ $(LDFLAGES) -o $@

%.o:%.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGES) -o $@

.PHONY:clean
clean:
	-rm -rf *.o
	-rm -rf app
test:
	@echo $(src)
	@echo $(obj)
