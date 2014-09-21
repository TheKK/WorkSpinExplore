 #
 # Author: KK <thumbd03803@gmail.com>
 #
 # File: Makefile
 #

CXX = clang++
CXXFLAG = -Wall -std=c++11 -g

SRC_PATH = $(PWD)/src

# Include flags
INCLUDE = -I $(PWD)/include
INCLUDE += $(shell pkg-config --cflags sdl2)
INCLUDE += $(shell pkg-config --cflags SDL2_image)
INCLUDE += $(shell pkg-config --cflags SDL2_ttf)
#INCLUDE += $(shell pkg-config --cflags lua)
#INCLUDE += $(shell pkg-config --cflags openal)

# Libs flags
LIB += $(shell pkg-config --libs sdl2)
LIB += $(shell pkg-config --libs SDL2_image)
LIB += $(shell pkg-config --libs SDL2_ttf)
#LIB += $(shell pkg-config --libs lua)
#LIB += $(shell pkg-config --libs openal)

# Object files
OBJ_PATH = $(PWD)/obj
OBJ = main.o		\
      game.o		\
      workGame.o	\
      spinGame.o	\
      exploreGame.o	\
      toolBox.o		\
      window.o		\
      timer.o		\
      texture.o		\
      sprite.o		\
      textLabel.o	\
      button.o		\
      achievementBar.o	\
      numberDisplayer.o	\
      renderable.o	\

OUT_EXE = wse

all: $(OUT_EXE)
	@echo "===========[[Everything done!!]]============"

$(OUT_EXE): $(addprefix $(OBJ_PATH)/, $(OBJ))
	@echo "    LD    " $(notdir $@)
	@$(CXX) $(addprefix $(OBJ_PATH)/, $(OBJ)) $(CXXFLAG) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@echo "    CC    " $(notdir $@)
	@$(CXX) -c $< $(CXXFLAG) $(INCLUDE) -o $@

.PHONY: tag
tag:
	@rm -f tags
	@ctags -aR --fields=+l --c++-kinds=+px /usr/include/SDL2
	@ctags -aR --fields=+l --c++-kinds=+px $(PWD)
	@echo "===========[[Tags updated!!]]============"

.PHONY: clean
clean:
	@rm -frv $(OBJ_PATH)/*.o $(OUT_EXE)
	@echo "===========[[Everything removed!!]]============"
