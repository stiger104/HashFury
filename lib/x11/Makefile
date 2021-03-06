# -*- mode: Makefile; -*-
# Distributed under the MIT/X11 software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

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

obj/%.o: %.c
	$(CC) -c $(CFLAGS) -fpermissive -MMD -MF $(@:%.o=%.d) -o $@ $<
	@cp $(@:%.o=%.d) $(@:%.o=%.P); \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	      -e '/^$$/ d' -e 's/$$/ :/' < $(@:%.o=%.d) >> $(@:%.o=%.P); \
	  rm -f $(@:%.o=%.d)

# this is for static lib generate
X_HASH_LIB = libxhash.a
$(X_HASH_LIB): $(OBJS)
	ar rv ${X_HASH_LIB} $?

clean:
	-rm -f obj/*.o
	-rm -f obj-test/*.o
	-rm -f obj/*.P
	-rm -f obj-test/*.P
	-rm -f obj/build.h
	-rm -f main.o
	-rm -f *.out *.a

FORCE: