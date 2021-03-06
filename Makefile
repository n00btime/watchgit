CFLAGS := -Wall -Wextra -ansi -pedantic -D_XOPEN_SOURCE=500 -Os
LDFLAGS := -Wl,-O1
LIBS = -lsqlite3

OBJECTS = db.o gitfuncs.o main.o
BINARY = watchgit

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@

install: $(BINARY)
	mkdir -p $(DESTDIR)/usr/bin
	cp $(BINARY) $(DESTDIR)/usr/bin
	chmod 555 $(DESTDIR)/usr/bin/watchgit

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(BINARY)

