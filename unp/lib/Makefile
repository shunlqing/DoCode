LIBPATH = $(shell pwd)
LIBS = libunp.a 
OBJS = $(LIBPATH)/*.o

INCLUDE_PATH = $(LIBPATH)/../include

all : $(LIBS)
	@echo $^ [Done]

$(LIBS) : $(OBJS)
	ar rcs $@ $(OBJS)
	rm $(OBJS)

%.o : %.c
	gcc -c $^ -I$(INCLUDE_PATH)

clean:
	rm libunp.a