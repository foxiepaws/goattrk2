/*
 * GOATTRACKER reSID interface
 */

#define GSID_C

#include <stdlib.h>
#include "resid/sid.h"
#include "resid-fp/sid.h"

extern "C" {

#include "gsid.h"
#include "gsound.h"

int clockrate;
int samplerate;
unsigned char sidreg[NUMSIDREGS];
unsigned char sidorder[] =
  {0x15,0x16,0x18,0x17,
   0x02,0x03,0x06,0x05,0x00,0x01,0x04,
   0x09,0x0a,0x0d,0x0c,0x07,0x08,0x0b,
   0x10,0x11,0x14,0x13,0x0e,0x0f,0x12};

unsigned char altsidorder[] =
  {0x15,0x16,0x18,0x17,
   0x04,0x00,0x01,0x02,0x03,0x05,0x06,
   0x0b,0x07,0x08,0x09,0x0a,0x0c,0x0d,
   0x12,0x0e,0x0f,0x10,0x11,0x13,0x14};

SID *sid = 0;
SIDFP *sidfp = 0;

extern unsigned residdelay;
extern unsigned adparam;

void sid_init(int speed, unsigned m, unsigned ntsc, unsigned interpolate, unsigned customclockrate, unsigned usefp)
{
  int c;

  if (ntsc) clockrate = NTSCCLOCKRATE;
    else clockrate = PALCLOCKRATE;

  if (customclockrate)
    clockrate = customclockrate;

  samplerate = speed;

  if (!usefp)
  {
    if (sidfp)
    {
      delete sidfp;
      sidfp = NULL;
    }

    if (!sid) sid = new SID;
  }
  else
  {
    if (sid)
    {
      delete sid;
      sid = NULL;
    }
    
    if (!sidfp) sidfp = new SIDFP;
  }

  switch(interpolate)
  {
    case 0:
    if (sid) sid->set_sampling_parameters(clockrate, SAMPLE_FAST, speed, 20000);
    if (sidfp) sidfp->set_sampling_parameters(clockrate, SAMPLE_FAST, speed, 20000);
    break;

    default:
    if (sid) sid->set_sampling_parameters(clockrate, SAMPLE_INTERPOLATE, speed, 20000);
    if (sidfp) sidfp->set_sampling_parameters(clockrate, SAMPLE_INTERPOLATE, speed, 20000);
    break;
  }

  if (sid) sid->reset();
  if (sidfp) sidfp->reset();
  for (c = 0; c < NUMSIDREGS; c++)
  {
    sidreg[c] = 0x00;
  }
  if (m == 1)
  {
    if (sid) sid->set_chip_model(MOS8580);
    if (sidfp) sidfp->set_chip_model(MOS8580FP);
  }
  else
  {
    if (sid) sid->set_chip_model(MOS6581);
    if (sidfp) sidfp->set_chip_model(MOS6581FP);
  }
}

unsigned char sid_getorder(unsigned char index)
{
  if (adparam >= 0xf000)
    return altsidorder[index];
  else
    return sidorder[index];
}

int sid_fillbuffer(short *ptr, int samples)
{
  int tdelta;
  int tdelta2;
  int result = 0;
  int total = 0;
  int c;

  int badline = rand() % NUMSIDREGS;

  tdelta = clockrate * samples / samplerate + 4;

  for (c = 0; c < NUMSIDREGS; c++)
  {
    unsigned char o = sid_getorder(c);

  	// Extra delay for loading the waveform (and mt_chngate,x)
  	if ((o == 4) || (o == 11) || (o == 18))
  	{
  	  tdelta2 = SIDWAVEDELAY;
      if (sid) result = sid->clock(tdelta2, ptr, samples);
      if (sidfp) result = sidfp->clock(tdelta2, ptr, samples);
      total += result;
      ptr += result;
      samples -= result;
      tdelta -= SIDWAVEDELAY;
    }

    // Possible random badline delay once per writing
    if ((badline == c) && (residdelay))
  	{
      tdelta2 = residdelay;
      if (sid) result = sid->clock(tdelta2, ptr, samples);
      if (sidfp) result = sidfp->clock(tdelta2, ptr, samples);
      total += result;
      ptr += result;
      samples -= result;
      tdelta -= residdelay;
    }

    if (sid) sid->write(o, sidreg[o]);
    if (sidfp) sidfp->write(o, sidreg[o]);

    tdelta2 = SIDWRITEDELAY;
    if (sid) result = sid->clock(tdelta2, ptr, samples);
    if (sidfp) result = sidfp->clock(tdelta2, ptr, samples);
    total += result;
    ptr += result;
    samples -= result;
    tdelta -= SIDWRITEDELAY;
  }
  if (sid) result = sid->clock(tdelta, ptr, samples);
  if (sidfp) result = sidfp->clock(tdelta, ptr, samples);
  total += result;

  return total;
}

}
