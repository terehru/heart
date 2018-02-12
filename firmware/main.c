#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

//банально счетчик
volatile uint8_t i=0;

//сколько шагов
#define MAX_STEP 16

//врем€ задержки старта
#define START_DELAY 500

//врем€ задержки иницилизации
#define INIT_DELAY 10

//врем€ задержки перед миганием
#define HEAT_DELAY 110



//табличка значений €ркости
const uint8_t led_level[MAX_STEP] PROGMEM =
	{250,240,200,150,100,50,40,30,
	 25,20,15,10,5,1,1,1};
	 /*1,3,7,15,31,63,127,255,
	 255,240,230,230,230,220,220,210,
	 210,200,200,190,190,180,180,170,
	 160,160,150,150,140,140,130,130,
	 130,120,110,100,90,80,70,60,
	 70,80,90,100,120,130,140,150};*/
	 
int ni,nj,nl;
	

ISR (TIMER0_OVF_vect)
	{
		PORTB = 0xFF;
		PORTC = 0xFF;
		PORTD = 0xFF;
	};
 
ISR (TIMER0_COMPA_vect)
	{
		PORTB = 0x00;
		PORTC = 0x00;
		PORTD = 0x00;
	};


int ledON(int val)
{
	switch (val) {
	case 0:
		PORTC |= _BV(0);
	break;
	case 1:
		PORTB |= _BV(5);
	break;
	case 2:
		PORTB |= _BV(4);
	break;
	case 3:
		PORTB |= _BV(3);
	break;
	case 4:
		PORTB |= _BV(2);
	break;
	case 5:
		PORTB |= _BV(1);
	break;
	case 6:
		PORTB |= _BV(0);
	break;
	case 7:
		PORTD |= _BV(7);
	break;
	case 8:
		PORTD |= _BV(6);
	break;
	case 9:
		PORTD |= _BV(5);
	break;
	case 10:
		PORTB |= _BV(7);
	break;
	case 11:
		PORTB |= _BV(6);
	break;
	case 12:
		PORTD |= _BV(4);
	break;
	case 13:
		PORTD |= _BV(3);
	break;
	case 14:
		PORTD |= _BV(2);
	break;
	case 15:
		PORTD |= _BV(1);
	break;
	case 16:
		PORTD |= _BV(0);
	break;
	case 17:
		PORTC |= _BV(5);
	break;
	case 18:
		PORTC |= _BV(4);
	break;
	case 19:
		PORTC |= _BV(3);
	break;
	case 20:
		PORTC |= _BV(2);
	break;
	case 21:
		PORTC |= _BV(1);
	break;
	}
}

int ledOFF(int val)
{
	switch (val) {
	case 0:
		PORTC &= ~(_BV(0));
	break;
	case 1:
		PORTB &= ~(_BV(5));
	break;
	case 2:
		PORTB &= ~(_BV(4));
	break;
	case 3:
		PORTB &= ~(_BV(3));
	break;
	case 4:
		PORTB &= ~(_BV(2));
	break;
	case 5:
		PORTB &= ~(_BV(1));
	break;
	case 6:
		PORTB &= ~(_BV(0));
	break;
	case 7:
		PORTD &= ~(_BV(7));
	break;
	case 8:
		PORTD &= ~(_BV(6));
	break;
	case 9:
		PORTD &= ~(_BV(5));
	break;
	case 10:
		PORTB &= ~(_BV(7));
	break;
	case 11:
		PORTB &= ~(_BV(6));
	break;
	case 12:
		PORTD &= ~(_BV(4));
	break;
	case 13:
		PORTD &= ~(_BV(3));
	break;
	case 14:
		PORTD &= ~(_BV(2));
	break;
	case 15:
		PORTD &= ~(_BV(1));
	break;
	case 16:
		PORTD &= ~(_BV(0));
	break;
	case 17:
		PORTC &= ~(_BV(5));
	break;
	case 18:
		PORTC &= ~(_BV(4));
	break;
	case 19:
		PORTC &= ~(_BV(3));
	break;
	case 20:
		PORTC &= ~(_BV(2));
	break;
	case 21:
		PORTC &= ~(_BV(1));
	break;
	}
}

int AllON () {
 int j;
 j = 0;
  while (j < 22) {
	ledON(j);
	j++;
  }
}
int AllOFF () {
 int j;
 j = 0;
  while (j < 22) {
	ledOFF(j);
	j++;
  }
}
 

int main(void)
{

 DDRB = 0xFF;
 DDRC = 0xFF;
 DDRD = 0xFF;
 PORTB = 0x00;
 PORTC = 0x00;
 PORTD = 0x00;

 _delay_ms(START_DELAY);
 //////////////
while (1) {
 PORTB |= _BV(PB0);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB7);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB4);
  _delay_ms(INIT_DELAY);
 PORTC |= _BV(PC3);
  _delay_ms(INIT_DELAY);
 PORTC |= _BV(PC5);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB1);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB6);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB2);
 //////////////////
  _delay_ms(INIT_DELAY); 
 PORTD |= _BV(PD0);
  _delay_ms(INIT_DELAY);
 PORTC |= _BV(PC4);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB3);
  _delay_ms(INIT_DELAY);
 PORTB |= _BV(PB5);
  _delay_ms(INIT_DELAY);
 PORTC |= _BV(PC1);
  _delay_ms(INIT_DELAY);
 PORTC |= _BV(PC2);
 //////////////////
  _delay_ms(INIT_DELAY);
 PORTC |= _BV(PC0);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD7);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD4);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD3);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD5);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD1);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD6);
  _delay_ms(INIT_DELAY);
 PORTD |= _BV(PD2);
 
 _delay_ms(HEAT_DELAY);
