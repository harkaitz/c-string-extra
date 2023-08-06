PROJECT =c-string-extra
VERSION =1.0.0
DESTDIR =
PREFIX  =/usr/local
HEADERS =$(shell find str -iname *.h)

all:
clean:
install: $(HEADERS)
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/str

## -- BLOCK:license --
install: install-license
install-license: 
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
	cp LICENSE README.md $(DESTDIR)$(PREFIX)/share/doc/$(PROJECT)
update: update-license
update-license:
	ssnip README.md
## -- BLOCK:license --
## -- BLOCK:man --
update: update-man
update-man:
	make-h-man update
install: install-man
install-man:
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/strarray.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/str2num.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/random_fill.3 $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/memsearch.3 $(DESTDIR)$(PREFIX)/share/man/man3
## -- BLOCK:man --
