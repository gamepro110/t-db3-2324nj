.PHONY: all clean

all: uploadAndMonitor

uploadAndMonitor:
	@~/.platformio/penv/bin/platformio run --target upload --target monitor --environment uno

upload:
	@~/.platformio/penv/bin/platformio run --target upload

clean:
	@~/.platformio/penv/bin/platformio run --target clean
