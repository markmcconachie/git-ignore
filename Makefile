PREFIX=/usr/local
CFLAGS=-g -Wall -I libgit2/include
LDFLAGS=-L/usr/local/Cellar/libgit2/0.19.0/lib -lgit2

all: git-ignore

git-ignore: ignore-file.o

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install git-ignore $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm git-ignore
	rm -f *.o
	rm -rf *.dSYM