///////////////////

PORTB = 0;
PORTC = 0;
PORTD = 0;

//_delay_ms(500); 

ni = 1;
nj = 0;
nl = 0;
while (ni<2) {

	while (nj<=22) {
		ledON(nj);
		_delay_ms(10); 
		nj++;
	}

	nj = 0;
	while (nj<22) {
		ledOFF(nj);
		_delay_ms(10); 
		nj++;
	}
	nj = 0;
	ledON(0);
	while (nj<22) {
		ledON(21-nj);
		_delay_ms(10); 
		nj++;
	}
	nj = 0;
	ledON(0);
	while (nj<22) {
		ledOFF(21-nj);
		_delay_ms(10); 
		nj++;
	}

	nj = 0;
	while (nl < 3) {
		while (nj<=22) {
			ledON(21-nj);
			_delay_ms(3);
			ledOFF(21-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}
	
	nj = 0;
	nl = 0;
	while (nl < 3) {
		while (nj<=22) {
			ledON(21-nj);
			ledON(20-nj);
			_delay_ms(3);
			ledOFF(21-nj);
			ledOFF(20-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}
	
	nj = 0;
	nl = 0;
	while (nl < 3) {
		while (nj<=22) {
			ledON(21-nj);
			ledON(20-nj);
			ledON(19-nj);
			_delay_ms(4);
			ledOFF(21-nj);
			ledOFF(20-nj); 
			ledOFF(19-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}
	
	nj = 0;
	nl = 0;
	while (nl < 4) {
		while (nj<=22) {
			ledON(21-nj);
			ledON(20-nj);
			ledON(19-nj);
			ledON(18-nj);			
			_delay_ms(5);
			ledOFF(21-nj);
			ledOFF(20-nj); 
			ledOFF(19-nj); 
			ledOFF(18-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}
	
	while (nl < 4) {
		while (nj<=22) {
			ledON(21-nj);
			ledON(20-nj);
			ledON(19-nj);
			ledON(18-nj);		
			ledON(17-nj);	
			_delay_ms(6);
			ledOFF(21-nj);
			ledOFF(20-nj); 
			ledOFF(19-nj); 
			ledOFF(18-nj); 
			ledOFF(17-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}
	
	while (nl < 4) {
		while (nj<=22) {
			ledON(21-nj);
			ledON(20-nj);
			ledON(19-nj);
			ledON(18-nj);		
			ledON(17-nj);	
			ledON(16-nj);
			_delay_ms(7);
			ledOFF(21-nj);
			ledOFF(20-nj); 
			ledOFF(19-nj); 
			ledOFF(18-nj); 
			ledOFF(17-nj); 
			ledOFF(16-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}
	
	while (nl < 4) {
		while (nj<=22) {
			ledON(21-nj);
			ledON(20-nj);
			ledON(19-nj);
			ledON(18-nj);		
			ledON(17-nj);	
			ledON(16-nj);
			ledON(15-nj);
			_delay_ms(8);
			ledOFF(21-nj);
			ledOFF(20-nj); 
			ledOFF(19-nj); 
			ledOFF(18-nj); 
			ledOFF(17-nj); 
			ledOFF(16-nj); 
			ledOFF(15-nj); 
			nj++;
		}
		nj = 0;
		nl++;
	}

	nj = 0;
	nl = 0;
	while (nl < 4) {
		AllON();
		_delay_ms(30);
		AllOFF();
		_delay_ms(25);
		AllON();
		_delay_ms(55);
		AllOFF();
		_delay_ms(110);
		nl++;
	}
	//PORTB = 0;
	//PORTC = 0;
	//PORTD = 0;
	// PORTB |= _BV(PB6);
	// PORTB |= _BV(PB7);
	// _delay_ms(300); 
	// PORTB &= ~(_BV(PB7));
	//_delay_ms(300);
	//PORTB = 0;
	ni++;
	nj = 0;
}


 //настройка таймера 0
 TCCR0A = 0<<WGM00|0<<WGM01; //режим normal
 TCCR0B = 0<<WGM02|0<<WGM01|0<<CS02|1<<CS01|1<<CS00; //в жопу предделитель, на max частоте фигачим
 //OCR0A = 0xFF;
 
 //настройка прерываний от таймера 0
 TIMSK0 = _BV(TOIE0); //разрешаем прерывание по переполнию таймера 0
 TIMSK0 |= _BV(OCIE0A); //разрешаем прерывание по регистру сравнени€ таймера 0
 sei(); //разрешаем работу прерываний вообще
 
 
 // _delay_ms(HEAT_DELAY);
 //_delay_ms(200);
 //OCR0A = 0x01;
 //_delay_ms(200);  
 //OCR0A = 64; 
 //_delay_ms(200);  
 //OCR0A = 128; 
 // _delay_ms(200);  
 //OCR0A = 0xFF; 
 
  
 
 i = 1;
 
 
 nl = 0;
 

 while (nl <= 511) 
	{
		cli();
		TCCR0B = 0; //отключаем таймер
		//TCNT0 = 0;
		OCR0A = i;
		//OCR0A = led_level[i];
		i++;
	
		//if ( i > MAX_STEP )  i = 0; 
		TCCR0B = 0<<WGM02|0<<WGM01|0<<CS02|1<<CS01|1<<CS00; //включаем таймер обратно
		sei();
		_delay_us(1000);
		nl++;
	
	}

	cli();
	/*cli();
	AllOFF();
	_delay_ms(50);
	AllON();
	_delay_ms(50);
	AllOFF();*/
};
 
return 0;
}