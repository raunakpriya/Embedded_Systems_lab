void Delay(unsigned int dms);
unsigned int delay_ms,ledval,n;
void Delay(unsigned int dms)
{
delay_ms=dms;
while(delay_ms>0)
{
delay_ms--;
}
}
void Init_GPIO(void)
{
PINSEL0=0x00;
PINSEL1=0x00;
g_pGPIO->IODIR=0xFFFFFFFF;
g_pGPIO1->IODIR=0xFFFFFFFF;
}
main()
{
Init_GPIO();
while(1)
{
for(n=0;n<8;n++)
{
switch(n){
case 0: ledval=0x01010101;
break;
case 1: ledval=0x02020202;
break;
case 2: ledval=0x03030303;
break;
case 3: ledval=0x04040404;
break;
case 4: ledval=0x05050505;
break;
case 5: ledval=0x06060606;
break;
case 6: ledval=0x07070707;
break;
case 7: ledval=0x08080808;
break;
}
}
}
}
