# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschenk <aschenk@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 12:24:25 by aschenk           #+#    #+#              #
#    Updated: 2024/10/17 16:02:08 by aschenk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			account

# SOURCE FILES
SRCS_DIR :=		src
SRCS_FILES :=	Account.cpp \


SRCS :=			$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

# OBJECT FILES
OBJS_DIR :=		obj
OBJS :=			$(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

# HEADER FILES
HDRS_DIR :=		include
HDRS_FILES := 	Account.hpp
HDRS :=			$(addprefix $(HDRS_DIR)/, $(HDRS_FILES))

# COMPILER
CC :=			c++
CFLAGS :=		-Werror -Wextra -Wall
CFLAGS +=		-I$(HDRS_DIR)
CFLAGS +=		-std=c++98
CFLAGS +=		-Wpedantic
#CFLAGS +=		-g

# Used for progress bar
TOTAL_SRCS :=	$(words $(SRCS))
SRC_NUM :=		0

# ANSI escape codes for colors and styles
RESET =			\033[0m
BOLD =			\033[1m
GREEN =			\033[32m
YELLOW =		\033[33m
RED :=			\033[91m

###########
## RULES ##
###########

# Default target
all:		$(NAME)

# Target $(NAME) depends on object files $(OBJS)
# Print out 'Thinking Philosopher' once program is compiled.
$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)\n$(NAME) successfully compiled.$(RESET)"

	@echo -n "$(BOLD)$(GREEN)"
	@echo "   __    ___  ___  _____  __  __  _  _  ____ "
	@echo "  /__\  / __)/ __)(  _  )(  )(  )( \( )(_  _)"
	@echo " /(__)\( (__( (__  )(_)(  )(__)(  )  (   )(  "
	@echo "(__)(__)\___)\___)(_____)(______)(_)\_) (__) "
	@echo -n "$(RESET)"

	@echo "\n$(BOLD)$(YELLOW)Usage: './$(NAME) [<message to shout>]'$(RESET)"

## COMPILATION PROGRESS BAR ##
# Rule to define how to generate object files (%.o) from corresponding
# source files (%.c). Each .o file depends on the associated .c file and the
# project header files.
# Last line:
# -c:		Generates o. files without linking.
# -$<:		Represents the first prerequisite (the c. file).
# -o $@:	Output file name;  '$@' is replaced with target name (the o. file).
$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp $(HDRS)
	@mkdir -p $(@D)
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@$(eval PERCENT := $(shell printf "%.0f" $(shell echo "scale=4; $(SRC_NUM) / $(TOTAL_SRCS) * 100" | bc)))
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@printf "$(GREEN)%0.s#$(RESET)$(BOLD)" $(shell seq 1 $(PROGRESS))
	@if [ $(PERCENT) -lt 100 ]; then printf "%0.s-" $(shell seq 1 $(shell expr 20 - $(PROGRESS))); fi
	@printf "] "
	@if [ $(PERCENT) -eq 100 ]; then printf "$(GREEN)"; fi
	@printf "%d/%d - " $(SRC_NUM) $(TOTAL_SRCS)
	@printf "%d%% $(RESET)" $(PERCENT)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -D FD_SIZE=$(FD_SIZE) -c $< -o $@

# Rule to remove all generated object files.
clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(BOLD)$(RED)$(NAME) object files removed.$(RESET)"

# Rule to remove all generated object files and the program executable.
fclean:	clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)$(NAME) removed.$(RESET)"

# Rule to remove all generated object files, the program executable,
# and then rebuild the program.
re:	fclean all

# Makes that make rules are invoked even if files of the same name happen to be in the directory.
.PHONY: all clean fclean re
