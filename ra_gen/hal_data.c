/* generated HAL source file - do not edit */
#include "hal_data.h"

/** Display framebuffer */
#if GLCDC_CFG_LAYER_1_ENABLE
        uint8_t fb_background[1][DISPLAY_BUFFER_STRIDE_BYTES_INPUT0 * DISPLAY_VSIZE_INPUT0] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".bss");
        #else
/** Graphics Layer 1 is specified not to be used when starting */
#endif
#if GLCDC_CFG_LAYER_2_ENABLE
        uint8_t fb_foreground[2][DISPLAY_BUFFER_STRIDE_BYTES_INPUT1 * DISPLAY_VSIZE_INPUT1] BSP_ALIGN_VARIABLE(64) BSP_PLACE_IN_SECTION(".bss");
        #else
/** Graphics Layer 2 is specified not to be used when starting */
#endif

#if GLCDC_CFG_CLUT_ENABLE
        /** Display CLUT buffer to be used for updating CLUT */
        static uint32_t CLUT_buffer[256];

        /** Display CLUT configuration(only used if using CLUT format) */
        display_clut_cfg_t g_display0_clut_cfg_glcdc =
        {
            .p_base              = (uint32_t *)CLUT_buffer,
            .start               = 0,   /* User have to update this setting when using */
            .size                = 256  /* User have to update this setting when using */
        };
        #else
/** CLUT is specified not to be used */
#endif

#if (false)
         #define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST   const
         #define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST    (uint16_t *)
         #define GLCDC_CFG_CORRECTION_GAMMA_CFG_CAST      (display_gamma_correction_t *)
        #else
#define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST
#define GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST
#define GLCDC_CFG_CORRECTION_GAMMA_CFG_CAST
#endif

