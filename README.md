# Embedded Systems Projects with AVR ATmega32
**Description:**

This repository showcases a collection of embedded systems projects developed using the AVR ATmega32 microcontroller. Each project includes well-organized source code, header files, and a detailed README file providing instructions on setup, usage, and hardware requirements.

**Tools and Components:**

- ![atmel](https://github.com/user-attachments/assets/e22d047e-823e-4d61-8574-07184f4ab3a7) **Development Environment:** Atmel Studio 7.0
- ![proteus](https://github.com/user-attachments/assets/c13fbe1c-637f-4439-9510-5b23406451ab) **Simulation Software:** Proteus 8 Application Framework
- ![image](https://github.com/user-attachments/assets/5b6fa58e-e13e-4665-abc7-0693b3e5843b) **Language Used:** C Language
- **Microcontroller:** AVR ATmega32
- **Datasheet:** [Link to ATmega32 datasheet](https://drive.google.com/file/d/1UMuUQ7lK8PmzG-fhNcWcx1v4-HpnDq6v/view?usp=sharing)



## **Project 1: Displaying numbers from 0 to 9 on 7-Segment Display**

**Description:**

This project demonstrates how to control a 7-segment display using the AVR ATmega32 microcontroller. The code sequentially displays numbers from 0 to 9 on the display.

**Hardware Requirements:**

- AVR ATmega32 microcontroller 
- 7-segment display (common cathode)

**Usage:**

1. **Compile the code:** Open the project in Atmel Studio 7.0 and compile it.
2. **Upload the code:** Upload the compiled code to your AVR microcontroller.
3. **Observe the display:** The 7-segment display should count from 0 to 9.

**Video Tutorial:** [Link to video tutorial on YouTube or other platform]


**Descriping Image:** <br> ![Image on Proteus](https://github.com/user-attachments/assets/89dae90b-e11d-4dfa-b973-7dd7793f95b7)


**Additional Notes:**

- The code assumes a common cathode 7-segment display. Adjust the pin connections and array values if using a common anode display.
- You can modify the code to display different numbers or patterns as desired.



## **Project 2: Traffic Lightening System with 7-Segment Displays**

**Description:**

This project implements a basic traffic light system using an AVR microcontroller. The system features three LEDs (red, yellow, and green) to simulate a traffic light and two 7-segment displays to count down the seconds for each light.

**Hardware Requirements:**

- AVR ATmega32 microcontroller
- 7-segment displays (2) (common cathode)
- LEDs (red, yellow, green)

**Functionality:**

1. **Green LED:** Turns on for 10 seconds.
2. **Yellow LED:** Turns on for 3 seconds.
3. **Red LED:** Turns on for 10 seconds.
4. **Repeat:** The cycle repeats indefinitely.
5. **7-Segment Displays:**  The two 7-segment displays will count down the seconds for each light.

**Video Tutorial:** [Link to video tutorial on YouTube or other platform]


**Descriping Image:** <br> ![Image 2 on Proteus](https://github.com/user-attachments/assets/7fb015e2-38c4-4cc1-bdc1-a383d66c265a)



**Additional Considerations:**

-  Adjust the delay values as needed to control the timing of the traffic light sequence.
- You'll need to fill in the specific pin numbers for your hardware setup and implement the logic to control the 7-segment displays and LEDs. 
- You can use the `PORTx` registers and bit manipulation to control the individual segments of the 7-segment displays.
