INCL := -I../../include/
LIBPATH = ../../lib/
CC := gcc
CFLAGS  := -ansi -pedantic-errors -Wall -Wextra -g -fpic
CPPFLAGS := $(INCL)
LDFLAGS= -lm
VPATH = ../src ../../test ../../include ../../include/utils $(LIBPATH)
ARCH = $(LIBPATH)libilrdds.a

.PHONY: clean all run_test add_to_ar
################################################################################
#                       folder-scpecific variables                             #
################################################################################

DIRNAME = $(notdir $(PWD))
SOURCES = $(wildcard *.c)
DEPS = $(DIRNAME).d
OBJS = $(SOURCES:.c=.o)
SHARED_OBJ = $(LIBPATH)lib$(DIRNAME).so
TEST = $(DIRNAME)_test
TEST_SRC = $(TEST).c
TEST_OBJ = $(TEST).o
ALL_LIBS = $(filter-out $(SHARED_OBJ),$(wildcard $(LIBPATH)*.so))

################################################################################
#                                  recipes                                     #
################################################################################

$(SHARED_OBJ): $(OBJS) 
	$(CC) -shared -o  $(SHARED_OBJ) $(OBJS) $(ALL_LIBS)

$(TEST): $(SHARED_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST) $(TEST_OBJ) $(SHARED_OBJ) $(ALL_LIBS) $(INCL)
	
add_to_ar: $(OBJS)
	ar -rcs $(ARCH) $(OBJS)

run_test: $(TEST) 
	@./$(TEST) > /dev/null
	@echo -e "\e[1;32m $(TEST) SUCCESS\e[1;0m"

all: $(TEST)
	./$(TEST)
	@echo SUCCESS, PROCEEDING	
	ar -rcs $(ARCH) $(OBJS)
	$(CC) -shared -o  $(SHARED_OBJ) -fpic $(OBJS)

clean:
	rm -f *.o *.d $(SHARED_OBJ) $(TEST)
	ar -d $(ARCH) $(OBJS)

################################################################################
#                            writing dependencies                              #
################################################################################
include $(DEPS)
$(DEPS): $(SOURCES)
	$(CC) -MM $(SOURCES) > $(DEPS) $(INCL)
