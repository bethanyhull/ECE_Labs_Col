# peripheral registers

/* 
 * stm32f407xx
 * updated 11/04/2015
 *
 */

/* 
 *  PWR - Power Controller
 *
 *  DM00031020 - Section 5.6
 */

  .equ PWR_BASE,0x40007000

    .equ PWR_CR,0x00			/* Power Control Register */

      .equ PWR_CR_VOS,(1<<14)
	.equ PWR_CR_VOS_SCALE2,(0b0<<14)
	.equ PWR_CR_VOS_SCALE1,(0b1<<14)
	.equ PWR_CR_VOS_RESET,(0b1<<14)
        .equ PWR_CR_VOS_DEFAULT,(0b1<<14)
      .equ PWR_CR_FPDS,(1<<9)
      .equ PWR_CR_DBP,(1<<8)
      .equ PWR_CR_PLS,(~(~0<<3)<<5)
      .equ PWR_CR_PVDE,(1<<4)
      .equ PWR_CR_CSBF,(1<<3)
      .equ PWR_CR_CWUF,(1<<2)
      .equ PWR_CR_PDDS,(1<<1)
      .equ PWR_CR_LPDS,(1<<0)

    .equ PWR_CSR,0x04			/* Power Control/Status Register */

      .equ PWR_CSR_VOSRDY,(1<<14)
      .equ PWR_CSR_BRE,(1<<9)
      .equ PWR_CSR_EWUP,(1<<8)
      .equ PWR_CSR_BRR,(1<<3)
      .equ PWR_CSR_PVDO,(1<<2)
      .equ PWR_CSR_SBF,(1<<1)
      .equ PWR_CSR_WUF,(1<<0)

/* 
 *  RCC - Reset and Clock Control
 *
 *  DM00031020 - Section 7
 */
      
  .equ RCC_BASE,0x40023800
  
    .equ RCC_CR,0x00			/* Clock Control Register */

      .equ RCC_CR_RESET,0x00000000
      .equ RCC_CR_HSION,(1<<0)
      .equ RCC_CR_HSIRDY,(1<<1)
      .equ RCC_CR_HSEON,(1<<16)
      .equ RCC_CR_HSERDY,(1<<17)
      .equ RCC_CR_HSERDY_STARTUP_TIMEOUT,0x500
      .equ RCC_CR_HSEBYP,(1<<18)
      .equ RCC_CR_CSSON,(1<<19)
      .equ RCC_CR_PLLON,(1<<24)
      .equ RCC_CR_PLLRDY,(1<<25)

    .equ PLL_M,8
    .equ PLL_N,336
    .equ PLL_P,2
    .equ PLL_Q,7
      
    .equ RCC_PLLCFGR,0x04		/* PLL Configuration Register */

      .equ RCC_PLLCFGR_RESET,0x24003010

      .equ RCC_PLLCFGR_PLLQ,(~(~0<<4)<<24)

        .equ RCC_PLLCFGR_PLLQ_VAL,(PLL_Q<<24)

      .equ RCC_PLLCFGR_PLLP,(~(~0<<2)<<16)

        .equ RCC_PLLCFGR_PLLP_VAL,(((PLL_P >> 1) -1)<<16)

      .equ RCC_PLLCFGR_PLLN,(~(~0<<9)<<6)

        .equ RCC_PLLCFGR_PLLN_VAL,(PLL_N<<6)

      .equ RCC_PLLCFGR_PLLM,(~(~0<<6)<<0)

        .equ RCC_PLLCFGR_PLLM_VAL,(PLL_M<<0)

      .equ RCC_PLLCFGR_PLLSRC,(1<<22)

	.equ RCC_PLLCFGR_PLLSRC_HSI,(0<<22)
	.equ RCC_PLLCFGR_PLLSRC_HSE,(1<<22)

      .equ RCC_PLLCFGR_HSE168,( RCC_PLLCFGR_PLLSRC_HSE | RCC_PLLCFGR_PLLQ_VAL | RCC_PLLCFGR_PLLP_VAL | RCC_PLLCFGR_PLLN_VAL | RCC_PLLCFGR_PLLM_VAL )

    .equ RCC_CFGR,0x08			/* Clock Configuration Register */

      .equ RCC_CFGR_MCO2,(~(~0<<2)<<30)

	.equ RCC_CFGR_MCO2_SYSCLK,(0b00<<30)
	.equ RCC_CFGR_MCO2_PLLI2S,(0b01<<30)
	.equ RCC_CFGR_MCO2_HSE,   (0b10<<30)
	.equ RCC_CFGR_MCO2_PLL,   (0b11<<30)

      .equ RCC_CFGR_MCO2PRE,(~(~0<<3)<<27)

	.equ RCC_CFGR_MCO2PRE_NODIV,(0b0000<<27)

      .equ RCC_CFGR_MCO1,(~(~0<<2)<<21)

	.equ RCC_CFGR_MCO1_HSI,(0b00<<21)
	.equ RCC_CFGR_MCO1_LSE,(0b01<<21)
	.equ RCC_CFGR_MCO1_HSE,(0b10<<21)
	.equ RCC_CFGR_MCO1_PLL,(0b11<<21)

      .equ RCC_CFGR_PPRE2,(~(~0<<3)<<13)

	.equ RCC_CFGR_PPRE2_DIV2,(0b100<<13)

      .equ RCC_CFGR_PPRE1,(~(~0<<3)<<10)

	.equ RCC_CFGR_PPRE1_DIV4,(0b101<<10)

      .equ RCC_CFGR_HPRE,(~(~0<<4)<<4)

	.equ RCC_CFGR_HPRE_DIV1,(0b0000<<4)

      .equ RCC_CFGR_SWS,(~(~0<<2)<<2)

        .equ RCC_CFGR_SWS_HSI,(0b00<<2)
        .equ RCC_CFGR_SWS_HSE,(0b01<<2)
        .equ RCC_CFGR_SWS_PLL,(0b10<<2)

      .equ RCC_CFGR_SW,(~(~0<<2)<<0)
        .equ RCC_CFGR_SW_HSI,(0b00<<0)
        .equ RCC_CFGR_SW_HSE,(0b01<<0)
        .equ RCC_CFGR_SW_PLL,(0b10<<0)

    .equ RCC_CIR,0x0c			/* Clock Interrupt Register */
      .equ RCC_CIR_RESET,0x00000000

    .equ RCC_AHB1ENR,0x30		/* AHB1 peripheral clock enable register */

      .equ RCC_AHB1ENR_GPIOA_EN,(1<<0)
      .equ RCC_AHB1ENR_GPIOB_EN,(1<<1)
      .equ RCC_AHB1ENR_GPIOC_EN,(1<<2)
      .equ RCC_AHB1ENR_GPIOD_EN,(1<<3)
      .equ RCC_AHB1ENR_GPIOE_EN,(1<<4)

    .equ RCC_APB1ENR,0x40		/* APB1 peripheral clock enable register */

      .equ RCC_APB1ENR_PWREN,(1<<28)    

/* 
 *  FLASH - FLASH Interface Registers
 *
 *  DM00031020 - Section 3.9
 */
  
  .equ FLASH_BASE,0x08000000

  .equ FLASH_R_BASE,0x40023c00

    .equ FLASH_ACR,0x00			/* Access Control Register */

      .equ FLASH_ACR_DCEN,(1<<10)

        .equ FLASH_ACR_DCEN_DISABLE,(0b0<<10)
        .equ FLASH_ACR_DCEN_ENABLE,(0b1<<10)

      .equ FLASH_ACR_ICEN,(1<<9)

        .equ FLASH_ACR_ICEN_DISABLE,(0b0<<9)
        .equ FLASH_ACR_ICEN_ENABLE,(0b1<<9)

      .equ FLASH_ACR_LATENCY,(~(~0<<3)<<0)

	.equ FLASH_ACR_LATENCY_0WS,(0b000<<0)
	.equ FLASH_ACR_LATENCY_1WS,(0b001<<0)
	.equ FLASH_ACR_LATENCY_2WS,(0b010<<0)
	.equ FLASH_ACR_LATENCY_3WS,(0b011<<0)
	.equ FLASH_ACR_LATENCY_4WS,(0b100<<0)
	.equ FLASH_ACR_LATENCY_5WS,(0b101<<0)
	.equ FLASH_ACR_LATENCY_6WS,(0b110<<0)
	.equ FLASH_ACR_LATENCY_7WS,(0b111<<0)

/* 
 *  SCB - System Control Block
 *
 *  DUI0553A - Section 3.9
 */
  
  .equ SCB_BASE,0xE000ED00

    .equ SCB_VTOR,0x08			/* Vector Table Offset Register */

      .equ VECT_TAB_OFFSET,0x00