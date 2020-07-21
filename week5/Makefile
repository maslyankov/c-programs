CC=gcc
AR=ar
INCLUDE=-I.
LIBDIR=-L.
DEBUG=
OPTIONS=$(DEBUG) $(INCLUDE)
COMPILE=$(CC) $(OPTIONS)
LINK=$(CC) $(DEBUG) $(LIBDIR)
SLINK=$(AR) -rv
RANLIB=ranlib

.c.o:
	$(COMPILE) -c $< -o $@

liblist.a: list.o
	$(SLINK) $@ $<
	$(RANLIB) $@

liblist.so: list.o
	$(LINK) -shared -fPIC $< -lpthread -o $@

testlist_static: liblist.a testlist.o
	$(LINK) testlist.o liblist.a -lpthread -o $@

testlist_dynamic: liblist.so testlist.o
	$(LINK) testlist.o -llist -o $@

all: liblist.a liblist.so testlist_static testlist_dynamic

clean:
	rm -f *.o *.s *.a *.so testlist_static testlist_dynamic
