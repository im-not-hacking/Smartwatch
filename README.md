# Smartwatch
Code for smartwatch project. Includes code for ESP32 and Android App to control it.

Photo of Smartwatch

# How it works
The smartwatch itself is an ESP32 microcontroller with an AdafruitGFX display, RTC, LED, Accelerometer, Light Sensor and three buttons.
The Android app works as a client to the ESP32 server, and sends information about the current weather, navigation, current time and button presses for music.

Photo of App

The smartwatch initializes with a loading screen while it connects to the app through BLE communication in the background.

Photo of loading screen

Once it loads, the smartwatch consists of 2 main components, a clock display and a menu display. In the clock display the user is able to see the time, weather information, day of the week, month and battery percentage. In the menu display the user can choose between 8 submenus.

Photo of clock, photo of menu

The 8 submenus in order are: Navigation, Heart Rate Monitor, Weather Information, Music Controller, Pong, Cronometer, Light, Settings.

If the smartwatch is left unactive and in a horizontal poisition it goes into sleepmode and can only be turned on again by either turning it into a vertical position or clicking a button.

# Navigation 

Photo of navigation premenu and menu

In navigation the user can select any place on a map in the Android App, the app will then calculate the distance between the user's current location and the selected point as well as point to the new location everywhere the user moves. This information will then be sent to the smartwatch through real time ble communication. The purpose of navigation is to be able to move anywhere you want by only using the smartwatch.

# Heart Rate Monitor

Photo of hr premenu and menu

In HRM the user can check his or her heart rate using the light sensor at the bottom of the smarwatch

# Weather Information

Photo of Weather premenu and menu

In Weather Information the user can see information retreived from an API in the Android App that fetches data regarding the weather of the user's current location. The information displayed is: Current weather description, current temperature and current humidity in the air.

# Music Control

Photo of Music control premenu and menu

In Music Control the user can pause, play, forward and backtrack a song. For this the smartwatch sends signals to the Android device to press buttons that replicate the action the user selected.

# Pong

Photo of Music control premenu and menu

In Pong the user can play a solitary pong where the purpose of the game is to not let the virtual ball pass the bar he controls (as is the case in regular pong), the user has three "lives" and after each level succesfully passed the speed of the ball increases. After the user loses three times the sceen turns red and the user is still able to play, but without advancing levels.

# Chronometer

Photo of Music control premenu and menu

A regular chronometer that counts minutes, seconds and miliseconds and can be reset to 0

# Flashlight

Photo of Music control premenu and menu

The user can click a button to turn on and off the smartwatch's internal flashlight

# Settings

Photo of Music control premenu and menu

In settings the user can change between 4 characteristics. The clock menu diplay (classic clock or analog), wake up by rotation or by button, color of the display and turn on/off sound. The information is saved in the internal memory of the ESP so that it can be retained even when the smartwatch is restarted. 
