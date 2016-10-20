CC       = g++
CSTD     = -std=c++11 -O2 -g
WARNINGS = -Wall -Wextra -Wformat=2 -pedantic \
           -Wfloat-equal -Wundef -Wcast-align \
           -Wmissing-declarations \
           -Wwrite-strings \
           -Wdouble-promotion
ERRORS   = -Werror -pedantic-errors -Wno-error=unused-result \
           -Wno-error=cast-align
CFLAGS   = $(CSTD) $(WARNINGS) $(ERRORS)

TARGET   = enigma

all : $(TARGET)

$(TARGET) : $(wildcard *.cpp)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) *.o

.PHONY: clean
