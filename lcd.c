#include<PIC18F4550.h>
#define RS  RC0
#define EN  RC1
#define DATABUS PORTD
void delay()
{ int i,j;
for(i=0;i<50;i++)
for(j=0;j<50;j++);
}
void cmd(char a)
{
RC0 = 0;
DATABUS = a;
RC1=1;
delay();
RC1=0;
}
void data(char a)
{
RC0=1;
DATABUS=a;
RC1=1;
delay();
RC1=0;
}
void lcd_int()
{
cmd(0x38);
cmd(0x0e);
cmd(0x06);
cmd(0x01);
cmd(0x80);

}
void main()
{
char   i,str[] = "Vrushabh";
char str1[] = "Bastwade";
TRISC = 0x00;
TRISD = 0x00;
lcd_int();
i=0;
while(str[i])
{
data(str[i]);
delay();
i++;
}
cmd(0xc0);
i = 0;
while(str1[i])
{
data(str1[i]);
delay();
i++;
}
while(1);
}
