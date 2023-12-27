#ifndef _CVI_COMM_HDMI_H_
#define _CVI_COMM_HDMI_H_
#include <linux/cvi_common.h>
#include <linux/cvi_defines.h>
#include <linux/cvi_comm_video.h>


#define CVI_HDMI_VENDOR_USER_DATA_MAX_LEN 22
#define CVI_HDMI_MAX_AUDIO_CAPBILITY_CNT 16
#define CVI_HDMI_MAX_SAMPLE_RATE_NUM 8
#define CVI_HDMI_MAX_BIT_DEPTH_NUM 6
#define CVI_HDMI_DETAIL_TIMING_MAX 10
#define CVI_HDMI_EDID_RAW_DATA_LEN 512
#define CVI_HDMI_HW_PARAM_NUM 4
#define CVI_HDMI_MANUFACTURE_NAME_LEN 4
#define CVI_HDMI_AUDIO_SPEAKER_BUTT 1

typedef enum _CVI_HDMI_VIDEO_FORMAT {
    CVI_HDMI_VIDEO_FORMAT_861D_640X480_60 = 1,
    CVI_HDMI_VIDEO_FORMAT_480P_60 = 2,        // 3
    CVI_HDMI_VIDEO_FORMAT_1080i_30 = 5,
    CVI_HDMI_VIDEO_FORMAT_1440x480i_30 = 6,   // 7
    CVI_HDMI_VIDEO_FORMAT_1080P_60 = 16,
    CVI_HDMI_VIDEO_FORMAT_576P_50 = 17,
    CVI_HDMI_VIDEO_FORMAT_720P_50 = 19,
    CVI_HDMI_VIDEO_FORMAT_1080i_25 = 20,
    CVI_HDMI_VIDEO_FORMAT_1440x576i_25 = 21,
    CVI_HDMI_VIDEO_FORMAT_1080P_50 = 31,
    CVI_HDMI_VIDEO_FORMAT_1080P_30,
    CVI_HDMI_VIDEO_FORMAT_1080P_24,
    CVI_HDMI_VIDEO_FORMAT_1080i_60,
    CVI_HDMI_VIDEO_FORMAT_1080i_50,
    CVI_HDMI_VIDEO_FORMAT_720P_60 = 69,
    CVI_HDMI_VIDEO_FORMAT_PAL, /* B D G H I P AL */
    CVI_HDMI_VIDEO_FORMAT_NTSC,  /* (M)NTSC*/
    CVI_HDMI_VIDEO_FORMAT_VESA_800X600_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1024X768_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1280X800_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1280X1024_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1366X768_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1440X900_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1400X1050_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1600X1200_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1680X1050_60,
    CVI_HDMI_VIDEO_FORMAT_VESA_1920X1200_60,
    CVI_HDMI_VIDEO_FORMAT_2560x1440_30,
    CVI_HDMI_VIDEO_FORMAT_2560x1440_60 = 108,
    CVI_HDMI_VIDEO_FORMAT_2560x1600_60,
    CVI_HDMI_VIDEO_FORMAT_1920x2160_30,
    CVI_HDMI_VIDEO_FORMAT_3840X2160P_24,
    CVI_HDMI_VIDEO_FORMAT_3840X2160P_25,
    CVI_HDMI_VIDEO_FORMAT_3840X2160P_30,
    CVI_HDMI_VIDEO_FORMAT_3840X2160P_50,
    CVI_HDMI_VIDEO_FORMAT_3840X2160P_60 = 90,
    CVI_HDMI_VIDEO_FORMAT_4096X2160P_24,
    CVI_HDMI_VIDEO_FORMAT_4096X2160P_25,
    CVI_HDMI_VIDEO_FORMAT_4096X2160P_30,
    CVI_HDMI_VIDEO_FORMAT_4096X2160P_50,
    CVI_HDMI_VIDEO_FORMAT_4096X2160P_60 = 102,
    CVI_HDMI_VIDEO_FORMAT_2560X1440P_60 = 108,
    CVI_HDMI_VIDEO_FORMAT_VESA_CUSTOMER_DEFINE,
    CVI_HDMI_VIDEO_FORMAT_BUTT,
} CVI_HDMI_VIDEO_FORMAT;

