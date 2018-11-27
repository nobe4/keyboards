default: run

# Install all the macos dependencies
install:
	brew tap osx-cross/avr PX4/homebrew-px4
	brew update
	brew install avr-gcc dfu-programmer gcc-arm-none-eabi avrdude

clean:
	rm -rf ./qmk

setup:
	git clone \
		--quiet \
		--depth=1 \
		--recurse-submodule \
		--shallow-submodules \
		https://github.com/qmk/qmk_firmware.git \
		./qmk

run:
	# Update the sources
	cp -rf ./nobe4 ./qmk/keyboards/planck/keymaps
	cd qmk; \
		make clean; \
		make planck/rev5:nobe4:dfu
