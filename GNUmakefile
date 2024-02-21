PROJECT =c-string-extra
VERSION =1.0.0
DESTDIR =
PREFIX  =/usr/local
HEADERS =$(shell find str -iname *.h)

all:
clean:
install: $(HEADERS)
	@mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/str

## -- BLOCK:license --
install: install-license
install-license: 
	@mkdir -p $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
	cp LICENSE  $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
## -- BLOCK:license --
## -- BLOCK:man --
install: install-man
install-man:
	@mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/strarray.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/str2num.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/random_fill.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/memsearch.3 $(DESTDIR)$(PREFIX)/share/man/man3
## -- BLOCK:man --