typedef enum _CVI_HDMI_ID {
    CVI_HDMI_ID_0 = 0,
    CVI_HDMI_ID_1 = 1,
    CVI_HDMI_ID_BUTT,
} CVI_HDMI_ID;

typedef enum _CVI_HDMI_EVENT_TYPE {
    CVI_HDMI_EVENT_HOTPLUG = 0x10,
    CVI_HDMI_EVENT_NO_PLUG,
    CVI_HDMI_EVENT_EDID_FAIL,
    CVI_HDMI_EVENT_BUTT,
} CVI_HDMI_EVENT_TYPE;

typedef enum _CVI_HDMI_VIDEO_MODE {
    CVI_HDMI_VIDEO_MODE_RGB888 = 0,
    CVI_HDMI_VIDEO_MODE_YCBCR444,
    CVI_HDMI_VIDEO_MODE_YCBCR422,
    CVI_HDMI_VIDEO_MODE_YCBCR420,
    CVI_HDMI_VIDEO_MODE_BUTT,
} CVI_HDMI_VIDEO_MODE;

typedef enum _CVI_HDMI_DEEP_COLOR {
    CVI_HDMI_DEEP_COLOR_8BIT = 8,
    CVI_HDMI_DEEP_COLOR_10BIT = 10,
    CVI_HDMI_DEEP_COLOR_12BIT = 12,
    CVI_HDMI_DEEP_COLOR_BUTT,
} CVI_HDMI_DEEP_COLOR;

typedef void (* CVI_HDMI_CALLBACK) (CVI_HDMI_EVENT_TYPE event, CVI_VOID *private_data);

typedef enum _CVI_HDMI_SAMPLE_RATE {
    CVI_HDMI_SAMPLE_RATE_UNKNOWN,
    CVI_HDMI_SAMPLE_RATE_32K = 32000,
    CVI_HDMI_SAMPLE_RATE_44K = 44100,
    CVI_HDMI_SAMPLE_RATE_48K = 48000,
    CVI_HDMI_SAMPLE_RATE_88K = 88000,
    CVI_HDMI_SAMPLE_RATE_96K = 96000,
    CVI_HDMI_SAMPLE_RATE_176K = 176000,
    CVI_HDMI_SAMPLE_RATE_192K = 192000,
    CVI_HDMI_SAMPLE_RATE_BUTT,
} CVI_HDMI_SAMPLE_RATE;

typedef enum _CVI_HDMI_BIT_DEPTH {
    CVI_HDMI_BIT_DEPTH_UNKNOWN,
    CVI_HDMI_BIT_DEPTH_16 = 16,
    CVI_HDMI_BIT_DEPTH_24 = 24,
    CVI_HDMI_BIT_DEPTH_BUTT,
} CVI_HDMI_BIT_DEPTH;

typedef enum _CVI_HDMI_AUDIO_FORMAT_CODE {
    CVI_HDMI_AUDIO_FORMAT_CODE_RESERVED,
    CVI_HDMI_AUDIO_FORMAT_CODE_PCM,
    CVI_HDMI_AUDIO_FORMAT_CODE_AC3,
    CVI_HDMI_AUDIO_FORMAT_CODE_MPEG1,
    CVI_HDMI_AUDIO_FORMAT_CODE_MP3,
    CVI_HDMI_AUDIO_FORMAT_CODE_MPEG2,
    CVI_HDMI_AUDIO_FORMAT_CODE_AAC,
    CVI_HDMI_AUDIO_FORMAT_CODE_DTS,
    CVI_HDMI_AUDIO_FORMAT_CODE_ATRAC,
    CVI_HDMI_AUDIO_FORMAT_CODE_ONE_BIT,
    CVI_HDMI_AUDIO_FORMAT_CODE_DDP,
    CVI_HDMI_AUDIO_FORMAT_CODE_DTS_HD,
    CVI_HDMI_AUDIO_FORMAT_CODE_MAT,
    CVI_HDMI_AUDIO_FORMAT_CODE_DST,
    CVI_HDMI_AUDIO_FORMAT_CODE_WMA_PRO,
    CVI_HDMI_AUDIO_FORMAT_CODE_BUTT,
} CVI_HDMI_AUDIO_FORMAT_CODE;

