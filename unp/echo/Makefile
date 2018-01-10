CURPATH = $(shell pwd)
BINS = echocli_udp01 echocli01 echosrv_udp01 echosrv01 echosrv02
OBJS = $(patsubst %, %.o, $(BINS))
INCLUDE_PATH = $(CURPATH)/../include
LIB_PATH = $(CURPATH)/../lib

all : $(BINS)
	@echo [Done]


$(BINS) : $(OBJS)
	gcc $(patsubst %,%.o,$@) -o $@ -L$(LIB_PATH) -lunp #多目标处理

%.o : %.c
	gcc -c $^ -I$(INCLUDE_PATH)

clean:
	rm $(OBJS) $(BINS)