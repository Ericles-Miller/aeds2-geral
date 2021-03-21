#regra: dependências 
#Apertar o botão TAB   comando  
#                      comando ...
############################# Makefile ##########################
all: queue
queue: queue.o main.o 
        # O compilador faz a ligação entre os dois objetos
		gcc -o queue queue.o main.o
#		botão TAB ### e 
#		não com espaços
queue.o: queue.c
		gcc -o queue.o -c queue.c -W -Wall -ansi -pedantic
main.o: main.c queue.h
		gcc -o main.o -c main.c -W -Wall -ansi -pedantic
clean:
		rm -rf *.o
mrproper: clean
		rm -rf queue
		
		
#-Wall
#		Ativa vários avisos que não são ativados normalmente. 
#		Pode dar alguns conselhos úteis.
#-pedantic
#		Ativa alguns avisos que existem de acordo com o padrão C 
#		mas que são desativados normalmente por extensões do gcc.
#-ansi
#		compila seu programa estritamente de acordo com o padrão ANSI, 
#		desativando qualquer extensão específica do gcc. 