typedef enum _CVI_HDMI_COLOR_SPACE {
    CVI_HDMI_COLOR_SPACE_RGB888,
    CVI_HDMI_COLOR_SPACE_YCBCR422,
    CVI_HDMI_COLOR_SPACE_YCBCR444,
    CVI_HDMI_COLOR_SPACE_YCBCR420,
    CVI_HDMI_COLOR_SPACE_BUTT,
} CVI_HDMI_COLOR_SPACE;

typedef enum _CVI_HDMI_BAR_INFO {
    CVI_HDMI_BAR_INFO_NCVI_VALID,
    CVI_HDMI_BAR_INFO_V,
    CVI_HDMI_BAR_INFO_H,
    CVI_HDMI_BAR_INFO_VH,
    CVI_HDMI_BAR_INFO_BUTT,
} CVI_HDMI_BAR_INFO;

typedef enum _CVI_HDMI_SCAN_INFO {
    CVI_HDMI_SCAN_INFO_NO_DATA,
    CVI_HDMI_SCAN_INFO_OVERSCANNED,
    CVI_HDMI_SCAN_INFO_UNDERSCANNED,
    CVI_HDMI_SCAN_INFO_BUTT,
} CVI_HDMI_SCAN_INFO;

typedef enum _CVI_HDMI_COLORIMETRY {
    CVI_HDMI_COMMON_COLORIMETRY_NO_DATA,
    CVI_HDMI_COMMON_COLORIMETRY_ITU601,
    CVI_HDMI_COMMON_COLORIMETRY_ITU709,
    CVI_HDMI_COMMON_COLORIMETRY_BUTT,
} CVI_HDMI_COLORIMETRY;

typedef enum _CVI_HDMI_EX_COLORIMETRY {
    CVI_HDMI_COMMON_COLORIMETRY_XVYCC_601,
    CVI_HDMI_COMMON_COLORIMETRY_XVYCC_709,
    CVI_HDMI_COMMON_COLORIMETRY_S_YCC_601,
    CVI_HDMI_COMMON_COLORIMETRY_ADOBE_YCC_601,
    CVI_HDMI_COMMON_COLORIMETRY_ADOBE_RGB,
    CVI_HDMI_COMMON_COLORIMETRY_2020_CONST_LUMINOUS,
    CVI_HDMI_COMMON_COLORIMETRY_2020_NON_CONST_LUMINOUS,
    CVI_HDMI_COMMON_COLORIMETRY_EX_BUTT,
} CVI_HDMI_EX_COLORIMETRY;

typedef enum _CVI_PIC_ASPECT_RATIO {
    CVI_HDMI_PIC_ASPECT_RATIO_NO_DATA,
    CVI_HDMI_PIC_ASPECT_RATIO_4TO3,
    CVI_HDMI_PIC_ASPECT_RATIO_16TO9,
    CVI_HDMI_PIC_ASPECT_RATIO_64TO27,
    CVI_HDMI_PIC_ASPECT_RATIO_256TO135,
    CVI_HDMI_PIC_ASPECT_BUTT,
} CVI_PIC_ASPECT_RATIO;

typedef enum _CVI_HDMI_ACTIVE_ASPECT_RATIO {
    CVI_HDMI_ACTIVE_ASPECT_RATIO_16TO9_TOP = 2,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_14TO9_TOP,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_16TO9_BOX_CENTER,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_SAME_PIC = 8,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_4TO3_CENTER,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_16TO9_CENTER,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_14TO9_CENTER,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_4TO3_14_9 = 13,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_16TO9_14_9,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_16TO9_4_3,
    CVI_HDMI_ACTIVE_ASPECT_RATIO_BUTT,
} CVI_HDMI_ACTIVE_ASPECT_RATIO;

typedef enum _CVI_HDMI_PIC_SCALINE {
    CVI_HDMI_PICTURE_NON_UNIFORM_SCALING,
    CVI_HDMI_PICTURE_SCALING_H,
    CVI_HDMI_PICTURE_SCALING_V,
    CVI_HDMI_PICTURE_SCALING_HV,
    CVI_HDMI_PICTURE_SCALING_BUTT,
} CVI_HDMI_PIC_SCALINE;

