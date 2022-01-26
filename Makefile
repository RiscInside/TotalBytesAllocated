CHARDFLAGS := -Wl,-init,init -fPIC -shared -Wl,-init,init

CFLAGS = -Wall -Werror -Wextra -O2

test: total_bytes_allocated.so
	LD_PRELOAD=./total_bytes_allocated.so seq 1 5

total_bytes_allocated.so: total_bytes_allocated.c
	gcc $(CFLAGS) $(CHARDFLAGS) total_bytes_allocated.c -o total_bytes_allocated.so

clean:
	rm -f total_bytes_allocated.so