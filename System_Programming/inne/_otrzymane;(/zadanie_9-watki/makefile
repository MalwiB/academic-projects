.SUFFIXES: .c .o

DIR = `basename $(PWD)`

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rv

NAME1 = sharing_variable


EXEC1  = $(NAME1).x


OBJS1  = $(NAME1).o


CFLAGS =  -O -fPIC
LFLAGS = -Wall -pthread

	
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<



.PHONY: all
all: $(EXEC1)



$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
	

	

.PHONY: run
run: $(EXEC1)
	./$(EXEC1)


	
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
