NAME =	lem-in

FLG =	-Wall -Wextra -Werror

SRC =	lem_inn.c stepone.c steptwo.c stepthree.c matrix.c solve.c sort.c ft_move.c \
		ft_valid.c ft_dellast.c

OBJ =	$(SRC:.c=.o)

HEAD = -I./libft/includes/

all: $(NAME) lib

$(NAME):	$(OBJ) libft/libft.a
	gcc $(FLG) $(OBJ) -L ./libft/ -lft -o $(NAME)

%.o: %.c lem_inn.h
	gcc -c $(FLG) $(HEAD) -o $@ $<

libft/libft.a: lib

lib:
	make -C ./libft/

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re:	fclean all