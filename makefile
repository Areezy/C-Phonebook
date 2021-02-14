TARGET_01        = phonebook
SOURCE_01        = phonebook.c


CC = gcc
CFLAGS = -Wall -g3 -gdwarf-2 -DDEBUG 


.PHONY: all
all: $(TARGET_01) 

$(TARGET_01): $(SOURCE_01)



.PHONY: clean
clean:
	rm $(TARGET_01) $(OBJS)
	rm *.txt

