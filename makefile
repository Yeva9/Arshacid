export EXE := benchmark
export CC := g++

export SRCS := $(wildcard src/*.cpp)
export OBJS := $(patsubst src/%.cpp, obj/%.o, $(SRCS))

export LIBS	:= ./lib/ByArshacid.so 

$(LIBS) : $(OBJS) #obj/Sortings.o
	@mkdir -p lib
	$(CC) -shared $^ -o $@

obj/%.o : src/%.cpp
	mkdir -p obj
	$(CC) -fPIC -c $< -o $@

.PHONY : clean
clean :
	rm -rf obj lib 	
