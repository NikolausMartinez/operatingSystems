# List headers needed
HEADERS = accessmemory.h

# List object files
OBJECTS = master.o palin.o

# This makes the executeable
default: master

# Complies all needed header files
%.o: %.c $(HEADERS)
	gcc -c $< -o $@

# Complies all needed source files into object file
program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

# Cleans up files
clean:
	-rm -f $(OBJECTS)
	-rm -f master
