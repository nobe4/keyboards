clean:
	rm -rf ./qmk

install:
	git clone \
		--depth 1 --no-tags \
		--recurse-submodules --shallow-submodules \
		--jobs 8 \
		https://github.com/qmk/qmk_firmware.git \
		./qmk
	./qmk/util/qmk_install.sh

setup:
	cp -rf ./nobe4 ./qmk/keyboards/planck/keymaps
	make -C qmk clean

# Automatically setup rev5 and rev6 as targets and inject the name into the make
# command
VERSIONS = rev5 rev6
$(VERSIONS): setup
	make -C qmk planck/$@:nobe4:flash
