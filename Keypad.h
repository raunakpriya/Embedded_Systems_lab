#include "xstdsys.h"
#include "lpc2148.h" 
unsigned int i,delay_ms,segval;
unsigned char index;
unsigned char lcdval,row,keyscan,keyret,keynum=0;
unsigned char keypress,scanret=0xff;
unsigned char seg7[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00,0x00,0x00};
	unsigned char scan[]={0xef,0xdf,0xbf,0x7f,0x00};
		unsigned char keycode[]={0xee,0xed,0xeb,0xe7,0xde,0xdd,0xdb,0xd7,0xbe,0xbd,0xbb,0xb7,0x7e,0x7d,0x7b,0x77,0x00};
			void InitLPC(void);
			void Delay(unsigned int);
			void InitLPC(void){
				PINSEL0=0x00L;
				IO0DIR=0xfffffff0;
			}
			void Delay(unsigned int dms){
				delay_ms=dms;
				while(delay_ms>0){
					delay_ms--;
				}
			}
			void GetKey(){
				row=0;
				while(1){
					IO0CLR=0xff;
					row&=0x03;
					keyscan=scan[row];
					IO0SET=keyscan;
					Delay(2);
					keyret=IO0PIN;
					if(keyscan!=keyret)
					break;
					row++;
				}
				for(i=0;i<0x10;i++){
					if(keycode[i]==keyret)
					keynum=i;
					IO0CLR=0xff00;
					segval=seg7[keynum];
					segval<<=8;
					IO0SET=segval;
				}
			}
				void main(void){
					InitLPC();
					index=0;
					while(1){
						GetKey();
					}
				}
