.SUFFIXES: .c .o

DIR = `basename $(PWD)`

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rv

NAME1 = 1
NAME2 = 2


EXEC1  = $(NAME1).x
EXEC2  = $(NAME2).x


OBJS1  = $(NAME1).o
OBJS2  = $(NAME2).o


CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O

	
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<



.PHONY: all
all: $(EXEC1) $(EXEC2)



$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
	

$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^

	

.PHONY: run1
run1: $(EXEC1)
	./$(EXEC1)	


.PHONY: run2
run2: $(EXEC2)
	./$(EXEC2)



	
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
