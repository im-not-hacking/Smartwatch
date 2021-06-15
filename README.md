# Smartwatch
Code for smartwatch project. Includes code for ESP32 and Android App to control it.

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122109770-bdc8e380-cdeb-11eb-9444-85e0e1fd540a.jpg" width="400" height="400">
</p>


# How it works
The smartwatch itself is an ESP32 microcontroller with an SSD1351 display, RV-3028C7 RTC, LED, Accelerometer, Light Sensor and three buttons.
The Android app works as a client to the ESP32 server, and sends information about the current weather, navigation, current time and button presses for music.

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122127759-aa287780-ce01-11eb-8fd2-2cc688c55da2.png" width="250" height="400">
</p>


The smartwatch initializes with a loading screen while it connects to the app through BLE communication in the background.

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122128088-291db000-ce02-11eb-988c-b6d1d4397a06.png" width="250" height="250">
</p>

Once it loads, the smartwatch consists of 2 main components, a clock display and a menu display. In the clock display the user is able to see the time, weather information, day of the week, month and battery percentage. In the menu display the user can choose between 8 submenus.

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122128416-a77a5200-ce02-11eb-8fd4-9e9af2840579.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122128421-a9441580-ce02-11eb-8417-8a42c2994174.png" width="250" height="250">
</p>

The 8 submenus in order are: Navigation, Heart Rate Monitor, Weather Information, Music Controller, Pong, Stopwatch, Lantern, Settings.

If the smartwatch is left unactive and in a horizontal poisition it goes into sleepmode and can only be turned on again by either turning it into a vertical position or clicking a button.

# Navigation 

Photo of navigation premenu and menu

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122128788-12c42400-ce03-11eb-8b87-008e0412a748.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122128786-12c42400-ce03-11eb-909c-4eb2b78c8c05.png" width="250" height="250">
</p>

In navigation the user can select any place on a map in the Android App, the app will then calculate the distance between the user's current location and the selected point as well as point to the new location everywhere the user moves. This information will then be sent to the smartwatch through real time ble communication. The purpose of navigation is to be able to move anywhere you want by only using the smartwatch.

# Heart Rate Monitor

Photo of hr premenu and menu

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130202-4b64fd00-ce05-11eb-9b36-6c71182c64da.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130201-4b64fd00-ce05-11eb-993c-44e6810abac4.png" width="250" height="250">
</p>

In HRM the user can check his or her heart rate using the light sensor at the bottom of the smartwatch

# Weather Information

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130303-6899cb80-ce05-11eb-9e74-3695b4ea1173.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130305-69326200-ce05-11eb-9186-0e7ebf1f7152.png" width="250" height="250">
</p>

In Weather Information the user can see information retreived from an API in the Android App that fetches data regarding the weather of the user's current location. The information displayed is: Current weather description, current temperature and current humidity in the air.

# Music Control

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130375-81a27c80-ce05-11eb-9ae9-9f4e92a413a5.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130374-81a27c80-ce05-11eb-99a8-ae66931475da.png" width="250" height="250">
</p>

In Music Control the user can pause, play, forward and backtrack a song. For this the smartwatch sends signals to the Android device to press buttons that replicate the action the user selected.

# Pong

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130439-9e3eb480-ce05-11eb-8881-1b1e7e2ce6f7.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130437-9da61e00-ce05-11eb-9090-3bc91d5c2a4c.png" width="250" height="250">
</p>

In Pong the user can play a solitary pong where the purpose of the game is to not let the virtual ball pass the bar he controls (as is the case in regular pong), the user has three "lives" and after each level succesfully passed the speed of the ball increases. After the user loses three times the sceen turns red and the user is still able to play, but without advancing levels.

# Stopwatch

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130486-b1ea1b00-ce05-11eb-81ff-671413c27841.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130487-b1ea1b00-ce05-11eb-8737-21bc99f614c6.png" width="250" height="250">
</p>

A regular chronometer that counts minutes, seconds and miliseconds and can be reset to 0

# Lantern

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130545-ca5a3580-ce05-11eb-8534-3841d9af115f.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130543-ca5a3580-ce05-11eb-9285-cbe05bbdf5ed.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130546-ca5a3580-ce05-11eb-9bfa-da45541eb059.png" width="250" height="250">
</p>

The user can click a button to turn on and off the smartwatch's internal LED

# Settings

<p align="center"> 
<img src="https://user-images.githubusercontent.com/79129370/122130655-fa093d80-ce05-11eb-8444-33bee59aae31.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130653-fa093d80-ce05-11eb-8e5e-880320b1edc5.png" width="250" height="250">
<img src="https://user-images.githubusercontent.com/79129370/122130656-fa093d80-ce05-11eb-9852-bffa89eec6ab.png" width="250" height="250">
</p>

In settings the user can change between 4 characteristics. The clock menu diplay (classic clock or analog), wake up by rotation or by button, color of the display and turn on/off sound. The information is saved in the internal memory of the ESP so that it can be retained even when the smartwatch is restarted. 
