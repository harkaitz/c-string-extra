DESTDIR =
PREFIX  =/usr/local
HEADERS =$(shell find str -iname *.h)

all:
install: $(HEADERS)
	mkdir -p $(DESTDIR)$(PREFIX)/include/str
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/str
clean:

## -- manpages --
install: install-man3
install-man3:
	@echo 'I share/man/man3/'
	@mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	@echo 'I share/man/man3/memsearch.3'
	@cp ./doc/memsearch.3 $(DESTDIR)$(PREFIX)/share/man/man3
	@echo 'I share/man/man3/random_fill.3'
	@cp ./doc/random_fill.3 $(DESTDIR)$(PREFIX)/share/man/man3
	@echo 'I share/man/man3/str2num.3'
	@cp ./doc/str2num.3 $(DESTDIR)$(PREFIX)/share/man/man3
	@echo 'I share/man/man3/strarray.3'
	@cp ./doc/strarray.3 $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
ifneq ($(PREFIX),)
install: install-license
install-license: LICENSE
	@echo 'I share/doc/c-string-extra/LICENSE'
	@mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
	@cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
endif
## -- license --
