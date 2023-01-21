DESTDIR =
PREFIX  =/usr/local
HEADERS =$(shell find str -iname *.h)

all:
	@true
install: $(HEADERS)
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/str
clean:
	@true

## -- manpages --
install: install-man3
install-man3:
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/strarray.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/str2num.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/random_fill.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/memsearch.3 $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
## -- license --
