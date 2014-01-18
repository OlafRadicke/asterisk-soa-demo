PROGNAME=tntsoafrontend

CC = g++
LD = g++
ECPPC=/usr/local/bin/ecppc
CFLAGS+=-I./ -I/usr/local/include -O2
LDFLAGS+=-L/usr/local/lib -ltntnet -lcxxtools

OBJECTS=\
main.o \
Core/controller/StatusController.o \
Core/model/Config.o 

CPP_SOURCES=\
main.cpp \
Core/controller/StatusController.cpp \
Core/model/Config.cpp 


### TNTNET THINGS ###

ECPP_OBJECTS=\
Core/view/StatusView.o

ECPP_CPP_SOURCES=\
Core/view/StatusView.cpp

ECPP_BASES=\
Core/view/StatusView.ecpp

ECPP_STATIC_SOURCES=\
Core/resource/favicon.ico \
Core/resource/style.css

ECPP_STATIC_CPP_SOURCES=Core/resource/static.cpp

ECPP_STATIC_CPP_OBJECTS=Core/resource/static.o

### END  TNTNET THINGS ###

ALL_OBJECTS=$(OBJECTS) $(ECPP_OBJECTS) $(ECPP_STATIC_CPP_OBJECTS)
ALL_SOURCES=$(CPP_SOURCES) $(ECPP_CPP_SOURCES) $(ECPP_STATIC_CPP_SOURCES)

all: $(PROGNAME)

$(PROGNAME): $(ALL_OBJECTS)
	$(LD) -o $(PROGNAME) $(ALL_OBJECTS)

$(OBJECTS):  $(ALL_SOURCES) 
	$(CC) -c $(CFLAGS) $< -o $@

$(ECPP_OBJECTS):  $(ECPP_CPP_SOURCES)
	$(CC) -c $(CFLAGS) $< -o $@


$(ECPP_CPP_SOURCES):  $(ECPP_BASES)
	${ECPPC} ${ECPPFLAGS} ${ECPPFLAGS_CPP} -o $@ $<


$(ECPP_STATIC_CPP_SOURCES):
	ecppc -bb -n $(ECPP_STATIC_CPP_SOURCES) -p $(ECPP_STATIC_SOURCES)

distclean:
	$(RM) $(ECPP_CPP_SOURCES) $(ECPP_OBJECTS) $(PROGNAME) $(OBJECTS)
