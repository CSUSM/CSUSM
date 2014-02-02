NAME=	CS351.HW1.Mathias.Lang
SRC=	\
	main.cpp	\
	Machine.cpp
OBJS=	$(SRC:.cpp=.o)

RM=	rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.NOTPARALLEL:	clean fclean re
.PHONY:		all clean fclean re
