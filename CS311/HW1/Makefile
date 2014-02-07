NAME=	HW1_MathiasLang
SRC=	client1.cpp	\
	queue.cpp	\
	stack.cpp
OBJS=	$(SRC:.cpp=.o)

RM=	rm -rf

CXXFLAGS += -W -Wall

all:	$(NAME)

$(NAME):	$(OBJS)
	g++ $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) *~

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
