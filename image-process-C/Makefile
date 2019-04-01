all: start
	@echo "Done!"

start: bin imgs bin/number.o bin/main.o
	@echo "-----------------#####-----------------"
	@echo "Creating executable..."
	gcc bin/number.o bin/main.o -o start -lm

imgs: 
	@echo "Creating aditional folders..."
	mkdir imgs
bin:
	@echo "-----------------#####-----------------"
	@echo "Creating aditional folders..."
	mkdir bin

bin/number.o: src/number.h
	@echo "Compiling number archieve..."
	gcc -c src/number.c -o bin/number.o

bin/main.o: src/main.c
	@echo "Compiling main function..."
	gcc -c src/main.c -o bin/main.o

clean:
	@echo "Removing binaries.."
	rm bin/*.o -f