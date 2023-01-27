NAME = s21_cat
SRCS = $(wildcard *.c)  #все файлы с расширением .с
INCL = $(wildcard *.h)	# то же, но с .h
OBJS = $(SRCS:.c=.o)	# все файлы с переделываем в объектные файлы и кладем OBJS

FLAGS = -Wall -Werror -Wextra

#Code should complite with flag -std=c11
# Поместить в объектный или исполняемый файл отладочную информацию для отладчика gdb.
FLAGS += -g
# стандарт с11
FLAGS += -std=c11

CC = gcc

all: $(NAME)

#линковка

$(NAME): $(OBJS) $(INCL)

	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

#создание объектных файлов
%.o: %.c $(INCL)

#если ты встречаешь, что-то оканчивающееся на .о сделай команду $(CC) $(FLAGS).
	$(CC) $(FLAGS) -c $< -o $@

# удалить все объектные файлы
clean:
	rm -rf $(OBJS)
	rm -rf *.txt

# удаляет все объектные файлы и саму программу
fclean: clean
	rm -rf $(NAME)
	rm -rf *.txt

#все удалить и пересобрать
re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --tool=memcheck --log-
file=log.txt ./cat s21_grep.c

cppcheck: s21_grep.c
	cppcheck --enable=all --std=c11 --inconclusive --
suppress=missingIncludeSystem *.c

test:

.PHONY: all clean fclean re test valgrind cppcheck

#http://www.opennet.ru/docs/RUS/make_compile/

