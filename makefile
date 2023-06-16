clean:
	rm -rf ./qmk

install:
	git clone \
		--depth 1 \
		--recurse-submodules \
		--shallow-submodules \
		--jobs 8 \
		--no-tags \
		https://github.com/qmk/qmk_firmware.git \
		./qmk
	./qmk/util/qmk_install.sh

setup:
	cp -rf ./nobe4 ./qmk/keyboards/planck/keymaps
	cd qmk && make clean

rev5: setup
	cd qmk && make planck/rev5:nobe4:flash

rev6: setup
	cd qmk && make planck/rev6:nobe4:flash
