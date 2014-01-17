PROGNAME=tntsoafrontend

CC = g++
LD = g++
CFLAGS+=-I./ -I/usr/local/include -O2
LDFLAGS+=-L/usr/local/lib -ltntnet -lcxxtools

OBJECTS=StatusController.o StatusManager.o Workplace.o

SOURCES=\
main.cpp \
Core/controller/StatusController.cpp \
Core/model/Config.cpp


ECPPC=/usr/local/bin/ecppc
ECPPOBJECTS=StatusView.o
ECPPSOURCES=StatusView.cpp
ECPPBASES=Core/view/StatusView.ecpp
STATICSOURCES=\
Core/resource/favicon.ico \
Core/resource/style.css

all: $(PROGNAME)

$(PROGNAME): $(OBJECTS) $(ECPPOBJECTS)
	$(LD) -o $(PROGNAME) $(OBJECTS) $(ECPPOBJECTS)


$(OBJECTS):  $(ECPPSOURCES) $(STATICSOURCES) $(SOURCES)
	$(CC) -c $(CFLAGS) $< -o $@

$(ECPPOBJECTS):  $(ECPPSOURCES)
	$(CC) -c $(CFLAGS) $< -o $@


$(ECPPSOURCES):  $(ECPPBASES)
	${ECPPC} ${ECPPFLAGS} ${ECPPFLAGS_CPP} -o $@ $<


static.cpp:
	ecppc -bb -n static -p $(STATICSOURCES)

distclean:
	$(RM) $(ECPPSOURCES) $(ECPPOBJECTS) $(PROGNAME) $(OBJECTS)
