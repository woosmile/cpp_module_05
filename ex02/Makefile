NAME = a.out

CXXFLAGS = -Werror -Wall -Wextra -std=c++98

RM = rm
RMFLAGS = -rf

HEADER = \
Bureaucrat.hpp \
AForm.hpp \
ShrubberyCreationForm.hpp \
RobotomyRequestForm.hpp \
PresidentialPardonForm.hpp

SRCS = \
Bureaucrat.cpp \
AForm.cpp \
main.cpp \
ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp \
PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re