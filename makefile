# List headers needed (none for this program)
HEADERS = 

# List object files
OBJECTS = my_prog.o

# The first target. This tell "make" to make the "my_prog" target
default: my_prog

# Complies all needed source files into object files 
%.o: %.c $(HEADERS)
	gcc -c $< -o $@

# Complies all needed source files into object files
program: $(OBJECTS)
	gcc $(OBJECTS) -o $@

# Cleans up files
clean:
	-rm -f $(OBJECTS)
	-rm -f my_prog
