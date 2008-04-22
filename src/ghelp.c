//
// GOATTRACKER v2 online help
//

#define GHELP_C

#include "goattrk2.h"

#define HELP_LASTROW 168

void onlinehelp(void)
{
  int hview = -1;

  int c;

  for (;;)
  {
    int gk = hview + 2;
    int pk = hview + 2;
    int ik;
    int sk;
    int pc;
    int ip;
    int tb;

    clearscreen();
    printtext(0, gk++, 15,"GENERAL KEYS");
    printtext(0, gk++, 7, "F1  Play from beginning");
    printtext(0, gk++, 7, "F2  Play from current position");
    printtext(0, gk++, 7, "F3  Play current pattern");
    printtext(0, gk++, 7, "F4  Stop playing");
    printtext(0, gk++, 7, "F5  Go to pattern editor");
    printtext(0, gk++, 7, "F6  Go to orderlist editor");
    printtext(0, gk++, 7, "F7  Go to instrument/table editor");
    printtext(0, gk++, 7, "F8  Go to songname editor");
    printtext(0, gk++, 7, "F9  Pack, relocate & save PRG,SID etc.");
    printtext(0, gk++, 7, "F10 Load song/instrument");
    printtext(0, gk++, 7, "F11 Save song/instrument");
    printtext(0, gk++, 7, "F12 This screen");
    printtext(0, gk++, 7, "SHIFT+F1-F3 Follow play begin/pos/patt.");
    printtext(0, gk++, 7, "SHIFT+F4 Mute current channel");
    printtext(0, gk++, 7, "SHIFT+F5-F6 Change speed multiplier");
    printtext(0, gk++, 7, "SHIFT+F7 Change hardrestart ADSR");
    printtext(0, gk++, 7, "SHIFT+F8 Switch between 6581/8580 SID");
    printtext(0, gk++, 7, "SHIFT+, . Move song startpos & restart");
    printtext(0, gk++, 7, "TAB Cycle between editing modes");
    printtext(0, gk++, 7, "INS Insert row (Press on endmark to");
    printtext(0, gk++, 7, "DEL Delete row change patt. length)");
    printtext(0, gk++, 7, "SHIFT+ESC Clear/optimize all musicdata");
    printtext(0, gk++, 7, "ESC Exit program");

    sk = gk + 1;

    printtext(40,pk++, 15,"PATTERN EDIT MODE");
    printtext(40,pk++, 7, "Enter notes like on piano (PT or DMC)");
    printtext(40,pk++, 7, "0-9 & A-F to enter commands");
    printtext(40,pk++, 7, "SPC Switch between jam/editmode");
    printtext(40,pk++, 7, "BACKSPC Insert rest");
    printtext(40,pk++, 7, "RET Keyoff (/w SHIFT = Keyon)");
    printtext(40,pk++, 7, "- + Select instrument");
    printtext(40,pk++, 7, "/ * Select octave");
    printtext(40,pk++, 7, "< > Select pattern");
    printtext(40,pk++, 7, "BACKQUOTE Select channel");
    printtext(40,pk++, 7, "SHIFT+SPC Play from cursor pos");
    printtext(40,pk++, 7, "SHIFT+CRSR Mark pattern");
    printtext(40,pk++, 7, "SHIFT+Q,W Transpose half/octave up");
    printtext(40,pk++, 7, "SHIFT+A,S Transpose half/octave down");
    printtext(40,pk++, 7, "SHIFT+E,R Copy,paste effects");
    printtext(40,pk++, 7, "SHIFT+H Make hifi vib/portaspeed");
    printtext(40,pk++, 7, "SHIFT+I Invert selection/pattern");
    printtext(40,pk++, 7, "SHIFT+J,K Join/split pattern");
    printtext(40,pk++, 7, "SHIFT+L Mark/unmark whole pattern");
    printtext(40,pk++, 7, "SHIFT+M,N Choose highlighting step");
    printtext(40,pk++, 7, "SHIFT+O,P Shrink/expand pattern");
    printtext(40,pk++, 7, "SHIFT+X,C,V Cut,copy,paste pattern");
    printtext(40,pk++, 7, "SHIFT+Z Cycle autoadvance-mode");
    printtext(40,pk++, 7, "SHIFT+1,2,3 Mute channel");

    ik = pk + 1;

    printtext(0, sk++, 15,"SONG EDIT MODE");
    printtext(0, sk++, 7, "0-9 & A-F to enter pattern numbers");
    printtext(0, sk++, 7, "SPC Set start position for F2 key");
    printtext(0, sk++, 7, "BACKSPC Set end position for F2 key");
    printtext(0, sk++, 7, "RET Go to pattern (/w SHIFT=all chns.)");
    printtext(0, sk++, 7, "< > Select subtune");
    printtext(0, sk++, 7, "- + Insert transpose down/up command");
    printtext(0, sk++, 7, "SHIFT+CRSR LEFT/RIGHT Mark orderlist");
    printtext(0, sk++, 7, "SHIFT+L Mark/unmark whole orderlist");
    printtext(0, sk++, 7, "SHIFT+R Insert repeat command");
    printtext(0, sk++, 7, "SHIFT+X,C,V Cut,copy,paste orderlist");
    printtext(0, sk++, 7, "SHIFT+1,2,3 Swap orderlist with chn.");
    printtext(0, sk++, 7, " ");
    printtext(0, sk++, 15,"SONGNAME EDIT MODE");
    printtext(0, sk++, 7, "Use cursor UP/DOWN to change rows");
    printtext(40,ik++, 15,"INSTRUMENT/TABLE EDIT MODE");
    printtext(40,ik++, 7, "0-9 & A-F to enter parameters");
    printtext(40,ik++, 7, "SPC Play test note");
    printtext(40,ik++, 7, "SHIFT+SPC Silence test note");
    printtext(40,ik++, 7, "RET Go to table");
    printtext(40,ik++, 7, "- + Select instrument");
    printtext(40,ik++, 7, "/ * Select octave");
    printtext(40,ik++, 7, "BACKQUOTE Select table");
    printtext(40,ik++, 7, "SHIFT+CRSR Mark table");
    printtext(40,ik++, 7, "SHIFT+Q,W Trans. speed half/octave up");
    printtext(40,ik++, 7, "SHIFT+A,S Trans. speed half/octave down");
    printtext(40,ik++, 7, "SHIFT+L Convert pulse/filter limit");
    printtext(40,ik++, 7, "SHIFT+N Edit name/negate value or note");
    printtext(40,ik++, 7, "SHIFT+O Optimize table (remove unused)");
    printtext(40,ik++, 7, "SHIFT+R Convert absolute/relative note");
    printtext(40,ik++, 7, "SHIFT+S ""Smart"" instrument paste");
    printtext(40,ik++, 7, "SHIFT+U Unlock/lock table view");
    printtext(40,ik++, 7, "SHIFT+X,C,V Cut,copy,paste instr./table");
    printtext(40,ik++, 7, "SHIFT+DEL Delete instrument+tabledata");
    printtext(40,ik++, 7, "SHIFT+RET Convert vibrato parameter");

    pc = ik + 1;

    printtext(0, pc++, 15,"PATTERN COMMANDS");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 0XY: Do nothing. Databyte will always be 00.                           ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 1XY: Portamento up. XY is index to a 16-bit speed in speedtable.       ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 2XY: Portamento down. XY is index to a 16-bit speed in speedtable.     ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 3XY: Toneportamento. Raise or lower pitch until target note has been   ");
    printtext(0, pc++,  7,"             reached. XY is index to a 16-bit speed or 00 for ""tie note"".      ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 4XY: Vibrato. XY is index to speedtable. Left side value determines how");
    printtext(0, pc++,  7,"             long until the direction changes (speed) and right side value is  ");
    printtext(0, pc++,  7,"             the amount of pitch change each tick (depth).                     ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 5XY: Set attack/decay register to value XY.                            ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 6XY: Set sustain/release register to value XY.                         ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 7XY: Set waveform register to value XY. If a wavetable is actively     ");
    printtext(0, pc++,  7,"             changing the channel's waveform at the same time, will be         ");
    printtext(0, pc++,  7,"             ineffective.                                                      ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 8XY: Set wavetable pointer. 00 stops wavetable execution.              ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command 9XY: Set pulsetable pointer. 00 stops pulsetable execution.            ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command AXY: Set filtertable pointer. 00 stops filtertable execution.          ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command BXY: Set filter control. X is resonance and Y is channel bitmask.      ");
    printtext(0, pc++,  7,"             00 turns filter off and also stops filtertable execution.         ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command CXY: Set filter cutoff to XY. Can be ineffective if the filtertable is ");
    printtext(0, pc++,  7,"             active and also changing the cutoff.                              ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command DXY: Set mastervolume to Y, if X is 0. If X is not 0, value XY is      ");
    printtext(0, pc++,  7,"             copied to the timing mark location, which is playeraddress+$3F.   ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command EXY: Funktempo. XY is an index to speedtable. Will alternate left side ");
    printtext(0, pc++,  7,"             and right side tempo values on each pattern step.                 ");
    printtext(0, pc++,  7,"                                                                               ");
    printtext(0, pc++,  7,"Command FXY: Set tempo. Values 03-7F set tempo on all channels, values 83-FF   ");
    printtext(0, pc++,  7,"             only on current channel (subtract 80 to get actual tempo). Tempos ");
    printtext(0, pc++,  7,"             00 and 01 recall the funktempos set by EXY command.               ");

    ip = pc + 1;

    printtext(0, ip++, 15,"INSTRUMENT PARAMETERS");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Attack/Decay          0 is fastest attack or decay, F is slowest               ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Sustain/Release       Sustain level 0 is silent and F is the loudest. Release  ");
    printtext(0, ip++,  7,"                      behaves like Attack & Decay (F slowest).                 ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Wavetable Pos         Wavetable startposition. Value 00 stops the wavetable    ");
    printtext(0, ip++,  7,"                      execution and is not very useful.                        ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Pulsetable Pos        Pulsetable startposition. Value 00 will leave pulse      ");
    printtext(0, ip++,  7,"                      execution untouched.                                     ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Filtertable Pos       Filtertable startposition. Value 00 will leave filter    ");
    printtext(0, ip++,  7,"                      execution untouched. In most cases it makes sense to have");
    printtext(0, ip++,  7,"                      a filter-controlling instrument only on one channel at a ");
    printtext(0, ip++,  7,"                      time.                                                    ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Vibrato Param         Instrument vibrato parameters. An index to the speed-    ");
    printtext(0, ip++,  7,"                      table, see command 4XY.                                  ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"Vibrato Delay         How many ticks until instrument vibrato starts. Value 00 ");
    printtext(0, ip++,  7,"                      turns instrument vibrato off.                            ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"HR/Gate Timer         How many ticks before note start note fetch, gateoff and ");
    printtext(0, ip++,  7,"                      hard restart happen. Can be at most tempo-1. So on tempo ");
    printtext(0, ip++,  7,"                      4 highest acceptable value is 3. Bitvalue 80 disables    ");
    printtext(0, ip++,  7,"                      hard restart and bitvalue 40 disables gateoff.           ");
    printtext(0, ip++,  7,"                                                                               ");
    printtext(0, ip++,  7,"1stFrame Wave         Waveform used on init frame of the note, usually 09 (gate");
    printtext(0, ip++,  7,"                      + testbit). Values 00, FE and FF have special meaning:   ");
    printtext(0, ip++,  7,"                      leave waveform unchanged and additionally set gate off   ");
    printtext(0, ip++,  7,"                      (FE), gate on (FF), or gate unchanged (00).              ");

    tb = ip + 1;

    printtext(0, tb++, 15,"TABLES");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Wavetable left side:  00    Leave waveform unchanged                           ");
    printtext(0, tb++,  7,"                      01-0F Delay this step by 1-15 frames                     ");
    printtext(0, tb++,  7,"                      10-DF Waveform values                                    ");
    printtext(0, tb++,  7,"                      E0-EF Inaudible waveform values 00-0F                    ");
    printtext(0, tb++,  7,"                      F0-FE Execute command 0XY-EXY. Right side is parameter   ");
    printtext(0, tb++,  7,"                      FF    Jump. Right side tells jump position (00 = stop)   ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Wavetable right side: 00-5F Relative notes                                     ");
    printtext(0, tb++,  7,"                      60-7F Negative relative notes (lower pitch)              ");
    printtext(0, tb++,  7,"                      80    Keep frequency unchanged                           ");
    printtext(0, tb++,  7,"                      81-DF Absolute notes C#0 - B-7                           ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Pulsetable left side: 01-7F Pulse modulation step. Left side indicates time and");
    printtext(0, tb++,  7,"                            right side the speed (8bit signed value).          ");
    printtext(0, tb++,  7,"                      8X-FX Set pulse width. X is the high 4 bits, right side  ");
    printtext(0, tb++,  7,"                            tells the 8 low bits.                              ");
    printtext(0, tb++,  7,"                      FF    Jump. Right side tells jump position (00 = stop)   ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Filt.table left side: 00    Set cutoff, indicated by right side                ");
    printtext(0, tb++,  7,"                      01-7F Filter modulation step. Left side indicates time   ");
    printtext(0, tb++,  7,"                            and right side the speed (signed 8bit value)       ");
    printtext(0, tb++,  7,"                      80-F0 Set filter parameters. Left side high nybble tells ");
    printtext(0, tb++,  7,"                            the passband (90 = lowpass, A0 = bandpass etc.) and");
    printtext(0, tb++,  7,"                            right side tells resonance/channel bitmask, as in  ");
    printtext(0, tb++,  7,"                            command BXY.                                       ");
    printtext(0, tb++,  7,"                      FF    Jump. Right side tells jump position (00 = stop)   ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Speedtbl. vibrato:    XX YY Left side tells how long until vibrato direction   ");
    printtext(0, tb++,  7,"                            changes (speed), right side is the value added to  ");
    printtext(0, tb++,  7,"                            pitch each tick (depth).                           ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Speedtbl. portamento: XX YY A 16-bit value added to pitch each tick. Left side ");
    printtext(0, tb++,  7,"                            is the MSB and the right side the LSB.             ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"Speedtbl. funktempo:  XX YY Two 8-bit tempo values that are alternated on each ");
    printtext(0, tb++,  7,"                            pattern row, starting from the left side.          ");
    printtext(0, tb++,  7,"                                                                               ");
    printtext(0, tb++,  7,"For both vibrato and portamento, if XX has the high bit ($80) set, note        ");
    printtext(0, tb++,  7,"independent vibrato depth / portamento speed calculation is enabled, and YY    ");
    printtext(0, tb++,  7,"specifies the divisor (higher value -> lower result and more rastertime taken).");

    printblank(0, 0, MAX_COLUMNS);
    sprintf(textbuffer, "%s Online Help", programname);
    printtext(0, 0, 15, textbuffer);
    printtext(55, 0, 15, "Arrows/PgUp/PgDn/Home/End scroll, others exit");
    printbg(0, 0, 1, MAX_COLUMNS);
    fliptoscreen();
    waitkeymousenoupdate();

    if (win_quitted)
    {
      exitprogram = 1;
      break;
    }

    switch(rawkey)
    {
      case KEY_LEFT:
      case KEY_UP:
      hview++;
      break;

      case KEY_RIGHT:
      case KEY_DOWN:
      hview--;
      break;

      case KEY_PGUP:
      for (c = 0; c < PGUPDNREPEAT; c++)
      {
        hview++;
      }
      break;

      case KEY_PGDN:
      for (c = 0; c < PGUPDNREPEAT; c++)
      {
        hview--;
      }
      break;

      case KEY_HOME:
      hview = -1;
      break;

      case KEY_END:
      hview = -(HELP_LASTROW-MAX_ROWS+1);
      break;

      default:
      if (rawkey) goto EXITHELP;
      break;
    }

    if ((mouseb) && (mousey == 1)) hview++;
    if ((mouseb) && (mousey == MAX_ROWS-1)) hview--;

    if (hview > -1) hview = -1;
    if (hview < -(HELP_LASTROW-MAX_ROWS+1)) hview = -(HELP_LASTROW-MAX_ROWS+1);
    if ((mouseb) && (!prevmouseb) && (!mousey)) break;
  }
  EXITHELP: ;
  printmainscreen();
  key = 0;
  rawkey = 0;
}

