#                                                                   
# makefile for application preconcole library
# 
#

EDIR = ./bin
ODIR = ./obj
SDIR = .

CC = gcc

CCFLAGS = -g

HORIZONTAL = $(EDIR)/horizontal

PROGRAM = $(HORIZONTAL)

##################### object files #####################
HORIZONTAL_OBJ = $(ODIR)/horizontal.o

########################################################
all:	$(PROGRAM)

$(HORIZONTAL)::	$(HORIZONTAL_OBJ)
	@echo ------ Linking...	------
	$(CC) -o $(HORIZONTAL) $(HORIZONTAL_OBJ) $(CCFLAGS)
	@echo ------ make $@ OK. ------

clean::
	@$(RM) $(HORIZONTAL) $(HORIZONTAL_OBJ)
	
cleanbin::
	@$(RM) $(PROGRAM)

.SUFFIXES: .cpp .c .o .so .a
##################### common ##################### 
$(ODIR)/horizontal.o:$(SDIR)/horizontal.c
	$(CC) -o $@ $(CCFLAGS) -c $?