typedef enum _CVI_HDMI_RGB_QUANT_RANGE {
    CVI_HDMI_RGB_QUANT_DEFAULT_RANGE,
    CVI_HDMI_RGB_QUANT_LIMITED_RANGE,
    CVI_HDMI_RGB_QUANT_FULL_RANGE,
    CVI_HDMI_RGB_QUANT_FULL_BUTT,
} CVI_HDMI_RGB_QUANT_RANGE;

typedef enum _CVI_HDMI_PIXEL_REPETITION {
    CVI_HDMI_PIXEL_REPET_NO,
    CVI_HDMI_PIXEL_REPET_2_TIMES,
    CVI_HDMI_PIXEL_REPET_3_TIMES,
    CVI_HDMI_PIXEL_REPET_4_TIMES,
    CVI_HDMI_PIXEL_REPET_5_TIMES,
    CVI_HDMI_PIXEL_REPET_6_TIMES,
    CVI_HDMI_PIXEL_REPET_7_TIMES,
    CVI_HDMI_PIXEL_REPET_8_TIMES,
    CVI_HDMI_PIXEL_REPET_9_TIMES,
    CVI_HDMI_PIXEL_REPET_10_TIMES,
    CVI_HDMI_PIXEL_REPET_BUTT,
} CVI_HDMI_PIXEL_REPETITION;

typedef enum _CVI_HDMI_CONTENT_TYPE {
    CVI_HDMI_CONTNET_GRAPHIC,
    CVI_HDMI_CONTNET_PHOTO,
    CVI_HDMI_CONTNET_CINEMA,
    CVI_HDMI_CONTNET_GAME,
    CVI_HDMI_CONTNET_BUTT,
} CVI_HDMI_CONTENT_TYPE;

typedef enum _CVI_HDMI_YCC_QUANT_RANGE {
    CVI_HDMI_YCC_QUANT_LIMITED_RANGE,
    CVI_HDMI_YCC_QUANT_FULL_RANGE,
    CVI_HDMI_YCC_QUANT_BUTT,
} CVI_HDMI_YCC_QUANT_RANGE;

typedef enum _CVI_HDMI_AUDIO_CHN_CNT {
    CVI_HDMI_AUDIO_CHANEL_CNT_STREAM,
    CVI_HDMI_AUDIO_CHANEL_CNT_2,
    CVI_HDMI_AUDIO_CHANEL_CNT_3,
    CVI_HDMI_AUDIO_CHANEL_CNT_4,
    CVI_HDMI_AUDIO_CHANEL_CNT_5,
    CVI_HDMI_AUDIO_CHANEL_CNT_6,
    CVI_HDMI_AUDIO_CHANEL_CNT_7,
    CVI_HDMI_AUDIO_CHANEL_CNT_8,
    CVI_HDMI_AUDIO_CHANEL_BUTT,
} CVI_HDMI_AUDIO_CHN_CNT;

typedef enum _CVI_HDMI_CODING_TYPE {
    CVI_HDMI_AUDIO_CODING_REFER_STREAM_HEAD,
    CVI_HDMI_AUDIO_CODING_PCM,
    CVI_HDMI_AUDIO_CODING_AC3,
    CVI_HDMI_AUDIO_CODING_MPEG1,
    CVI_HDMI_AUDIO_CODING_MP3,
    CVI_HDMI_AUDIO_CODING_MPEG2,
    CVI_HDMI_AUDIO_CODING_AACLC,
    CVI_HDMI_AUDIO_CODING_DTS,
    CVI_HDMI_AUDIO_CODING_ATRAC,
    CVI_HDMI_AUDIO_CODIND_ONE_BIT_AUDIO,
    CVI_HDMI_AUDIO_CODING_ENAHNCED_AC3,
    CVI_HDMI_AUDIO_CODING_DTS_HD,
    CVI_HDMI_AUDIO_CODING_MAT,
    CVI_HDMI_AUDIO_CODING_DST,
    CVI_HDMI_AUDIO_CODING_WMA_PRO,
    CVI_HDMI_AUDIO_CODING_BUTT,
} CVI_HDMI_CODING_TYPE;

