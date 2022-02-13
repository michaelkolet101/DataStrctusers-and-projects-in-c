
OBJ = calculator.o state_mach.o

a.out : $(OBJ)
	gcc calculator.o  

calculator.o : calculator.c /home/michael/michael-kolet/ds/src/state_mach/state_mach.c /home/michael/michael-kolet/ds/src/state_mach/state_mach.h /home/michael/michael-kolet/ds/src/stack/stack.c /home/michael/michael-kolet/ds/src/stack/stack.h 
	gcc -c /home/michael/michael-kolet/ds/src/state_mach/state_mach.c /home/michael/michael-kolet/ds/src/state_mach/state_mach.h /home/michael/michael-kolet/ds/src/stack/stack.c /home/michael/michael-kolet/ds/src/stack/stack.h

state_mach.o : /home/michael/michael-kolet/ds/src/state_mach/state_mach.c
	gcc -c /home/michael/michael-kolet/ds/src/state_mach/state_mach.c /home/michael/michael-kolet/ds/src/state_mach/state_mach.h
	
stack.o : stack.c
	gcc -c /home/michael/michael-kolet/ds/src/stack/stack.c /home/michael/michael-kolet/ds/src/stack/stack.h
	
	
