# 7Segment_DRIVER_ATMEGA32
by using DIO_DRIVER that I created , I made this driver which is have many features like :
 - you can define and use more than one SSD up to 4 as ATmega32 has omly 4 PORTS
 - can chooose your SSD type "common cathode or common anode" , code will debug as your choice
 - have multipile functions :
     - inialize SSD by using HSSD_voidInit() function with input of portNAame that SSD will connect
     - turn off SSD by using HSSD_voidTurnOFF() function with input of portNAame that SSD will connect
     - function HSSD_voidDisplayNum(u8 A_U8SSD_PORT , u8 A_U8Num) to display specific number on SSD
     - fuction  "HSSD_voidCountUP(u8 A_U8SSD_PORT , u8 A_U8Num)" to start with value you enter and count up
    - fuction  "HSSD_voidCountDOWN(u8 A_U8SSD_PORT , u8 A_U8Num)" to start with value you enter and count down

IN APP I use my driver to create aproject which is watch that contain of FOUR SSD show time in hours and minutes . 
