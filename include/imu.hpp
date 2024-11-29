#pragma once
#ifndef IMU_HPP
#define IMU_HPP

#include "LSM6DS3.h"
#include "Wire.h"

#define SENSOR_READ_DELAY_MS 50
#define DEFAULT_IMU_I2C_ADDR 0x6A

class IMU
{
public:
    // Constructor with a default I2C address
    IMU(uint8_t address = DEFAULT_IMU_I2C_ADDR); // Default I2C address for LSM6DS3

    // Initialize the sensor
    bool begin();

    // Detect significant motion based on acceleration threshold
    bool isMotionDetected(float threshold = 2.5); // Detect motion (default threshold: 2.5)

    void collectAndTransmit(std::function<void(void *, String)> transmitCallback, void *callbackArg = nullptr);

private:
    LSM6DS3 sensor; // IMU sensor object

    // Accelerometer and Gyroscope data
    float aX, aY, aZ, gX, gY, gZ = 0;
};

#endif