#if ((GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B) && GLCDC_CFG_COLOR_CORRECTION_ENABLE)
        /** Gamma correction tables */
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_r_gain[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_r_threshold[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960};
        #endif
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_g_gain[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_g_threshold[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960};
        #endif
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_b_gain[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024, 1024};
        static GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST uint16_t glcdc_gamma_b_threshold[DISPLAY_GAMMA_CURVE_ELEMENT_NUM] = {0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960};
        #endif
        GLCDC_CFG_CORRECTION_GAMMA_TABLE_CONST display_gamma_correction_t g_display0_gamma_cfg =
        {
            .r =
            {
                .enable      = GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R,
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R
                .gain        = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_r_gain,
                .threshold   = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_r_threshold
        #else
                .gain        = NULL,
                .threshold   = NULL
        #endif
            },
            .g =
            {
                .enable      = GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G,
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G
                .gain        = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_g_gain,
                .threshold   = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_g_threshold
        #else
                .gain        = NULL,
                .threshold   = NULL
        #endif
            },
            .b =
            {
                .enable      = GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B,
        #if GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B
                .gain        = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_b_gain,
                .threshold   = GLCDC_CFG_CORRECTION_GAMMA_TABLE_CAST glcdc_gamma_b_threshold
        #else
                .gain        = NULL,
                .threshold   = NULL
        #endif
            }
        };
        #endif

/** Display device extended configuration */
const glcdc_extended_cfg_t g_display0_extend_cfg =
{ .tcon_hsync = GLCDC_TCON_PIN_0,
  .tcon_vsync = GLCDC_TCON_PIN_1,
  .tcon_de = GLCDC_TCON_PIN_2,
  .correction_proc_order = GLCDC_CORRECTION_PROC_ORDER_BRIGHTNESS_CONTRAST2GAMMA,
  .clksrc = GLCDC_CLK_SRC_INTERNAL,
  .clock_div_ratio = GLCDC_PANEL_CLK_DIVISOR_24,
  .dithering_mode = GLCDC_DITHERING_MODE_TRUNCATE,
  .dithering_pattern_A = GLCDC_DITHERING_PATTERN_11,
  .dithering_pattern_B = GLCDC_DITHERING_PATTERN_11,
  .dithering_pattern_C = GLCDC_DITHERING_PATTERN_11,
  .dithering_pattern_D = GLCDC_DITHERING_PATTERN_11 };

/** Display control block instance */
glcdc_instance_ctrl_t g_display0_ctrl;

/** Display interface configuration */
const display_cfg_t g_display0_cfg =
        {
        /** Input1(Graphics1 layer) configuration */
        .input[0] =
        {
#if GLCDC_CFG_LAYER_1_ENABLE
                .p_base              = (uint32_t *)&fb_background[0],
                #else
          .p_base = NULL,
#endif
          .hsize = DISPLAY_HSIZE_INPUT0,
          .vsize = DISPLAY_VSIZE_INPUT0, .hstride = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0, .format =
                  DISPLAY_IN_FORMAT_16BITS_RGB565,
          .line_descending_enable = false, .lines_repeat_enable = false, .lines_repeat_times = 0 },

          /** Input2(Graphics2 layer) configuration */
          .input[1] =
          {
#if GLCDC_CFG_LAYER_2_ENABLE
                .p_base              = (uint32_t *)&fb_foreground[0],
                #else
            .p_base = NULL,
#endif
            .hsize = DISPLAY_HSIZE_INPUT1,
            .vsize = DISPLAY_VSIZE_INPUT1, .hstride = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT1, .format =
                    DISPLAY_IN_FORMAT_16BITS_RGB565,
            .line_descending_enable = false, .lines_repeat_enable = false, .lines_repeat_times = 0 },

          /** Input1(Graphics1 layer) layer configuration */
          .layer[0] =
          { .coordinate =
          { .x = 0, .y = 0 },
            .bg_color =
            { .byte =
            { .a = 255, .r = 255, .g = 255, .b = 255 } },
            .fade_control = DISPLAY_FADE_CONTROL_NONE, .fade_speed = 0 },

          /** Input2(Graphics2 layer) layer configuration */
          .layer[1] =
          { .coordinate =
          { .x = 0, .y = 0 },
            .bg_color =
            { .byte =
            { .a = 255, .r = 255, .g = 255, .b = 255 } },
            .fade_control = DISPLAY_FADE_CONTROL_NONE, .fade_speed = 0 },

          /** Output configuration */
          .output =
                  { .htiming =
                  { .total_cyc = 525, .display_cyc = 480, .back_porch = 40, .sync_width = 1, .sync_polarity =
                            DISPLAY_SIGNAL_POLARITY_LOACTIVE },
                    .vtiming =
                    { .total_cyc = 288, .display_cyc = 272, .back_porch = 8, .sync_width = 1, .sync_polarity =
                              DISPLAY_SIGNAL_POLARITY_LOACTIVE },
                    .format = DISPLAY_OUT_FORMAT_16BITS_RGB565, .endian = DISPLAY_ENDIAN_LITTLE, .color_order =
                            DISPLAY_COLOR_ORDER_BGR,
                    .data_enable_polarity = DISPLAY_SIGNAL_POLARITY_HIACTIVE, .sync_edge =
                            DISPLAY_SIGNAL_SYNC_EDGE_RISING,
                    .bg_color =
                    { .byte =
                    { .a = 255, .r = 0, .g = 0, .b = 0 } },
#if (GLCDC_CFG_COLOR_CORRECTION_ENABLE)
                .brightness =
                {
                    .enable          = false,
                    .r               = 512,
                    .g               = 512,
                    .b               = 512
                },
                .contrast =
                {
                    .enable          = false,
                    .r               = 128,
                    .g               = 128,
                    .b               = 128
                },
#if (GLCDC_CFG_CORRECTION_GAMMA_ENABLE_R | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_G | GLCDC_CFG_CORRECTION_GAMMA_ENABLE_B)
 #if false
                .p_gamma_correction  = GLCDC_CFG_CORRECTION_GAMMA_CFG_CAST (&g_display0_gamma_cfg),
 #else
                .p_gamma_correction  = &g_display0_gamma_cfg,
 #endif
#else
                .p_gamma_correction  = NULL,
#endif
#endif
                    .dithering_on = false },

          /** Display device callback function pointer */
          .p_callback = NULL,
          .p_context = NULL,

          /** Display device extended configuration */
          .p_extend = (void*) (&g_display0_extend_cfg),

          .line_detect_ipl = (12),
          .underflow_1_ipl = (BSP_IRQ_DISABLED), .underflow_2_ipl = (BSP_IRQ_DISABLED),

#if defined(VECTOR_NUMBER_GLCDC_LINE_DETECT)
            .line_detect_irq        = VECTOR_NUMBER_GLCDC_LINE_DETECT,
#else
          .line_detect_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GLCDC_UNDERFLOW_1)
            .underflow_1_irq        = VECTOR_NUMBER_GLCDC_UNDERFLOW_1,
#else
          .underflow_1_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GLCDC_UNDERFLOW_2)
            .underflow_2_irq        = VECTOR_NUMBER_GLCDC_UNDERFLOW_2,
#else
          .underflow_2_irq = FSP_INVALID_VECTOR,
#endif
        };

#if GLCDC_CFG_LAYER_1_ENABLE
        /** Display on GLCDC run-time configuration(for the graphics1 layer) */
        display_runtime_cfg_t g_display0_runtime_cfg_bg =
        {
            .input =
            {
                #if (true)
                .p_base              = (uint32_t *)&fb_background[0],
                #else
                .p_base              = NULL,
                #endif
                .hsize               = DISPLAY_HSIZE_INPUT0,
                .vsize               = DISPLAY_VSIZE_INPUT0,
                .hstride             = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT0,
                .format              = DISPLAY_IN_FORMAT_16BITS_RGB565,
                .line_descending_enable = false,
                .lines_repeat_enable = false,
                .lines_repeat_times  = 0
            },
            .layer =
            {
                .coordinate = {
                        .x           = 0,
                        .y           = 0
                },
                .bg_color            =
                {
                    .byte            =
                    {
                        .a           = 255,
                        .r           = 255,
                        .g           = 255,
                        .b           = 255
                    }
                },
                .fade_control        = DISPLAY_FADE_CONTROL_NONE,
                .fade_speed          = 0
            }
        };
#endif
#if GLCDC_CFG_LAYER_2_ENABLE
        /** Display on GLCDC run-time configuration(for the graphics2 layer) */
        display_runtime_cfg_t g_display0_runtime_cfg_fg =
        {
            .input =
            {
                #if (false)
                .p_base              = (uint32_t *)&fb_foreground[0],
                #else
                .p_base              = NULL,
                #endif
                .hsize               = DISPLAY_HSIZE_INPUT1,
                .vsize               = DISPLAY_VSIZE_INPUT1,
                .hstride             = DISPLAY_BUFFER_STRIDE_PIXELS_INPUT1,
                .format              = DISPLAY_IN_FORMAT_16BITS_RGB565,
                .line_descending_enable = false,
                .lines_repeat_enable = false,
                .lines_repeat_times  = 0
             },
            .layer =
            {
                .coordinate = {
                        .x           = 0,
                        .y           = 0
                },
                .bg_color            =
                {
                    .byte            =
                    {
                        .a           = 255,
                        .r           = 255,
                        .g           = 255,
                        .b           = 255
                    }
                },
                .fade_control        = DISPLAY_FADE_CONTROL_NONE,
                .fade_speed          = 0
            }
        };
#endif

/* Instance structure to use this module. */
const display_instance_t g_display0 =
{ .p_ctrl = &g_display0_ctrl, .p_cfg = (display_cfg_t*) &g_display0_cfg, .p_api = (display_api_t*) &g_display_on_glcdc };
gpt_instance_ctrl_t g_timer5_ctrl;
#if 0
const gpt_extended_pwm_cfg_t g_timer5_pwm_extend =
{
    .trough_ipl          = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT5_COUNTER_UNDERFLOW)
    .trough_irq          = VECTOR_NUMBER_GPT5_COUNTER_UNDERFLOW,
#else
    .trough_irq          = FSP_INVALID_VECTOR,
#endif
    .poeg_link           = GPT_POEG_LINK_POEG0,
    .output_disable      = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger         = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up  = 0,
    .dead_time_count_down = 0,
    .adc_a_compare_match = 0,
    .adc_b_compare_match = 0,
    .interrupt_skip_source = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count  = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc    = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer5_extend =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = true, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT5_CAPTURE_COMPARE_A)
    .capture_a_irq       = VECTOR_NUMBER_GPT5_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT5_CAPTURE_COMPARE_B)
    .capture_b_irq       = VECTOR_NUMBER_GPT5_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
          .capture_filter_gtioca = GPT_CAPTURE_FILTER_NONE,
          .capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg                   = &g_timer5_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) true,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif
        };
const timer_cfg_t g_timer5_cfg =
{ .mode = TIMER_MODE_PWM,
/* Actual period: 0.001 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x1d4c0,
  .duty_cycle_counts = 0xea60, .source_div = (timer_source_div_t) 0, .channel = 5, .p_callback = NULL,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &g_timer5_extend,
  .cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT5_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT5_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer5 =
{ .p_ctrl = &g_timer5_ctrl, .p_cfg = &g_timer5_cfg, .p_api = &g_timer_on_gpt };
sci_uart_instance_ctrl_t g_uart9_ctrl;

baud_setting_t g_uart9_baud_setting =
        {
        /* Baud rate calculated with 0.160% error. */.semr_baudrate_bits_b.abcse = 0,
          .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 0, .brr = 64, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
                  false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart9_cfg_extend =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &g_uart9_baud_setting, .flow_control =
          SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_UART_RS485_DISABLE, .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
#if 0xFF != 0xFF
                    .de_control_pin = BSP_IO_PORT_FF_PIN_0xFF,
                #else
    .de_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
          }, };

/** UART interface configuration */
const uart_cfg_t g_uart9_cfg =
{ .channel = 9, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          my_uart_irq,
  .p_context = NULL, .p_extend = &g_uart9_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI9_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI9_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI9_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI9_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI9_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart9 =
{ .p_ctrl = &g_uart9_ctrl, .p_cfg = &g_uart9_cfg, .p_api = &g_uart_on_sci };
void g_hal_init(void)
{
    g_common_init ();
}
