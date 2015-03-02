
PREFIX?=	/usr/local
CFLAGS?=	
CC?=		cc
CXX?=		c++
PKGNAME=	goattracker2

SRCDIR=		src
OBJDIR=		src
BINDIR=		bin
INCS=		-I${SRCDIR}/bme -I${SRCDIR}/asm -I${SRCDIR}
LIBINC=		`sdl-config --cflags`
LIBS=		`sdl-config --libs`
CFLAGS=		-O3 -Wall ${INCS}
CXXFLAGS=	${CFLAGS}

EXE=		${BINDIR}/goattrk2 \
		${BINDIR}/gt2reloc \
		${BINDIR}/ins2snd2 \
		${BINDIR}/sngspli2 \
		${BINDIR}/betaconv \
		${BINDIR}/mod2sng


all: dirs bme ${EXE}

dirs:
	mkdir -p ${BINDIR} ${OBJDIR} ${DESTDIR}

CSRC=$(wildcard ${SRCDIR}/*.c) $(wildcard ${SRCDIR}/*/*.c)
CXXSRC=$(wildcard ${SRCDIR}/*.cpp) $(wildcard ${SRCDIR}/*/*.cpp)

COBJ=${CSRC:${SRCDIR}/%.c=${OBJDIR}/%.o}
CXXOGJ=${CXXSRC:${SRCDIR}/%.cpp=${OBJDIR}/%.o}

${COBJ}: ${OBJDIR}/%.o : ${SRCDIR}/%.c
	${CC} -o $@ ${INCS} ${LIBINC} -c ${CFLAGS} ${DEFINES} $<

${CXXOBJ}: ${OBJDIR}/%.o : ${SRCDIR}/%.cpp
	${CXX} -o $@ -c $< ${LIBS}

bme: ${SRCDIR}/bme/datafile ${SRCDIR}/bme/dat2inc

${SRCDIR}/bme/datafile: ${SRCDIR}/bme/datafile.c ${SRCDIR}/bme/bme_end.c
	${CC} ${CFLAGS} ${LIBINC} -o $@ \
		${SRCDIR}/bme/datafile.c ${SRCDIR}/bme/bme_end.c

${SRCDIR}/bme/dat2inc: ${SRCDIR}/bme/dat2inc.c
	${CC} ${CFLAGS} ${LIBINC} -o $@ $<

${SRCDIR}/goattrk2.dat: ${SRCDIR}/player.s ${SRCDIR}/altplayer.s \
	  ${SRCDIR}/chargen.bin ${SRCDIR}/palette.bin ${SRCDIR}/cursor.bin \
          ${SRCDIR}/goattrk2.bmp ${SRCDIR}/goattrk2.seq
	 # this is a little nasty, but its possibly the only way to do this.
	 echo goattrk2.dat hack
	 echo `cd src; bme/datafile goattrk2.dat goattrk2.seq`


${SRCDIR}/goatdata.c: ${SRCDIR}/goattrk2.dat
	${SRCDIR}/bme/dat2inc $< $@

${BINDIR}/goattrk2: ${OBJDIR}/goatdata.o ${OBJDIR}/goattrk2.o ${OBJDIR}/gsong.o \
	 ${OBJDIR}/gorder.o ${OBJDIR}/gpattern.o ${OBJDIR}/ginstr.o \
	 ${OBJDIR}/gtable.o ${OBJDIR}/gplay.o ${OBJDIR}/gdisplay.o ${OBJDIR}/gfile.o \
	 ${OBJDIR}/greloc.o ${OBJDIR}/ghelp.o ${OBJDIR}/gsound.o ${OBJDIR}/gconsole.o \
	 ${OBJDIR}/gsid.o ${OBJDIR}/resid/envelope.o ${OBJDIR}/resid/extfilt.o \
	 ${OBJDIR}/resid/filter.o ${OBJDIR}/resid/pot.o ${OBJDIR}/resid/sid.o \
	 ${OBJDIR}/resid/wave.o ${OBJDIR}/resid/wave6581__ST.o ${OBJDIR}/resid/wave6581_P_T.o \
	 ${OBJDIR}/resid/wave6581_PS_.o ${OBJDIR}/resid/wave6581_PST.o ${OBJDIR}/resid/wave8580__ST.o \
	 ${OBJDIR}/resid/wave8580_P_T.o ${OBJDIR}/resid/wave8580_PS_.o ${OBJDIR}/resid/wave8580_PST.o \
	 ${OBJDIR}/resid/voice.o ${OBJDIR}/resid-fp/envelopefp.o ${OBJDIR}/resid-fp/extfiltfp.o \
	 ${OBJDIR}/resid-fp/filterfp.o ${OBJDIR}/resid-fp/potfp.o ${OBJDIR}/resid-fp/sidfp.o \
	 ${OBJDIR}/resid-fp/wavefp.o ${OBJDIR}/resid-fp/voicefp.o ${OBJDIR}/asm/asmtab.o \
	 ${OBJDIR}/asm/chnkpool.o ${OBJDIR}/asm/expr.o ${OBJDIR}/asm/lexyy.o ${OBJDIR}/asm/log.o \
	 ${OBJDIR}/asm/membuf.o ${OBJDIR}/asm/membufio.o ${OBJDIR}/asm/namedbuf.o ${OBJDIR}/asm/parse.o \
	 ${OBJDIR}/asm/pc.o ${OBJDIR}/asm/vec.o ${OBJDIR}/bme/bme_gfx.o ${OBJDIR}/bme/bme_snd.o \
	 ${OBJDIR}/bme/bme_win.o ${OBJDIR}/bme/bme_mou.o ${OBJDIR}/bme/bme_kbd.o ${OBJDIR}/bme/bme_io.o ${OBJDIR}/bme/bme_end.o ${OBJDIR}/bme/bme.o
	${CXX} -o $@ $^ ${LIBS}	


