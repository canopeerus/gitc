CFLAGS=-Wall 
LDFLAGS=-lncurses -lmenu -lgit2
PREFIX=$(HOME)/.local
INDIR=$(PREFIX)/bin
OBIN=gitc

all:
	$(CC) $(CFLAGS) src/gitc.c src/main.c $(LDFLAGS) -o $(OBIN)

install:
	install -Dm755 $(OBIN) $(BINDIR)/$(OBIN)
	rm $(OBIN)

clean:
	rm $(OBIN)

uninstall:
	rm -f $(BINDIR)/$(OBIN)


