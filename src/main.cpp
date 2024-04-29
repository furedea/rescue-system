#include <kernel.h>

// #include "GR_PEACH_WlanBP3595.h"
// #include "Milkcocoa.h"
#include "car.h"
// #include "ip_address.h" // TODO: IPアドレス用だがエラーが怖いのでコメントアウト
#include "private_car_strategy.h"  // 自家用車
// #include "rescue_car_strategy.h" // 救助車
#include "Zumo.h"
#include "app.h"
#include "app_config.h"
#include "kernel_cfg.h"
#include "mbed.h"

// GR_PEACH_WlanBP3595 wlan;
extern void onpush(MQTT::MessageData& md);
Serial pc(USBTX, USBRX);
// Zumo zumo;

void onpush(MQTT::MessageData& md) {
    pc.printf("onpush\n\r");
    MQTT::Message& message = md.message;
    DataElement de = DataElement((char*)message.payload);
    int v = de.getInt("z");
}

// ここまでテンプレート?

void task_main(intptr_t exinf) {
    pc.baud(9600);  // シリアル通信のボーレートを9600bpsに設定。ないとエラーが出る。
    dly_tsk(5000);
    // ここまでテンプレート?
    PrivateCarStrategy strategy;
    // RescueCarStrategy strategy;
    Car car("192.168.11.12", &strategy);  // 自家用車
    // Car car("192.168.11.11", &strategy); // 救助車
    car.run();
}
