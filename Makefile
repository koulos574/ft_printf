NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

DIR_H = include/

DIR_S = src/

HEADER = printf.h

SOURCES = 		src/allinwrite.c \
				src/conversion_check.c \
				src/flags_check.c \
				src/ft_printf.c \
				src/init_all.c \
				src/letsee.c \
				src/parser.c \
				src/precision_check.c \
				src/print_percent.c \
				src/print_c.c \
				src/print_d_or_i.c \
				src/print_d_or_i_part_2.c \
				src/print_p.c \
				src/print_s.c \
				src/print_u.c \
				src/print_u_part_2.c \
				src/print_width.c \
				src/print_x.c \
				src/print_x_part_2.c \
				src/utils1.c \
				src/utils2.c \
				src/utils3.c \
				src/utils4.c \
				src/width_check.c \

OBJS = 			allinwrite.o \
				conversion_check.o \
				flags_check.o \
				ft_printf.o \
				init_all.o \
				letsee.o \
				parser.o \
				precision_check.o \
				print_percent.o \
				print_c.o \
				print_d_or_i.o \
				print_d_or_i_part_2.o \
				print_p.o \
				print_s.o \
				print_u.o \
				print_u_part_2.o \
				print_width.o \
				print_x.o \
				print_x_part_2.o \
				utils1.o \
				utils2.o \
				utils3.o \
				utils4.o \
				width_check.o \

all: $(NAME)

$(NAME):
			@gcc $(CFLAGS) -c $(SOURCES) $(DIR_H)$(HEADER) 
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
