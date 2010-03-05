
  HTTPD := /usr/sbin/httpd2
    PWD := $(shell pwd)
    PID := $(shell cat logs/httpd.pid)

start:
	$(HTTPD) -d $(PWD) -f conf/httpd.conf -e info

stop:
	kill $(PID)


