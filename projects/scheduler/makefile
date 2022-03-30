

scheduler : scheduler_test.o scheduler.o priorityq.o sorted_list.o task.o simple_UID.o dlist.o vector.o
	gcc -o scheduler scheduler.o scheduler_test.o priorityq.o sorted_list.o task.o simple_UID.o dlist.o 
	

scheduler_test.o : scheduler_test.c scheduler.h 
	gcc -c scheduler_test.c 

scheduler.o : scheduler.c scheduler.h utils.h
	gcc -c scheduler.c scheduler.h


priorityq.o : /home/michael/michael-kolet/ds/src/priorityq/priorityq.c priorityq.h vector.h utils.h
	gcc -c /home/michael/michael-kolet/ds/src/priorityq/priorityq.c -I ./


sorted_list.o : /home/michael/michael-kolet/ds/src/sorted_list/sorted_list.c sorted_list.h utils.h
	gcc -c /home/michael/michael-kolet/ds/src/sorted_list/sorted_list.c -I ./

	
vector.o : /home/michael/michael-kolet/ds/src/vector/vector.c vector.h utils.h
	gcc -c /home/michael/michael-kolet/ds/src/vector/vector.c -I ./
	

task.o : /home/michael/michael-kolet/ds/src/task/task.c task.h simple_UID.h utils.h
	gcc -c /home/michael/michael-kolet/ds/src/task/task.c -I ./
	
simple_UID.o : /home/michael/michael-kolet/ds/src/simple_UID/simple_UID.c simple_UID.h utils.h
	gcc -c /home/michael/michael-kolet/ds/src/simple_UID/simple_UID.c -I ./


dlist.o : /home/michael/michael-kolet/ds/src/dlist/dlist.c dlist.h utils.h
	gcc -c /home/michael/michael-kolet/ds/src/dlist/dlist.c -I ./

clean :
	rm *.o
