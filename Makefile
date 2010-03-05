
  HTTPD := /usr/sbin/httpd2-prefork
    PWD := $(shell pwd)
    PID := $(shell cat logs/httpd.pid)

clean:
	rm -f logs/error_log logs/access_log

start:
	$(HTTPD) -d $(PWD) -f conf/httpd.conf -e info

stop:
	-kill $(PID)

restart:
	make stop start

