default: run

clean:
	rm -rf ./qmk

setup:
	git clone --recurse-submodules -j8 https://github.com/qmk/qmk_firmware.git ./qmk
	./qmk/util/qmk_install.sh

rev5:
	# Update the sources
	cp -rf ./nobe4 ./qmk/keyboards/planck/keymaps
	cd qmk; \
		make clean; \
		make planck/rev5:nobe4:dfu

rev6:
	cp -rf ./nobe4 ./qmk/keyboards/planck/keymaps
	cd qmk; \
		make clean; \
		make planck/rev6:nobe4:dfu-util
