NAME = Converter
VERMILION_RED=\033[1;31m
AZURE_BLUE=\033[1;34m
GOLD_COLOR=\033[38;5;220m
GREEN=\033[0;32m
RESET=\033[0m
SRC_FILES = main.cpp \
			Fixed.cpp \

OBJECTS = $(SRC_FILES:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)  

$(NAME) : $(OBJECTS) $(INCLUDE) Makefile
	@echo "$(GOLD_COLOR)Compiling Converter...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME)  $(OBJECTS) 
	@echo "$(GOLD_COLOR)Converter compiled ! :)$(RESET)"

clean:
	@echo "$(AZURE_BLUE)Cleaning in progress...$(RESET)"
	@rm -f $(OBJECTS)
	@echo "$(AZURE_BLUE)Cleanup done ! :)$(RESET)"

fclean: clean
	@echo "$(AZURE_BLUE)Deep cleaning in progress...$(RESET)"
	@rm -f $(NAME)
	@echo "$(AZURE_BLUE)Deep Cleaning over ! :)$(RESET)"	

re: fclean $(NAME)

.PHONY: all clean fclean re