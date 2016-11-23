ATmega8:
ATmega32:
ATmega2560:

ATmega%:
	mkdir -p build/$@
	cd build/$@ && \
	cmake ../../ \
	-DCMAKE_TOOLCHAIN_FILE=toolchains/AVR/$@.cmake
	$(MAKE) -C build/$@ install

clean:
	rm -rf -- build/

mrproper:
	rm -rf -- build/ deliv/
