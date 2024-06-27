NAME			= matrix
INC_DIR			= ./include/
SRC_DIR			= ./src/
OUT_DIR			= ./obj/

SRC				= 	main.cpp

SRCC			= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS			= ${SRCC:%.cpp=${OUT_DIR}%.o}
INCLUDE			= -I${INC_DIR}

CC				= c++
CFLAGS			= -g
CFLAGS			+= -Wall -Werror -Wextra
# CFLAGS			+= -fsanitize=address
MKDIR			= mkdir -p
RM				= rm -rf

all: ${NAME}

ifdef OS 
${NAME}:
	g++ -g -Wall -Wextra -lstdc++ -o ${NAME} src\main.cpp -I.\include
else
${NAME}: ${OBJS}
	@${CC} -o ${NAME} ${INCLUDE} ${OBJS} ${CFLAGS}
endif

TESTS = 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
${TESTS}:
	@${CC} ${CFLAGS} -o $@ ${INCLUDE} src/ex$@.cpp $<
	@./$@
	@rm $@

test:
	@for i in 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 ; do \
		${MAKE} --no-print-directory $$i; \
	done

${OUT_DIR}%.o: %.cpp Makefile
	@${MKDIR} ${OUT_DIR}
	@${MKDIR} ${@D}
	@${CC} ${CFLAGS} ${INCLUDE} $< -c -o $@

clean:
	@${RM} ${OBJS}
	@${RM} ${OUT_DIR}

fclean:	clean
	@${RM} ${NAME}

re: fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re bonus