typedef enum _CVI_HDMI_AUDIO_SAMPLE_SIZE {
    CVI_HDMI_AUDIO_SAMPLE_SIZE_STREAM,
    CVI_HDMI_AUDIO_SAMPLE_SIZE_16 = 16,
    CVI_HDMI_AUDIO_SAMPLE_SIZE_20 = 20,
    CVI_HDMI_AUDIO_SAMPLE_SIZE_24 = 24,
    CVI_HDMI_AUDIO_SAMPLE_SIZE_BUTT,
} CVI_HDMI_AUDIO_SAMPLE_SIZE;

typedef enum _CVI_HDMI_AUDIO_SAMPLE_FREQ {
    CVI_HDMI_AUDIO_SAMPLE_FREQ_STREAM,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_32000 = 32000,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_44100 = 44100,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_48000 = 48000,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_88200 = 88200,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_96000 = 96000,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_176400 = 176400,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_192000 = 192000,
    CVI_HDMI_AUDIO_SAMPLE_FREQ_BUTT,
} CVI_HDMI_AUDIO_SAMPLE_FREQ;

typedef enum _CVI_HDMI_LEVEL_SHIFT_VAL {
    CVI_HDMI_LEVEL_SHIFT_VALUE_0_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_1_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_2_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_3_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_4_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_5_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_6_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_7_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_8_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_9_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_10_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_11_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_12_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_13_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_14_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_15_DB,
    CVI_HDMI_LEVEL_SHIFT_VALUE_BUTT,
} CVI_HDMI_LEVEL_SHIFT_VAL;

typedef enum _CVI_HDMI_LFE_PLAYBACK_LEVEL {
    CVI_HDMI_LFE_PLAYBACK_NO,
    CVI_HDMI_LFE_PLAYBACK_0_DB,
    CVI_HDMI_LFE_PLAYBACK_10_DB,
    CVI_HDMI_LFE_PLAYBACK_BUTT,
} CVI_HDMI_LFE_PLAYBACK_LEVEL;

typedef enum _CVI_HDMI_INFOFRAME_TYPE {
    CVI_INFOFRAME_TYPE_AVI,
    CVI_INFOFRAME_TYPE_AUDIO,
    CVI_INFOFRAME_TYPE_VENDORSPEC,
    CVI_INFOFRAME_TYPE_BUTT,
} CVI_HDMI_INFOFRAME_TYPE;

typedef enum _CVI_HDMI_TRACE_LEN {
    CVI_HDMI_TRACE_LEN_0,
    CVI_HDMI_TRACE_LEN_1,
    CVI_HDMI_TRACE_LEN_2,
    CVI_HDMI_TRACE_LEN_3,
    CVI_HDMI_TRACE_LEN_4,
    CVI_HDMI_TRACE_LEN_5,
    CVI_HDMI_TRACE_LEN_6,
    CVI_HDMI_TRACE_LEN_7,
    CVI_HDMI_TRACE_LEN_8,
    CVI_HDMI_TRACE_DEFAULT,
    CVI_HDMI_TRACE_BUTT
} CVI_HDMI_TRACE_LEN;

typedef struct _CVI_HDMI_CALLBACK_FUNC {
    CVI_HDMI_CALLBACK hdmi_event_callback;
    CVI_VOID *private_data;
} CVI_HDMI_CALLBACK_FUNC;

typedef struct _CVI_HDMI_ATTR {
    CVI_BOOL hdmi_en;
    CVI_HDMI_VIDEO_FORMAT video_format;
    CVI_HDMI_DEEP_COLOR deep_color_mode;
    CVI_BOOL audio_en;
    CVI_BOOL hdcp14_en;
    CVI_HDMI_VIDEO_MODE hdmi_video_input;
    CVI_HDMI_VIDEO_MODE hdmi_video_output;
    CVI_HDMI_SAMPLE_RATE sample_rate;
    CVI_HDMI_BIT_DEPTH bit_depth;
    CVI_BOOL auth_mode_en;
    CVI_U64 audio_start_vaddr;
    CVI_U64 audio_stop_vaddr;
    CVI_BOOL deep_color_adapt_en;
    CVI_U32 pix_clk;
} CVI_HDMI_ATTR;

