TARGET = mtag
CC = gcc 

CFLAGS = -Wall -o2 -I ./include
LINK_FLAG = -L ./libs -lmlog

SRCS = $(wildcard *.c)
OBJS = $(patsubst %c, %o, $(SRCS))

.PHONY: ALL clean 

ALL:$(TARGET)
    
$(TARGET):$(OBJS) 
	@$(CC) $(OBJS) $(LINK_FLAG) -o $@ 

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
   
clean:
	@rm -rf *.o 
	@rm -rf $(TARGET)  
