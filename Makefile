# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 13:26:57 by pabeckha          #+#    #+#              #
#    Updated: 2024/05/23 11:38:02 by pabeckha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ar rcs $@ $^ is the recipe or command to build the target. 
# ar: Archive command used for creating static libraries.
# rcs: Options for ar:
#     r: Insert files into the archive.
#     c: Create the archive if it doesn't exist.
#     s: Write an index (symbol table) into the archive.
# $@: Automatic variable representing the target name
# $^: Automatic variable representing all the prerequisites(the object files)



# ar rcs $@ $^ is the recipe or command to build the target. 
# ar: Archive command used for creating static libraries.
# rcs: Options for ar:
#     r: Insert files into the archive.
#     c: Create the archive if it doesn't exist.
#     s: Write an index (symbol table) into the archive.
# $@: Automatic variable representing the target name
# $^: Automatic variable representing all the prerequisites(the object files)

# =============================================================================
# Color Variables
# =============================================================================

BLACK				= 		"\033[0;30m"
GRAY				= 		"\033[1;30m"
RED					=		"\033[0;31m"
GREEN				=		"\033[0;32m"
YELLOW				=		"\033[1;33m"
PURPLE				=		"\033[0;35m"
CYAN				=		"\033[0;36m"
WHITE				=		"\033[1;37m"
EOC					=		"\033[0;0m"
RESET_COLOR 		= 		"\033[0m"


# Standard
NAME			= philo

# Directories
SRC_DIR			:= src/
OBJ_DIR			:= obj/

# Compiler and Flags
CC				:= cc
RM				:= rm -f
CFLAGS			:= -Wall -Wextra -Werror
# DEBUG			:= -g -fsanitize=thread
# SANITIZER 		:= -fsanitize=address -g



SHARED_SRCS			:= 	$(SRC_DIR)main.c \
						$(SRC_DIR)ft_atoi.c \
						$(SRC_DIR)init_vars.c \
						$(SRC_DIR)init_philo.c \
						$(SRC_DIR)ft_putstr_fd.c \
						$(SRC_DIR)simulation.c \
						$(SRC_DIR)get_time.c \
						$(SRC_DIR)write_status.c \
						$(SRC_DIR)ft_usleep.c \
						$(SRC_DIR)ft_philo.c \
						$(SRC_DIR)ft_strcmp.c \
						$(SRC_DIR)take_fork_and_eat.c \
						$(SRC_DIR)compare_philo_id.c \
						
						


	

#Source Files
SRCS			:= 	$(SHARED_SRCS)
					

SRCS_BONUS		:= 	$(SHARED_SRCS)\
				

# Creation of Object Files for each Source File
OBJ				:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Creation of Object Files for each Bonus Source File
OBJ_BONUS		:= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

# Rules
all: 		${NAME}

bonus: 		${NAME}_bonus

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c
					@echo $(YELLOW) "Compiling...\t" $< $(EOC)
					@mkdir -p $(@D)
					@${CC} ${CFLAGS} ${DEBUG} $(SANITIZER) -c $? -o $@


${NAME}: 		${OBJ}
					@echo  $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo  $(WHITE) "Building ${NAME} for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@${CC} ${CFLAGS} ${DEBUG} $(SANITIZER) $^ -o ${NAME}
					@echo  $(GREEN) "${NAME} Mandatory is created!\n" $(EOC) $(RESET_COLOR)


${NAME}_bonus:	${OBJ_BONUS}
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building ${NAME} for" $(YELLOW) "Bonus" $(WHITE)
					@make -s -C ./libs/libft
					@${CC} ${CFLAGS} {DEBUG} $^ -L./libs/libft -lft -o ${NAME}_bonus
					@echo $(GREEN) "${NAME} Bonus is created!\n" $(EOC) $(RESET_COLOR)

libft:
				@make -C libs/libft


clean:
				@echo $(YELLOW) "Cleaning object files..." $(EOC)
				@${RM} ${OBJ} ${OBJ_BONUS}
				@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean:			clean
				@echo $(YELLOW) "Removing ${NAME}..." $(EOC)
				@${RM} ${NAME} ${NAME}_bonus
				@rm -rf ${OBJ_DIR}
				@echo $(RED) "${NAME} is removed!\n" $(EOC)

re:				fclean all



.PHONY: all clean fclean re libft bonus