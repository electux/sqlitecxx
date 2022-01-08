# @info   gen_cc_pro ver.2.0
# @author Vladimir Roncevic <elektron.ronca@gmail.com>
# @brief  Process this file with automake to produce Makefile.in.

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS = \
	-std=c++2a
	-Wall \
	-g

bin_PROGRAMS = sqlitecxx

sqlitecxx_SOURCES = \
	main.cc \
	sqlitecxx.cc

sqlitecxx_LDFLAGS = -lsqlite3

sqlitecxx_LDADD = 

