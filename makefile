# List headers needed
#HEADERS =

# List object files
OBJECTS = oss.o

# This makes the executeable
default: oss

# Complies all needed header files
# %.o: %.c $(HEADERS)
# 	gcc -c $< -o $@

# Complies all needed source files into object file
program: $(OBJECTS)
	gcc $(ObJECTS) -o $@

# Clean up files
clean:
	-rm -f $(OBJECTS)
	-rm -f oss 
