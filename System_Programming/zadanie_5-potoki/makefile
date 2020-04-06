.SUFFIXES: .c .o

DIR = `basename $(PWD)`

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rv

NAME1 = producent
NAME2 = klient
NAME3 = program

EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x
EXEC3  = $(NAME3).x

OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o
OBJS3  = $(NAME3).o

CFLAGS = -Wall -O -fPIC -w
LFLAGS = -Wall -O

	
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<



.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)



$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
	

$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^


$(EXEC3): $(OBJS3) 
	$(LD) -o $@ $(LFLAGS) $^
	

.PHONY: run1
run1: $(EXEC1) $(EXEC2) $(EXEC3)
	./$(EXEC3) $(ARGS)


	
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
