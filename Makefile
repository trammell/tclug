
  APACHECTL := /usr/sbin/apache2ctl
        PWD := $(shell pwd)
       CONF := $(PWD)/conf/httpd.conf

clean:
	rm -f logs/*_log

start:
	$(APACHECTL) -d $(PWD) -f $(CONF) -k start

stop:
	$(APACHECTL) -d $(PWD) -f $(CONF) -k stop

restart graceful:
	$(APACHECTL) -d $(PWD) -f $(CONF) -k graceful

test:
	ack --literal '<?' htdocs/
	ack --literal 'FIXME' htdocs/

