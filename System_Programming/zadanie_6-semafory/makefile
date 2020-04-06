.SUFFIXES: .c .o .h

DIR = `basename $(PWD)`

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rv

NAME1 = 1
NAME2 = 2
NAME3 = semafory


EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x


OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o

HEADS1 = $(NAME3).h

CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O

	
%.o: %.c %.h $(HEADS1)
	$(CO) $(CFLAGS) -c $<




.PHONY: all
all: $(EXEC1) $(EXEC2) $(HEADS1)



$(EXEC1): $(OBJS1) $(OBJS3) $(HEADS1)
	$(LD) -o $@ $(LFLAGS) $^
	

$(EXEC2): $(OBJS2) $(OBJS3) $(HEADS1)
	$(LD) -o $@ $(LFLAGS) $^



#$(OBJS1): $(HEADS1)

#$(OBJS2): $(HEADS1)

#$(OBJS3): $(HEADS1)

	
#przerobic ten fragment, coby dzialalo xdd
.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1) $(ARGS)


	
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
