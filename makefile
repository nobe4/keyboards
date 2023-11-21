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

	ln -s $(pwd)/planck ./qmk/keyboards/planck/keymaps/nobe4
	ln -s $(pwd)/ferris ./qmk/keyboards/ferris/keymaps/nobe4

# Automatically setup rev5 and rev6 as targets and inject the name into the make
# command
VERSIONS = rev5 rev6
$(VERSIONS):
	make -C qmk clean
	make -C qmk planck/$@:nobe4:flash

.PHONY: ferris
ferris:
	CONVERT_TO=rp2040_ce qmk flash -kb ferris/sweep -km nobe4
