## -- manpages --
install: install-man
install-man: ./doc/memsearch.3.md ./doc/random_fill.3.md ./doc/str2num.3.md ./doc/strarray.3.md 
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man3
	cp ./doc/memsearch.3 ./doc/random_fill.3 ./doc/str2num.3 ./doc/strarray.3  $(DESTDIR)$(PREFIX)/share/man/man3
## -- manpages --
## -- license --
install: install-license
install-license: LICENSE
	mkdir -p $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
	cp LICENSE $(DESTDIR)$(PREFIX)/share/doc/c-string-extra
## -- license --
