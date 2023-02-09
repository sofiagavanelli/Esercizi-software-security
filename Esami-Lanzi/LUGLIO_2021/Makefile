OV = GIUGNO_2020/rop-esame GIUGNO_2022/vuln LUGLIO_2021/
PROGRAMS = $(OV)
CFLAGS += -no-pie -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -zexecstack

# Convenience to auto-call mcheck before the first malloc()
#CFLAGS += -lmcheck

all: $(PROGRAMS)
clean:
	rm -f $(PROGRAMS)

