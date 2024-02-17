# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 17:43:44 by sagemura          #+#    #+#              #
#    Updated: 2024/02/17 19:44:58 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = helper_func.a
UTILSNAME = utils.a
PHILOCOMPNAME = philo_components.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(UTILSDIR) -I$(PHILOCOMPDIR)

SRC = ft_close.c ft_time.c print_behavior.c routine.c threads.c
UTILSDIR = ./utils
PHILOCOMPDIR = ./philo_components

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(MAKE) -C $(UTILSDIR)
	$(MAKE) -C $(PHILOCOMPDIR)
	ar rcs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	$(MAKE) clean -C $(UTILSDIR)
	$(MAKE) clean -C $(PHILOCOMPDIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(UTILSDIR)
	$(MAKE) fclean -C $(PHILOCOMPDIR)
	rm -f $(NAME)

re: fclean all