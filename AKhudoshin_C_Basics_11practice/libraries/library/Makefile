SRCS += files.c
LIBNAME += libmypath.so

all:
	gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
	cp $(LIBNAME) /usr/lib
	cp files.h /usr/include

uninstall:
	rm -f /usr/lib/$(LIBMANE) /usr/include/mymath.h

clean:
	rm -f $(LIBNAME) *.o