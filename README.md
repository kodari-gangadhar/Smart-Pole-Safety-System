![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)
![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)


# Smart Pole – Be Smart and Safe 🚨🌐

A final-year Diploma project aimed at enhancing public safety through the integration of smart technology into urban street lighting infrastructure.

## 📌 Project Overview

Smart Pole is an innovative system that upgrades traditional streetlights with emergency response features. It is specifically designed to assist individuals in distress—particularly women and children—by allowing them to send an immediate alert to nearby police stations, while simultaneously activating lights, sirens, and GPS location tracking.

## 🎯 Aim

To develop a real-time emergency alert and response system embedded into smart street poles, enhancing public safety using:

- Distress button activation  
- Siren and LED light alerts  
- Real-time GPS tracking  
- GSM-based SMS alerts  

## 🔧 Components Used

### Hardware

- Arduino Uno (Microcontroller)
- GPS Module (SIM28ML or equivalent)
- GSM Module (SIM900A)
- Buzzer
- LED Light (Red)
- Emergency Button
- 12V 2A Adapter
- Data Transfer Cable

### Software

- Arduino IDE
- MS Word (Documentation)
- Web Browsers (Google Chrome, IE 6.0)

## 📐 System Workflow

1. Emergency button is pressed
2. Buzzer and siren are activated
3. LED light turns on to draw attention
4. GPS module retrieves real-time location
5. Message with coordinates is sent via GSM
6. Police receive location alert and respond

## 📂 Project Structure
- `/code/` – Arduino source code
- `/docs/` – Project documentation
- `/output-images/` – Output Screenshots
- `/Models/` - Arduino Model Architecture Designs

## 💡 Features

- Immediate visual and audible alert
- Real-time location sharing with authorities
- Coded in embedded C using Arduino IDE
- Fully automated alert dispatch system
- Integration-ready for surveillance cameras

## 🔄 Example Use Cases

- Women's safety at night in urban areas
- Elderly in medical emergencies
- Children in distressful situations

## 📸 Output

- **SMS Alert:** “ALERT HELP NEEDED” with GPS coordinates  
- **LED Indicator:** Illuminates area during alert  
- **Buzzer/Siren:** Audible signal for local awareness  

## 📜 Sample Code Snippet

```c
if (digitalRead(btnPin) == HIGH) {
  digitalWrite(ledPin, HIGH);
  delay(3000);
  digitalWrite(ledPin, LOW);
  sgsm.listen();
  sgsm.print("AT+CMGF=1\r");
  delay(1000);
  sgsm.print("AT+CMGS=\"+91XXXXXXXXXX\"\r");
  delay(1000);
  sgsm.print("https://www.google.com/maps/?q=");
  sgsm.print(gpslat, 6);
  sgsm.print(",");
  sgsm.print(gpslon, 6);
  delay(1000);
  sgsm.write(0x1A);
}
```

## 🧠 Future Enhancements

- Integration of camera modules with fisheye lenses
- Cloud-based data storage and analytics
- Mobile app interface for public use
- Solar power support for sustainability

## 👨‍💻 Developed By

**K.Gangadhar & Team**  
Diploma in Computer Engineering  
Government Polytechnic, Warangal (2021–2024)

## 📜 License
This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

## 📚 References

- [Arduino Documentation](https://www.arduino.cc/)
- [W3Schools](https://www.w3schools.com/)
- [Microcontrollers Lab – SIM900A Guide](http://microcontrollerslab.com)
```