typedef struct _CVI_HDMI_AUDIO_INFO {
    CVI_HDMI_AUDIO_FORMAT_CODE audio_format_code;
    CVI_HDMI_SAMPLE_RATE support_sample_rate[CVI_HDMI_MAX_SAMPLE_RATE_NUM];
    CVI_U32   support_sample_rate_num;
    CVI_U8    audio_chn;
    CVI_HDMI_BIT_DEPTH support_bit_depth[CVI_HDMI_MAX_BIT_DEPTH_NUM];
    CVI_U32   support_bit_depth_num;
    CVI_U32   max_bit_rate;
} CVI_HDMI_AUDIO_INFO;

typedef struct _CVI_HDMI_TIMING_INFO {
    CVI_U32 vfb;
    CVI_U32 vbb;
    CVI_U32 vact;
    CVI_U32 hfb;
    CVI_U32 hbb;
    CVI_U32 hact;
    CVI_U32 vpw;
    CVI_U32 hpw;
    CVI_BOOL idv;
    CVI_BOOL ihs;
    CVI_BOOL ivs;
    CVI_U32 img_width;
    CVI_U32 img_height;
    CVI_U32 aspect_ratio_w;
    CVI_U32 aspect_ratio_h;
    CVI_BOOL interlace;
    CVI_U32 pixel_clk;
} CVI_HDMI_TIMING_INFO;

typedef struct _CVI_HDMI_DETAIL_TIMING {
    CVI_U32 detail_timing_num;
    CVI_HDMI_TIMING_INFO detail_timing[CVI_HDMI_DETAIL_TIMING_MAX];
}CVI_HDMI_DETAIL_TIMING;

typedef struct _CVI_HDMI_SINK_CAPABILITY {
    CVI_BOOL is_connected;
    CVI_BOOL support_hdmi;
    CVI_BOOL is_sink_power_on;
    CVI_HDMI_VIDEO_FORMAT native_video_format;
    CVI_S32 support_video_format[CVI_HDMI_VIDEO_FORMAT_BUTT];
    CVI_BOOL support_ycbcr;
    CVI_BOOL support_xvycc601;
    CVI_BOOL support_xvycc709;
    CVI_U8 md_bit;
    CVI_U32 audio_info_num;
    CVI_BOOL hdcp14_en;
    CVI_HDMI_VIDEO_MODE hdmi_video_input;
    CVI_HDMI_VIDEO_MODE hdmi_video_output;
    CVI_HDMI_AUDIO_INFO audio_info[CVI_HDMI_MAX_AUDIO_CAPBILITY_CNT];
    CVI_BOOL speaker[CVI_HDMI_AUDIO_SPEAKER_BUTT];
    CVI_U8 manufacture_name[CVI_HDMI_MANUFACTURE_NAME_LEN];
    CVI_U32 pdt_code;
    CVI_U32 serial_num;
    CVI_U32 week_of_manufacture;
    CVI_U32 year_of_manufacture;
    CVI_U8 version;
    CVI_U8 revision;
    CVI_U8 edid_ex_blk_num;
    CVI_BOOL is_phy_addr_valid;
    CVI_U8 phys_addr_a;
    CVI_U8 phys_addr_b;
    CVI_U8 phys_addr_c;
    CVI_U8 phys_addr_d;
    CVI_BOOL support_dvi_dual;
    CVI_BOOL support_deepcolor_ycbcr444;
    CVI_BOOL support_deep_color_30bit;
    CVI_BOOL support_deep_color_36bit;
    CVI_BOOL support_deep_color_48bit;
    CVI_BOOL support_ai;
    CVI_U32 max_tmds_clk;
    CVI_BOOL i_latency_fields_present;
    CVI_BOOL latency_fields_present;
    CVI_BOOL hdmi_video_present;
    CVI_U8 video_latency;
    CVI_U8 audio_latency;
    CVI_U8 interlaced_video_latency;
    CVI_U8 interlaced_audio_latency;
    CVI_BOOL support_y420_dc_30bit;
    CVI_BOOL support_y420_dc_36bit;
    CVI_BOOL support_y420_dc_48bit;
    CVI_BOOL support_hdmi_2_0;
    CVI_BOOL support_y420_format[CVI_HDMI_VIDEO_FORMAT_BUTT];
    CVI_BOOL only_support_y420_format[ CVI_HDMI_VIDEO_FORMAT_BUTT];
    CVI_BOOL ycc_quant_selectable;
    CVI_BOOL rgb_quant_selectable;
    CVI_HDMI_DETAIL_TIMING detailed_timing;
} CVI_HDMI_SINK_CAPABILITY;

