DIR = `basename $(PWD)`

NAME1 = serwer
NAME2 = klient
NAME3 = biblioteka_kolejki

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o


LIB_NAME = biblioteka_kolejki
LIB_DIR = ./lib
LIB_STAT = lib$(LIB_NAME).a
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

.PHONY: all
all: $(EXEC1) $(EXEC2) $(OBJS3)

$(EXEC1): $(OBJS1) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) -static $(OBJS1)  -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)

$(EXEC2): $(OBJS2) $(LIB_STAT)
	$(LD) -o $@ $(LFLAGS) -static $(OBJS2) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)

$(OBJS3): $(HEADS3)

.PHONY: serwer
serwer: $(EXEC1) 
	./$(EXEC1)
			
.PHONY: klient
klient: $(EXEC2)
	./$(EXEC2)

.PHONY: xterm
xterm: $(EXEC1) $(EXEC2)
	xterm -hold -title SERWER -bg black -e ./$(EXEC1) &
	xterm -hold -title KLIENT -bg black -e ./$(EXEC2) &
	xterm -hold -title KLIENT -bg black -e ./$(EXEC2) &


.PHONY: clean tar
clean:                                                    
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