${OBJDIR}/greloc2.o: ${SRCDIR}/greloc.c
	${CC} ${CFLAGS} ${LIBINC} -DGT2RELOC -c -o $@ $^

${BINDIR}/gt2reloc: ${OBJDIR}/goatdata.o ${OBJDIR}/gt2reloc.o ${OBJDIR}/gsong.o \
	 ${OBJDIR}/gorder.o ${OBJDIR}/gpattern.o ${OBJDIR}/ginstr.o \
	 ${OBJDIR}/gtable.o ${OBJDIR}/gplay.o ${OBJDIR}/gdisplay.o ${OBJDIR}/gfile.o \
	 ${OBJDIR}/greloc2.o ${OBJDIR}/ghelp.o ${OBJDIR}/gsound.o ${OBJDIR}/gconsole.o \
	 ${OBJDIR}/gsid.o ${OBJDIR}/resid/envelope.o ${OBJDIR}/resid/extfilt.o \
	 ${OBJDIR}/resid/filter.o ${OBJDIR}/resid/pot.o ${OBJDIR}/resid/sid.o \
	 ${OBJDIR}/resid/wave.o ${OBJDIR}/resid/wave6581__ST.o ${OBJDIR}/resid/wave6581_P_T.o \
	 ${OBJDIR}/resid/wave6581_PS_.o ${OBJDIR}/resid/wave6581_PST.o ${OBJDIR}/resid/wave8580__ST.o \
	 ${OBJDIR}/resid/wave8580_P_T.o ${OBJDIR}/resid/wave8580_PS_.o ${OBJDIR}/resid/wave8580_PST.o \
	 ${OBJDIR}/resid/voice.o ${OBJDIR}/resid-fp/envelopefp.o ${OBJDIR}/resid-fp/extfiltfp.o \
	 ${OBJDIR}/resid-fp/filterfp.o ${OBJDIR}/resid-fp/potfp.o ${OBJDIR}/resid-fp/sidfp.o \
	 ${OBJDIR}/resid-fp/wavefp.o ${OBJDIR}/resid-fp/voicefp.o ${OBJDIR}/asm/asmtab.o \
	 ${OBJDIR}/asm/chnkpool.o ${OBJDIR}/asm/expr.o ${OBJDIR}/asm/lexyy.o ${OBJDIR}/asm/log.o \
	 ${OBJDIR}/asm/membuf.o ${OBJDIR}/asm/membufio.o ${OBJDIR}/asm/namedbuf.o ${OBJDIR}/asm/parse.o \
	 ${OBJDIR}/asm/pc.o ${OBJDIR}/asm/vec.o ${OBJDIR}/bme/bme_gfx.o ${OBJDIR}/bme/bme_snd.o \
	 ${OBJDIR}/bme/bme_win.o ${OBJDIR}/bme/bme_mou.o ${OBJDIR}/bme/bme_kbd.o ${OBJDIR}/bme/bme_io.o ${OBJDIR}/bme/bme_end.o ${OBJDIR}/bme/bme.o
	${CXX} -DGT2RELOC -o $@ $^ ${LIBS}

${BINDIR}/mod2sng: ${OBJDIR}/mod2sng.o ${OBJDIR}/bme/bme_end.o
	${CC} -o $@ $^

${BINDIR}/ins2snd2: ${OBJDIR}/ins2snd2.o ${OBJDIR}/bme/bme_end.o
	${CC} -o $@ $^

${BINDIR}/sngspli2: ${OBJDIR}/sngspli2.o ${OBJDIR}/bme/bme_end.o
	${CC} -o $@ $^

${BINDIR}/betaconv: ${OBJDIR}/betaconv.o ${OBJDIR}/bme/bme_end.o
	${CC} -o $@ $^

install: all
	@echo Install binaries
	install -d ${DESTDIR}${PREFIX}/bin
	install -s -m 755 ${BINDIR}/* ${DESTDIR}${PREFIX}/bin
	@echo Install documentation and examples
	install -d ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/examples
	install -m 755 readme.txt goat_tracker_commands.pdf \
	    ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/
	cp -r examples/ ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/examples
	chmod -R 755 ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}
	
clean:
	${RM} ${OBJDIR}/*.o
	${RM} ${OBJDIR}/asm/*.o
	${RM} ${OBJDIR}/bme/*.o
	${RM} ${SRCDIR}/goattrk2.dat ${SRCDIR}/goatdata.c
	${RM} ${OBJDIR}/resid/*.o
	${RM} ${OBJDIR}/resid-fp/*.o
	${RM} ${EXE}
