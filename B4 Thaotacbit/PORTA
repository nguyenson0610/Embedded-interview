#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00101111;

void readByte(uint8_t byte)
{
    printf("0b");
    for (int i = 0; i < 8; i++)
    {
        uint8_t temp = 0b10000000;
        uint8_t kq = byte & temp;
        if (kq == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        byte = byte << 1;
    }
}

typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} s_pins;

typedef enum
{
    LOW,
    HIGH
} s_status;

void pinHigh(s_pins pin)
{
    PORTA = PORTA | (128 >> pin);

}

void pinLow(s_pins pin)
{

    PORTA = PORTA ^ (128 >> pin) ;
}

void digitalWrite(s_pins pin, s_status status)
{
    
    if (status == LOW)
    {
        pinLow(pin);
    }
    else
    {
        pinHigh(pin);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    digitalWrite(PIN7, LOW);
    digitalWrite(PIN2, LOW);
    digitalWrite(PIN0,HIGH);
    readByte(PORTA);
    return 0;
}

