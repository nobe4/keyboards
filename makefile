clean:
	rm -rf ./qmk

install:
	pip install --user qmk

	qmk config user.qmk_home=$(shell pwd)/qmk
	qmk setup -y

	ln -s $(shell pwd)/planck ./qmk/keyboards/planck/keymaps/nobe4
	ln -s $(shell pwd)/ferris ./qmk/keyboards/ferris/keymaps/nobe4

# Automatically setup rev5 and rev6 as targets and inject the name into the make
# command
VERSIONS = rev5 rev6
$(VERSIONS):
	qmk flash -kb planck/$@ -km nobe4

.PHONY: ferris
ferris:
	CONVERT_TO=rp2040_ce qmk flash -kb ferris/sweep -km nobe4
