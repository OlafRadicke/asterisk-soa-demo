AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = tntsoafrontend
AM_CPPFLAGS = -I$(srcdir)

EXTRA_DIST = \
	controller/StatusController.cpp \
	resources/favicon.ico \
	resources/style.css \
	views/parts/status.ecpp

noinst_HEADERS = \
	controller/StatusController.h \
	manager/StatusManager.h \
	models/Workplace.h 

ecppSources = \
	Core/views/StatusView.ecpp

staticSources = \
	Core/resources/favicon.ico \
	Core/resources/style.css

tntsoafrontend_SOURCES = \
	mein.cpp \
	Core/controller/AsteriskStatus.cpp \
	Core/manager/BibleManager.cpp \
	Core/models/AccountData.cpp \
	Core/models/Config.cpp \
	$(ecppSources)

nodist_tntsoafrontend_SOURCES = \
	resources.cpp

tntsoafrontend_LDFLAGS = -lcxxtools -ltntnet -ltntdb

CLEANFILES = $(ecppSources:.ecpp=.cpp) $(ecppSources:.ecpp=.deps) resources.cpp

#
# Rules for tntnet applications
#
resources.cpp: $(staticSources) Makefile.am
	$(ECPPC) -bb -z -n resources -p -o resources.cpp -I $(srcdir) $(staticSources)

SUFFIXES=.ecpp .ico .cpp

.ecpp.cpp:
	$(ECPPC) -I $(top_srcdir)/src -o $@ $<
.ecpp.deps:
	$(ECPPC) -M -n $* -I $(srcdir) -I $(srcdir)/include $< | $(SED) '1s/\(.*\).cpp:/\1.cpp \1.deps:/' > $@
.ico.cpp:
	$(ECPPC) -b -m image/x-icon -o $@ $<

-include $(ecppSources:.ecpp=.deps)
