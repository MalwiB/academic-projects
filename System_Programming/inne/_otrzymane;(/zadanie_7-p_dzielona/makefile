DIR = `basename $(PWD)`

NAME1 = producent
NAME2 = konsument
NAME3 = biblioteka

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x

EXEC1d1  = $(NAME1)d1.x
EXEC2d1  = $(NAME2)d1.x

EXEC1d2  = $(NAME1)d2.x
EXEC2d2  = $(NAME2)d2.x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o


LIB_NAME = biblioteka
LIB_DIR = ./lib
LIB_STAT = lib$(LIB_NAME).a
LIB_SHAR = lib$(LIB_NAME).so
HEADS1 = $(LIB_NAME).h

LIB_OBJS = $(OBJS3)
HEADS3 = $(NAME3).h

CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rcs

%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<

$(LIB_STAT): $(LIB_OBJS)
	$(CO) -c $(LIB_NAME).c -o $(LIB_NAME).o
	$(AR) $(ARFLAGS) lib$(LIB_NAME).a $(LIB_NAME).o
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)

$(LIB_SHAR): $(LIB_OBJS) 
	$(LD) -shared -o $@ $(CFLAGS) $(LIB_OBJS)
	mkdir -p $(LIB_DIR)
	mv $(LIB_SHAR) $(LIB_DIR)

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC1d1) $(EXEC2d1) $(EXEC1d2) $(EXEC2d2) $(OBJS3)

$(EXEC1): $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) -static $(OBJS1)  -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)

$(EXEC2): $(OBJS2) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) -static $(OBJS2) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)
	
$(EXEC1d1): $(OBJS1) $(LIB_SHAR)
	$(LD) -o $@ $(LFLAGS) $(OBJS1) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS) -Wl,-R $(LIB_DIR) 

$(EXEC2d1): $(OBJS2) $(LIB_SHAR)
	$(LD) -o $@ $(LFLAGS) $(OBJS2) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS) -Wl,-R $(LIB_DIR) 

$(EXEC1d2): $(OBJS1) $(LIB_SHAR)
	$(LD) -o $@ $(LFLAGS) $(OBJS1) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)

$(EXEC2d2): $(OBJS2) $(LIB_SHAR)
	$(LD) -o $@ $(LFLAGS) $(OBJS2) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)

$(OBJS3): $(HEADS3)

.PHONY: run1
run1: $(EXEC1) $(EXEC2)
	./$(EXEC1) $(EXEC2)

run2d1: $(EXEC1d1)  $(EXEC2d1)
	./$(EXEC1d1) $(EXEC2d1)
    
run2d2: $(EXEC1d2) $(EXEC2d2)
	(export LD_LIBRARY_PATH=${LIB_DIR}:${LD_LIBRARY_PATH}; \
	./$(EXEC1d2) $(EXEC2d2) )

.PHONY: clean tar diff xterm
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

diff:
	diff -s file.txt file2.txt


.PHONY: xterm1 xtermd1 xtermd2
xterm1: $(EXEC1) $(EXEC2)
	xterm -hold -title SERWER -bg black -e ./$(EXEC1) &
	xterm -hold -title KLIENT -bg black -e ./$(EXEC2) &
	
	
xtermd1: $(EXEC1d1) $(EXEC2d1)
	xterm -hold -title SERWER -bg black -e ./$(EXEC1d1) &
	xterm -hold -title KLIENT -bg black -e ./$(EXEC2d1) &

	
xtermd2: $(EXEC1d2) $(EXEC2d2)
	( export LD_LIBRARY_PATH=${LIB_DIR}:${LD_LIBRARY_PATH}; \
	xterm -hold -title SERWER -bg black -e ./$(EXEC1d2) &
	xterm -hold -title KLIENT -bg black -e ./$(EXEC2d2) &