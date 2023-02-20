# Makefile implemented for:
# 	master_test_namespace (default)
#	classes
#	dynamic_vs_static
# Note that makefile must use tabs not spaces

######## Executable files #########
# Specify how to make the executable files

# Only the first (default goal) line is ran with just 'make' command
# Specify all executable files as prerequisites to make them all
all: master_test_namespace classes dynamic_vs_static

# Get with 'make master_test_namespace'
objects_1 = master_test_namespace.o test_namespace.o
master_test_namespace: $(objects_1)
	$(CXX) -o master_test_namespace $(objects_1)

# Get with 'make classes'
objects_2 = classes.o
classes: $(objects_2)
	$(CXX) -o classes $(objects_2)

# Get with 'make dynamic_vs_static'
objects_3 = dynamic_vs_static.o
dynamic_vs_static: $(objects_3)
	$(CXX) -o dynamic_vs_static $(objects_3)

######## Object files #########
# Specify how to make the object files
# Specify dependencies (prerequisites) + command to run to
# obtain target for each target

test_namespace.o: test_namespace.cpp test_namespace.h
	$(CXX) -c test_namespace.cpp
master_test_namespace.o: master_test_namespace.cpp test_namespace.h
	$(CXX) -c master_test_namespace.cpp

# Implicit compilation rule for source files (.c, .cpp):
classes.o: classes.h

# Don't even need header files if we don't have them for the implicit rule:
dynamic_vs_static.o:

######## Clean #########
# Specify clean up procedure(s)

# Run with 'make clean'
# Specify each clean function as prerequisite to run them all
clean: clean_master_test_namespace clean_classes clean_dynamic_vs_static

clean_master_test_namespace:
	rm master_test_namespace $(objects_1)

clean_classes:
	rm classes $(objects_2)

clean_dynamic_vs_static:
	rm dynamic_vs_static $(objects_3)