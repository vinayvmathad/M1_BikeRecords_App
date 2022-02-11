#Target : Dependencies
#<TAB>commands
PROJECT_NAME= M1_BikeRecords_App
SRC=src/bikemain.c\
# creatinng header files
INC=inc

ifdef OS
	RM=del /q
	FixPath = $(subst /,\,$l)
	EXEC= exe
else
   ifeq ($(shell uname), Linux)
    	RM = rm -rf
    	FixPath = $1
		EXEC= out
   endif
endif



Build:
	gcc -I $(INC) $(SRC)  -o $(call FixPath, ./$(PROJECT_NAME).$(EXEC))

Run : Build
	$(call FixPath, ./$(PROJECT_NAME).$(EXEC))

Clean: 
	$(RM) $(call FixPath,*.out)