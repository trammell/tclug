
  HTTPD := /usr/sbin/httpd2
    PWD := $(shell pwd)

start:
	$(HTTPD) -d $(PWD) -f conf/httpd.conf -e info


