
NAME = $(notdir $(PWD))

TARGET= lib$(NAME).so

OBJ= $(NAME).o

OBJS= $(NAME).o  $(NAME)_test.o

SRC1 = /home/michael/michael-kolet/ds/src/$(NAME)/$(NAME).c 
SRC2 = /home/michael/michael-kolet/ds/test/$(NAME)_test.c
SRC3 = $(NAME).h

LIB_LOCATION = /home/michael/michael-kolet/ds/lib/

STATIC_LIB=libilrdds.a

CC= gcc

CFLAGS= -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3

INCLUDE = ../../include/

#****************************************************************


$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -shared -o $(LIB_LOCATION)$(TARGET) $(OBJ) 
		

$(OBJ) : $(SRC1) $(SRC3)
	$(CC) $(CFLAGS) -fpic $(SRC1) $(SRC3) 

$(NAME)_run : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME)_run $(OBJS)   

$(NAME).o : $(SRC1) $(INCLUDE) 
	$(CC) $(CFLAGS) -c $(SRC1) -I $(INCLUDE)

$(NAME)_test.o :  $(SRC1) $(SRC2) $(INCLUDE) 
	$(CC) $(CFLAGS) -c $(SRC2) $(SRC1) -I $(INCLUDE)



#***********************************************************************
		                                 
run_test :
	$(CC) -L $(LIB_LOCATION) -Wl,-rpath=$(LIB_LOCATION) -o $(NAME)_run \
	 $(SRC2) -I $(INCLUDE) -l$(NAME); ./$(NAME)_run
	
insert_test:
	./$(NAME)_run > test.txt

clean :
	rm *.o
	
Add_to_archive:	
	ar r $(LIB_LOCATION)$(STATIC_LIB) $(OBJ)

