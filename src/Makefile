# -*- mode: Makefile; -*-
# Copyright (c) 2011 Bitcoin Developers
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

# Mac OS X makefile for bitcoin
# Originally by Laszlo Hanyecz (solar@heliacal.net)

CXX=llvm-g++
CC=llvm-gcc
DEPSDIR=/usr/local


INCLUDEPATHS= \
 -I"$(CURDIR)" \
 -I"$(CURDIR)/obj" \
 -I"$(DEPSDIR)/include" \

LIBPATHS= \
 -L"$(DEPSDIR)/lib" \

LIBS= -dead_strip


DEFS=-DMAC_OSX -DMSG_NOSIGNAL=0 -DBOOST_SPIRIT_THREADSAFE


# osx 10.9 has changed the stdlib default to libc++. To prevent some link error, you may need to use libstdc++
# CFLAGS += -stdlib=libstdc++

# ppc doesn't work because we don't support big-endian
CFLAGS += -Wall -Wextra -Wformat -Wformat-security -Wno-unused-parameter \
    $(DEBUGFLAGS) $(DEFS) $(INCLUDEPATHS)

OBJS= \
    obj/cubehash.o \
    obj/luffa.o \
    obj/aes_helper.o \
    obj/echo.o \
    obj/shavite.o \
    obj/simd.o \
    obj/blake.o\
    obj/bmw.o\
    obj/groestl.o\
    obj/jh.o\
    obj/keccak.o\
    obj/skein.o \

# auto-generated dependencies:
-include obj/*.P

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) -MMD -MF $(@:%.o=%.d) -o $@ $<
	@cp $(@:%.o=%.d) $(@:%.o=%.P); \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	      -e '/^$$/ d' -e 's/$$/ :/' < $(@:%.o=%.d) >> $(@:%.o=%.P); \
	  rm -f $(@:%.o=%.d)

obj/%.o: %.c
	$(CC) -c $(CFLAGS) -fpermissive -MMD -MF $(@:%.o=%.d) -o $@ $<
	@cp $(@:%.o=%.d) $(@:%.o=%.P); \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	      -e '/^$$/ d' -e 's/$$/ :/' < $(@:%.o=%.d) >> $(@:%.o=%.P); \
	  rm -f $(@:%.o=%.d)

hash: $(OBJS:obj/%=obj/%)
	$(CXX) $(CFLAGS) -o $@ $(LIBPATHS) $^ obj/main.o $(LIBS)

clean:
	-rm -f obj/*.o
	-rm -f obj-test/*.o
	-rm -f obj/*.P
	-rm -f obj-test/*.P
	-rm -f obj/build.h
	-rm -f main.o

FORCE: