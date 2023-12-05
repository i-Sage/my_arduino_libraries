#ifndef HC_SRO4_H
#define HC_SRO4_H

#include <Arduino.h>

/**
 * @class HC_SRO4
 * @brief Represents a HC_SRO4 Ultrasonic sensor object.
 *
 * @note The Ultrasonic Sensor is an electronic device which measures distances
 * by sending out sound waves and collecting the returning echoes. It can
 * measure up to 4.5 meters away. It enables measuring distances accurately
 * without contact with the target item. The sensor fetures adjustable pulse
 * width, allowing for higher resolution measurnments when set at lower levels
 * though this comes at cost of range accuracy diminishing as a result.
 * The principle of ultrasonic range finders is to measure the time it
 * takes the signal sent by the transmitter and propagated back to the receiver.
 * These sensors operate on frequencies beyond our hearing range known as
 * ultrasonic frequencies. These frequencies are above 20K Hertz.
 * The distance is determined by measuring the travel time of ultrasonic
 * sound and its speed. DISTANCE = (TIME * SPEED OF SOUND) / 2
 * To generate the ultrasonic sound, we need to trigger the trigger pin high for
 * a minimum of 10us. Then the module will start sending 8 sonic burst
 * ultrasounds from the moudule at 40 khz. These bursts will be received by the
 * receiver called, and can be accessed from the Echo pin and it will calculate
 * the output time to measure the distance. For example, lets say the echo pin
 * was high for 2ms(measured using the pulseIn() function). If we want to get
 * the distance result in cm, we can convert the speed of sound value from
 * 340m/s to 34cm/ms. DISTANCE = 34CM/MS * 2MS) / 2 = 34CM.
 *
 * @note Specification of the HC_SRO4
 * - Supply Voltage: +5V
 * - Consumption in silent mode: 2mA
 * - Consumption at work: 15mA
 * - Measurnment range: 2 to 400cm
 * - Effective measuring angle: 15 degrees
 * - Accuracy: +- 3mm
 * - Dimensions: 45*20*15mm
 */

namespace UT {

class HC_SRO4 {
private:
  /**
   * @brief The trigger pin
   */
  int trigger_pin;
  /**
   * @brief The echo pin
   */
  int echo_pin;
  /**
   * @brief Stores the distance from the ultrasonic sensor
   */
  float distance;
  /**
   * @brief Stores the duration the echo pin stays high
   */
  unsigned long duration;

public:
  /**
   * @brief The constructor sets up the Pins
   *
   * @param trg The pin to use as the trigger pin
   * @param echo The pin to use as the echo pin
   */
  HC_SRO4(int trg, int echo);
  /**
   * @brief Calculates the
   *
   * @return distance in cm
   */
  [[nodiscard]] float get_distance();
};
} // namespace UT
#endif
