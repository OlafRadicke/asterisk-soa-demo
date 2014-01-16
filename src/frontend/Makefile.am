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
	models/Workplace.h \

ecppSources = \
	Core/views/StatusView.ecpp

staticSources = \
	Core/resources/favicon.ico \
	Core/resources/style.css

peruschim_cpp_SOURCES = \
	mein.cpp \
	Core/controller/AsteriskStatus.cpp \
	Core/controller/AlterLogInController.cpp \
	Core/controller/EditAccountController.cpp \
	Core/controller/EditEditionsController.cpp \
	Core/controller/EditOwnVersesController.cpp \
	Core/controller/EditQuoteController.cpp \
	Core/controller/ExportOwnVersesController.cpp \
	Core/controller/ImportOwnVersesController.cpp \
	Core/controller/KeywordDetailController.cpp \
	Core/controller/KeywordRegisterController.cpp \
	Core/controller/NewAccountController.cpp \
	Core/controller/NewQuoteController.cpp \
	Core/controller/ResetOwnPasswordController.cpp \
	Core/controller/SwitchToHandheldVersionController.cpp \
	Core/controller/TrustAUserController.cpp \
	Core/manager/BibleManager.cpp \
	Core/manager/EditionManager.cpp \
	Core/manager/KeywordRegister.cpp \
	Core/manager/QuoteManager.cpp \
	Core/manager/QuoteRegister.cpp \
	Core/manager/RSSfeedManager.cpp \
	Core/manager/TableManager.cpp \
	Core/manager/WebACL.cpp \
	Core/models/AccountData.cpp \
	Core/models/Config.cpp \
	Core/models/DatabaseProxy.cpp \
	Core/models/KeywordData.cpp \
	Core/models/OString.cpp \
	Core/models/Quote.cpp \
	Core/models/UserSession.cpp \
	RouteReverse/manager/Manager.cpp \
	SessionForm/controller/Controller.cpp \
	SessionForm/manager/Manager.cpp \
	$(ecppSources)

nodist_peruschim_cpp_SOURCES = \
	resources.cpp

peruschim_cpp_LDFLAGS = -lcxxtools -ltntnet -ltntdb

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
