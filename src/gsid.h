#ifndef GSID_H
#define GSID_H

#define NUMSIDREGS 0x19
#define SIDWRITEDELAY 9 // lda $xxxx,x 4 cycles, sta $d400,x 5 cycles
#define SIDWAVEDELAY 4 // and $xxxx,x 4 cycles extra

void sid_init(int speed, unsigned m, unsigned ntsc, unsigned interpolate, unsigned customclockrate, unsigned usefp);
int sid_fillbuffer(short *ptr, int samples);
unsigned char sid_getorder(unsigned char index);

#ifndef GSID_C
extern unsigned char sidreg[NUMSIDREGS];
#endif

#endif
