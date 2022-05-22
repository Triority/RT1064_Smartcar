#include "utils/FuncThread.hpp"
//
extern "C" {
#include "SEEKFREE_IPS114_SPI.h"
#include "SEEKFREE_MT9V03X_CSI.h"
#include "common.h"
#include "fsl_debug_console.h"
#include "zf_gpio.h"
#include "zf_usb_cdc.h"
}

#include "apriltag/visualization.hpp"
#include "devices.hpp"
#include "edge_detect/canny.hpp"
#include "edge_detect/conv.hpp"
#include "edge_detect/show_edge.hpp"

static void testCannyEntry() {
    using namespace imgProc::apriltag;
    using namespace imgProc::edge_detect;

    int32_t pre_time = rt_tick_get();

    for (;;) {
        bool visualize = slave_switch[2].get();  // ���뿪�ؾ����Ƿ���п��ӻ�����Ϊ���ӻ�������ʱ��

        staticBuffer.reset();

        uint8_t* img = mt9v03x_csi_image_take();
        if (!visualize) show_grayscale(img);

        canny(img, 50, 100);  // ��Ե���

        if (visualize) show_edge(img);

        if (!slave_key[0].get()) {
            static uint8_t buf[4]{0x00, 0xff, 0x80, 0x7f};
            usb_cdc_send_buff(buf, 4);
            usb_cdc_send_buff(img, N * M);
        }

        mt9v03x_csi_image_release();  // �ͷ�ͼƬ

        int32_t cur_time = rt_tick_get();
        ips114_showint32(188, 0, cur_time - pre_time, 3);  // ��ʾ��ʱ/ms
        pre_time = cur_time;
    }
}

bool testCannyNode() { return FuncThread(testCannyEntry, "testCanny", 4096, 2, 1000); }