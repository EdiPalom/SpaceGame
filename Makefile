CXX=g++

# CXXFLAGS=-I"include"
# CFLAGS=-Wall
LDLIBS=-lSDL2 -lm -lSDL2_mixer
LDFLAGS = -L/usr/lib
OPTS:=-Wall
# APP_BIN = bin/app/
INCLUDEDIR:=src:include:/usr/include
SRCDIR:=src
BUILDDIR:=build
OBJDIR:=obj
OBJPATH:=$(BUILDDIR)/$(OBJDIR)

INCLUDE := $(patsubst %, -I%,$(subst :, ,$(INCLUDEDIR)))

# SOURCES:=$(wildcard $(SRCDIR)/*.cpp)
SOURCES:=$(shell find $(SRCDIR) -type f -name *.cpp)
# OBJECTS:=$(subst .cpp,.o,$(SOURCES))
OBJECTS:=$(subst $(SRCDIR),$(BUILDDIR)/$(OBJDIR),$(SOURCES:.cpp=.o))

# all:main

# main:$(OBJECTS)

# $(CPP) $(APP_BIN)$^ -o main
# $(CPP) $(OPTS) -o $(APP_BIN)$@ -c $^ $(CPP_FLAGS)
# rm -f $(APP_BIN)*.o *.a main

main: $(OBJECTS)
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)

$(OBJPATH)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(OPTS) -o $@ -c $^ $(INCLUDE) 

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))

clean:
	$(RM) $(OBJPATH)/*.o *.a main

rm_main:
	$(RM) main

delete:
	@read -p "Enter file name:" file; \
	$(RM) $(OBJPATH)/$$file.o; \
	echo "deleted $(OBJPATH)/$$file.o";
	$(RM) main
