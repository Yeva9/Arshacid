export CC := g++

export SRCS := $(wildcard src/*.cpp)
export OBJS := $(patsubst src/%.cpp, obj/%.o, $(SRCS))

export LIBS	:= ./lib/ByArshakid.so 

$(LIBS) : $(OBJS) 
	@mkdir -p lib
	$(CC) -shared $^ -o $@

obj/%.o : src/%.cpp
	mkdir -p obj
	$(CC) -fPIC -c $< -o $@

.PHONY : clean
clean :
	rm -rf obj lib 	
