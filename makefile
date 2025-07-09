clean:
	rm -rf ./qmk

install:
	devenv shell qmk config user.qmk_home=$(shell pwd)/qmk
	devenv shell qmk setup -y

	ln -s $(shell pwd)/planck ./qmk/keyboards/planck/keymaps/nobe4
	ln -s $(shell pwd)/ferris ./qmk/keyboards/ferris/keymaps/nobe4

# Automatically setup rev5 and rev6 as targets and inject the name into the make
# command
VERSIONS = rev5 rev6
$(VERSIONS):
	devenv shell qmk flash -kb planck/$@ -km nobe4

.PHONY: ferris
ferris:
	devenv shell CONVERT_TO=rp2040_ce qmk flash -kb ferris/sweep -km nobe4
