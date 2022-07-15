DESTDIR =
PREFIX  =/usr/local
HEADERS =$(shell find str -iname *.h)

all:
install: $(HEADERS)
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/str

## -- manpages --
MAN_3=./doc/memsearch.3 ./doc/random_fill.3 ./doc/str2num.3 ./doc/strarray.3 
install: install-man3
install-man3: $(MAN_3)
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp $(MAN_3) $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
## -- license --
