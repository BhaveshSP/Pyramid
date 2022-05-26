CC = gcc 
CFLAGS = -c -std=c99 -g 
LDFLAGS = -g 
SRC = ${wildcard src/*.c}
OBJ = ${SRC:.c=.o}
HDR = ${wildcard include/*.h}
EXEC = pyramid

all : ${SRC} ${OBJ} ${EXEC}

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o: %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean :
	rm src/*.o ${EXEC}

