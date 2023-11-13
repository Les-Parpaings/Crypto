##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

# Compilation
CXX			:=		g++ -g
FLAGS		:=		-std=c++17 -Wall -Wextra
VALG		:=		valgrind --leak-check=full --log-file=report.txt

# Binary
BINDIR		:=		.
BINNAME		:=		mypgp
BIN			:=		$(BINDIR)/$(BINNAME)

# Source
SRCDIR		:=		src
SRCEXT		:=		cpp
SRC			:=		$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
SRCNOMAIN	:=		$(shell find $(SRCDIR) -type f -name *.$(SRCEXT) \
					\( ! -name main.$(SRCEXT) \))

# Objects
OBJDIR		:=		obj
OBJEXT		:=		o
OBJ			:=		\
$(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SRC:.$(SRCEXT)=.$(OBJEXT)))

# Test
TESTDIR		:=		tests
TESTEXT		:=		cpp
TESTSRC		:=		$(shell find $(TESTDIR) -type f -name *.$(TESTEXT))
TESTBIN		:=		unit_tests
TESTLIB		:=		-lcriterion

# Library / Include
LIB			:=		-L./lib/
INC			:=		-I./include/

# Command
RM			:=		rm -rf

# Display
BLACK		:=		\033[1;30m
RED			:=		\033[1;31m
GREEN		:=		\033[1;32m
YELLOW		:=		\033[1;33m
BLUE		:=		\033[1;34m
MAGENTA		:=		\033[1;35m
CYAN		:=		\033[1;36m
WHITE		:=		\033[1;37m
NC			:=		\033[0m
LINE			:=		\n================================================\n
INTRO_SUCCES	:=		$(GREEN)➜$(NC)
INTRO_FAILED	:=		$(RED)➜$(NC)

.PHONY:		all	clean	fclean	re	tests_run
.SILENT:	all	$(OBJ)	$(BIN)	clean	fclean	re	tests_run

all:	$(BIN)

# Compiled all .c file not compiled in .o
$(OBJ): $(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(dir $@)
	$(CXX) $(FLAGS) $(INC) -c -o $@ $< \
	&& printf "$(GREEN)➜  $(BLUE)file $(CYAN)$@ $(GREEN)created$(NC)\n" \
	|| printf "$(RED)➜  $(BLUE)file $(CYAN)$@ $(RED)failed$(NC)\n"

# Compiled project with lib and all .o files
$(BIN):	$(OBJ)
	$(CXX) $(FLAGS) $(INC) -o $@ $^ \
	&& printf "$(YELLOW)$(LINE) · Compilation Done$(LINE)$(NC)\n" \
	|| printf "$(RED)$(LINE) · Compilation Failed$(LINE)$(NC)\n"

# Removes all .o files
clean:
	find $(OBJDIR) -type f -name *.$(OBJEXT) \
	-exec printf "$(GREEN)➜  $(BLUE)file $(CYAN){} $(BLUE)removed$(NC)\n" \;
	$(RM) $(OBJDIR)/*

# Removes all useless files, binary and library
fclean:	clean
	find $(BINDIR) -type f -name $(BINNAME) \
	-exec printf "$(GREEN)➜  $(BLUE)binary $(CYAN){} $(BLUE)removed$(NC)\n" \;
	$(RM) $(BIN)
	find $(BINDIR) -type f -name $(TESTBIN) \
	-exec printf "$(GREEN)➜  $(BLUE)binary $(CYAN){} $(BLUE)removed$(NC)\n" \;
	$(RM) $(TESTBIN)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) vgcore.*
	$(RM) report.txt
	$(RM) report.txt.core.*

# Clean all and compile the project
re:	fclean all

# Compile and run tests
tests_run:	re
	$(CXX) $(FLAGS) $(INC) -o $(TESTBIN) $(SRCNOMAIN) $(TESTSRC) $(LIB) $(TESTLIB)
	./$(TESTBIN)

gcovr:		tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