typedef struct _CVI_HDMI_EDID{
    CVI_BOOL edid_valid;
    CVI_U32 edid_len;
    CVI_U8 edid[256];
} CVI_HDMI_EDID;

typedef struct _CVI_HDMI_AVI_INFOFRAME {
    CVI_HDMI_VIDEO_FORMAT timing_mode;
    CVI_HDMI_COLOR_SPACE color_space;
    CVI_BOOL active_info_present;
    CVI_HDMI_BAR_INFO bar_info;
    CVI_HDMI_SCAN_INFO scan_info;
    CVI_HDMI_COLORIMETRY colorimetry;
    CVI_HDMI_EX_COLORIMETRY ex_colorimetry;
    CVI_PIC_ASPECT_RATIO aspect_ratio;
    CVI_HDMI_ACTIVE_ASPECT_RATIO active_aspect_ratio;
    CVI_HDMI_PIC_SCALINE pic_scaling;
    CVI_HDMI_RGB_QUANT_RANGE rgb_quant;
    CVI_BOOL is_it_content;
    CVI_HDMI_PIXEL_REPETITION pixel_repetition;
    CVI_HDMI_CONTENT_TYPE content_type;
    CVI_HDMI_YCC_QUANT_RANGE ycc_quant;
    CVI_U16   line_n_end_of_top_bar;
    CVI_U16 line_n_start_of_bcvi_bar;
    CVI_U16 pixel_n_end_of_left_bar;
    CVI_U16 pixel_n_start_of_right_bar;
} CVI_HDMI_AVI_INFOFRAME;

typedef struct _CVI_HDMI_AUDIO_INFOFRAME {
    CVI_HDMI_AUDIO_CHN_CNT chn_cnt;
    CVI_HDMI_CODING_TYPE coding_type;
    CVI_HDMI_AUDIO_SAMPLE_SIZE sample_size;
    CVI_HDMI_AUDIO_SAMPLE_FREQ sampling_freq;
    CVI_U8 chn_alloc;
    CVI_HDMI_LEVEL_SHIFT_VAL level_shift;
    CVI_HDMI_LFE_PLAYBACK_LEVEL lfe_playback_level;
    CVI_BOOL down_mix_inhibit;
} CVI_HDMI_AUDIO_INFOFRAME;

typedef struct _CVI_HDMI_VENDORSPEC_INFOFRAME {
    CVI_U8 data_len;
    CVI_U8 user_data[CVI_HDMI_VENDOR_USER_DATA_MAX_LEN];
} CVI_HDMI_VENDORSPEC_INFOFRAME;

typedef struct _CVI_HDMI_INFOFRAME_UNIT {
    CVI_HDMI_AVI_INFOFRAME avi_infoframe;
    CVI_HDMI_AUDIO_INFOFRAME audio_infoframe;
    CVI_HDMI_VENDORSPEC_INFOFRAME vendor_spec_infoframe;
} CVI_HDMI_INFOFRAME_UNIT;

typedef struct _CVI_HDMI_INFOFRAME {
    CVI_HDMI_INFOFRAME_TYPE infoframe_type;
    CVI_HDMI_INFOFRAME_UNIT infoframe_unit;
} CVI_HDMI_INFOFRAME;

typedef struct _CVI_HDMI_HW_PARAM {
    CVI_U32 i_de_main_clk;
    CVI_U32 i_de_main_data;
    CVI_U32 i_main_clk;
    CVI_U32 i_main_data;
    CVI_U32 ft_cap_clk;
    CVI_U32 ft_cap_data;
} CVI_HDMI_HW_PARAM;

typedef struct _CVI_HDMI_HW_SPEC {
    CVI_HDMI_HW_PARAM hw_param[CVI_HDMI_HW_PARAM_NUM];
} CVI_HDMI_HW_SPEC;

typedef struct _CVI_HDMI_MOD_PARAM {
    CVI_HDMI_TRACE_LEN trace_len; /* Phy parameters selection. */
    CVI_BOOL emi_en; /* emi enable/disable */
} CVI_HDMI_MOD_PARAM;


#endif