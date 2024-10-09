SRC := main.c list.c sms.c
TARGET := sms

$(TARGET): $(SRC)
	gcc -o $@ $^

.PHONY: clean
clean:
	rm -rf sms
