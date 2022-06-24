/* Pr�ctica 10: Calculadora de 3 bits
   Paulo Salvatore Partida Escamilla   15300210
   Jose Luis Mar�n Alarc�n             15300157
*/
#include <16F886.h>
#use delay(clock=4000000)
#include <lcd1.c>
#fuses intrc_io,nowdt,noput,nomclr,noprotect,nocpd,nobrownout
#fuses noieso,nofcmen,nodebug,nowrt,borv21
#use fast_io(A)
#use fast_io(B)

void main()
{     
   set_tris_A(0xFF);
   lcd_init(); 
   while(1)
   {
      int A=Input_A();                                                             //0011 1000= 38
      A=A&0x38;
      A>>=3;
      
      int B=Input_A();                                                             //0000 0111 =07
      B=B&0x07;
   
      int Operacion=Input_A();                                                     //1100 0000= C0
      Operacion=Operacion&0xC0;
      Operacion>>=6;
 
      signed int Resultadosrm;
      Lcd_gotoxy(1,1);
      if (Operacion== 0x00)                                                      //Suma
         {
         Resultadosrm=A+B;
         printf(lcd_putc,"\f \n \f");
         printf (lcd_putc, "A + B\n %u + %u = %u",A,B,Resultadosrm);
         }
      if (Operacion== 0x01)                                                      //Resta
         {
         Resultadosrm=A-B;
         printf(lcd_putc,"\f \n \f");
         printf (lcd_putc, "A - B\n %u - %u = %d",A,B,Resultadosrm);
         }
      if (Operacion== 0x02)                                                      //Multiplicaci�n
         {
         Resultadosrm=A*B;
         printf(lcd_putc,"\f \n \f");
         printf (lcd_putc, "A * B\n %u * %u = %d",A,B,Resultadosrm);
         }
      if (Operacion== 0x03)                                                      //Divisi�n
         {
         float Resultadod=(float)A/B;
         printf (lcd_putc,"\f \n \f");
         printf (lcd_putc, "A / B\n %u / %u = %.3g",A,B,Resultadod);
         }
      delay_ms(300);
   }
}
