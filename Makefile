PREFIX=/usr/local

.PHONY: all clean install

all:
	mkdir -p build && cd build && qmake ../discord-player.pro -spec linux-g++
	make -C build

clean:
	rm -rf build

install:
	mkdir -p ${PREFIX}/bin
	cp build/discord-player ${PREFIX}/bin
