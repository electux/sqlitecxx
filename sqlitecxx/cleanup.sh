#!/bin/bash

make mostlyclean
make clean
make distclean

rm -rf `pwd`/autom4te.cache
rm -rf `pwd`/src/.deps/
rm -f `pwd`/po/Makefile.in.in
rm -f `pwd`/*.m4
rm -f `pwd`/compile
rm -f `pwd`/config.guess
rm -f `pwd`/config.h.in
rm -f `pwd`/config.sub
rm -f `pwd`/depcomp
rm -f `pwd`/INSTALL
rm -f `pwd`/install-sh
rm -f `pwd`/intltool-extract.in
rm -f `pwd`/intltool-merge.in
rm -f `pwd`/intltool-update.in
rm -f `pwd`/ltmain.sh
rm -f `pwd`/Makefile.in
rm -f `pwd`/missing
rm -f `pwd`/src/Makefile.in

