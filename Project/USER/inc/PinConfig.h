#ifndef _PinConfig_h
#define _PinConfig_h

// clang-format off

// #define EncoderL1_CONFIG QTIMER_3, QTIMER3_TIMER2_B18, QTIMER3_TIMER3_B19, true  // ��ɵ�
#define EncoderL1_CONFIG QTIMER_1, QTIMER1_TIMER2_C2,  QTIMER1_TIMER3_C24, true
#define EncoderL2_CONFIG QTIMER_2, QTIMER2_TIMER0_C3,  QTIMER2_TIMER3_C25, true
#define EncoderR1_CONFIG QTIMER_1, QTIMER1_TIMER0_C0,  QTIMER1_TIMER1_C1,  false
#define EncoderR2_CONFIG QTIMER_3, QTIMER3_TIMER0_B16, QTIMER3_TIMER1_B17, false  // �Լ���

#define UART2_CONFIG USART_2, 115200, UART2_TX_B18, UART2_RX_B19, 32, 32, 100
#define UART3_CONFIG USART_3, 115200, UART3_TX_C8,  UART3_RX_C9,  32, 32, 100
#define UART4_CONFIG USART_4, 115200, UART4_TX_C16, UART4_RX_C17, 32, 32, 100
#define UART5_CONFIG USART_5, 115200, UART5_TX_C28, UART5_RX_C29, 32, 32, 100
#define UART8_CONFIG USART_8, 115200, UART8_TX_D16, UART8_RX_D17, 32, 32, 100

#define ICM20948_CONFIG SPI_4, SPI4_SCK_C23, SPI4_MOSI_C22, SPI4_MISO_C21, SPI4_CS0_C20, C30

#define MOTORDRV_L1_CONFIG D2,  PWM1_MODULE3_CHA_D0,  false
#define MOTORDRV_R1_CONFIG D3,  PWM1_MODULE3_CHB_D1,  true
#define MOTORDRV_L2_CONFIG D15, PWM1_MODULE0_CHB_D13, false
#define MOTORDRV_R2_CONFIG D14, PWM1_MODULE0_CHA_D12, true

#define MASTER_KEY C31, C27, C26, B29, B28
#define MASTER_SWITCH C11, D4, D27

#define SLAVE_KEY C4, C26, C27, C31, C25
#define SLAVE_SWITCH C24, D4, D27

#endif  // _PinConfig_h