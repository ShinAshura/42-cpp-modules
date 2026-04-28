NAME = array

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98

S_DIR = srcs
O_DIR = .objs

SRCS = 	\
	main.cpp

OBJS = $(SRCS:%.cpp=$(O_DIR)/%.o)

RESET = \033[0m
GREEN = \033[0;32m
RED	= \033[0;31m

COUNTER_FILE = .counter_makefile


all: reset_counter $(NAME)
	@if [ ! -f .built ]; then \
		echo "$(NAME): everything is already up to date."; \
	fi
	@rm -f .built
	@rm -f .counter_makefile

$(O_DIR)/%.o : %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -I./hdrs/ -c $< -o $@
	@count=`cat $(COUNTER_FILE)`; \
	count=`expr $$count + 1`; \
	echo $$count > $(COUNTER_FILE); \
	echo -n "\r$(NAME): compiling... $$count/$(words $(SRCS))"

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -I./hdrs/ $(OBJS) $(LIBS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME)$(RESET) has been compiled."
	@rm $(COUNTER_FILE)
	@touch .built

clean:
	@rm -rf $(O_DIR) $(COUNTER_FILE) .built
	@echo "$(NAME): ${RED}${O_DIR}${RESET} has been deleted."

fclean:
	@rm -rf $(O_DIR) $(NAME) $(COUNTER_FILE) .built
	@echo "$(NAME): ${RED}${O_DIR}${RESET} and ${RED}${NAME}${RESET} have been deleted."

re: fclean all

reset_counter:
	@echo 0 > $(COUNTER_FILE)

.PHONY: all clean fclean re reset_counter
